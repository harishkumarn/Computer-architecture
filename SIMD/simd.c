#include<arm_neon.h>
#include<stdio.h>
#include<stdlib.h>
// Example of SIMD multiplication using ARM NEON intrinsics
void neon_multiply(float32_t* a, float32_t* b, float32_t* result, int size) {
    int i;
    for (i = 0; i < size; i += 4) {
        float32x4_t vec_a = vld1q_f32(&a[i]); // Load 4 single-precision floats from array a
        float32x4_t vec_b = vld1q_f32(&b[i]); // Load 4 single-precision floats from array b
        float32x4_t vec_result = vmulq_f32(vec_a, vec_b); // Multiply corresponding elements
        vst1q_f32(&result[i], vec_result); // Store the result in the array
    }
}


int main(){

	float arr1[16] = {8.30, 8.60, 7.70, 1.50, 9.30, 3.50, 8.60, 9.20, 4.90, 2.10, 6.20, 2.70, 9.00, 5.90, 6.30, 2.60};
	float arr2[16] = {4.00, 2.60, 7.20, 3.60, 1.10, 6.80, 6.70, 2.90, 8.20, 3.00, 6.20, 2.30, 6.70, 3.50, 2.90, 0.20};
	float *arr3 = (float*)malloc(16 * sizeof(float));

	neon_multiply(arr1,arr2,arr3,16);
	
	for(int i = 0 ; i < 16;++i){
		printf("%f, ",arr3[i]);
	}


	return 0 ;
}
