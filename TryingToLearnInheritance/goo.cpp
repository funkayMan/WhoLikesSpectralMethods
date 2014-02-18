
#include <iostream>
#include "goo.h"


goo::goo(int initial)
{
  std::cout << "initializing goo" << std::endl;
  setMyPrecious(initial);
}

goo::~goo(void)
{
  std::cout << "destroying goo" << std::endl;
}


void goo::setMyPrecious(int val)
{
	myPrecious=val;
}

int goo::getMyPrecious()
{
	return(myPrecious);
}
