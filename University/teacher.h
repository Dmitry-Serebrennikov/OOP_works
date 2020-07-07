#ifndef TEACHER_H_INCLUDED
#define TEACHER_H_INCLUDED

#include <string>
#include "human.h"

using namespace std;

class Teacher : public Human {
	public:
		Teacher(string last_name, string name, string second_name, string position,
			string subject_name, unsigned int work_experience, unsigned int work_time);

		string get_position();
		string get_subject_name();
		unsigned int get_work_experience();
		unsigned int get_work_time();

	private:
		string position; 
		string subject_name;
		unsigned int work_experience;
		unsigned int work_time;
};
#endif