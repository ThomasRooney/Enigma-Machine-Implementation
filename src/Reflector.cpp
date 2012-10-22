#include "Reflector.h"


Reflector::Reflector() : Enigma_Part() {}

void Reflector::operation () {
  state = INTTOCHAR(\
    (CHARTOINT(state) + 13) % LENGTH_OF_ALPHABET\
    );
} 