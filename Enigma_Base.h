#ifndef _ENIGMA_BASE
#define _ENIGMA_BASE
#include "common.h"



class Enigma_Base {
  protected: 
		vector<int> *config;
    char state;
	public: 
		explicit Enigma_Base(char * filename);
    explicit Enigma_Base();
    ~Enigma_Base();
    virtual void operation (); // Every enigma function does something to its internal state 
    friend char operator >>= (char &strm, Enigma_Base &object);
};
#endif