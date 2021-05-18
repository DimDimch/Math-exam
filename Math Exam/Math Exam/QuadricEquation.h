#pragma once
#include <string>
#include <list>
#include <vector>

using namespace std;

class Roots {
public:
	int count;
	double x1;
	double x2;
	friend bool operator==(const Roots& x, const Roots& y) {
		return x.count == y.count && x.x1 == y.x1 && x.x2 == y.x2;
	}
};

class QuadricEquation {
public:
	double a;
	double b;
	double c;
	QuadricEquation() {}
	QuadricEquation(double _a, double _b, double _c) {
		a = _a;
		b = _b;
		c = _c;
	}
	friend bool operator==(const QuadricEquation& x, const QuadricEquation& y) {
		return x.a == y.a && x.b == y.b && x.c == y.c;
	}
	Roots FindRoots() const;
private:
	double FindDiscriminant() const {
		return (a * b - 4.0 * a * c);
	}
};

class Solution {
public:
	string name;
	QuadricEquation task;
	Roots answer;
	Solution() {}
	Solution(string _name, QuadricEquation _task, Roots _answer) {
		name = _name;
		task = _task;
		answer = _answer;
	};
};
