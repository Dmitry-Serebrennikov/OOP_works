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
	// ������������
	//Complex() {};
	Complex();
	Complex(double rl);
	Complex(double rl, double im);
	//����������� �����������
	Complex(const Complex& c);
	//����������
	~Complex() {};
	//��������� ������������ �����
	double GetReal() const; //
	double GetImag() const; //
	// ������
	double abs();
	// ���� (��������)
	double arg();
	// �������� ������������
	Complex& operator = (Complex& c);
	// �������� +=
	Complex& operator += (Complex& c);
	// �������� ��������
	Complex operator + (const Complex& c);
	//�������� ���������
	Complex operator - (const Complex& c);
	//�������� ���������
	Complex operator * (const Complex& c);
	//�� ������������ �����
	Complex operator * (const double& num);
	//�������� �������
	Complex operator / (const Complex& c);
	//�������� ���������
	bool operator == (const Complex& c);
	bool operator == (const double& num);
	//�������� �����������
	bool operator != (const Complex& c);
	bool operator != (const double& num);
	//������� �� ������� ������
	Complex exp(const double& num);
	//���������� ������������ ����� � ����������� �������
	Complex exp(const Complex& c);
	friend ostream& operator << (ostream&, const Complex&);
	friend istream& operator >> (istream&, Complex&);
};

#endif