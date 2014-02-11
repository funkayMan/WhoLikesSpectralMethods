#include <iostream>
#include "LegendreQuad.h"
//using namespace std;


//~ g++ -c LegendreQuad.cpp -o LegendreQuad.o
//~ g++ -main.cpp -o dumdum LegendreQuad.o -lm
//~ ./dumdum

int main(int argc,char **argv)
{
	int N=5;
	LegendreQuad dummy;
	dummy.setElementSize(N);
	dummy.PointsAndWeights();  // run func. to get colloc. points and weights
	dummy.LegPolynomials();		
//********************************************************************
//   uncomment if you want to print collocation points and weights	**
//																	**
//********************************************************************
	int i,j;
	std::cout << "Collocation Pts: " << std::endl;
	for(i=0;i<N+1;i++)
	{
		std::cout << dummy.getCollocation(i) << std::endl;
	}
	std::cout << "\n\n";
	
	std::cout << "Collocation Weights: " << std::endl;
	for(i=0;i<N+1;i++)
	{
		std::cout << dummy.getWeight(i) << std::endl;
	}
	std::cout << "\n\n";
	
	std::cout << "The Legendre Polynomial Matrix: " << std::endl;
	for(j=0;j<N+1;j++)
	{
		for(i=0;i<N+1;i++)
		{
			std::cout << dummy.getLegPolys(j,i) << "  ";
		}
		std::cout<<std::endl;
	}
	
	std::cout << "\n\n";
	std::cout << "The normalizing parameters: "<< std::endl;
	for(j=0;j<N+1;j++)
	{
		std::cout<< dummy.getGamma(j) << std::endl;
	}
}
