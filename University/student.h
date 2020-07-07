#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <string>
#include <vector>
#include "human.h"

using namespace std;

class Student : public Human {
	public:
		Student(string last_name, string name, string second_name, string speciality_name, 
			unsigned int current_course, string subject_name, vector<int> scores);

		string get_speciality_name();
		string get_subject_name();
		unsigned int get_current_course();
		float get_average_score();

	private:
		string speciality_name;
		unsigned int current_course;
		string subject_name;
		vector<int> scores;
};
#endif