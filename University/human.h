#ifndef HUMAN_H_INCLUDED
#define HUMAN_H_INCLUDED

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Human {
	public:
		Human(string last_name, string name, string second_name);

		string get_full_name();
	
	private:
		string name;
		string second_name;
		string last_name;
};


#endif
