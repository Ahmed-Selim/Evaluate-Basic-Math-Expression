/*
 * Solution.h
 *
 *  Created on: Sep 10, 2017
 *      Author: Administrator
 */

#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std ;

class Solution {
private:
	stack<char> Ops ; // Operators
	stack<double> Value ;
	string postfix = "" ;

public:
	int isOperator (char) ;
	double Operation (char,double,double) ;
	void Convert (string) ;
	void Solve (string) ;
};

#endif /* SOLUTION_H_ */
