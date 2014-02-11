#include <iostream>
#include "LegendreQuad.h"
//using namespace std;


//~ g++ -c LegendreQuad.cpp -o LegendreQuad.o
//~ g++ -main.cpp -o dumdum LegendreQuad.o -lm
//~ ./dumdum

#define N 5

int main(int argc,char **argv)
{
  LegendreQuad dummy;
  int i;
  dummy.setElementSize(N);
  dummy.Eigs();
  // uncomment if you want to print collocation points and weights
  
  //~ for(i=0;i<=N;++i)
    //~ {
      //~ std::cout << dummy.getCollocation(i) <<"\t"<<dummy.getWeight(i)<< std::endl;
	//~ }
}
