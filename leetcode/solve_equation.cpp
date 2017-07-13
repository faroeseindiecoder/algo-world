#include<iostream>
#include<string>
#include<cassert>
using namespace std;


pair<int, int> reduceLinearEquation(string formula) {
	int sumCoeffX = 0, sumRest = 0;
	string term;

	for (int i = 0; i < formula.length(); i++) {
		while (i < formula.length() && formula[i] != '+' && formula[i] != '-') {
			term += formula[i];
			i++;
		}
		if (term.find('x') != string::npos) {
			term.pop_back();
			if (term == "" || term == "+") {
				sumCoeffX += 1;
			} else if (term == "-") {
				sumCoeffX -= 1;
			} else {
				sumCoeffX += atoi(term.c_str());
			}
		} else {
			sumRest += atoi(term.c_str());
		}
		
		term = formula[i];
	}
	
	return make_pair(sumCoeffX, sumRest);
}

string solveEquation(string equation) {
	size_t delimPos = equation.find('=');
	string lhs = equation.substr(0, delimPos);
	string rhs = equation.substr(delimPos + 1);
	
	pair<int, int> lhsReducedTerms = reduceLinearEquation(lhs);
	pair<int, int> rhsReducedTerms = reduceLinearEquation(rhs);
	
	if (lhsReducedTerms.first == rhsReducedTerms.first) {
		if (lhsReducedTerms.second == rhsReducedTerms.second) {
			return "Infinite solutions";
		} else {
			return "No solution";
		}
	} 
	
	if (lhsReducedTerms.second == rhsReducedTerms.second) {
		return "x=0";
	}
	
	int xCoeff = lhsReducedTerms.first - rhsReducedTerms.first;
	int rest = rhsReducedTerms.second - lhsReducedTerms.second;
	return "x=" + to_string(rest/xCoeff);

}

int main() {
	assert(solveEquation("x+5-3+x=6+x-2") == "x=2");
	assert(solveEquation("x=x") == "Infinite solutions");
	assert(solveEquation("2x=x") == "x=0");
	assert(solveEquation("2x+3x-6x=x+2") == "x=-1");
	assert(solveEquation("x=x+2") == "No solution");
}
