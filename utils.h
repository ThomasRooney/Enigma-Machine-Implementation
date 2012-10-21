#include "common.h"

void signalHandler( int signum );
// Definition must go in header file so definition is available at compile time when the template is used.
// And export isn't defined correctly in my IDE/Compiler.
template <typename T>
vector<T> *readFile(char * fileName)
{
  // Create a vector<T> on the heap
  vector<T> *out = new vector<T>();
  ifstream in_file;
  // Open the file +r
  in_file.open(fileName, ifstream::in);
  T primBuffer;
  if (in_file.is_open())
  {
    while ( in_file.good() )
    {
      // Stream the type we want to stream. Let the ifstream class handle the rest
      if (in_file >> primBuffer)
      // If we can stream it
      // add it to the output.
        out->push_back(primBuffer);
    }
    in_file.close();
  }
  else
  {
    cout << "Error Reading File: " << fileName << endl;
    exit(0);
  }
  // Which is returned
  return out;
}
