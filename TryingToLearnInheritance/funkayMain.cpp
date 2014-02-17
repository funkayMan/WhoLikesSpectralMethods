#include <iostream>

#include "goo.h"
#include "moo.h"

using namespace std;

int main()
{
goo googoo;
moo moomoo;

int M=5;
googoo.setM(M);

cout << "m = " << googoo.getM() << endl;

int N=20;
moomoo.countUp(N);

cout << "After the moo call, m = " << googoo.getM() << endl;


return 0;
}
