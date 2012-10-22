#include "Enigma_Part.h"
#include "utils.h"

Enigma_Part::Enigma_Part(char * filename)
{
  config = readFile<int>(filename);
}

Enigma_Part::Enigma_Part()
{
  config = NULL;
}

Enigma_Part::~Enigma_Part()
{
  if (config != NULL) {
	  delete config;
  }
}

void Enigma_Part::operation ()
{} // Every enigma function does something to its internal state. 

void Enigma_Part::invoperation ()
{
  operation();
} // By default, acts the same as normal operation (e.g. plugboard

char operator>>=( char &strm, Enigma_Part &object ) 
{ 
    object.state = strm; // Stream it in
    object.operation(); // Do some defined operation on its state
    strm = object.state;
    return strm;  //return the new state
}

char operator<<=( char &strm, Enigma_Part &object ) 
{ 
    object.state = strm; // Stream it in
    object.invoperation(); // Do some defined operation on its state
    strm = object.state;
    return strm;  //return the new state
}