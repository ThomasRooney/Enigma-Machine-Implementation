#ifndef _Enigma_Part
#define _Enigma_Part
#include "common.h"



class Enigma_Part {
  protected: 
		vector<int> *config;
    char state;
	public: 
		explicit Enigma_Part(char * filename);
    explicit Enigma_Part();
    ~Enigma_Part();
    virtual void operation ();    // Every enigma function does something to its internal state 
    virtual void invoperation (); // Some enigma function to inverse the orignal function
    friend char operator >>= (char &strm, Enigma_Part &object);
    friend char operator <<= (char &strm, Enigma_Part &object);
};
#endif