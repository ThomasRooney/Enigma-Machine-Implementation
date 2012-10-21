#include "Enigma_Base.h"

class Reflector : public Enigma_Base{
public:
  Reflector() : Enigma_Base() {}
  void operation () {
    state = INTTOCHAR(\
      (CHARTOINT(state) + 13) % LENGTH_OF_ALPHABET\
      );
  }
};