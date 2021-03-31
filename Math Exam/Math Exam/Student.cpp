#include "Student.h"

using namespace std;

void GoodStudent::SolveEquations(vector<QuadricEquation>& tasks, list<Solution>& ans) {
	if (tasks.empty())
		return;

	Roots r;

	for (int i = 0; i < tasks.size(); i++) {
		r = tasks[i].FindRoots();

		Solution s(name, tasks[i], r);
		ans.push_back(s);
	}
}

void NormalStudent::SolveEquations(vector<QuadricEquation>& tasks, list<Solution>& ans) {
	if (tasks.empty())
		return;

	int chance = 63; //persent of correct answers
	Roots r;

	for (int i = 0; i < tasks.size(); i++) {
		if ((rand() % 100) < chance)
			r = tasks[i].FindRoots();
		else
			r = { 2, 0, 1 };

		Solution s(name, tasks[i], r);
		ans.push_back(s);
	}
}

void BadStudent::SolveEquations(vector<QuadricEquation>& tasks, list<Solution>& ans) {
	if (tasks.empty())
		return;

	Roots r;

	for (int i = 0; i < tasks.size(); i++) {
		r = { 1, 0, 0 };

		Solution s(name, tasks[i], r);
		ans.push_back(s);
	}
}