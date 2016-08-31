#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_SIZE 10000000

typedef struct  {
    double real;
    double imag;
} complex_t;

complex_t multiply_complex(complex_t a, complex_t b){
  
    complex_t multiplication;
    multiplication.real = a.real * b.real - a.imag * b.imag;
    multiplication.imag = a.imag * b.real + a.real * b.imag;
    return multiplication;
}

double absolute_complex(complex_t a) {
    return sqrt( pow(a.real, 2) + pow(a.imag, 2) );
}

double randRange(double m, double n) {
    return m + (rand() / ( RAND_MAX / (n-m) ) ) ;
}

complex_t* create_random_complex_array(int size) {
    
    complex_t array[size];
    complex_t number;
    
//    complex_t *array = (complex_t *) malloc(sizeof(complex_t) * size);
//    for (int i = 0; i < size; i++) {
//        array[i] = { .real = 0., .imag = 0. };
//    }
    
    for (int i = 0; i < size; i++) {
        number.real = randRange(-3, 3);
        number.imag = randRange(-3, 3);
        array[i] = number;
    }
    return array;
    
}

int* fractal_test_array(complex_t* in, int size) {
    
//    int out[size];
    int *out = (int *) malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        out[i] = 0;
    }
    for (int i = 0; i < size; i++) {
//        if ( in[i].real * in[i].real + in[i].imag * in[i].imag >= 4 ) {
        if ( absolute_complex(in[i]) >= 2 ) {
            out[i] = 1;
        } else {
            out[i] = 0;
        }
    }
    return out;
}

int main(){
  complex_t a = { .real = -4.0, .imag = 3.0};
  complex_t b = { .real = 10.0, .imag = -8.0};
  complex_t c;

  c = multiply_complex(a, b);
  printf("%f + %fi\n", c.real, c.imag);  // Should print -16 + 62i

  double b_abs;
  b_abs = absolute_complex(b);

  printf("%f\n", b_abs);  // Should print 12.806248

  complex_t* complex_array = create_random_complex_array(ARRAY_SIZE);

  int* fractal_test = fractal_test_array(complex_array, ARRAY_SIZE);
/**
  // This will test the correctness of your implementation of fractal_test_array
  // Remove this before doing your timings.
  complex_t correctness_test_in[20];
  correctness_test_in[0] = (complex_t){.real = -0.201511, .imag = -2.801871};
  correctness_test_in[1] = (complex_t){.real = 2.947470, .imag = 2.131311};
  correctness_test_in[2] = (complex_t){.real = 0.940579, .imag = -1.688483};
  correctness_test_in[3] = (complex_t){.real = 1.673621, .imag = 0.542952};
  correctness_test_in[4] = (complex_t){.real = -0.604970, .imag = 2.271816};
  correctness_test_in[5] = (complex_t){.real = -1.595234, .imag = 2.897538};
  correctness_test_in[6] = (complex_t){.real = 2.916106, .imag = 2.989747};
  correctness_test_in[7] = (complex_t){.real = -1.324724, .imag = 1.368677};
  correctness_test_in[8] = (complex_t){.real = -0.652224, .imag = 0.077847};
  correctness_test_in[9] = (complex_t){.real = 0.369454, .imag = -0.589145};
  correctness_test_in[10] = (complex_t){.real = -1.753048, .imag = 2.524388};
  correctness_test_in[11] = (complex_t){.real = 1.391200, .imag = -0.096644};
  correctness_test_in[12] = (complex_t){.real = 1.710839, .imag = 2.077615};
  correctness_test_in[13] = (complex_t){.real = -1.530207, .imag = -2.185918};
  correctness_test_in[14] = (complex_t){.real = -0.728149, .imag = 2.005854};
  correctness_test_in[15] = (complex_t){.real = -1.605720, .imag = 0.671666};
  correctness_test_in[16] = (complex_t){.real = 2.695829, .imag = 2.797411};
  correctness_test_in[17] = (complex_t){.real = 0.091064, .imag = 0.515436};
  correctness_test_in[18] = (complex_t){.real = -1.075304, .imag = -0.628689};
  correctness_test_in[19] = (complex_t){.real = -0.370658, .imag = -1.642990};

  int* correctness_test_out = fractal_test_array(correctness_test_in, 20);
  int correct_result[20] = {1, 1, 0, 0, 1, 1, 1, 0, 0, 0,
                            1, 0, 1, 1, 1, 0, 1, 0, 0, 0};
  for (int i = 0; i < 20; i++) {
    if (correctness_test_out[i] != (int)correct_result[i]) {
      printf("Your program does not seem to run correctly\n");
      break;
    }
  }


  free(correctness_test_out);
 */
  free(complex_array);
  free(fractal_test);

}
