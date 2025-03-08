// Have to specify which implementation using CFLAG (e.g., -DIJK, -DIKJ)

#ifdef IJK
void matmul(double *C, double *A, double *B, int M, int N, int K) {
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<K; k++) {
                *(C + i*N + j) += (*(A + i*N + k)) *  (*(B + k*N + j));
            }
        }
    }
}
#endif

// Implement different loop variations and measure performance of each
#ifdef IKJ
void matmul(double *C, double *A, double *B, int M, int N, int K) {
    for (int i = 0; i < M; i++) {
        for (int k = 0; k < K; k++) {
            for (int j = 0; j < N; j++) {
                *(C + i * N + j) += (*(A + i * N + k)) * (*(B + k * N + j));
            }
        }
    }
}
#endif
