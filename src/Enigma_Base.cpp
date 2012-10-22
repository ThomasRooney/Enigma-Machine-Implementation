#include "Enigma_Base.h"
#include "utils.h"

Enigma_Base::Enigma_Base(char * filename)
{
  config = readFile<int>(filename);
}

Enigma_Base::Enigma_Base()
{
  config = NULL;
}

Enigma_Base::~Enigma_Base()
{
  if (config != NULL) {
	  delete config;
  }
}

void Enigma_Base::operation ()
{} // Every enigma function does something to its internal state. 

void Enigma_Base::invoperation ()
{
  operation();
} // By default, acts the same as normal operation (e.g. plugboard

char operator>>=( char &strm, Enigma_Base &object ) 
{ 
    object.state = strm; // Stream it in
    object.operation(); // Do some defined operation on its state
    strm = object.state;
    return strm;  //return the new state
}

char operator<<=( char &strm, Enigma_Base &object ) 
{ 
    object.state = strm; // Stream it in
    object.invoperation(); // Do some defined operation on its state
    strm = object.state;
    return strm;  //return the new state
}