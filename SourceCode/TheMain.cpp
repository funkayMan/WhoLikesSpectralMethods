#include <iostream>
#include "LegendreQuad.h"
#include "BuildMassAndStiffness.h"
//using namespace std;


int main(int argc,char **argv)
{
	int N=5;
	
	BuildMassStiffness dumdum(N);	
	
	//~ dumdum.PointsAndWeights();
	//~ dumdum.LegPolynomials();
	
	dumdum.buildMass();	
	dumdum.buildStiffness();
	
}
	


