#
# Copyright(C) 2012 Robinson Mittmann. All Rights Reserved.
# 
# This file is part of the YARD-ICE.
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 3.0 of the License, or (at your option) any later version.
# 
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
# 
# You can receive a copy of the GNU Lesser General Public License from 
# http://www.gnu.org/

#
# File:   Makefile
# Author: Robinson Mittmann <bobmittmann@gmail.com>
# 

ELL = ../../ell/src/ell

all: ll ll2

clean: ll-clean ll2-clean

ll: microjs_ll.c microjs_ll.h

ll2: microjs2_ll.c microjs2_ll.h

ll-clean: 
	rm microjs_ll.c microjs_ll.h

ll2-clean: 
	rm microjs2_ll.c microjs2_ll.h

microjs_ll.h: microjs.gr
	$(ELL) -e -d -h $<

microjs_ll.c: microjs.gr
	$(ELL) -e -d -c $<
	
microjs2_ll.h: microjs2.gr
	$(ELL) -e -a -d -p microjs -o $@ -h $<

microjs2_ll.c: microjs2.gr
	$(ELL) -e -a -d -p microjs -o $@ -c $<
	
.PHONY: ll ll2 ll-clean ll2-clean

