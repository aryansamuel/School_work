#------------------------------------------------------------------------------
# Makefile
# Aryan Samuel
# arsamuel
# CMPS 101
# 10/22/16
# Programming Assignment 3
# Creates an executable jar file called Sparse.  This makefile will compile 
# all .java files in your current working directory.  
#------------------------------------------------------------------------------

MAINCLASS  = Sparse
JAVAC      = javac 
JAVASRC    = $(wildcard *.java)
SOURCES    = $(JAVASRC) Makefile README
CLASSES    = $(patsubst %.java, %.class, $(JAVASRC))
JARCLASSES = $(patsubst %.class, %*.class, $(CLASSES))
JARFILE    = $(MAINCLASS) 

all: $(JARFILE)
	
$(JARFILE): $(CLASSES)
	echo Main-class: $(MAINCLASS) > Manifest
	jar cvfm $(JARFILE) Manifest $(JARCLASSES)
	chmod +x $(JARFILE)
	rm Manifest

%.class: %.java
	$(JAVAC) $<

clean:
	rm -f *.class $(JARFILE)
	
submit:
	submit cmps101-pt.f16 pa3 Makefile README Sparse.java Matrix.java List.java MatrixTest.java ListTest.java

subchk:
	ls  /afs/cats.ucsc.edu/class/cmps101-pt.f16/pa3/arsamuel