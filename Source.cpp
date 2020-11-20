#include"Functions.h"
double eps = 0.001;
double tmax = 0.1;

//подсчет верный
void Function(double* vector_F, double* vector_U) {
	vector_F[0] = vector_U[1] - ((2 * vector_U[0] + 0.25 * vector_U[1]) * vector_U[0]);
	vector_F[1] = exp(vector_U[0]) - ((vector_U[0] + 2 * vector_U[1]) * vector_U[0]);
}

double findStep(double* vector_F) {
	double vector_t[2];			//массивчик шагов

	//п=расчитываем по формуле 3.11
	for (int i = 0; i < 2; i++){
		vector_t[i] = eps / (vector_F[i] + eps / tmax);
	}

	//найдем минимальный шаг по формуле 3.12
	double tmin = abs(vector_t[0]);
	if (tmin > abs(vector_t[1]))
		tmin = abs(vector_t[1]);
	
	return tmin;
}

void makeStep(double* vector_F, double* vector_U, double t) {
	for (int i = 0; i < 2; i++)
	{
		vector_U[i] = vector_U[i] + t * vector_F[i];			//выполняем шаг
	}
}

void find_tk(double* tk, double t) {
	*tk = *tk + t;
}