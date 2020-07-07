#include <iostream>
#include "teacher.h"
using namespace std;

Teacher::Teacher(string last_name, string name, string second_name, string position,
	string subject_name, unsigned int work_experience, unsigned int work_time) : Human(
		last_name, name, second_name) {
	this->position = position;
	this->subject_name = subject_name;
	this->work_experience = work_experience;
	this->work_time = work_time;
}

string Teacher::get_position() {
	return this->position;
}
string Teacher::get_subject_name() {
	return this->subject_name;
}
unsigned int Teacher::get_work_experience() {
	return this->work_experience;
}

unsigned int Teacher::get_work_time() {
	return this->work_time;
}