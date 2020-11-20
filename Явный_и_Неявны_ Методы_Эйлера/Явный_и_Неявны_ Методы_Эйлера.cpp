#include"Functions.h"

using namespace std;

double eps = 0.001;
double u[2] = { 1,0 };
int T = 1;
double tmax = 0.1;

void main() {
	setlocale(LC_ALL,"ru");
	cout << "Все работает норм. Кчау" << endl;
	
	double res[2];
	Function(res, u);

	for (int i = 0; i < 2; i++) {
		cout << res[i] << endl;
	}

}