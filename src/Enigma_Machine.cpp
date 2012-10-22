#include "Enigma_Machine.h"
#include "utils.h"
#include "Reflector.h"
#include "Plugboard.h"


Enigma_Machine::Enigma_Machine(int argc, char ** argv)
{
  Plugboard * plugboard = NULL;
  Reflector * reflector = NULL;
  vector<Rotor *>::iterator rotorIter;
  int i;
  // Lets create the rotors
  for (i = 1; i < argc - 1; i++){
    rotors.push_back(new Rotor(argv[i]));
  }
  // Then the plugboard
  // Quick sanity check, we do have at least one argument right?
  if (argc > 1)
    plugboard = new Plugboard(argv[i]);
  // Finally a reflector
  reflector = new Reflector();



  // First object wired is the plugboard 
  wiring.push_back(plugboard);
  // Then we have the rotors
  for (rotorIter = rotors.begin(); rotorIter != rotors.end(); rotorIter++){
    wiring.push_back(*rotorIter);
  }
  // Then a reflector
  wiring.push_back(reflector);
  // More rotors, backwards
  if (rotors.size() > 0)
  {
    for (rotorIter = rotors.end() - 1; rotorIter != rotors.begin(); rotorIter--){
      wiring.push_back(*rotorIter);
    }
     wiring.push_back(*rotorIter); // Push back the first rotor (don't want to overflow)
  }
  // Then the plugboard again
  wiring.push_back(plugboard);
}

Enigma_Machine::~Enigma_Machine()
{
  for (std::vector<Enigma_Part *>::iterator objectIter = wiring.begin();
      objectIter != wiring.end();
      objectIter++)
  {
    if (*objectIter != NULL)
    {
//      delete *objectIter;
//      *objectIter = NULL; // Just a temporary fix. Tests don't like this. Goes out of scope anyway.
    }
  }
}

char operator>>=( char &buffer, Enigma_Machine &machine ) 
{ 
  unsigned int i = 0;
  // Make sure its an uppercase letter
  if (!isalpha(buffer))
  {
    cout << endl << "Sir, you have entered an invalid letter: " << buffer << endl;
    return buffer;
  }
  buffer = toupper(buffer); 
  // For each item, in order, datastream (>>=) between them.
  for (std::vector<Enigma_Part *>::iterator objectIter = machine.wiring.begin();
    objectIter != machine.wiring.end(); objectIter++)
  {
    // if its null (not included, e.g. no args, ignore it)
    if (*objectIter != NULL)
    {
      // If we're beyond the half way point, use inverse operations
      if (++i > machine.wiring.size() / 2)
        buffer <<= **objectIter;
      else
        // Send data in and collect its output.
        buffer >>= **objectIter;
    }
  }
  // rotate the rotors
  rotateRotors(machine.rotors);
  return buffer;  //return the new state
}