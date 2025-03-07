// uncomment ONLY one of these defines
//
#define IJK
// #define JIK
// #define KIJ
// #define KJI
// #define IKJ
// #define JKI


#ifdef IJK
void matmul(double *C, double *A, double *B, int M, int N, int K){

  
  for (int i=0; i<M; i++){
    for (int j=0; j<N; j++){
      for (int k=0; k<K; k++){
	*(C + i*N + j) += (*(A + i*N + k)) *  (*(B + k*N + j));
      }
    }
  }
}
#endif
// ----------------------------

// TODO
// Implement different loop variations inside of each ifdef
//
#ifdef JIK   // jik variation

#endif       // jik variation

// ----------------------------

#ifdef KIJ   // kij variation

#endif       // kij variation

// ----------------------------

#ifdef KJI   // kji variation

#endif       // kji variation

// ----------------------------

#ifdef IKJ   // ikj variation

#endif       // ikj variation

// ----------------------------

#ifdef JKI   // jki variation

#endif       // jki variation

