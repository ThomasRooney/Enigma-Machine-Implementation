// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include "common.h"
#include "utils.h"
#include "Enigma_Part.h"
#include "Enigma_Machine.h"
#include "Reflector.h"
#include "Plugboard.h"
#include "Rotor.h"

int main(int argc, char **argv)
{
  char buffer;
  // Before anything else, lets create a signals handler 
  signal(SIGINT, signalHandler);  
  // Create our superclass on the stack.
  Enigma_Machine enigma(argc, argv);
  // Now we listen to stdin and pass it to our enigma machine
  while (cin.good()) {
    cin >> ws; // Strip whitespace
    cin >> buffer; // Lets deal with one character
    buffer >>= enigma;
    // Double check cin is not closed
    if (cin.good())
     cout << buffer;
   }
  return 0;
}
