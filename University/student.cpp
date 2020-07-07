#include <iostream>
#include "student.h"

Student::Student(string last_name, string name, string second_name, string speciality_name, 
	unsigned int current_course, string subject_name, vector<int> scores) : Human(
	last_name, name, second_name) {
	this->speciality_name = speciality_name;
	this->current_course = current_course;
	this->subject_name = subject_name;
	this->scores = scores;
}

string Student::get_speciality_name() {
	return this->speciality_name;
}
string Student::get_subject_name() {
	return this->subject_name;
}

unsigned int Student::get_current_course() {
	return this->current_course;
}

float Student::get_average_score() {
	unsigned int count_scores = this->scores.size();
	unsigned int sum_scores = 0;
	float average_score;

	for (unsigned int i = 0; i < count_scores; ++i) {
		sum_scores += this->scores[i];
	}

	average_score = (float)sum_scores / (float)count_scores;
	return average_score;
}