#include"Functions.h"

void main() {
	setlocale(LC_ALL,"ru");
	cout << "Все работает норм. Кчау" << endl;
	
	double u[2] = { 1,0 };
	double tk = 0;
	double T = 1;


	//explicit_Euler_method(u,tk,T,0.001,0.1);
	//
	//cout << "\n\n\tImplicit Euler method 'Quasi-Optimal Strategy'..\n";
	//cout << setw(20) << "U1" << setw(20) << "U2" << setw(20) << "t" << endl;

	int size = 2;
	double* vectordF = new double[size];
	double* vectorU = new double[size] {1, 0};
	double* temp = new double[size];
	bool strategy = true;
	double t = 0;
	double tauMin = 0.01;
	double tauMax = 0.1;
	double eps = 0.001;
	bool type = false;
	//ImplicitEulerMethod(vectordF, vectorU, temp, size, t, T, tauMin, tauMax, eps, strategy, type);


	//cout << "\n\n\tImplicit Euler method 'Three Zone Strategy'..\n";
	//cout << setw(20) << "U1" << setw(20) << "U2" << setw(20) << "t" << endl;

	//strategy = false;
	//ImplicitEulerMethod(vectordF, vectorU, temp, size, t, T, tauMin, tauMax, eps, strategy, type);


	size = 3;
	vectordF = new double[size];
	vectorU = new double[size] {10, 22, 9};
	temp = new double[size];
	strategy = true;
	t = 0;
	tauMin = 0.01;
	tauMax = 0.1;
	eps = 0.001;
	type = true;
	strategy = false;
	cout << "\n\n\tImplicit Euler method 'Quasi-Optimal Strategy'..\n";
	cout << setw(20) << "U1" << setw(20) << "U2" << setw(20) << "t" << endl;
	ImplicitEulerMethod(vectordF, vectorU, temp, size, t, T, tauMin, tauMax, eps, strategy, type);

	strategy = true;
	cout << "\n\n\tImplicit Euler method 'Three Zone Strategy'..\n";
	cout << setw(20) << "U1" << setw(20) << "U2" << setw(20) << "t" << endl;
	ImplicitEulerMethod(vectordF, vectorU, temp, size, t, T, tauMin, tauMax, eps, strategy, type);
}