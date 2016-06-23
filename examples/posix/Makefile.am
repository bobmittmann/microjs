## Process this file with automake to produce Makefile.in

AUTOMAKE_OPTIONS = subdir-objects

#AM_CPPFLAGS = -DPACKAGE_DATA_DIR=\""$(datadir)"\" 
AM_CPPFLAGS = -I$(top_srcdir)/../../include

AM_CFLAGS = -Os -Wall

bin_PROGRAMS = mjs mjs2

mjs_SOURCES = ../../src/microjs_lex.c ../../src/microjs_sym.c ../../src/microjs_dbg.c ../../src/microjs_sdt.c ../../src/microjs_vm.c ../../src/microjs_ll.c ../../src/microjs_str.c ../../src/microjs_lib.c microjs.c 

mjs2_SOURCES = ../../src/microjs2_lex.c ../../src/microjs_sym.c ../../src/microjs_dbg.c ../../src/microjs2_sdt.c ../../src/microjs2_vm.c ../../src/microjs2_ll.c ../../src/microjs_str.c ../../src/microjs_lib.c microjs.c 

#nodist_microjs_SOURCES = microjs_ll.c microjs_ll.h
#CLEANFILES = microjs_ll.c microjs_ll.h const_str.h

microjs_ll.h: microjs.gr Makefile
	../ell/ell -e -d -h $<

microjs_ll.c: microjs.gr Makefile
	../ell/ell -e -d -c $<

const_str.h: const_str.txt Makefile
	./mkstr.py -n const $< > $@
