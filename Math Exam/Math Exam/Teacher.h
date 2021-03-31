#pragma once
#include "QuadricEquation.h"
#include "Human.h"
#include <map>

class Teacher : public Human {
private:
	list<Solution> correctAnswers;
	map<string, int> results;
public:
	list <Solution> answers;
	Teacher(string _name, vector<QuadricEquation>& tasks);
	void SolveEquations(vector<QuadricEquation>& tasks, list<Solution>& ans);
	void CheckAnswers();
	void CrateTable();
};
