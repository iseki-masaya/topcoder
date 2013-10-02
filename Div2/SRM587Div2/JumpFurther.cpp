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

class JumpFurther {
	
public:
	
	int furthest(int N, int badStep)
	{
		int ans = 0;
		for (int i=1; i<=N; ++i) {
			if (ans+i==badStep) {
				ans += i-1;
			}
			else {
				ans += i;
			}
		}
		return ans;
	}
	
	
	
	
};





// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
