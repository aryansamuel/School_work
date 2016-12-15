#------------------------------------------------------------------------------
# List.java Makefile
# Aryan Samuel
# arsamuel
# CMPS 12M
# 05/20/16
# Lab 6
# Makefile for List ADT
#------------------------------------------------------------------------------

# Variables
JARFILE    = ListClient
MAINCLASS  = ListClient
SOURCES    = List.java ListInterface.java ListClient.java\
             ListIndexOutOfBoundsException.java
CLASSES    = List.class ListInterface.class ListClient.class List\$$Node.class\
             ListIndexOutOfBoundsException.class

# Build Targets
all: $(JARFILE)

$(JARFILE): $(CLASSES)
	echo Main-class: $(MAINCLASS) > Manifest
	jar cvfm $(JARFILE) Manifest $(CLASSES)
	rm Manifest
	chmod +x $(JARFILE)

$(CLASSES): $(SOURCES)
	javac -Xlint $(SOURCES)  

clean:
	rm -f $(CLASSES) $(JARFILE)
	
submit:
	submit  cmps012b-pt.s16 lab6 List.java README Makefile ListTest.java ListInterface.java ListIndexOutOfBoundsException.java ListClient.java
	
subchk:
	ls  /afs/cats.ucsc.edu/class/cmps012b-pt.s16/lab6/arsamuel
	
	