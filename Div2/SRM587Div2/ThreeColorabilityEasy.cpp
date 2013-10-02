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

class ThreeColorabilityEasy {
	
public:
	
	bool
	isOk(char lt,char rt,char ld,char rd)
	{
		int nz=0;
		nz += lt=='Z'?1:0;
		nz += rt=='Z'?1:0;
		nz += ld=='Z'?1:0;
		nz += rd=='Z'?1:0;
		return (nz&1)==1?false:true;
	}
	
	string isColorable(vector <string> cells)
	{
		if (cells.size()<2 || cells[0].size()<2) {
			return "Yes";
		}
		
		for (int y=1; y<cells.size(); ++y) {
			for (int x=1; x<cells[0].size(); ++x) {
				if (!isOk(cells[y-1][x-1], cells[y-1][x], cells[y][x-1], cells[y][x])) {
					return "No";
				}
			}
		}
		
		return "Yes";
	}
	
	
	
	
};





// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
