;;;
;;; spl.el v 1.0
;;;
;;; An Emacs major mode for the Shakespeare Programming Language.
;;; 
;;; Author:
;;;   Frej Drejhammar <frej@sics.se>
;;;
;;; Copyright (C) 2001 Frej Drejhammar <frej@sics.se>
;;;
;;; This program is free software; you can redistribute it and/or modify
;;; it under the terms of the GNU General Public License Version 2 as 
;;; published by the Free Software Foundation.
;;;
;;; This program is distributed in the hope that it will be useful,
;;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;;; GNU General Public License for more details.
;;;
;;; You should have received a copy of the GNU General Public License
;;; along with this program; if not, write to the Free Software
;;; Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
;;;
;;;
;;; This major mode is based on the Oz-mode copyrighted by:
;;;   Leif Kornstaedt, Michael Mehl, and Ralf Scheidhauer, 1993-1998
;;;   Denys Duchier, 1998.
;;; See http://www.mozart-oz.org for more information.
;;; See the file "LICENSE-mozart" for the original license agreement.
;;;

;;
;; Global Effects
;;
(or (assoc "\\.spl$" auto-mode-alist)
    (setq auto-mode-alist
	  (append '(("\\.spl$" . spl-mode))
		  auto-mode-alist)))

;;
;; GNU and Lucid Emacsen Support
;;

(eval-and-compile
  (defvar spl-gnu-emacs
    (string-match "\\`[0-9]+\\(\\.[0-9]+\\)*\\'" emacs-version)
    "Non-nil iff we're running under GNU Emacs.")
  (defvar spl-lucid-emacs
    (string-match "\\<XEmacs\\>\\|\\<Lucid\\>" emacs-version)
    "Non-nil iff we're running under XEmacs."))
;;
;; Patterns for Indentation and Expression Hopping
;;

(defun spl-make-keywords-for-match (args)
  (concat "\\<\\(" (if (fboundp 'regexp-opt)
		       (regexp-opt args)
		     (mapconcat 'regexp-quote args "\\|"))
	  "\\)\\>"))


(defconst spl-act-scene-begin-pattern
  (spl-make-keywords-for-match
   '("Act" "Scene")))

(defconst spl-act-scene-enter-exit-pattern
  (concat spl-act-scene-begin-pattern "\\|\\(\\["
	  (spl-make-keywords-for-match '("Enter" "Exit" "Exeunt")) "\\)"))

;;
;; Indentation
;;


(defconst spl-indent-lines
  8
  "The number of columns lines are indented.")

(defun spl-electric-terminate-line ()
  "Terminate current line. Indent the terminated line and the following line."
  (interactive)
  (delete-horizontal-space)		; Removes trailing whitespace
  (open-line 1)
  (spl-indent-line-sub t)
  (forward-line 1)
  (spl-indent-line-sub))

(defun spl-indent-buffer ()
  "Indent every line in the current buffer."
  (interactive)
  (spl-indent-region (point-min) (point-max)))

(defun spl-indent-region (start end)
  "Indent every line in the current region."
  (interactive "r")
  (let ((old-line (count-lines 1 (point))))
    (goto-char start)
    (let ((current-line (+ (count-lines 1 start)
			   (if (= (current-column) 0) 1 0)))
	  (end-line (1+ (count-lines 1 end))))
      (while (< current-line end-line)
	(message "Indenting line %s ..." current-line)
	(spl-indent-line-sub t)
	(setq current-line (1+ current-line))
	(forward-line 1)))
    (message nil)
    (goto-line old-line)))

(defun spl-indent-line (&optional arg)
  "Indent the current line.
If ARG is given, reindent that many lines above and below point as well."
  (interactive "P")
  (save-excursion
    (let* ((current-line (1+ (count-lines 1 (point))))
	   (n (abs (if arg (prefix-numeric-value arg) 0)))
	   (start-line (max (- current-line n) 1))
	   (nlines (- current-line start-line)))
      (forward-line (- nlines))
      (while (> nlines 0)
	(spl-indent-line-sub t)
	(setq nlines (1- nlines))
	(forward-line 1))))
  (spl-indent-line-sub nil)
  (save-excursion
    (let ((nlines (abs (if arg (prefix-numeric-value arg) 0))))
      (while (> nlines 0)
	(if (= (forward-line 1) 0)
	    (spl-indent-line-sub t))
	(setq nlines (1- nlines))))))

(defun spl-indent-line-sub (&optional dont-change-empty-lines)
  ;; Indent the current line.
  ;; If DONT-CHANGE-EMPTY-LINES is non-nil and the current line is empty
  ;; save for whitespace, then its indentation is not changed.  If the
  ;; point was inside the line's leading whitespace, then it is moved to
  ;; the end of this whitespace after indentation.
  (let ((case-fold-search nil))		; respect case
    (unwind-protect
	(save-excursion
	  (beginning-of-line)
	  (skip-chars-forward " \t")
	  (if (and dont-change-empty-lines (spl-is-empty)) t
	    (let ((col (save-excursion (spl-calc-indent))))
	      ;; a negative result means: do not change indentation
	      (if (>= col 0)
		  (if (or (progn (beginning-of-line)
				 (not (looking-at "\t* ? ? ? ? ? ? ?")))
			  (progn (goto-char (match-end 0))
				 (or (looking-at "[\t ]")
				     (/= (current-column) col))))
		      (progn
			(delete-horizontal-space)
			(indent-to col)))))))
      (if (spl-is-left)
	  (skip-chars-forward " \t")))))

(defun spl-backward-keyword ()
  "Search backward for the last act, scene, enter or exit statement preceding
 point. Return non-nil iff such a keyword was found. Point is left at the first
 character of the keyword."
  (let ((continue t)
	(ret nil))
    (while continue
      (if (re-search-backward spl-act-scene-enter-exit-pattern nil t)
	  (setq ret t continue nil)
	(setq continue nil)))
    ret))

(defun spl-calc-indent ()
  ;; Calculate the required indentation for the current line.
  ;; The point must be at the beginning of the current line.
  ;; Return a negative value if the indentation is not to be changed,
  ;; else return the column up to where the line should be indented.
  (cond
   ((looking-at spl-act-scene-begin-pattern)
    (let (llen)
      (beginning-of-line)
      (delete-horizontal-space)
      (end-of-line)
      (delete-horizontal-space)
      (setq llen (current-column))
      (if (> llen fill-column)
	  0 ;; Flush left if the line is to long
	(/ (- fill-column llen) 2))))
   ((looking-at spl-act-scene-enter-exit-pattern)
    0)
   ((looking-at (concat spl-character-matcher ":"))
    0)
   ((spl-backward-keyword) spl-indent-lines)
   (0)))


(defun spl-is-left ()
  ;; Return non-nil iff the point is only preceded by whitespace in the line.
  (save-excursion
    (skip-chars-backward " \t")
    (= (current-column) 0)))

(defun spl-is-right ()
  ;; Return non-nil iff the point is only followed by whitespace in the line.
  (looking-at "[ \t]*$"))

(defun spl-is-empty ()
  ;; Return non-nil iff the current line is empty save for whitespace.
  (and (spl-is-left) (spl-is-right)))

(defun forward-spl-line (&optional arg)
  "Move forward one line. With argument, do it that many times. 
 Negative ARG means backwards."
  (interactive "p")
  (re-search-forward (concat spl-character-matcher ":") nil t)
  (forward-line))

(defun backward-spl-line (&optional arg)
  "Move backward one line. With argument, do it that many times.  Argument must be positive."
  (interactive "p")
  (re-search-backward (concat spl-character-matcher ":") nil t)
  (re-search-backward (concat spl-character-matcher ":") nil t)
  (forward-line))

(defun forward-spl-act-scene (&optional arg)
  "Move forward one scene/act. With argument, do it that many times. 
 Negative ARG means backwards."
  (interactive "p")
  (re-search-forward (concat spl-act-scene-begin-pattern ".*:") nil t)
  (forward-line))

(defun backward-spl-act-scene (&optional arg)
  "Move backward one scene/act. With argument, do it that many times.  Argument must be positive."
  (interactive "p")
  (re-search-backward (concat spl-act-scene-begin-pattern ".*:") nil t)
  (re-search-backward (concat spl-act-scene-begin-pattern ".*:") nil t)
  (forward-line))

;;
;; Keymap Definitions
;;

(defun spl-define-key (key fun)
  ;; if IS-ALIAS is non nil, define fun/tty to be an alias for fun
  ;; and use fun/tty as the definition instead of fun.  This way
  ;; menu entries will always document the short prefix.
  (let ((afun fun))
    (cond (is-alias
	   (setq afun (intern (concat (symbol-name fun) "/tty")))
	   (fset afun fun)))
    (define-key map key afun)))

(defvar spl-mode-map
  (let ((map (make-sparse-keymap)))
    (define-key map [tab]    'spl-indent-line)
    (define-key map [(meta tab)]    'spl-fill-paragraph)
    (define-key map [del]    'backward-delete-char-untabify)
    (define-key map [return] 'spl-electric-terminate-line)
    ;;
    (define-key map [(meta control ?f)]  'forward-spl-line)
    (define-key map [(meta control ?b)]  'backward-spl-line)

    (define-key map [(meta control ?F)]  'forward-spl-act-scene)
    (define-key map [(meta control ?B)]  'backward-spl-act-scene)
    ;;

    (define-key map [(meta ?n)] 'spl-next-buffer)
    (define-key map [(meta ?p)] 'spl-previous-buffer)
    map)
  "Keymap used in the Spl modes.")

;;
;; Menus
;;

;; GNU Emacs: a menubar is a usual key sequence with prefix "menu-bar"
;; Lucid Emacs: a menubar is a new datastructure
;;    (see function set-buffer-menubar)

(defvar spl-menubar nil
  "Spl Menubar for Lucid Emacs.")

(defun spl-make-menu (list)
  (cond (spl-gnu-emacs
	 (spl-make-menu-gnu spl-mode-map
			    (list (cons "menu-bar" (cons nil list))))
	 ;;(define-key spl-mode-map [down-mouse-3] 'spl-menubar)
	 )
	(spl-lucid-emacs
	 (setq spl-menubar (car (spl-make-menu-lucid list))))))

(defvar spl-temp-counter 0
  "Internal counter for gensym.")

(defun spl-make-temp-name (prefix)
  (setq spl-temp-counter (1+ spl-temp-counter))
  (intern (format "%s%d" (make-temp-name prefix) spl-temp-counter)))

(defun spl-make-menu-gnu (map list)
  (if list
      (progn
	(let* ((entry (car list))
	       (name (car entry))
	       (aname (intern name))
	       (command (car (cdr entry)))
	       (rest (cdr (cdr entry))))
	  (cond ((null rest)
		 (define-key map (vector (spl-make-temp-name name))
		   (cons name nil)))
		((null command)
		 (let ((newmap (make-sparse-keymap name)))
		   (define-key map (vector aname)
		     (cons name newmap))
		   (if (string= name "Spl")
		       (fset 'spl-menubar newmap))
		   (spl-make-menu-gnu newmap (reverse rest))))
		(t
		 (define-key map (vector aname) (cons name command))
		 (put command 'menu-enable (car rest)))))
	(spl-make-menu-gnu map (cdr list)))))

(defun spl-make-menu-lucid (list)
  (if list
      (cons
       (let* ((entry (car list))
	      (name (car entry))
	      (command (car (cdr entry)))
	      (rest (cdr (cdr entry))))
	 (cond ((null rest)
		(vector name nil nil))
	       ((null command)
		(cons name (spl-make-menu-lucid rest)))
	       (t
		(vector name command (car rest)))))
       (spl-make-menu-lucid (cdr list)))))

(defvar spl-menu
  '(("Spl" nil
     ("Movement" nil
      ("Line forward"       forward-spl-line t)
      ("Line backward"      backward-spl-line t)
      ("-----")
      ("Act/Scene forward"       forward-spl-act-scene t)
      ("Act/Scene backward"      backward-spl-act-scene t))
     ("Indent" nil
      ("Buffer"             spl-indent-buffer t)
      ("Region"             spl-indent-region (mark t))
      ("Line"               spl-indent-line t))
     ("Fill" nil
      ("Paragraph"          spl-fill-paragraph t))
     ("Print" nil
      ("Buffer"             ps-print-buffer-with-faces t)
      ("Region"             ps-print-region-with-faces (mark t)))
     ("-----")
     ("Next Spl Buffer"      spl-next-buffer t)
     ("Previous Spl Buffer"  spl-previous-buffer t)
     ))
  "Contents of the Spl menu.")

(spl-make-menu spl-menu)

;;
;; Syntax Table Definitions
;;

(defvar spl-mode-syntax-table
  (make-syntax-table)
  "Syntax table used in the Spl modes.")

(modify-syntax-entry ?_ "w" spl-mode-syntax-table)
(modify-syntax-entry ?< "w" spl-mode-syntax-table)
(modify-syntax-entry ?> "w" spl-mode-syntax-table)
(modify-syntax-entry ?\" "w" spl-mode-syntax-table)
(modify-syntax-entry ?%  "<" spl-mode-syntax-table)
(modify-syntax-entry ?\n ">" spl-mode-syntax-table)
(modify-syntax-entry ?/ ". 14" spl-mode-syntax-table)
(modify-syntax-entry ?* ". 23b" spl-mode-syntax-table)

;; add the accented characters:
(defun spl-modify-syntax-entries (start end s)
  (let ((i start))
    (while (<= i end)
      (modify-syntax-entry i s spl-mode-syntax-table)
      (setq i (1+ i)))))
(spl-modify-syntax-entries 192 214 "w")
(spl-modify-syntax-entries 216 222 "w")
(spl-modify-syntax-entries 223 246 "w")
(spl-modify-syntax-entries 248 255 "w")

;;
;; Major Mode Definitions
;;

(defun spl-mode-variables ()
  (set (make-local-variable 'paragraph-start)
       "\f\\|$")
  (set (make-local-variable 'paragraph-separate)
       paragraph-start)
  (set (make-local-variable 'paragraph-ignore-fill-prefix)
       t)
  (set (make-local-variable 'fill-paragraph-function)
       'spl-fill-paragraph)
  (set (make-local-variable 'indent-line-function)
       'spl-indent-line)
  (set (make-local-variable 'comment-start)
       "%")
  (set (make-local-variable 'comment-end)
       "")
  (set (make-local-variable 'comment-start-skip)
       "/\\*+ *\\|%+ *")
  (set (make-local-variable 'parse-sexp-ignore-comments)
       t)
  (set (make-local-variable 'words-include-escapes)
       t))

(defun spl-mode ()
  "Major mode for editing Spl code.

Commands:
\\{spl-mode-map}
Entry to this mode calls the value of `spl-mode-hook'
if that value is non-nil."
  (interactive)
  (kill-all-local-variables)
  (setq major-mode 'spl-mode)
  (setq mode-name "Spl")
  (auto-fill-mode)
  (use-local-map spl-mode-map)
  (set-syntax-table spl-mode-syntax-table)
  (spl-mode-variables)
  (spl-set-lucid-menu)
  (spl-set-font-lock-defaults)
  (font-lock-mode 1)
  (run-hooks 'spl-mode-hook))


(defun spl-set-lucid-menu ()
  ;; Add the Spl menu to the menu bar.
  (if spl-lucid-emacs
      (progn
	(setq mode-popup-menu (cons "Spl Mode Menu" (cdr spl-menubar)))
	(if (and (featurep 'menubar) current-menubar)
	    (progn
	      (set-buffer-menubar current-menubar)
	      (add-submenu nil spl-menubar))))))

;;
;; Lisp Paragraph Filling Commands
;;

(defun spl-fill-paragraph (&optional justify)
  "Like \\[fill-paragraph], but handles Spl comments.
If any of the current line is a comment, fill the comment or the
paragraph of it that point is in, preserving the comment's indentation
and initial percent signs."
  (interactive "P")

  ;; Narrow to include only the comment, and then fill the region.
  (save-restriction
    (narrow-to-region
     ;; Find the first line we should include in the region to fill.
     (save-excursion
       (while (and (zerop (forward-line -1))
		   (not (or (looking-at spl-act-scene-enter-exit-pattern)
			    (looking-at spl-character-matcher)))))
       
       ;; We may have gone to far.  Go forward again.
       (if (or (looking-at spl-act-scene-enter-exit-pattern)
	       (looking-at spl-character-matcher))
	   (forward-line 1))
       (point))
     
     ;; Find the beginning of the first line past the region to fill.
     (save-excursion
       (while (and (= (forward-line 1) 0)
		   (not (or (looking-at spl-act-scene-enter-exit-pattern)
			    (looking-at spl-character-matcher)))))
       (point)))
    (fill-paragraph justify))
  t)

;;
;; Fontification
;;

(if window-system
    (require 'font-lock))

(defconst spl-keywords
  '("Act" "Scene")
  "List of all Spl keywords with identifier syntax.")

(defconst spl-keywords-matcher-1
  (concat "\\(" (mapconcat 'identity spl-keywords "\\|") "\\)\\>")
  "Regular expression matching any keyword at the beginning of a line.")

(defconst spl-roman-thousands-pattern
  "M+")

(defconst spl-roman-hundreds-pattern
  "\\(C\\(D\\|M\\)\\|D\\(C\\|CC\\|CCC\\)?\\|\\(C\\|CC\\|CCC\\)\\)")

(defconst spl-roman-tens-pattern
  "\\(X\\(L\\|C\\)\\|L\\(X\\|XX\\|XXX\\)?\\|\\(X\\|XX\\|XXX\\)\\)")

(defconst spl-roman-ones-pattern
  "\\(I\\(V\\|X\\)\\|V\\(I\\|II\\|III\\)?\\|\\(I\\|II\\|III\\)\\)")




(defconst spl-scene-matcher
  (concat "\\(Scene\\|Act\\|scene\\|act\\)\\W*\\(\\(" spl-roman-ones-pattern "\\)\\|"
	  "\\(" spl-roman-tens-pattern "\\(" spl-roman-ones-pattern "\\)?" "\\)\\|"
	  "\\(" spl-roman-hundreds-pattern "\\(" spl-roman-tens-pattern "\\)?" "\\(" spl-roman-ones-pattern "\\)?" "\\)\\|"
	  "\\(" spl-roman-thousands-pattern "\\(" spl-roman-hundreds-pattern "\\)?" "\\(" spl-roman-tens-pattern "\\)?" "\\(" spl-roman-ones-pattern "\\)?" "\\)\\)\\b")

  "Regular expression matching roman numerals.")

(defconst spl-enter-exit-matcher
  "\\[\\(Enter\\|Exit\\|Exeunt\\)\\([^]]*\\)\\]"
  "Regular expression matching Enter, Exit, Exeunt.")

(defconst spl-character-matcher
  (spl-make-keywords-for-match
   '("Achilles" "Adonis" "Adriana" "Aegeon" "Aemilia" "Agamemnon" "Agrippa"
     "Ajax" "Alonso" "Andromache" "Angelo" "Antiochus" "Antonio" "Arthur"
     "Autolycus" "Balthazar" "Banquo" "Beatrice" "Benedick" "Benvolio"
     "Bianca" "Brabantio" "Brutus" "Capulet" "Cassandra" "Cassius"
     "Christopher Sly" "Cicero" "Claudio" "Claudius" "Cleopatra" "Cordelia"
     "Cornelius" "Cressida" "Cymberline" "Demetrius" "Desdemona" "Dionyza"
     "Doctor Caius" "Dogberry" "Don John" "Don Pedro" "Donalbain" "Dorcas"
     "Duncan" "Egeus" "Emilia" "Escalus" "Falstaff" "Fenton" "Ferdinand"
     "Ford" "Fortinbras" "Francisca" "Friar John" "Friar Laurence"
     "Gertrude" "Goneril" "Hamlet" "Hecate" "Hector" "Helen" "Helena"
     "Hermia" "Hermonie" "Hippolyta" "Horatio" "Imogen" "Isabella" 
     "John of Gaunt" "John of Lancaster" "Julia" "Juliet" "Julius Caesar"
     "King Henry" "King John" "King Lear" "King Richard" "Lady Capulet"
     "Lady Macbeth" "Lady Macduff" "Lady Montague" "Lennox" "Leonato" "Luciana"
     "Lucio" "Lychorida" "Lysander" "Macbeth" "Macduff" "Malcolm" "Mariana"
     "Mark Antony" "Mercutio" "Miranda" "Mistress Ford" "Mistress Overdone"
     "Mistress Page" "Montague" "Mopsa" "Oberon" "Octavia"
     "Octavius Caesar" "Olivia" "Ophelia" "Orlando" "Orsino" "Othello" "Page"
     "Pantino" "Paris" "Pericles" "Pinch" "Polonius" "Pompeius" "Portia"
     "Priam" "Prince Henry" "Prospero" "Proteus" "Publius" "Puck"
     "Queen Elinor" "Regan" "Robin" "Romeo" "Rosalind" "Sebastian" "Shallow"
     "Shylock" "Slender" "Solinus" "Stephano" "Thaisa"
     "The Abbot of Westminster" "The Apothecary" "The Archbishop of Canterbury"
     "The Duke of Milan" "The Duke of Venice" "The Ghost" "Theseus" "Thurio"
     "Timon" "Titania" "Titus" "Troilus" "Tybalt" "Ulysses" "Valentine" "Venus"
     "Vincentio" "Viola"))

  "Regular expression matching characters.")

(defconst spl-font-lock-keywords-1
  (list spl-keywords-matcher-1)
  "Subdued level highlighting for Spl mode.")

(defconst spl-font-lock-keywords spl-font-lock-keywords-1
  "Default expressions to highlight in Spl mode.")

(defconst spl-font-lock-keywords-2
  spl-font-lock-keywords-1
  "Medium level highlighting for Spl mode.")

(defconst spl-font-lock-keywords-3
  (append (list (cons spl-enter-exit-matcher
		      font-lock-variable-name-face)
		(cons spl-scene-matcher
		      font-lock-type-face)
		(cons spl-character-matcher
		      font-lock-function-name-face)
		)
	  spl-font-lock-keywords-2)
  "Gaudy level highlighting for Spl mode.")

(defun spl-set-font-lock-defaults ()
  (set (make-local-variable 'font-lock-defaults)
       '((spl-font-lock-keywords
	  spl-font-lock-keywords-1
	  spl-font-lock-keywords-2
	  spl-font-lock-keywords-3)
	 nil nil ((?& . "/")) beginning-of-line)))



;;
;; Buffers
;;

(defun spl-previous-buffer ()
  "Switch to the next buffer in the buffer list that runs in an Spl mode."
  (interactive)
  (bury-buffer)
  (spl-walk-through-buffers (buffer-list)))

(defun spl-next-buffer ()
  "Switch to the last buffer in the buffer list that runs in an Spl mode."
  (interactive)
  (spl-walk-through-buffers (reverse (buffer-list))))

(defun spl-walk-through-buffers (buffers)
  (let ((none-found t) (cur (current-buffer)))
    (while (and buffers none-found)
      (set-buffer (car buffers))
      (if (or (equal mode-name "Spl")
	      (equal mode-name "Spl-Machine"))
	  (progn
	    (switch-to-buffer (car buffers))
	    (setq none-found nil))
	(setq buffers (cdr buffers))))
    (if none-found
	(progn
	  (set-buffer cur)
	  (error "There is no buffer in an Spl mode")))))

(provide 'spl)

;;; Local Variables: ***
;;; mode: emacs-lisp ***
;;; byte-compile-dynamic-docstrings: nil ***
;;; byte-compile-compatibility: t ***
;;; End: ***
