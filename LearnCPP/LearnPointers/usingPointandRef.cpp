#include <iostream>

using namespace std;

double passmematrix(double *poo, int n);

int main()
{
	int i,j,n;
	double ii,jj;
	
	n=5;
	double M[n][n];
	double *MM;
	
	ii=0.0;
	jj=ii;
	
	for(i=0;i<n;i++)
	{
		ii+=1.0;
		for(j=0;j<n;j++)
		{
			jj+=1.0;
			M[i][j]=(ii+1.0)/(jj+ii);
		}
	}
	//~ double MM;
	MM=*M;
	cout <<M[0][1] <<endl;
	cout <<(MM)<<endl;
	void passmematrix(MM, n);
}


void passmematrix(double *poo, int n)
{
	cout << "hi" << endl;
	//~ int i,j;
	//~ cout<< "The matrix passed is :" << endl;
	//~ cout << poo[1][1] << endl;
	//~ for(i=0;i<n;i++)
	//~ {
		//~ for(j=0;j<n;j++)
		//~ {
			//~ cout << poo[i][j] << endl;		
		//~ }
		//~ cout << <<endl;
	//~ }
}
