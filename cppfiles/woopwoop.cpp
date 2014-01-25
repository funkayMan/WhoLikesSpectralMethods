#include <iostream>
#include "LegendreQuad.h"

using namespace std;



//~ g++ -c LegendreQuad.cpp -o LegendreQuad.o
//~ g++ -main.cpp -o dumdum LegendreQuad.o
//~ ./dumdum

int main(int argc,char **argv)
{
LegendreQuad dummy;
dummy.setElementSize(5);
cout << dummy.MakeTmatrix() << endl;
}
