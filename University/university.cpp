#include <iostream>
#include <locale.h>
#include <vector>

#include "human.h"
#include "student.h"
#include "teacher.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	
	unsigned int current_course = 2;
	vector<int> scores;
	scores.push_back(3);
	scores.push_back(4);
	scores.push_back(4);
	scores.push_back(5);
	scores.push_back(5);
	scores.push_back(5);
	scores.push_back(5);
	scores.push_back(5);
	scores.push_back(5);

	Student *stud = new Student("Риман", "Бернхард", "Алексеевич", "Фундаментальная математика", current_course, 
		"Неевклидова геометрия", scores);
	cout << typeid(Student).name() << endl;
	cout << stud->get_full_name() << endl;
	cout << "Название специальности: " << stud->get_speciality_name() << endl;
	cout << "Текущий курс: " << stud->get_current_course() << endl;
	cout << "Предмет: " << stud->get_subject_name() << endl;
	cout << "Средний балл: " << stud->get_average_score() << endl;
	cout << endl;
	
	unsigned int teacher_work_experience = 40;
	unsigned int teacher_work_time = 40;
	
	Teacher *tch = new Teacher("Гаусс", "Карл Фридрих", "Сергеевич", "Профессор, доктор наук", 
		"Теория чисел", teacher_work_experience, teacher_work_time);
	cout << typeid(Teacher).name() << endl;
	cout << tch->get_full_name() << endl;
	cout << "Должность/ученая степень: " << tch->get_position() << endl;
	cout << "Предмет: " << tch->get_subject_name() << endl;
	cout << "Преподавательский стаж в годах: " << tch->get_work_experience() << endl;
	cout << "Количество часов в неделю: " << tch->get_work_time() << endl;

	return 0;
}
