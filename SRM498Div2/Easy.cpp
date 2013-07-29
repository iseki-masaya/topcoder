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

using namespace std;

class AdditionGame {
public:
  int
	getMaximumPoints(int A, int B, int C, int N)
	{
		priority_queue<int> pq;
		pq.push(A),pq.push(B),pq.push(C);
		int ans = 0;
		for (int i=0; i<N; ++i) {
			if(pq.top()>=1) {
				int p = pq.top();
				pq.pop();
				ans += p;
				pq.push(p-1);
			}
		}

		return ans;
	}
};