#include"Functions.h"

void main() {
	setlocale(LC_ALL,"ru");
	cout << "Все работает норм. Кчау" << endl;
	
	double u[2] = { 1,0 };
	double tk = 0;
	double T = 1;

	explicit_Euler_method(u,tk,T,0.001,0.1);

	cout << "погнали пробовать сделать неявный метод" << endl;

	////инициализирую переменные из пункта 2
	//double tk = 0;
	//double T = 1;
	//double u[3] = { 10,22,9 };
	//double eps = 0.00001;
	//double taumin = 0.01;
	//double taumax = 0.05;

	////начнем со значений
	//tk = 0;
	//double vector_Yk[3];
	//for (int i = 0; i < 3; i++) {
	//	vector_Yk[i] = u[i];
	//}
	//double vector_Yk_prev[3];
	//for (int i = 0; i < 3; i++) {
	//	vector_Yk_prev[i] = u[i];
	//}
	//double vector_Yk_next[3];
	//for (int i = 0; i < 3; i++) {
	//	vector_Yk_next[i] = u[i];
	//}
	//double tau_prev, tau;
	//tau_prev = tau = taumin;

	////вычисляем следующий tk
	//find_tk(&tk, tau);

	////массив Л1, Л2, Л3
	//double x[3];


}