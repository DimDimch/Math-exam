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
	Teacher(string _name, const vector<QuadricEquation>& tasks);
	void SolveEquations(const vector<QuadricEquation>& tasks, list<Solution>& ans) override;
	void CheckAnswers();
	void CrateTable() const;
};

