#include <iostream>
#include <locale.h>
#include <cmath>
#include "complex.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	Complex z1;
	Complex z2(5);
	Complex z3(3, 3);
	cout << "Пример вывода чисел в алг. форме комплекс. числа: z1 = " << z1 << "; z2 = " << z2 << "; z3 = " << z3 << endl;
	cout << "Основные операции: " << endl;
	Complex a1(5, 2), b1(3, -3);
	cout << "a = " << a1 << "; b = " << b1 << endl;
	a1 += b1;
	cout << "a += b: " << a1 << endl;
	Complex c1 = a1 + b1;
	cout << "c = a + b: " << c1 << endl;
	cout << "(" << a1 << ") - (" << b1 << ") = " << a1 - b1 << endl;
	cout << "(" << a1 << ") * (" << b1 << ") = " << a1 * b1 << endl;
	cout << "(" << a1 << ") / (" << b1 << ") = " << a1 / b1 << endl;
	cout << "(" << a1 << ") * 5 = " << a1 * 5 << endl;
	Complex z(3, 4);
	cout << "нахождение модуля z = 3 + 4i: " << z.abs() << endl;
	cout << "нахождение фазы (аргумента) того же числа z в радианах: "<< z.arg() << endl;
	
	cout << "взятие вещественной части из комплексного числа z: " << z.GetReal() << endl;
	cout << "взятие мнимой части из комплексного числа z: " << z.GetImag() << endl;

	cout << "возведение в целую степень числа z по формуле Муавра: " << z.exp(2) << endl;
	cout << "возведение в вещественную степень числа z: " << z.exp(2.5) << endl;
	Complex k(1, 2);
	cout << "возведение в комплексную степень k числа z: " << z.exp(k) << endl;
	cout << "----------------------------" << endl;
	cout << "Решение квадратного уравнения:" << endl;
	cout << "Введите коэффициенты a, b и c квадратного уравнения: " << endl;
	float a, b, c;
	cin >> a >> b >> c;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << endl;
	float d, d_sqrt;
	d = b * b - 4 * a * c;
	if (d > 0) {
		d_sqrt = sqrt(d);
		float x1 = (-b + d_sqrt) / (2 * a);
		float x2 = (-b - d_sqrt) / (2 * a);
		cout << "Решения: x1 = " << x1 << ", x2 = " << x2 << endl;
	}
	else if (d == 0) {
		float x = -b / (2 * a);
		cout << "Решение: x = " << x << endl;
	}
	else {
		d_sqrt = sqrt(-d);
		Complex x1(-b / (2 * a), d_sqrt / (2 * a));
		Complex x2(-b / (2 * a), -d_sqrt / (2 * a));
		cout << "Решения: x1 = " << x1 << ", x2 = " << x2 << endl;
	}
}
