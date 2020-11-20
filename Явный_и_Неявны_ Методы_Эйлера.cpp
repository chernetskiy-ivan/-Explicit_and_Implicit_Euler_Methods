#include"Functions.h"

using namespace std;

void main() {
	setlocale(LC_ALL,"ru");
	cout << "Все работает норм. Кчау" << endl;
	
	double res[2];
	double u[2] = { 1,0 };
	double tmin;
	double tk = 0;
	double T = 1;

	cout << "Явный метод Эйлера" << endl;
	cout << "u1" << setw(25) << "u2" << setw(25) << "tk" << endl;
	while (tk < T) {

		Function(res, u);

		//for (int i = 0; i < 2; i++) {
		//	cout << res[i] << endl;
		//}
	
		tmin = findStep(res);
		/*cout << "Вычисленный шаг равен " << tmin << endl;*/

		//cout << "До шага" << endl;
		//for (int i = 0; i < 2; i++)
		//	cout << u[i] << endl;

		makeStep(res, u, tmin);

		//cout << "После шага" << endl;
		//for (int i = 0; i < 2; i++) {
		//	cout << u[i] << endl;
		//}

		find_tk(&tk, tmin);
		//cout << "следующий шаг: " << tk << endl;

		cout << u[0] << setw(25) << u[1] << setw(25) << tk << endl;

	}


}