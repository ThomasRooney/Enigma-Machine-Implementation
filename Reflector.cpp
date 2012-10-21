#include "Reflector.h"


Reflector::Reflector() : Enigma_Base() {}

void Reflector::operation () {
  state = INTTOCHAR(\
    (CHARTOINT(state) + 13) % LENGTH_OF_ALPHABET\
    );
}