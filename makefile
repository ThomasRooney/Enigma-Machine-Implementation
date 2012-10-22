# edit this makefile so that running make compiles your enigma program
CC=g++
CFLAGS=-std=c++0x
FILES= Main.cpp common.h Plugboard.h Plugboard.cpp Reflector.cpp Reflector.h Rotor.cpp Rotor.h utils.cpp utils.h Enigma_Base.h Enigma_Base.cpp


enigma: ${FILES}
	g++ ${CFLAGS} -o enigma ${FILES}
	
clean:
	rm -rf enigma *.o

.phony: clean
