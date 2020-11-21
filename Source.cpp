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
		vector_U[i] = vector_U[i] + t * vector_F[i];			//выполн€ем шаг
	}
}

void find_tk(double* tk, double t) {
	*tk = *tk + t;
}

//јлгоритм €вного метода Ёйлера
void explicit_Euler_method(double* vector_U, double tk, double T, double eps, double tmax) {

	double res[2];
	double tmin;

	cout << "явный метод Ёйлера" << endl;
	cout << "u1" << setw(25) << "u2" << setw(25) << "tk" << endl;
	int iter = 0;
	while (tk < T) {

		Function(res, vector_U);

		tmin = findStep(res);

		makeStep(res, vector_U, tmin);

		find_tk(&tk, tmin);

		cout << vector_U[0] << setw(25) << vector_U[1] << setw(25) << tk << endl;

		iter++;

	}
	cout << endl << "Iteration " << setw(15) << iter << endl;
}