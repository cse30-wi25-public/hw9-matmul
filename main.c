#include <stdlib.h>
#include <stdio.h>
#include <float.h>
extern void matmul(double *C, double *A, double *B, int M, int N, int K);
extern void ref_matmul(double *C, double *A, double *B, int M, int N, int K);

//!
//! set matrix to random values
//!
void set_rand_matrix(double *x, int rows, int cols){
  double *p = x;
  for (int i=0; i<rows; i++){
    for (int j=0; j<cols; j++){
      *p++ = drand48();
    }
  }
}

//!
//! set matrix to a constant value
//!
void set_matrix(double *x, int rows, int cols, double v){
  double *p = x;
  for (int i=0; i<rows; i++){
    for (int j=0; j<cols; j++){
      *p++ = v;
    }
  }
}

//!
//! compare two matrices
//!
int compare_matrix(double *X, double *Y, int rows, int cols){
  for (int i=0; i<rows; i++){
    for (int j=0; j<cols; j++){
      if (*X - *Y > 3*DBL_EPSILON){
	fprintf(stderr, "mismatch at %d %d   ref=%f  vs %f\n", i, j, *X, *Y);
	return 1;
      }
      X++;
      Y++;
    }
  }
  return 0;
}

//!
//!
//!
int main(int argc, char *argv[]){
  if (argc < 2){
    fprintf(stderr, "%s needs at least 1 argument (Nsize : matrix size)\n", argv[0]);
    fprintf(stderr, "%s Usage Nsize  [reps]\n", argv[0]);
    return(EXIT_FAILURE);
  }
  int reps = 10;
  if (argc == 3){
    reps = atoi(argv[argc-1]);
    argc--;
  }
  int Nsize = atoi(argv[argc-1]);
  int M = Nsize;
  int N = Nsize;
  int K = Nsize;

  double *A = NULL;
  double *B = NULL;
  double *C = NULL;
  double *refC = NULL;
  if ((C = malloc(sizeof(double) * M * N)) == NULL){
    fprintf(stderr, "%s failed to allocate matrix C (%d x %d : matrix size)\n", argv[0], N, N);
    return(EXIT_FAILURE);
  }
  if ((refC = malloc(sizeof(double) * M * N)) == NULL){
    fprintf(stderr, "%s failed to allocate matrix refC (%d x %d : matrix size)\n", argv[0], N, N);
    return(EXIT_FAILURE);
  }

  if ((A = malloc(sizeof(double) * M * K)) == NULL){
    fprintf(stderr, "%s failed to allocate matrix A (%d x %d : matrix size)\n", argv[0], N, N);
    return(EXIT_FAILURE);
  }
  if ((B = malloc(sizeof(double) * K * N)) == NULL){
    fprintf(stderr, "%s failed to allocate matrix B (%d x %d : matrix size)\n", argv[0], N, N);
    return(EXIT_FAILURE);
  }


  set_rand_matrix(A, M, K);
  set_rand_matrix(B, K, N);



  ref_matmul(refC, A, B, M, N, K);
  matmul(C, A, B, M, N, K);
  // verify
  if (compare_matrix(refC, C, M, N)){
    fprintf(stderr, "calculation errors\n");
    return EXIT_FAILURE;
  }
  
  set_matrix(C, M, N, 0.0);
  for (int r = 0; r < reps; r++){
    matmul(C, A, B, M, N, K);
  }


  return(EXIT_SUCCESS);

}


