#pragma once
#include "QuadricEquation.h"
#include "Human.h"

class GoodStudent : public Human {
public:
	GoodStudent(string _name) : Human(_name) {}
	void SolveEquations(const vector<QuadricEquation>& tasks, list<Solution>& ans) override;
};

class NormalStudent : public Human {
public:
	NormalStudent(string _name) : Human(_name) {}
	void SolveEquations(const vector<QuadricEquation>& tasks, list<Solution>& ans) override;
private:
	const int m_errorChance = 63;
};

class BadStudent : public Human {
public:
	BadStudent(string _name) : Human(_name) {}
	void SolveEquations(const vector<QuadricEquation>& tasks, list<Solution>& ans) override;
};
