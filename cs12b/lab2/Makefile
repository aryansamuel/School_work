#----------------------------------------------------------------
# FileReverse.java Makefile
# Aryan Samuel
# arsamuel
# CMPS 12M
# 04/09/16
# Lab 2
# Makefile for the FileReverse.java program.
#----------------------------------------------------------------

JAVASRC     = FileReverse.java
SOURCES     = README Makefile $(JAVASRC)
MAINCLASS   = FileReverse
CLASSES     = FileReverse.class
JARFILE     = FileReverse
SUBMIT      = submit cmps012b-pt.s16 lab2

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
	ls  /afs/cats.ucsc.edu/class/cmps012b-pt.s16/lab2/arsamuel
