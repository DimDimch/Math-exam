#include "QuadricEquation.h"
#include <cmath>

Roots QuadricEquation::FindRoots()  const {
	double D = FindDiscriminant();
	Roots roots = { 0,0,0 };

	//special and linear cases
	if (a == 0.0) {
		if (b == 0.0 && c == 0.0)
			return roots;
		else  if (b == 0.0)
			return roots;
		else {
			roots.count = 1;
			roots.x1 = (-c / b);
			return roots;
		}
	}

	//general case
	if (D > 0) {
		roots.count = 2;
		roots.x1 = ((-b + sqrt(D)) / (2.0 * a));
		roots.x2 = ((-b - sqrt(D)) / (2.0 * a));
		if (roots.x1 > roots.x2) {
			double temp = roots.x2;
			roots.x2 = roots.x1;
			roots.x1 = temp;
		}
		return roots;
	}
	else if (D == 0) {
		roots.count = 1;
		roots.x1 = ((-b) / (2.0 * a));
		return roots;
	}
	else
		return roots;
}

