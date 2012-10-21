#include "Plugboard.h"

Plugboard::Plugboard(char *a) : Enigma_Base(a)
{}


void Plugboard::operation () {
  int distance;
  // Is state in the configuration?
  vector<int>::iterator query = find(config->begin(), config->end(), CHARTOINT(state));
  if (query != config->end())
  {
    // Check distance
    distance = std::distance(config->begin(), query);
    // The file refers to pairs of variables, thus if we're an even distance, the other of the pair is in front, else behind  
    // We swap them. Isn't fitting it all in one line beautiful? (-10000)
    state = INTTOCHAR(*(!(distance%2)?++query:--query));
  }
}
