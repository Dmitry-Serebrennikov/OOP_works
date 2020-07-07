#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
#define PI 3.14159 
#define E 2.71828

#include <iostream>
#include <cmath>

using namespace std;

class Complex {
private:
	double real, imag;

public:
	// конструкторы
	//Complex() {};
	Complex();
	Complex(double rl);
	Complex(double rl, double im);
	//конструктор копирования
	Complex(const Complex& c);
	//деструктор
	~Complex() {};
	//параметры комплексного числа
	double GetReal() const; //
	double GetImag() const; //
	// модуль
	double abs();
	// фаза (аргумент)
	double arg();
	// оператор присваивания
	Complex& operator = (Complex& c);
	// оператор +=
	Complex& operator += (Complex& c);
	// оператор сложения
	Complex operator + (const Complex& c);
	//оператор вычитания
	Complex operator - (const Complex& c);
	//оператор умножения
	Complex operator * (const Complex& c);
	//на вещественное число
	Complex operator * (const double& num);
	//оператор деления
	Complex operator / (const Complex& c);
	//оператор равенства
	bool operator == (const Complex& c);
	bool operator == (const double& num);
	//оператор неравенства
	bool operator != (const Complex& c);
	bool operator != (const double& num);
	//степень по формуле Муавра
	Complex exp(const double& num);
	//возведение комплексного числа в комплексную степень
	Complex exp(const Complex& c);
	friend ostream& operator << (ostream&, const Complex&);
	friend istream& operator >> (istream&, Complex&);
};

#endif