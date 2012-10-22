// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include "common.h"
#include "utils.h"
#include "Enigma_Base.h"
#include "Reflector.h"
#include "Plugboard.h"
#include "Rotor.h"

int main(int argc, char **argv)
{
	int i;
  vector<Enigma_Base *> objects;
  vector<Enigma_Base *>::iterator objectIter;
  vector<Rotor *> rotors;
  vector<Rotor *>::iterator rotorIter;
  char buffer;
  Plugboard *plugboard = NULL;
  Reflector *reflector = NULL;
  // Before anything else, lets create a signals handler 
  signal(SIGINT, signalHandler);  


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
  objects.push_back(plugboard);
  // Then we have the rotors
  for (rotorIter = rotors.begin(); rotorIter != rotors.end(); rotorIter++){
    objects.push_back(*rotorIter);
  }
  // Then a reflector
  objects.push_back(reflector);
  // More rotors, backwards
  if (rotors.size() > 0)
  {
    for (rotorIter = rotors.end() - 1; rotorIter != rotors.begin(); rotorIter--){
      objects.push_back(*rotorIter);
    }
  }
  // Then the plugboard again
  objects.push_back(plugboard);
  

  // Now we listen to stdin and pass it through our objects list one by one
  
  while (cin.good()) {
    cin >> ws; // Strip whitespace
    cin >> buffer; // Lets deal with one character
    // Make sure its an uppercase letter
    if (!isalpha(buffer))
    {
      cout << endl << "Sir, you have entered an invalid letter: " << buffer << endl;
      continue;
    }
    buffer = toupper(buffer);
    // For each item, in order, the wriing passes through.
    for (objectIter = objects.begin(); objectIter != objects.end(); objectIter++)
    {
      // if its null (not included, e.g. no args, ignore it)
      if (*objectIter != NULL)
      {
        // Send data in and collect its output.
        buffer >>= **objectIter;
      }
    }
    // rotate the rotors
    for (rotorIter = rotors.begin(); rotorIter != rotors.end(); rotorIter++)
    {
      (*rotorIter)->rotate();
      // Only rotate the next rotors when the previous rotor has done a full rotation
      if ((*rotorIter)->rotation % LENGTH_OF_ALPHABET != 0)
        break;
    }
    // Send buffer to cout
    cout << buffer;
  }
  return 0;
}
