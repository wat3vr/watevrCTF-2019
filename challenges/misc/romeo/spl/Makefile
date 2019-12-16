########################################################################
#
# SPL, the Shakespeare Programming Language
#
# Copyright (C) 2001 Karl Hasselström and Jon Åslund
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or (at
# your option) any later version.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307,
# USA.
#
########################################################################

NAME     = spl
VERSION  = 1.2.1
DISTNAME = $(NAME)-$(VERSION)

# compiler commands 
AR      = ar
CC      = gcc
LEX     = flex
RANLIB  = ranlib
TAR     = tar
YACC    = bison

INCLUDEPATH = include
EDITORPATH  = editor
EXAMPLEPATH = examples

# source / outputs
MAKESCANNERINCLUDE = $(wildcard $(INCLUDEPATH)/*.{wordlist,metaflex})

# compiler flags
YACCFLAGS = --verbose
CCFLAGS   = -O2 -Wall
LEXFLAGS  = -Cem

.PHONY: all clean examples install libspl tar
all: install examples

examples: install
	$(MAKE) -C $(EXAMPLEPATH) all

grammar.tab.h grammar.tab.c: grammar.y
	$(YACC) $(YACCFLAGS) -d $<

grammar.tab.o: grammar.tab.c grammar.tab.h telma.h
	$(CC) $(CCFLAGS) -c $<

install: spl2c libspl.a spl.h
	mkdir -p spl/bin spl/include spl/lib
	cp -pf spl2c spl/bin
	cp -pf spl.h spl/include
	cp -pf libspl.a spl/lib

libspl.a: libspl.o strutils.o
	$(AR) rc $@ $^
	$(RANLIB) $@

libspl.o: libspl.c spl.h
	$(CC) $(CCFLAGS) -c $<

makescanner: makescanner.o
	$(CC) $< $(CCFLAGS) -o $@

makescanner.o: makescanner.c
	$(CC) $(CCFLAGS) -c $<

scanner.c: scanner.l
	$(LEX) $(LEXFLAGS) -t $< > $@

scanner.l: makescanner $(MAKESCANNERINCLUDE)
	./$< $(INCLUDEPATH) > $@

scanner.o: scanner.c grammar.tab.h telma.h
	$(CC) $(CCFLAGS) -c $<

spl2c: grammar.tab.o scanner.o strutils.o
	$(CC) $^ $(CCFLAGS) -lfl -o $@

strutils.o: strutils.c strutils.h
	$(CC) $(CCFLAGS) -c $<

tar: clean
	mkdir -p $(DISTNAME)
	cp `find . -type f -maxdepth 1` $(DISTNAME)
	cp -r $(INCLUDEPATH) $(DISTNAME)
	cp -r $(EDITORPATH) $(DISTNAME)
	cp -r $(EXAMPLEPATH) $(DISTNAME)
	$(TAR) zcvf $(DISTNAME).tar.gz $(DISTNAME)

# clean-up funtion
clean:
	rm -f *~ $(EDITORPATH)/*~ $(INCLUDEPATH)/*~ *.l *.o *.a core grammar.output grammar.tab.h grammar.tab.c scanner.c makescanner spl2c *.tar.gz
	rm -rf spl $(DISTNAME)
	$(MAKE) -C $(EXAMPLEPATH) clean
