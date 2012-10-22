#include "Rotor.h"
#include <stdexcept>
#include <algorithm>


Rotor::Rotor(char *a) : Enigma_Base(a) {
  rotation = 0;
}

void Rotor::rotate() {
  rotation = (rotation + 1) % LENGTH_OF_ALPHABET;
//  std::rotate(config->begin(),
//            config->end ()-1, // this will be the new first element
//            config->end());
}


void Rotor::operation () {
  // Lookup index in config
  try {
    // Rotate it according to the Rotor Internal Configuration
    state = (CHARTOINT(state)+rotation)%LENGTH_OF_ALPHABET;
    state = (config->at(state));
    state = (state - rotation + LENGTH_OF_ALPHABET) % LENGTH_OF_ALPHABET;
    state = INTTOCHAR(state);
  }
  catch (out_of_range) {
    cout << "Error. Out of Bounds Exception inside Rotor operation" << endl;
  }
}

void Rotor::invoperation () {
  // Lookup index in config
  // Look up the state in the config, output the index required to get to that state
  int expected = CHARTOINT(state);
  expected = ((expected - rotation + LENGTH_OF_ALPHABET) % LENGTH_OF_ALPHABET);

  for (unsigned int i=0;
      i < config->size();
      i++)
  {
    if (config->at(i) == expected)
    {
      state = ((i + rotation) % LENGTH_OF_ALPHABET);
      state = INTTOCHAR(state);
      
      return;
    }
  }
  
  cout << "Error. Out of Bounds Exception inside Rotor operation" << endl;
  exit(0);
}

