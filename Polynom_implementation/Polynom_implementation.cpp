#include <iostream>
#include <locale.h>
#include <iomanip>
#include "Polynom.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	//vector<double> v;
	//Polynom p1(2, {1, 2, 1});
	////cout << p1;
	//Polynom p2(2, { 1, 2, 1});
	//Polynom p = p1 + p1;
	////cout << p;
	//Polynom p3 = p1 - p2;
	////cout << p3 << endl;
	////cout << p3.getDegree() << endl;
	//cout << p1 * p2 << endl; 
	//Polynom p4 = p1 * p2;
	////cout << p4 << endl;
	//Polynom p6(2, {5, 0, 3});
	//Polynom p5(1, {1 , 2});
	//Polynom p7 = p5 * p6;
	////cout << p7 << endl;
	/*Polynom p9 = p7.increase(2);
	cout << p9 << endl;
	Polynom p10 = p7.increase(1);
	Polynom p11 = p7.increase(0);
	cout << p10 << endl;
	cout << p11 << endl;*/
	//Polynom p8 = p1 * p2 / p1;
	//cout << p8;

	Polynom p11 (2, { 2, 4, 2 });
	Polynom p12(1, { 1, 1 });
	//cout << p11 - p12.increase(1) * 2 - p12 * 2 << endl;
	//cout << p12 << endl;
	//cout << p12.increase(1) << endl;
	//cout << p12.increase(1) * 2 << endl;
	//cout << p11 - p12.increase(1) * 2 << endl;
	//cout << p12 * 2 << endl;
	//cout << p11 - p12.increase(1) * 2 - p12 * 2 << endl;
	//cout << p11 / p12 << endl;
	//Polynom p77  = p12 / p11;
	//cout << p77 << endl;
	//Polynom p88(2);
	//cin >> p88;
	//cout << p88;
	Polynom p99;
	cin >> p99;
	cout << p99;
	//cout << p12 / p11 << endl; //!!!!!
	//cout << p11.integral() << endl;
	//cout << p11.derivative() << endl;
	//p = p1 - p2;
	//cout << p << endl;

	
	/*Polynom()
	cin >> p;*/
	//cout << p;
}
