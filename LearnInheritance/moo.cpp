
#include <iostream>
#include "moo.h"
#include "goo.h"


moo::moo(int initial) : goo(initial)
{
  std::cout << "Constructor for moo." << std::endl;
}

moo::~moo()
{
  std::cout << "Destructor for moo." << std::endl;
}

int moo::countUp(int val)
{
  setMyPrecious(getMyPrecious()+val);
  std::cout << "new M should be " << getMyPrecious() << std::endl;
}

