#include "Teacher.h"
#include <iostream>

Teacher::Teacher(string _name, vector<QuadricEquation>& tasks) : Human(_name) {
	SolveEquations(tasks, correctAnswers);
}

void Teacher::SolveEquations(vector<QuadricEquation>& tasks, list<Solution>& ans) {
	if (tasks.empty())
		return;

	Roots r;
	for (int i = 0; i < tasks.size(); i++) {
		r = tasks[i].FindRoots();
		ans.push_back(Solution(name, tasks[i], r));
	}
}

void Teacher::CheckAnswers() {
	//for correct answers
	for (auto ans = answers.begin(); ans != answers.end();) {
		results[ans->name];
		for (auto res = correctAnswers.begin(); res != correctAnswers.end(); ++res) {
			if (res->task == ans->task) {
				if (res->answer == ans->answer) {
					results[ans->name] += 1;
				}
				auto temp = ans;
				++ans;
				answers.erase(temp);
				break;
			}
		}
	}
}

void Teacher::CrateTable() {
	cout << "   Преподаватель: " << name << "\n\n";
	cout << "    Студенты:\t\t  Баллы:\n";
	for (auto i = results.begin(); i != results.end(); ++i) {
		cout << i->first << "\t\t|   " << i->second << endl;
	}
}