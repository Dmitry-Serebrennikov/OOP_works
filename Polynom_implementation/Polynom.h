#ifndef POLYNOM_H_INCLUDED
#define POLYNOM_H_INCLUDED
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Polynom {
private:
	int degree;
	vector<double> coeff;
public:
	//конструкторы
	Polynom();
	Polynom(int dg);
	Polynom(int dg, const vector<double> & cf);
	//конструктор копирования
	Polynom(const Polynom& p);
	//получение степени полинома
	void reduce(void);
	int getDegree();
	double getCoeff(int dg);
	
	Polynom& operator + (const Polynom&) const;
	Polynom& operator - (const Polynom&) const;
	Polynom& operator * (const Polynom&) const;
	Polynom& operator / (const Polynom&) const;
	Polynom& increase(int) const;
	
	Polynom& operator * (double) const;
	Polynom& operator / (double) const;
	Polynom& operator += (Polynom&);
	Polynom& operator += (double);

	//оператор присваивания
	//Polynom& operator = (Polynom&);
	//вычисление значения многочлена для заданного аргумена
	Polynom operator () (int);
	//Polynom arg(int x); //
	//взятие производной произвольного порядка с получением нового объекта-многочлена
	Polynom derivative();
	//взятие интерргала
	Polynom integral();
	friend ostream& operator << (ostream&, const Polynom&);
	friend istream& operator >> (istream&, Polynom&);
};
#endif