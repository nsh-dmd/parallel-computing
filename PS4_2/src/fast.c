#include <complex.h>
#include <xmmintrin.h>
#include <pmmintrin.h>

//Currently just a copy of naive...

void chemm(complex float* A,
        complex float* B,
        complex float* C,
        int m,
        int n,
        complex float alpha,
        complex float beta){
    
    for(int x = 0; x < n; x++){
        for(int y = 0; y < m; y++){
            C[y*n + x] *= beta;
            for(int z = 0; z < m; z++){
                C[y*n + x] += alpha*A[y*m+z]*B[z*n + x];
            }
        }
    }

}
