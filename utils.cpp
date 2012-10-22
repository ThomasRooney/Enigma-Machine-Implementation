#include "utils.h"

void signalHandler( int signum )
{
  //cout << "Sir, we recieved an interrupt signal (" << signum << ")." << endl;
  exit(signum);  
}