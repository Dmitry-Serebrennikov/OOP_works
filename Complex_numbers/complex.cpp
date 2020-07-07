#include <iostream>
#include <cmath>
#include "complex.h"
#define PI 3.14159 
#define E 2.71828

using namespace std;

Complex::Complex() {
	real = 0;
	imag = 0;
}
Complex::Complex(double rl) {
	real = rl;
	imag = 0;
}
Complex::Complex(double rl, double im) {
	real = rl;
	imag = im;
}
//конструктор копирования
Complex::Complex(const Complex& c) {
	real = c.real;
	imag = c.imag;
}
//параметры комплексного числа
double Complex::GetReal() const {
	return real;
}
double Complex::GetImag() const {
	return imag;
}
// модуль
double Complex::abs() {
	return sqrt(real * real + imag * imag);
}
// фаза (аргумент)
double Complex::arg() {
	return atan2(imag, real); //в градусах: *180 / PI;
}
// оператор присваивания
Complex& Complex::operator = (Complex& c) {
	real = c.real;
	imag = c.imag;
	return (*this);
}
// оператор +=
Complex& Complex::operator += (Complex& c) {
	real += c.real;
	imag += c.imag;
	return *this;
}
// оператор сложения
Complex Complex::operator + (const Complex& c) {
	return Complex(real + c.real, imag + c.imag);
}
//оператор вычитания
Complex Complex::operator - (const Complex& c) {
	return Complex(real - c.real, imag - c.imag);
}
//оператор умножения
Complex Complex::operator * (const Complex& c) {
	return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}
//на вещественное число
Complex Complex::operator * (const double& num) {
	return Complex(real * num, imag * num);
}
//оператор деления
Complex Complex::operator / (const Complex& c) {
	Complex tmp;
	double r = c.real * c.real + c.imag * c.imag;
	tmp.real = (real * c.real + imag * c.imag) / r;
	tmp.imag = (imag * c.real - real * c.imag) / r;
	return tmp;
}
//оператор равенства
bool Complex::operator == (const Complex& c) {
	return (real == c.real && imag == c.imag);
}
bool Complex::operator == (const double& num) {
	if (imag == 0)
		return (real == num);
	else
		return false;
}
//оператор неравенства
bool Complex::operator != (const Complex& c) {
	return !(real == c.real && imag == c.imag);
}
bool Complex::operator != (const double& num) {
	if (imag == 0)
		return (real != num);
	else
		return false;
}
//степень по формуле Муавра
Complex Complex::exp(const double& num) {
	Complex cpx;
	cpx.real = pow(sqrt(real * real + imag * imag), num) * cos(num * atan2(imag, real));
	cpx.imag = pow(sqrt(real * real + imag * imag), num) * sin(num * atan2(imag, real));
	return cpx;
}
//возведение комплексного числа в комплексную степень
Complex Complex::exp(const Complex& c) {
	Complex z2_stepen(c.real, c.imag);
	Complex stepen_vozved(log(sqrt(real * real + imag * imag)), atan2(real, imag));
	Complex z3_stepen = stepen_vozved * z2_stepen;
	Complex cpx(cos(z3_stepen.GetImag()), sin(z3_stepen.GetReal()));
	double result = pow(E, z3_stepen.GetReal());
	return cpx * result;
}

ostream& operator << (ostream& out, const Complex& c) {
	if (c.real == 0 && c.imag == 0)
		out << 0;
	else if (c.imag == 0)
		out << c.real;
	else
		out << c.real << ((c.imag > 0) ? " + " : " ") << c.imag << "i";
	return out;
}

istream& operator >> (istream& in, Complex& c) {
	in >> c.real >> c.imag;
	return in;
}