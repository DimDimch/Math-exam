#include "Teacher.h"
#include <iostream>

Teacher::Teacher(string _name, const vector<QuadricEquation>& tasks) : Human(_name) {
	SolveEquations(tasks, correctAnswers);
}

void Teacher::SolveEquations(const vector<QuadricEquation>& tasks, list<Solution>& ans) {
	if (tasks.empty())
		return;

	Roots r;
	for (int i = 0; i < tasks.size(); i++) {
		r = tasks[i].FindRoots();
		ans.push_back(Solution(name, tasks[i], r));
	}
}

bool CheckCurAnswer(const list<Solution>& correctAnswers, const Solution& ans) {
	for (auto res = correctAnswers.begin(); res != correctAnswers.end(); ++res) {
		if (res->task == ans.task) {
			if (res->answer == ans.answer) {
				return true;
			}
			return false;
		}
	}
	return false;
}
void Teacher::CheckAnswers() {
	bool check;
	for (auto ans = answers.begin(); ans != answers.end();) {
		results[ans->name];
		check = CheckCurAnswer(correctAnswers, *ans);
		if (check == true) {
			results[ans->name] += 1;
		}
		auto temp = ans;
		++ans;
		answers.erase(temp);
	}
}

void Teacher::CrateTable() const {
	cout << "   Преподаватель: " << name << "\n\n";
	cout << "    Студенты:\t\t  Баллы:\n";
	for (auto i = results.begin(); i != results.end(); ++i) {
		cout << i->first << "\t\t|   " << i->second << endl;
	}
}
