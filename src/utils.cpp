#include "utils.h"

void signalHandler( int signum )
{
  //cout << "Sir, we recieved an interrupt signal (" << signum << ")." << endl;
  exit(signum);  
}

void rotateRotors(std::vector<Rotor *> &rotors)
{
  for (std::vector<Rotor *>::iterator rotorIter = rotors.begin(); rotorIter != rotors.end(); rotorIter++)
  {
    (*rotorIter)->rotate();
    // Only rotate the next rotors when the previous rotor has done a full rotation
      if ((*rotorIter)->rotation % LENGTH_OF_ALPHABET != 0)
      break;
  }
}

void dataStream(std::vector<Enigma_Part *> &objects, char &buffer) {
unsigned int i = 0;
}