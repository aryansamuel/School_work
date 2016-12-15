#------------------------------------------------------------------------------
# Simulation.java Makefile
# Aryan Samuel
# arsamuel
# CMPS 12B
# 05/11/16
# Programming Assignment 4
# Makefile for the Simulation.java program
#------------------------------------------------------------------------------

JAVAC      = javac 
MAINCLASS  = Simulation
JAVASRC    = $(wildcard *.java)
SOURCES    = $(JAVASRC) makefile README
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
	rm *.class $(JARFILE)

submit:
	submit  cmps012b-pt.s16 pa4 README Makefile Simulation.java Queue.java QueueTest.java QueueInterface.java QueueEmptyException.java Job.java

check:
	ls  /afs/cats.ucsc.edu/class/cmps012b-pt.s16/pa4/arsamuel
