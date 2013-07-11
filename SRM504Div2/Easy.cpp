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

#define MAX 50000 // 5133
#define SIZE 10000
#define INF (1<<30)

using namespace std;

class ComparerInator {
public:
  int
	makeProgram(vector <int> A, vector <int> B, vector <int> wanted)
	{
		bool isA = true;
		for (int i=0; i<A.size(); ++i) {
			if (wanted[i] != A[i]) {
				isA = false;
				break;
			}
		}
		bool isB = true;
		for (int i=0; i<B.size(); ++i) {
			if (wanted[i] != B[i]) {
				isB = false;
				break;
			}
		}
		bool isAB = true;
		for (int i=0; i<A.size(); ++i) {
			int a = A[i]<B[i]?A[i]:B[i];
			if (wanted[i] != a) {
				isAB = false;
				break;
			}
		}
		bool isBA = true;
		for (int i=0; i<B.size(); ++i) {
			int a = A[i]<B[i]?B[i]:A[i];
			if (wanted[i] != a) {
				isBA = false;
				break;
			}
		}
		int ans = isBA||isAB?7:-1;
		ans = isA||isB?1:ans;
		return ans;
	}
};