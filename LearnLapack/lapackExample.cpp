#include <string.h>
#include <stdio.h>
#include <stdlib.h>
// tutorial from http://charlesmartinreid.com/wiki/Lapack


extern "C" void sgetri_ ( int* n, const void* A, int* lda,
    int* ipiv, const void* work, int* lwork, int* info );
 
extern "C" void sgetrf_ ( int* m, int* n, const void* a, int* lda,
    int* ipiv, int* info );
 
int main (void) {
 
    // A matrix (the one being inverted)
    float A[] = {1,3,2,4};  // Matrix [1 2
                            //         3 4]
                            // (matrices have to be provided to Lapack as 1-D arrays)
 
    int i,j,n;
    int lda, arows, acols;
    int ipiv[4];
    int info;
 
    // Set the dimension of A
    n=2;
    arows=n;
    acols=n;
 
    // Set the leading dimension of A 
    lda=2;
 
    // Set the dimension of the "workspace" array WORK
    // see http://www.netlib.org/lapack-dev/lapack-coding/program-style.html#workspace
    int lwork=100;
    float work[lwork];
 
    printf ("Matrix A before any calls:\n");
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++)
            printf ("A[%d][%d]:%f\t", i,j, A[n*j+i]); // this looks backwards, but it's b
        printf ("\n");
    }
    printf ("\n");
 
    // Allocate memory for arrays:
    // Pivot indices array
    memset (ipiv, 0, sizeof(int)*4);
    // Work (workspace) array
    memset (work, 0, sizeof(float)*100);
 
    // -------------------------------------------
    // Calculate the LU decomposition of A (and store it in A)
    // see http://www.netlib.org/lapack/single/sgetrf.f
    sgetrf_ ( &arows, &acols, A, &lda, ipiv, &info );
 
    printf ("Matrix A after sgetrf\n");
    for (i=0;i<2;i++) {
        for (j=0;j<2;j++) {
            printf("A[%d][%d]:%f\t", i,j, A[n*j+i]); // this looks backwards, but it's be
        }
        printf("\n");
    }
    if( info != 0 ) {
      printf("sgetrf_ returned an error! \n");
    }
 
    printf ("\n");
 
    // -------------------------------------------
    // Calculate the inverse of A using the LU decomposition of A
    // http://www.netlib.org/lapack/single/sgetri.f
    sgetri_ (&n, A, &lda, ipiv, work, &lwork, &info);
 
 
    printf ("Matrix A after sgetri\n");
    for (i=0;i<2;i++) {
        for (j=0;j<2;j++) {
            printf("A[%d][%d]:%f\t", i,j, A[n*j+i]); // this looks backwards, but it's be
        }
        printf("\n");
    }
    if( info != 0 ) {
      printf("sgetri_ returned an error! \n");
    }
 
    printf ("\n");
 
    return(0);
};
