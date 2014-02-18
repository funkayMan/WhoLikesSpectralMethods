#ifndef MOO
#define MOO
#include "goo.h"

class moo: public goo {
public:
  moo(int initial=0); // constructor for this class.
  ~moo();             // destructor for the class
  int countUp(int val);

protected:
private:
};

#endif
