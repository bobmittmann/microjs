include ../mk/config.mk

PATH := $(PATH);C:\Program Files\MiKTeX 2.9\miktex\bin\x64
export PATH

TEXFILES = microjs-user.tex microjs-internals.tex

T2TFILES = $(wildcard *.t2t)

HTMLFILES = $(notdir $(T2TFILES:.t2t=.html))
LOGFILES = $(notdir $(TEXFILES:.tex=.log))
PDFFILES = $(notdir $(TEXFILES:.tex=.pdf))
LOTFILES = $(notdir $(TEXFILES:.tex=.lot))
TOCFILES = $(notdir $(TEXFILES:.tex=.toc))
AUXFILES = $(notdir $(TEXFILES:.tex=.aux))
LOFFILES = $(notdir $(TEXFILES:.tex=.lof))
TMPFILES = $(LOGFILES) $(LOTFILES) $(TOCFILES) $(LOFFILES) $(AUXFILES)

.SUFFIXES:

%.html : %.t2t
	@$(TXT2TAGS) -t html --style=$(STYLE) --css-sugar --css-inside --toc -o $@ $<

%.html:%.tex
	@$(PANDOC) -f lstex -t html5 -N --toc --listings --highlight-style tango --css pandoc.css -o $@ $<

%.pdf:%.tex
	miktex-pdflatex --c-style-errors $<

all: $(PDFFILES)
# $(HTMLFILES)

clean: 
	@$(RMALL) $(HTMLFILES) $(PDFFILES) $(TMPFILES) 

.PHONY: all clean

