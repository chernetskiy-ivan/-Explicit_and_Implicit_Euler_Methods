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

void find_tk(double* tk, double tau) {
	*tk = *tk + tau;
}

//јлгоритм €вного метода Ёйлера
void explicit_Euler_method(double* vector_U, double tk, double T, double eps, double tmax) {

	double res[2];
	double tmin;

	cout << "явный метод Ёйлера" << endl;
	cout << setw(25) << "u1" << setw(25) << "u2" << setw(25) << "tk" << endl;
	int iter = 0;
	while (tk < T) {

		Function(res, vector_U);

		tmin = findStep(res);

		makeStep(res, vector_U, tmin);

		find_tk(&tk, tmin);

		cout << setw(25) << vector_U[0] << setw(25) << vector_U[1] << setw(25) << tk << endl;

		iter++;

	}
	cout << endl << "Iteration " << setw(15) << iter << endl;
}


//не €вный метод

void ImplicitEulerMethod(double* vectordF, double* vectorU, double* temp, int size, double t, double T, double tauMin, double tauMax, double eps, bool strategy, bool type)
{
	double* Y = new double[size];
	double* Ym = new double[size];
	double* Yp = new double[size];
	Y = vectorU;
	Ym = vectorU;
	Yp = vectorU;


	double tauM = tauMin,
		tau = tauMin;

	bool is = false;
	double* Eps = new double[size];
	double tP;

	int count = 0;
	do
	{
		do
		{
			tP = t + tau;

			//приготовлени€ дл€ метода ньютона
			double** matrix_Jacobi = new double* [size];
			for (int i = 0; i < size; i++)
				matrix_Jacobi[i] = new double[size + 1];

			double* vectorF = new double[size] {};
			double* vector = new double[size] {};

			double Neps = 1e-9,
				NincrementM = 0.01;
			int Niter = 15;


			if (!type)
				Function(vectordF, Yp);
			else
				vectordF = temp;

			//разностна€ схема не€вного метода
			for (int i = 0; i < size; i++)
				Yp[i] = Y[i] + tau * vectordF[i];


			if (!type)
				NewtonMethod(matrix_Jacobi, vectorF, Yp, vector, size, Niter, NincrementM, Neps);

			//пасчет массива Ёпсмлонт 
			for (int i = 0; i < size; i++)
				Eps[i] = -(tau / (tau + tauM)) * (Yp[i] - Y[i] - (tau / tauM) * (Y[i] - Ym[i]));

			for (int i = 0; i < size; i++)
				if (Eps[i] > eps) {
					tau /= 2;
					tP = t;
					Yp[i] = Y[i];
					is = true;
					break;
				}

		} while (is);

		double* Tau = new double[size];
		double tauP = 0;

		if (strategy)
			QuasiOptimalStrategy(Tau, Eps, size, tau, tauP, eps);
		else
			ThreeZoneStrategy(Tau, Eps, size, tau, tauP, eps);

		if (tauP > tauMax)
			tauP = tauMax;

		cout << setw(20) << Yp[0] << setw(20) << Yp[1] << setw(20) << tP << endl;

		Ym = Y;
		Y = Yp;
		tauM = tau;
		tau = tauP;
		t = tP;

		count++;
	} while (t < T);

	cout << "Iter = " << count << endl;

}

void FillVectordF(double* vector_dF, double* vector_U)
{
	vector_dF[0] = vector_U[1] - (2 * vector_U[0] + 0.25 * vector_U[1]) * vector_U[0];
	vector_dF[1] = exp(vector_U[0]) - (vector_U[0] + 2 * vector_U[1]) * vector_U[0];
}

void NewtonMethod(double** matrix_Jacobi, double* vector_dF, double* vector_U, double* vector_X2, int size, int iter, double increment_M, double eps)
{
	double delta1, delta2, max;

	int c = 0;
	FillMatrixJacobi_II(matrix_Jacobi, vector_dF, vector_U, size, increment_M);

	while (true)
	{
		Function(vector_dF, vector_U);

		FillMatrixJacobi_II(matrix_Jacobi, vector_dF, vector_U, size, increment_M);

		GaussMethod(matrix_Jacobi, vector_U, vector_X2, size);
		max = 0;

		Function(vector_dF, vector_U);
		for (int i = 0; i < size; i++)
			if (fabs(vector_dF[i]) > max)
				max = fabs(vector_dF[i]);

		delta1 = max;
		max = 0;

		for (int i = 0; i < size; i++)
		{
			if (fabs(vector_U[i]) < 1 && fabs(vector_X2[i]) > max)
				max = fabs(vector_X2[i]);
			if (fabs(vector_U[i]) >= 1 && fabs(vector_X2[i] / vector_U[i]) > max)
				max = fabs(vector_X2[i] / vector_U[i]);
		}

		delta2 = max;

		if (delta1 <= eps && delta2 <= eps || c >= iter)
			break;
	}
}

void FillMatrixJacobi_II(double** matrix_Jacobi, double* vector_dF, double* vector_U, int size, double increment_M)
{
	//конечно-разностный метод заполнени€ матрицы €коби
	double F1, F2;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			vector_U[j] += increment_M;
			Function(vector_dF, vector_U);
			F1 = vector_dF[i];
			vector_U[j] -= increment_M;
			Function(vector_dF, vector_U);
			F2 = vector_dF[i];
			matrix_Jacobi[i][j] = (F1 - F2) / increment_M;
			matrix_Jacobi[i][size] = -vector_dF[i];
		}
}

void GaussMethod(double** matrix_Jacobi, double* vector_U, double* vector_X2, int size)
{
	for (int i = 0; i < size; i++)
	{
		double max = fabs(matrix_Jacobi[i][i]);
		int index = i;
		for (int j = i; j < size; j++)
			if (fabs(matrix_Jacobi[j][i]) > max)
			{
				max = fabs(matrix_Jacobi[j][i]);
				index = j;
			}

		if (index != i)
		{
			double* temp = matrix_Jacobi[i];
			matrix_Jacobi[i] = matrix_Jacobi[index];
			matrix_Jacobi[index] = temp;
		}

		double mainelement = matrix_Jacobi[i][i];
		for (int j = 0; j < size + 1; j++)
			matrix_Jacobi[i][j] /= mainelement;


		for (int j = i + 1; j < size; j++)
		{
			double temp = matrix_Jacobi[j][i];
			for (int k = i; k < size + 1; k++)
				matrix_Jacobi[j][k] -= matrix_Jacobi[i][k] * temp;
		}

	}

	for (int i = size - 1; i > 0; i--)
	{
		double temp = matrix_Jacobi[i][size];
		for (int j = i - 1; j >= 0; j--)
			matrix_Jacobi[j][size] -= matrix_Jacobi[j][i] * temp;
	}

	for (int i = 0; i < size; ++i)
		vector_X2[i] = matrix_Jacobi[i][size];

	for (int i = 0; i < size; i++)
		vector_U[i] += matrix_Jacobi[i][size];
}

void QuasiOptimalStrategy(double* Tau, double* Eps, int size, double tau, double& tauP, double eps)
{
	for (int i = 0; i < size; i++)
		Tau[i] = sqrt(eps / fabs(Eps[i])) * tau;

	tauP = Tau[0];
	for (int i = 0; i < size; i++)
		if (tauP > Tau[i])
			tauP = Tau[i];
}

void ThreeZoneStrategy(double* Tau, double* Eps, int size, double tau, double& tauP, double eps)
{
	for (int i = 0; i < size; i++)
	{
		if (fabs(Eps[i]) > eps)
			Tau[i] = tau / 2;

		if (eps / 4 < fabs(Eps[i]) <= eps)
			Tau[i] = tau;

		if (fabs(Eps[i]) <= eps / 4)
			Tau[i] = tau * 2;
	}

	tauP = Tau[0];
	for (int i = 0; i < size; i++)
		if (tauP > Tau[i])
			tauP = Tau[i];
}