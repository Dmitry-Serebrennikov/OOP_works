#include <iostream>
#include <string>
#include "Polynom.h"

using namespace std;

Polynom::Polynom() {
	degree = 0;
	coeff.push_back(0);
}

Polynom::Polynom(int dg) {
	degree = dg;
	for (int i = 0; i <= dg; i++) {
		coeff.push_back(0);
	}
}
Polynom::Polynom(int dg, const vector<double> & cf) {
	degree = dg;
	coeff = * new vector<double>(0);
	/*if (cf.size() > 0) { */
		for (int i = 0; i <= degree; i++) {
			coeff.push_back(cf[i]);
		}
	/*} else {
		coeff.push_back(0);
	}*/
}

Polynom::Polynom(const Polynom& p) {
	degree = p.degree;
	coeff = * new vector<double>(0);
	for (int i = 0; i <= degree; i++) {
		coeff.push_back(p.coeff[i]);
	}
}

void Polynom::reduce() {
	//for (; coeff[degree] == 0 && degree != 0; degree--) {};
}

int Polynom::getDegree() {
	return degree;
}

double Polynom::getCoeff(int dg) {
	if (dg <= degree) {
		return coeff[dg];
	}
	else
		return 0.0;
}

//Polynom& Polynom::operator = (Polynom& p) {
//	Polynom * result = new Polynom(p.coeff.size() + 1, p.coeff);
//	return *result;
//	/*degree = p.degree;
//	for (int i = 0; i <= degree; i++) {
//		coeff[i] = p.coeff[i];
//	}*/
//
//}

Polynom& Polynom::operator + (const  Polynom& p) const {
	if (degree >= p.degree) { //I >= II
		Polynom * Z = new Polynom(*this);
		for (int i = 0; i <= degree; i++) {
			Z->coeff[i] = coeff[i] + ((i < p.coeff.size()) ? p.coeff[i] : 0);
		}
		Z->reduce();
		return *Z;
	}
	else { // I < II
		Polynom * Z = new Polynom(p);
		for (int i = 0; i <= p.degree; i++) {
			Z->coeff[i] = p.coeff[i] + ((i < coeff.size()) ? coeff[i] : 0);
		}
		Z->reduce();
		return *Z;
	}
}

Polynom& Polynom::operator - (const Polynom& p) const {
	if (degree >= p.degree) {
		Polynom * Z = new Polynom(*this);
		for (int i = 0; i <= degree; i++) {
			Z->coeff[i] = coeff[i] - ((i < p.coeff.size()) ? p.coeff[i] : 0);
		}
		Z->reduce();
		return *Z;
	}
	else {
		Polynom * Z = new Polynom(p);
		for (int i = 0; i <= p.degree; i++) {
			Z->coeff[i] = p.coeff[i] - ((i < coeff.size()) ? coeff[i] : 0);
		}
		Z->reduce();
		return *Z;
	}
}
Polynom& Polynom::operator * (const Polynom& p) const {
	Polynom * Z = new Polynom(degree + p.degree);
	for (int i = 0; i <= degree; i++) {
		for (int j = 0; j <= p.degree; j++) {
			Z->coeff[i + j] += coeff[i] * p.coeff[j];
		}
	}
	//Z->reduce();
	return *Z;
}
//Polynom& Polynom::operator * (const Polynom& p) const {
//	Polynom Z(degree + p.degree);
//	for (int i = 0; i < degree; i++) {
//		for (int j = 0; i < p.degree; j++) {
//			Z.coeff[i + j] += coeff[i] * p.coeff[j];
//		}
//	}
//	return Z;
//}

Polynom& Polynom::operator * (double cf) const {
	/*Polynom& p = * new Polynom(*this);*/
	Polynom& p = *new Polynom(*this);
	for (int i = 0; i <= degree; i++) {
		p.coeff[i] = p.coeff[i] * cf;
	}
	return p;
}
Polynom& Polynom::increase(int dg) const {
	vector<double> v = coeff;
	for (int i = 0; i < dg; i++) {
		v.insert(v.begin(), 0);
	}
	Polynom & p = * new Polynom(degree + dg, v);
	return p;
}
Polynom& Polynom::operator / (const Polynom& p) const {
	//Polynom ostatok = *this;
	Polynom& ostatok = *(new Polynom(*this));

	//Polynom check = p.increase(i - p.degree);
	vector<double> result;
	double c;
	int delta = ostatok.degree - p.degree;
	if (delta < 0) {
		//return ostatok;
		//cout << ostatok;
		return ostatok;
	}
	else {
		for (int i = degree; i >= p.degree; i--) {
			c = ostatok.coeff[i] / p.coeff[p.degree];
			Polynom tmp = p.increase(i - p.degree);
			Polynom tmp2 = tmp * c;
			//cout << ostatok << "  ----> " << tmp << endl;
			//cout << ostatok - tmp2 << endl;
			//ostatok = ostatok - tmp2;
			//ostatok = ostatok - p.increase(i - p.degree) * c;
			result.insert(result.begin(), c);
			//result = ostatok.coeff[] / p.coeff[];
		}
		Polynom& r = *(new Polynom(result.size() - 1, result));
		return r;
	}
}
//Polynom Polynom::operator / (const Polynom& p) {
//	
//}

//Polynom Polynom::operator / (const Polynom& p) {
//		Polynom temp = *this;
//		int rdeg = temp.degree - p.degree + 1;
//		Polynom res(rdeg);
//		for (int i = 0; i < rdeg; i++) {
//			res.coeff[rdeg - i - 1] = temp.coeff[temp.degree - i - 1] / p.coeff[p.degree - 1];
//			for (int j = 0; j < p.degree; j++) {
//				temp.coeff[temp.degree - j - i - 1] -= p.coeff[p.degree - j - 1] * res.coeff[rdeg - i - 1];
//			}
//		}
//		temp.reduce();
//		if (temp.degree != 0) {
//			cout << "!!! имеется остаток от деления " << temp << endl;
//		}
//		return res;
//	}
//аргумент
Polynom Polynom::operator () (int x) {
	int sum = 0;
	for (int i = 0; i <= degree; i++) {
		sum += pow(x, i) * coeff[i];
	}
	return sum;
}


Polynom Polynom::derivative() {
	if (degree == 0) {
		return Polynom(0);
	}
	else {
		Polynom* Z = new Polynom(degree - 1);
		//Polynom Z(degree - 1);
		for (int i = 1; i <= degree; i++) { 
			Z->coeff[i-1] = coeff[i] * i; //!!!
		}
		return *Z;
	}
}

//Polynom Polynom::derivative() {
//	if (degree == 0) {
//		return Polynom(0);
//	}
//	else {
//		//Polynom* Z = new Polynom(degree - 1);
//		Polynom Z(degree - 1);
//		for (int i = 0; i < degree; i++) {
//			Z.coeff[i] = coeff[i - 1] * i; //!!!
//		}
//		return Z;
//	}
//}
Polynom Polynom::integral() {
	Polynom P(degree + 1);
	for (int i = 1; i <= degree + 1; i++) {
		P.coeff[i] = (coeff[i - 1]) / i;
	}
	P.coeff[0] = 0;
	return P;
}

//istream& operator>>(istream& s, Polynom& c)// перегруженный оператор ввода
//{
//	int i;
//	for (i = 0; i <= c.n; i++)
//	{
//		s >> c.koef[i];
//	}
//	return s;
//}

istream& operator >> (istream& in, Polynom& p) {
	//int  dg;
	//in >> dg;
	in >> p.degree;
	p.coeff = *new vector <double>(p.degree + 1);
	//*coeff = *new vector<double>(0);
	//vector <double> cf = *new vector<double>(0);
	//Polynom Z(dg, <double> cf);
	for (int i = 0; i <= p.degree; i++) {
 		in >> p.coeff[i];
	}
	/*for (int i = 0; i <= p.degree; i++) {
		in >> p.coeff[i];
	}*/
	return in;
}
//istream& operator >> (istream& in, Polynom& p) {
//	int n;
//	in >> n;
//	/*p = *(new Polynom(n));
//	for (int i = 0; i <= p.degree; i++) {		
//		in >> p.coeff[i];
//	}*/
//	return in;
//}

ostream& operator << (ostream& out, const Polynom& p) {
	for (int i = p.degree; i >= 0; i--) {
		out << ((i == p.degree) ? ((p.coeff[i] < 0) ? "-" : "") : ((p.coeff[i] < 0) ? " - " : " + "));
		if (i != 0 && p.coeff[i] != 1) {
			out << p.coeff[i];
		}
		out << ((i != 0) ? "x^" : "");
		if (i != 0) {
			out << i;
		} else {
			out << p.coeff[i];
		}
	}
	out << endl;
	// int degree = 0;
	// for (int i = 0; i <= p.degree; i++) {
	// 	if (p.coeff[i] != 0) {
	// 		degree++;
	// 	}
	// }
	// if (degree != 0) {
	// 	if (p.coeff[0] != 0) {
	// 		out << p.coeff[0];
	// 	}
	// 	for (int i = 1; i <= p.degree; i++) {
	// 		if (p.coeff[i] < 0) {
	// 			if (p.coeff[i] != -1)
	// 				out << p.coeff[i] << "X^" << i;
	// 			else
	// 				out << "-" << "X^" << i;	
				
	// 		}
	// 		else {
	// 			if (p.coeff[i] != 0) {
	// 				if (p.coeff[i] != 1)
	// 					out << "+" << p.coeff[i] << "X^" << i;
	// 				else
	// 					out << "+ X^" << i;
	// 			}

	// 		}
	// 	}
	// 	out << '\n';
	// }
	// else {
	// 	out << 0;
	// }
	return out;
}

