#ifndef _Rotor
#define _Rotor

#include "common.h"
#include "Enigma_Part.h"

class Rotor : public Enigma_Part{
public:
  int rotation;
  Rotor(char *a);
  void rotate();
  void operation ();
  void invoperation ();
};

#endif