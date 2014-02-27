#include <iostream>
#include "LegendreQuad.h"
#include "BuildMassAndStiffness.h"
//using namespace std;


int main(int argc,char **argv)
{
	int N=6;
	
	BuildMassStiffness dumdum(N);	
	

	
	dumdum.buildMass();	
	dumdum.buildStiffness();
	
}
	


