#include <iostream>
#include "LegendreQuad.h"
#include "MatrixOperations.h"
//using namespace std;


//~ g++ -c LegendreQuad.cpp -o LegendreQuad.o
//~ g++ -main.cpp -o dumdum LegendreQuad.o -lm
//~ ./dumdum

int main(int argc,char **argv)
{
	int N=6;
	
	double init_vec[N+1];
	
	MatOperations dumdum(N);
	
	int i;
	for(i=0;i<N+1;i++)
	{
		init_vec[i]=(double)i;
	}
	std::cout << "The input vector: "<< std::endl;
	for(i=0;i<N+1;i++)
	{
		std::cout << init_vec[i] << std::endl;
		dumdum.setVecIn(init_vec[i],i);		
	}
	
	
	
	dumdum.MatrixSolve();
	

	
		
	std::cout << "The resulting vector: "<< std::endl;
	for(i=0;i<N+1;i++)
	{
		std::cout << dumdum.getVecOut(i) << std::endl;
			
	}
}
	


