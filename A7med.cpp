#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <sstream>
#include "Solution.h"

using namespace std;

int main()
{
	string infix ;
	while (getline(cin,infix)){
		Solution x ;
		cout << "infix expression : " << infix << endl ;
		infix.erase(remove(begin(infix),end(infix),' '),end(infix)) ;
		x.Solve(infix) ;
	}
	return 0;
}
