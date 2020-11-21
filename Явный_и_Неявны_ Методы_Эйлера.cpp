#include"Functions.h"

void main() {
	setlocale(LC_ALL,"ru");
	cout << "Все работает норм. Кчау" << endl;
	
	double u[2] = { 1,0 };
	double tk = 0;
	double T = 1;

	explicit_Euler_method(u,tk,T,0.001,0.1);

}