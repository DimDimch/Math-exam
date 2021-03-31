#pragma once
#include "QuadricEquation.h"

class Human {
public:
	string name;
	Human(string _name) : name(_name) {}
	virtual void SolveEquations(vector<QuadricEquation>& tasks, list<Solution>& ans) = 0;
};