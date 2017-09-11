/*
 * Solution.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: Administrator
 */

#include "Solution.h"
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <sstream>

int Solution::isOperator (char s) {
	int Priority ;
	if (s == '^')
		Priority = 0 ;
	else if (s == '*' || s == '/')
		Priority = 1 ;
	else if (s == '+' || s == '-')
		Priority = 2 ;
	else if (s == '(')
		Priority = 3 ;
	else if (s == ')')
		Priority = 4 ;

	return Priority ;
}

double Solution::Operation (char o , double a , double b) {
	double ans = 0 ;
	switch(o){
	case '^':
		ans =  pow(a*1.0,b) ;		break;
	case '*':
		ans =  a*1.0*b ;		break;
	case '/':
		ans = a*1.0 / b ;		break;
	case '+':
		ans =  a*1.0+b ;		break;
	case '-':
		ans =  a*1.0-b ;		break;
	}
	return ans ;
}

void Solution::Convert (string exp) {  // infix expression
	for (unsigned int i = 0 ; i < exp.length() ; ++i){
		if (isdigit(exp[i])){
			postfix += exp[i] ;
		}
		else if (isOperator(exp[i]) == 3 || isOperator(exp[i]) == 0){
			Ops.push(exp[i]) ;
		}
		else if (isOperator(exp[i]) == 4){
			while (!Ops.empty() && Ops.top() != '('){
				postfix += Ops.top() ;
				Ops.pop();
			}
			Ops.pop() ;			// to consume (
		}
		else if (isOperator(exp[i]) == 2){    // Low Priority Operator
			while (!(Ops.empty() || Ops.top() == '(' )) {
				postfix += Ops.top() ;
				Ops.pop();
			}
		Ops.push(exp[i]);
		}
		else if (isOperator(exp[i]) == 1){	  // High Priority Operator
			while (!(Ops.empty() || Ops.top() == '('|| isOperator(Ops.top()) == 2)){
				postfix += Ops.top() ;
				Ops.pop();
			}
		Ops.push(exp[i]);
		}
	}

	while(!Ops.empty()){	// empty the stack
		postfix += Ops.top() ;
		Ops.pop();
	}

	cout << "postfix expression : " << postfix << endl ;
}

void Solution::Solve (string exp) {
	Convert(exp) ;
	double a , b ;
	stringstream ss ;
	for (unsigned int i = 0 ; i < postfix.length() ; ++i){
		if (isdigit(postfix[i])){
			ss.clear();
			ss << postfix[i] ;
			ss >> a ;
			Value.push(a) ;
		}
		else {
			b = Value.top() ;
			Value.pop();
			a = Value.top() ;
			Value.pop();
			Value.push(Operation(postfix[i], a, b)) ;
		}
	}
	cout << "result = " <<  Value.top() << endl ;
}
