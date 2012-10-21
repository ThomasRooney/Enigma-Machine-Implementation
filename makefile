# edit this makefile so that running make compiles your enigma program

enigma: Main.o
	g++ -o -std=c++0x enigma Main.o

Main.o: Main.cpp
	g++ -c -std=c++0x Main.cpp

clean:
	rm -rf enigma *.o

.phony: clean
