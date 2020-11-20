#include"Functions.h"

//подсчет верный
double* Function(double* vector_F, double* vector_U) {
	vector_F[0] = vector_U[1] - ((2 * vector_U[0] + 0.25 * vector_U[1]) * vector_U[0]);
	vector_F[1] = exp(vector_U[0]) - ((vector_U[0] + 2 * vector_U[1]) * vector_U[0]);
	return vector_F;
}