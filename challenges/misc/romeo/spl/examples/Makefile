########################################################################
#
# SPL, the Shakespeare Programming Language
#
# Copyright (C) 2001 Karl Hasselstr�m and Jon �slund
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

SPLPATH = ../spl

# compiler commands
CC    = gcc
SPL2C = $(SPLPATH)/bin/spl2c

# compiler flags
CCFLAGS      = -O2 -Wall -Wno-unused
INCLUDEFLAGS = -I$(SPLPATH)/include
LDFLAGS      = -L$(SPLPATH)/lib -lspl
LDLIBS       = -lm

# target files
TARGETS = $(patsubst %.spl, %, $(wildcard *.spl))

.PHONY: all
all: $(TARGETS)

%: %.o 
	$(CC) $(CCFLAGS) $^ $(LDFLAGS) -o $@ $(LDLIBS)

%.c: %.spl
	$(SPL2C) < $< > $@

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDEFLAGS) -c $<

# clean-up funtion
.PHONY: clean
clean:
	rm -f *~ *.c *.o core $(TARGETS)
