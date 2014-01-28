#include<stdio.h>
#include<stdlib.h>
#include "type.h"
#include "util.h"

DOUBLE *****fivetensor(int n1,int n2,int n3,int n4,int n5) {
  DOUBLE *****u;
  register int s,i,j,k,l;

  u = new DOUBLE****[n1];

  if(u==NULL) {
    printf("Error - fivetensor. Could not allocate memory\n");
    exit(2);
  }

  u[0] = new DOUBLE***[n1*n2];
  if(u[0]==NULL) {
    printf("Error - fivetensor. Could not allocate memory for *** vector.\n");
    exit(2);
   }

  u[0][0] = new DOUBLE**[n1*n2*n3];
  if(u[0][0]==NULL) {
    printf("Error - fivetensor. Could not allocate memory for ** vector.\n");
    exit(2);
  }

  u[0][0][0] = new DOUBLE*[n1*n2*n3*n4];
  if(u[0][0][0]==NULL) {
    printf("Error - fivetensor. Could not allocate memory for * vector.\n");
    exit(2);
  }

  u[0][0][0][0] = new DOUBLE[n1*n2*n3*n4*n5];
  if(u[0][0][0][0]==NULL) {
    printf("Error - fivetensor. Could not allocate memory for * vector.\n");
    exit(2);
  }


  for(s=0;s<n1;++s) {
      u[s] = u[0] + s*n2;
      for(i=0;i<n2;++i) {
          u[s][i] = u[0][0] + n3*n2*s + n3*i;
          for(j=0;j<n3;++j) {
              u[s][i][j] = u[0][0][0] + n4*n3*n2*s + n4*n3*i + n4*j;
              for(k=0;k<n4;++k) {
                  u[s][i][j][k] = u[0][0][0][0] + n5*n4*n3*n2*s + n5*n4*n3*i + n5*n4*j + n5*k;
                  for(l=0;l<n5;++l)
                      u[s][i][j][k][l] = 0.0;
              }
          }
      }
  }

  return(u);

}


DOUBLE ****fourtensor(int n1,int n2,int n3,int n4) {
  DOUBLE ****u;
  register int s,i,j,k;

  u = new DOUBLE***[n1];

  if(u==NULL) {
    printf("Error - fourtensor. Could not allocate memory\n");
    exit(2);
  }

  u[0] = new DOUBLE**[n1*n2];
  if(u[0]==NULL) {
    printf("Error - fourtensor. Could not allocate memory for *** vector.\n");
    exit(2);
   }

  u[0][0] = new DOUBLE*[n1*n2*n3];
  if(u[0][0]==NULL) {
    printf("Error - fourtensor. Could not allocate memory for ** vector.\n");
    exit(2);
  }

  u[0][0][0] = new DOUBLE[n1*n2*n3*n4];
  if(u[0][0][0]==NULL) {
    printf("Error - fourtensor. Could not allocate memory for * vector.\n");
    exit(2);
  }

  for(s=0;s<n1;++s) {
      u[s] = u[0] + s*n2;
      for(i=0;i<n2;++i) {
	  u[s][i] = u[0][0] + n3*n2*s + n3*i;
	  for(j=0;j<n3;++j) {
	      u[s][i][j] = u[0][0][0] + n4*n3*n2*s + n4*n3*i + n4*j;
	      for(k=0;k<n4;++k)
		  u[s][i][j][k] = 0.0;
	  }
      }
  }

  return(u);
  
}

DOUBLE ***threetensor(int n1,int n2,int n3) {
  DOUBLE ***u;
  register int s,i,j;

  u = new DOUBLE**[n1];

  if(u==NULL) {
    printf("Error - threetensor. Could not allocate memory.\n");
    exit(2);
  }

  u[0] = new DOUBLE*[n1*n2];
  if(u[0]==NULL) {
    printf("Error - threetensor. Could not allocate memory for ** vector.\n");
    exit(2);
  }

  u[0][0] = new DOUBLE[n1*n2*n3];
  if(u[0][0]==NULL) {
    printf("Error - threetensor. Could not allocate memory for * vector.\n");
    exit(2);
  }

  for(s=0;s<n1;++s) {
      u[s] = u[0] + s*n2;
      for(i=0;i<n2;++i) {
	  u[s][i] = u[0][0] + n3*n2*s + n3*i;
	  for(j=0;j<n3;++j)
	      u[s][i][j] = 0.0;
      }
  }

  return(u);

}



DOUBLE **twotensor(int n1,int n2){
  DOUBLE **u;
  register int s,i;

  u = new DOUBLE*[n1];


  if(u==NULL) {
    printf("Error - twotensor. Could not allocate memory.\n");
    exit(2);
  }

  u[0] = new DOUBLE[n1*n2];
  if(u[0]==NULL) {
    printf("Error - twotensor. Could not allocate memory for vector.\n");
    exit(2);
  }

  for(s=0;s<n1;++s) {
    u[s] = u[0] + s*n2;

    for(i=0;i<n2;++i) 
      u[s][i] = 0.0;

  }

  return(u);

}


DOUBLE *onetensor(int n1) {
  DOUBLE *u;
  register int i;

  u = new DOUBLE[n1];

  if (u==NULL) {
    printf("Error - onetensor. Could not allocate memory.\n");
    exit(2);
  }

  for(i=0;i<n1;++i)
    u[i] = 0.0;

  return(u);

}


void delfivetensor(DOUBLE *****u) {

    if(u==NULL)
	return;

    delete u[0][0][0][0];
    delete u[0][0][0];
    delete u[0][0];
    delete u[0];
    delete [] u;

}


void delfourtensor(DOUBLE ****u) {

    if(u==NULL)
	return;

    delete u[0][0][0];
    delete u[0][0];
    delete u[0];
    delete [] u;

}




void delthreetensor(DOUBLE ***u) {

    if(u==NULL)
	return;

  delete u[0][0];
  delete u[0];
  delete [] u;

}



void deltwotensor(DOUBLE **u){


    if(u==NULL)
	return;

  delete u[0];
  delete [] u;


}

void delonetensor(DOUBLE *u) {

    if(u==NULL)
	return;

  delete [] u;

}
