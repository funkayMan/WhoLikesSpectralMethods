#include <iostream>

#include "goo.h"
#include "moo.h"

using namespace std;

int main()
{
  int M=5;
  moo moomoo(M);

  cout << "Initial value of my precious is " << moomoo.getMyPrecious() << endl;

  int N=20;
  moomoo.countUp(N);

  cout << "My precious is this much better " << moomoo.getMyPrecious() << endl;


  return 0;
}
