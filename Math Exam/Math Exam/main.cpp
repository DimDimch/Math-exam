#include <iostream>
#include "Teacher.h"
#include "Student.h"
#include <clocale>
#include <vector>
#include <ctime>
#pragma warning(disable:4996)

#define MAX_TASK_COUNT 100

void ReadEaquations(vector<QuadricEquation>& tasks, FILE* fp) {
	double a, b, c;
	int check = 0;
	do {
		check = fscanf(fp, "%lf %lf %lf\n", &a, &b, &c);
		if (check == -1)
			break;
		tasks.push_back(QuadricEquation(a, b, c));
	} while (1);
}

int main() {
	setlocale(LC_ALL, "Russian");
	
	//srand(time(NULL));

	vector<QuadricEquation> tasks;
	FILE* fp = fopen("tasks.txt", "r");
	
	ReadEaquations(tasks, fp);
	Teacher teacher("Халидов И.А.", tasks);

	vector<string> students = { 
		"Чекашев Сергей", 
		"Алексеенко Егор", 
		"Егорова Катя", 
		"Турченко Олег", 
		"Коноров Кирилл", 
		"Ним Ашас", 
		"Багет Афанасий" 
	};

	for (int i = 0; i < students.size(); i++) {
		string name = students[i];
		switch (rand() % 3) {
		case 0: {
			GoodStudent student(name);
			student.SolveEquations(tasks, teacher.answers);
			break;
		}
		case 1: {
			NormalStudent student(name);
			student.SolveEquations(tasks, teacher.answers);
			break;
		}
		case 2: {
			BadStudent student(name);
			student.SolveEquations(tasks, teacher.answers);
			break;
		}
		}
	}

	teacher.CheckAnswers();
	teacher.CrateTable();
	
	return 0;
}