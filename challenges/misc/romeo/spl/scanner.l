
%{
#include <stdio.h>

#include "telma.h"
#include "grammar.tab.h"
#include "strutils.h"

%}

%option yylineno
%option case-insensitive


ROMAN_THOUSANDS m+
ROMAN_HUNDREDS  (c(d|m)|dc{0,3}|c{1,3})
ROMAN_TENS      (x(l|c)|lx{0,3}|x{1,3})
ROMAN_ONES      (i(v|x)|vi{0,3}|i{1,3})
ROMAN_NUMBER    {ROMAN_ONES}|{ROMAN_TENS}{ROMAN_ONES}?|{ROMAN_HUNDREDS}{ROMAN_TENS}?{ROMAN_ONES}?|{ROMAN_THOUSANDS}{ROMAN_HUNDREDS}?{ROMAN_TENS}?{ROMAN_ONES}?

%%

 /* rules from file include/article.wordlist */
"a" {
   yylval.str = newstr(yytext); return ARTICLE;
}
"an" {
   yylval.str = newstr(yytext); return ARTICLE;
}
"the" {
   yylval.str = newstr(yytext); return ARTICLE;
}

 /* rules from file include/be.wordlist */
"am" {
   yylval.str = newstr(yytext); return BE;
}
"are" {
   yylval.str = newstr(yytext); return BE;
}
"art" {
   yylval.str = newstr(yytext); return BE;
}
"be" {
   yylval.str = newstr(yytext); return BE;
}
"is" {
   yylval.str = newstr(yytext); return BE;
}

 /* rules from file include/character.wordlist */
"Achilles" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Adonis" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Adriana" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Aegeon" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Aemilia" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Agamemnon" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Agrippa" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Ajax" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Alonso" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Andromache" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Angelo" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Antiochus" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Antonio" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Arthur" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Autolycus" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Balthazar" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Banquo" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Beatrice" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Benedick" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Benvolio" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Bianca" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Brabantio" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Brutus" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Capulet" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Cassandra" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Cassius" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Christopher"[[:space:]]+"Sly" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Cicero" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Claudio" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Claudius" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Cleopatra" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Cordelia" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Cornelius" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Cressida" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Cymberline" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Demetrius" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Desdemona" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Dionyza" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Doctor"[[:space:]]+"Caius" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Dogberry" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Don"[[:space:]]+"John" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Don"[[:space:]]+"Pedro" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Donalbain" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Dorcas" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Duncan" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Egeus" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Emilia" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Escalus" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Falstaff" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Fenton" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Ferdinand" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Ford" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Fortinbras" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Francisca" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Friar"[[:space:]]+"John" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Friar"[[:space:]]+"Laurence" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Gertrude" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Goneril" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Hamlet" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Hecate" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Hector" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Helen" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Helena" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Hermia" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Hermonie" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Hippolyta" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Horatio" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Imogen" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Isabella" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"John"[[:space:]]+"of"[[:space:]]+"Gaunt" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"John"[[:space:]]+"of"[[:space:]]+"Lancaster" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Julia" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Juliet" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Julius"[[:space:]]+"Caesar" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"King"[[:space:]]+"Henry" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"King"[[:space:]]+"John" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"King"[[:space:]]+"Lear" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"King"[[:space:]]+"Richard" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Lady"[[:space:]]+"Capulet" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Lady"[[:space:]]+"Macbeth" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Lady"[[:space:]]+"Macduff" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Lady"[[:space:]]+"Montague" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Lennox" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Leonato" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Luciana" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Lucio" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Lychorida" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Lysander" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Macbeth" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Macduff" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Malcolm" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Mariana" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Mark"[[:space:]]+"Antony" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Mercutio" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Miranda" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Mistress"[[:space:]]+"Ford" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Mistress"[[:space:]]+"Overdone" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Mistress"[[:space:]]+"Page" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Montague" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Mopsa" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Oberon" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Octavia" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Octavius"[[:space:]]+"Caesar" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Olivia" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Ophelia" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Orlando" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Orsino" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Othello" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Page" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Pantino" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Paris" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Pericles" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Pinch" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Polonius" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Pompeius" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Portia" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Priam" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Prince"[[:space:]]+"Henry" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Prospero" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Proteus" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Publius" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Puck" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Queen"[[:space:]]+"Elinor" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Regan" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Robin" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Romeo" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Rosalind" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Sebastian" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Shallow" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Shylock" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Slender" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Solinus" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Stephano" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Thaisa" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"The"[[:space:]]+"Abbot"[[:space:]]+"of"[[:space:]]+"Westminster" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"The"[[:space:]]+"Apothecary" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"The"[[:space:]]+"Archbishop"[[:space:]]+"of"[[:space:]]+"Canterbury" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"The"[[:space:]]+"Duke"[[:space:]]+"of"[[:space:]]+"Milan" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"The"[[:space:]]+"Duke"[[:space:]]+"of"[[:space:]]+"Venice" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"The"[[:space:]]+"Ghost" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Theseus" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Thurio" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Timon" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Titania" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Titus" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Troilus" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Tybalt" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Ulysses" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Valentine" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Venus" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Vincentio" {
   yylval.str = newstr(yytext); return CHARACTER;
}
"Viola" {
   yylval.str = newstr(yytext); return CHARACTER;
}

 /* rules from file include/first_person.wordlist */
"I" {
   yylval.str = newstr(yytext); return FIRST_PERSON;
}
"me" {
   yylval.str = newstr(yytext); return FIRST_PERSON;
}

 /* rules from file include/first_person_possessive.wordlist */
"mine" {
   yylval.str = newstr(yytext); return FIRST_PERSON_POSSESSIVE;
}
"my" {
   yylval.str = newstr(yytext); return FIRST_PERSON_POSSESSIVE;
}

 /* rules from file include/first_person_reflexive.wordlist */
"myself" {
   yylval.str = newstr(yytext); return FIRST_PERSON_REFLEXIVE;
}

 /* rules from file include/negative_adjective.wordlist */
"bad" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"cowardly" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"cursed" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"damned" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"dirty" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"disgusting" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"distasteful" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"dusty" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"evil" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"fat" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"fat-kidneyed" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"fatherless" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"foul" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"hairy" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"half-witted" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"horrible" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"horrid" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"infected" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"lying" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"miserable" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"misused" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"oozing" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"rotten" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"rotten" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"smelly" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"snotty" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"sorry" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"stinking" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"stuffed" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"stupid" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"vile" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"villainous" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}
"worried" {
   yylval.str = newstr(yytext); return NEGATIVE_ADJECTIVE;
}

 /* rules from file include/negative_comparative.wordlist */
"punier" {
   yylval.str = newstr(yytext); return NEGATIVE_COMPARATIVE;
}
"smaller" {
   yylval.str = newstr(yytext); return NEGATIVE_COMPARATIVE;
}
"worse" {
   yylval.str = newstr(yytext); return NEGATIVE_COMPARATIVE;
}

 /* rules from file include/negative_noun.wordlist */
"Hell" {
   yylval.str = newstr(yytext); return NEGATIVE_NOUN;
}
"Microsoft" {
   yylval.str = newstr(yytext); return NEGATIVE_NOUN;
}
"bastard" {
   yylval.str = newstr(yytext); return NEGATIVE_NOUN;
}
"beggar" {
   yylval.str = newstr(yytext); return NEGATIVE_NOUN;
}
"blister" {
   yylval.str = newstr(yytext); return NEGATIVE_NOUN;
}
"codpiece" {
   yylval.str = newstr(yytext); return NEGATIVE_NOUN;
}
"coward" {
   yylval.str = newstr(yytext); return NEGATIVE_NOUN;
}
"curse" {
   yylval.str = newstr(yytext); return NEGATIVE_NOUN;
}
"death" {
   yylval.str = newstr(yytext); return NEGATIVE_NOUN;
}
"devil" {
   yylval.str = newstr(yytext); return NEGATIVE_NOUN;
}
"draught" {
   yylval.str = newstr(yytext); return NEGATIVE_NOUN;
}
"famine" {
   yylval.str = newstr(yytext); return NEGATIVE_NOUN;
}
"flirt-gill" {
   yylval.str = newstr(yytext); return NEGATIVE_NOUN;
}
"goat" {
   yylval.str = newstr(yytext); return NEGATIVE_NOUN;
}
"hate" {
   yylval.str = newstr(yytext); return NEGATIVE_NOUN;
}
"hog" {
   yylval.str = newstr(yytext); return NEGATIVE_NOUN;
}
"hound" {
   yylval.str = newstr(yytext); return NEGATIVE_NOUN;
}
"leech" {
   yylval.str = newstr(yytext); return NEGATIVE_NOUN;
}
"lie" {
   yylval.str = newstr(yytext); return NEGATIVE_NOUN;
}
"pig" {
   yylval.str = newstr(yytext); return NEGATIVE_NOUN;
}
"plague" {
   yylval.str = newstr(yytext); return NEGATIVE_NOUN;
}
"starvation" {
   yylval.str = newstr(yytext); return NEGATIVE_NOUN;
}
"toad" {
   yylval.str = newstr(yytext); return NEGATIVE_NOUN;
}
"war" {
   yylval.str = newstr(yytext); return NEGATIVE_NOUN;
}
"wolf" {
   yylval.str = newstr(yytext); return NEGATIVE_NOUN;
}

 /* rules from file include/neutral_adjective.wordlist */
"big" {
   yylval.str = newstr(yytext); return NEUTRAL_ADJECTIVE;
}
"black" {
   yylval.str = newstr(yytext); return NEUTRAL_ADJECTIVE;
}
"blue" {
   yylval.str = newstr(yytext); return NEUTRAL_ADJECTIVE;
}
"bluest" {
   yylval.str = newstr(yytext); return NEUTRAL_ADJECTIVE;
}
"bottomless" {
   yylval.str = newstr(yytext); return NEUTRAL_ADJECTIVE;
}
"furry" {
   yylval.str = newstr(yytext); return NEUTRAL_ADJECTIVE;
}
"green" {
   yylval.str = newstr(yytext); return NEUTRAL_ADJECTIVE;
}
"hard" {
   yylval.str = newstr(yytext); return NEUTRAL_ADJECTIVE;
}
"huge" {
   yylval.str = newstr(yytext); return NEUTRAL_ADJECTIVE;
}
"large" {
   yylval.str = newstr(yytext); return NEUTRAL_ADJECTIVE;
}
"little" {
   yylval.str = newstr(yytext); return NEUTRAL_ADJECTIVE;
}
"normal" {
   yylval.str = newstr(yytext); return NEUTRAL_ADJECTIVE;
}
"old" {
   yylval.str = newstr(yytext); return NEUTRAL_ADJECTIVE;
}
"purple" {
   yylval.str = newstr(yytext); return NEUTRAL_ADJECTIVE;
}
"red" {
   yylval.str = newstr(yytext); return NEUTRAL_ADJECTIVE;
}
"rural" {
   yylval.str = newstr(yytext); return NEUTRAL_ADJECTIVE;
}
"small" {
   yylval.str = newstr(yytext); return NEUTRAL_ADJECTIVE;
}
"tiny" {
   yylval.str = newstr(yytext); return NEUTRAL_ADJECTIVE;
}
"white" {
   yylval.str = newstr(yytext); return NEUTRAL_ADJECTIVE;
}
"yellow" {
   yylval.str = newstr(yytext); return NEUTRAL_ADJECTIVE;
}

 /* rules from file include/neutral_noun.wordlist */
"animal" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"aunt" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"brother" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"cat" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"chihuahua" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"cousin" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"cow" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"daughter" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"door" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"face" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"father" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"fellow" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"granddaughter" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"grandfather" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"grandmother" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"grandson" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"hair" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"hamster" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"horse" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"lamp" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"lantern" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"mistletoe" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"moon" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"morning" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"mother" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"nephew" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"niece" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"nose" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"purse" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"road" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"roman" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"sister" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"sky" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"son" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"squirrel" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"stone"[[:space:]]+"wall" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"thing" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"town" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"tree" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"uncle" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}
"wind" {
   yylval.str = newstr(yytext); return NEUTRAL_NOUN;
}

 /* rules from file include/nothing.wordlist */
"nothing" {
   yylval.str = newstr(yytext); return NOTHING;
}
"zero" {
   yylval.str = newstr(yytext); return NOTHING;
}

 /* rules from file include/positive_adjective.wordlist */
"amazing" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"beautiful" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"blossoming" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"bold" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"brave" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"charming" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"clearest" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"cunning" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"cute" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"delicious" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"embroidered" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"fair" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"fine" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"gentle" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"golden" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"good" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"handsome" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"happy" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"healthy" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"honest" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"lovely" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"loving" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"mighty" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"noble" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"peaceful" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"pretty" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"prompt" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"proud" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"reddest" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"rich" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"smooth" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"sunny" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"sweet" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"sweetest" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"trustworthy" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}
"warm" {
   yylval.str = newstr(yytext); return POSITIVE_ADJECTIVE;
}

 /* rules from file include/positive_comparative.wordlist */
"better" {
   yylval.str = newstr(yytext); return POSITIVE_COMPARATIVE;
}
"bigger" {
   yylval.str = newstr(yytext); return POSITIVE_COMPARATIVE;
}
"fresher" {
   yylval.str = newstr(yytext); return POSITIVE_COMPARATIVE;
}
"friendlier" {
   yylval.str = newstr(yytext); return POSITIVE_COMPARATIVE;
}
"nicer" {
   yylval.str = newstr(yytext); return POSITIVE_COMPARATIVE;
}
"jollier" {
   yylval.str = newstr(yytext); return POSITIVE_COMPARATIVE;
}

 /* rules from file include/positive_noun.wordlist */
"Heaven" {
   yylval.str = newstr(yytext); return POSITIVE_NOUN;
}
"King" {
   yylval.str = newstr(yytext); return POSITIVE_NOUN;
}
"Lord" {
   yylval.str = newstr(yytext); return POSITIVE_NOUN;
}
"angel" {
   yylval.str = newstr(yytext); return POSITIVE_NOUN;
}
"flower" {
   yylval.str = newstr(yytext); return POSITIVE_NOUN;
}
"happiness" {
   yylval.str = newstr(yytext); return POSITIVE_NOUN;
}
"joy" {
   yylval.str = newstr(yytext); return POSITIVE_NOUN;
}
"plum" {
   yylval.str = newstr(yytext); return POSITIVE_NOUN;
}
"summer's"[[:space:]]+"day" {
   yylval.str = newstr(yytext); return POSITIVE_NOUN;
}
"hero" {
   yylval.str = newstr(yytext); return POSITIVE_NOUN;
}
"rose" {
   yylval.str = newstr(yytext); return POSITIVE_NOUN;
}
"kingdom" {
   yylval.str = newstr(yytext); return POSITIVE_NOUN;
}
"pony" {
   yylval.str = newstr(yytext); return POSITIVE_NOUN;
}

 /* rules from file include/second_person.wordlist */
"thee" {
   yylval.str = newstr(yytext); return SECOND_PERSON;
}
"thou" {
   yylval.str = newstr(yytext); return SECOND_PERSON;
}
"you" {
   yylval.str = newstr(yytext); return SECOND_PERSON;
}

 /* rules from file include/second_person_possessive.wordlist */
"thine" {
   yylval.str = newstr(yytext); return SECOND_PERSON_POSSESSIVE;
}
"thy" {
   yylval.str = newstr(yytext); return SECOND_PERSON_POSSESSIVE;
}
"your" {
   yylval.str = newstr(yytext); return SECOND_PERSON_POSSESSIVE;
}

 /* rules from file include/second_person_reflexive.wordlist */
"thyself" {
   yylval.str = newstr(yytext); return SECOND_PERSON_REFLEXIVE;
}
"yourself" {
   yylval.str = newstr(yytext); return SECOND_PERSON_REFLEXIVE;
}

 /* rules from file include/third_person_possessive.wordlist */
"his" {
   yylval.str = newstr(yytext); return THIRD_PERSON_POSSESSIVE;
}
"her" {
   yylval.str = newstr(yytext); return THIRD_PERSON_POSSESSIVE;
}
"its" {
   yylval.str = newstr(yytext); return THIRD_PERSON_POSSESSIVE;
}
"their" {
   yylval.str = newstr(yytext); return THIRD_PERSON_POSSESSIVE;
}

 /* single word rules */
"and" {
   yylval.str = newstr(yytext); return AND;
}
"as" {
   yylval.str = newstr(yytext); return AS;
}
"enter" {
   yylval.str = newstr(yytext); return ENTER;
}
"exeunt" {
   yylval.str = newstr(yytext); return EXEUNT;
}
"exit" {
   yylval.str = newstr(yytext); return EXIT;
}
"heart" {
   yylval.str = newstr(yytext); return HEART;
}
"if"[[:space:]]+"not" {
   yylval.str = newstr(yytext); return IF_NOT;
}
"if"[[:space:]]+"so" {
   yylval.str = newstr(yytext); return IF_SO;
}
"less" {
   yylval.str = newstr(yytext); return LESS;
}
"let"[[:space:]]+"us" {
   yylval.str = newstr(yytext); return LET_US;
}
"listen"[[:space:]]+"to" {
   yylval.str = newstr(yytext); return LISTEN_TO;
}
"mind" {
   yylval.str = newstr(yytext); return MIND;
}
"more" {
   yylval.str = newstr(yytext); return MORE;
}
"not" {
   yylval.str = newstr(yytext); return NOT;
}
"open" {
   yylval.str = newstr(yytext); return OPEN;
}
"proceed"[[:space:]]+"to" {
   yylval.str = newstr(yytext); return PROCEED_TO;
}
"recall" {
   yylval.str = newstr(yytext); return RECALL;
}
"remember" {
   yylval.str = newstr(yytext); return REMEMBER;
}
"return"[[:space:]]+"to" {
   yylval.str = newstr(yytext); return RETURN_TO;
}
"speak" {
   yylval.str = newstr(yytext); return SPEAK;
}
"than" {
   yylval.str = newstr(yytext); return THAN;
}
"the"[[:space:]]+"cube"[[:space:]]+"of" {
   yylval.str = newstr(yytext); return THE_CUBE_OF;
}
"the"[[:space:]]+"difference"[[:space:]]+"between" {
   yylval.str = newstr(yytext); return THE_DIFFERENCE_BETWEEN;
}
"the"[[:space:]]+"factorial"[[:space:]]+"of" {
   yylval.str = newstr(yytext); return THE_FACTORIAL_OF;
}
"the"[[:space:]]+"product"[[:space:]]+"of" {
   yylval.str = newstr(yytext); return THE_PRODUCT_OF;
}
"the"[[:space:]]+"quotient"[[:space:]]+"between" {
   yylval.str = newstr(yytext); return THE_QUOTIENT_BETWEEN;
}
"the"[[:space:]]+"remainder"[[:space:]]+"of"[[:space:]]+"the"[[:space:]]+"quotient"[[:space:]]+"between" {
   yylval.str = newstr(yytext); return THE_REMAINDER_OF_THE_QUOTIENT_BETWEEN;
}
"the"[[:space:]]+"square"[[:space:]]+"of" {
   yylval.str = newstr(yytext); return THE_SQUARE_OF;
}
"the"[[:space:]]+"square"[[:space:]]+"root"[[:space:]]+"of" {
   yylval.str = newstr(yytext); return THE_SQUARE_ROOT_OF;
}
"the"[[:space:]]+"sum"[[:space:]]+"of" {
   yylval.str = newstr(yytext); return THE_SUM_OF;
}
"twice" {
   yylval.str = newstr(yytext); return TWICE;
}
"we"[[:space:]]+"must" {
   yylval.str = newstr(yytext); return WE_MUST;
}
"we"[[:space:]]+"shall" {
   yylval.str = newstr(yytext); return WE_SHALL;
}

 /* rules for terminals from file include/terminals.metaflex */
:		{ yylval.str = newstr(yytext); return COLON; }
,		{ yylval.str = newstr(yytext); return COMMA; }
!		{ yylval.str = newstr(yytext); return EXCLAMATION_MARK; }
\[		{ yylval.str = newstr(yytext); return LEFT_BRACKET; }
\.		{ yylval.str = newstr(yytext); return PERIOD; }
\?		{ yylval.str = newstr(yytext); return QUESTION_MARK; }
\]		{ yylval.str = newstr(yytext); return RIGHT_BRACKET; }

{ROMAN_NUMBER}				{ yylval.str = newstr(yytext); return ROMAN_NUMBER; }
"act"[[:space:]]+{ROMAN_NUMBER}		{ yylval.str = newstr(yytext); return ACT_ROMAN; }
"scene"[[:space:]]+{ROMAN_NUMBER}	{ yylval.str = newstr(yytext); return SCENE_ROMAN; }

[[:alnum:]]+	{ yylval.str = newstr(yytext); return NONMATCH; }
[[:space:]]+	/* Eat space (like Mantrid drones) */
.		{ yylval.str = newstr(yytext); return NONMATCH; }

%%

