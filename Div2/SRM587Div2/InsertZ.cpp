#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include <sstream>
#include <set>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <time.h>

using namespace std;

class InsertZ {
	
public:
	
	string
	canTransform(string init, string goal) {
		string nz;
		for (int i=0; i<goal.size(); ++i) {
			if (goal[i] != 'z') {
				nz.push_back(goal[i]);
			}
		}
		return init==nz?"Yes":"No";
	}
	
	
	
	
};





// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
