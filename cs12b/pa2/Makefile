#----------------------------------------------------------------
# Search.java Makefile
# Aryan Samuel
# arsamuel
# CMPS 12B
# 04/12/16
# Programming Assignment 2
# Makefile for the Search.java program.
#----------------------------------------------------------------

JAVASRC     = Search.java
SOURCES     = README Makefile $(JAVASRC)
MAINCLASS   = Search
CLASSES     = Search.class
JARFILE     = Search
SUBMIT      = submit cmps012b-pt.s16 pa2

all: $(JARFILE)

$(JARFILE): $(CLASSES)
	echo Main-class: $(MAINCLASS) > Manifest
	jar cvfm $(JARFILE) Manifest $(CLASSES)
	rm Manifest
	chmod +x $(JARFILE)

$(CLASSES): $(JAVASRC)
	javac -Xlint $(JAVASRC)

clean:
	rm $(CLASSES) $(JARFILE)

submit: $(SOURCES)
	$(SUBMIT) $(SOURCES)

check:
	ls  /afs/cats.ucsc.edu/class/cmps012b-pt.s16/pa2/arsamuel
