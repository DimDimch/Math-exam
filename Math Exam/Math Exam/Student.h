#pragma once
#include "QuadricEquation.h"
#include "Human.h"

class GoodStudent : public Human {
public:
	GoodStudent(string _name) : Human(_name) {}
	void SolveEquations(vector<QuadricEquation>& tasks, list<Solution>& ans);
};

class NormalStudent : public Human {
public:
	NormalStudent(string _name) : Human(_name) {}
	void SolveEquations(vector<QuadricEquation>& tasks, list<Solution>& ans);
};

class BadStudent : public Human {
public:
	BadStudent(string _name) : Human(_name) {}
	void SolveEquations(vector<QuadricEquation>& tasks, list<Solution>& ans);
};