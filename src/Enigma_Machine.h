#ifndef _Enigma_Machine
#define _Enigma_Machine

#include "common.h"
#include "Enigma_Part.h"
#include "Rotor.h"

class Enigma_Machine
{
  protected:
    vector<Enigma_Part *> wiring;
    vector<Rotor *> rotors;
  public:
    Enigma_Machine(int argc, char ** argv);
    ~Enigma_Machine();
    friend char operator>>=( char &buffer, Enigma_Machine &machine );
};

#endif