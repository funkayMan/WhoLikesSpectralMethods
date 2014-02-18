
#include <iostream>
#include "moo.h"
#include "goo.h"

int moo::countUp(int val)
{
	goo blahblah;
	std::cout << "new M should be " << blahblah.getM() << std::endl;
	
	blahblah.setM(blahblah.getM()+val);
}

