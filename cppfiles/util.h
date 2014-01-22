#ifndef UTILROUTINE
#define UTILROUTINE

DOUBLE *****fivetensor(int n1,int n2,int n3,int n4,int n5);
DOUBLE ****fourtensor(int n1,int n2,int n3,int n4);
DOUBLE ***threetensor(int n1,int n2,int n3);
DOUBLE **twotensor(int n1,int n2);
DOUBLE *onetensor(int n1);

void delfivetensor(DOUBLE *****u);
void delfourtensor(DOUBLE ****u);
void delthreetensor(DOUBLE ***u);
void deltwotensor(DOUBLE **u);
void delonetensor(DOUBLE *u);

#endif

