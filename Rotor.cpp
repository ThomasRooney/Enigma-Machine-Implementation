#include "Rotor.h"

Rotor::Rotor(char *a) : Enigma_Base(a) {
  rotation = 0;
}

void Rotor::rotate() {
  rotation++;
}


void Rotor::operation () {
  // Lookup index in config
  try {
    // Rotate it according to the Rotor Internal Configuration
    state = INTTOCHAR(config->at((CHARTOINT(state) + rotation) \
                                % (LENGTH_OF_ALPHABET)));
  }
  catch (out_of_range) {
    cout << "Error. Out of Bounds Exception inside Rotor operation" << endl;
  }
}