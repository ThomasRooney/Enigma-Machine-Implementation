#include "common.h"
#include "Enigma_Base.h"

class Rotor : public Enigma_Base{
public:
  int rotation;
  Rotor(char *a);
  void rotate();
  void operation ();
  void invoperation ();
};