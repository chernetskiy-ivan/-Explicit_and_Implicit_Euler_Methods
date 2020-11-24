#include"Functions.h"

void main() {
	setlocale(LC_ALL,"ru");
	cout << "Все работает норм. Кчау" << endl;
	
	double u[2] = { 1,0 };
	double tk = 0;
	double T = 1;


	explicit_Euler_method(u,tk,T,0.001,0.1);

	cout << "погнали пробовать сделать неявный метод" << endl;
	
	cout << "\n\n\tImplicit Euler method 'Quasi-Optimal Strategy'..\n";
	cout << setw(20) << "U1" << setw(20) << "U2" << setw(20) << "t" << endl;

	int size = 2;
	double* vectordF = new double[size];
	double* vectorU = new double[size] {1, 0};
	double* temp = new double[size];
	bool strategy = true;
	double t = 0;
	double tauMin = 0.01;
	double tauMax = 0.1;
	double eps = 0.001;
	ImplicitEulerMethod(vectordF, vectorU, temp, size, t, T, tauMin, tauMax, eps, strategy);


	cout << "\n\n\tImplicit Euler method 'Three Zone Strategy'..\n";
	cout << setw(20) << "U1" << setw(20) << "U2" << setw(20) << "t" << endl;

	strategy = false;
	ImplicitEulerMethod(vectordF, vectorU, temp, size, t, T, tauMin, tauMax, eps, strategy);


	double res[3];
	double uw[3] = { 10,22,9 };

	Function_Two(res, uw);

	for (int i = 0; i < 3; i++)
		cout << res[i] << endl;

}