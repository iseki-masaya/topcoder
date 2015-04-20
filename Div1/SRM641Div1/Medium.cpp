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
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <cstdio>
//#include <cstdlib>
#include <cstring>
#include <numeric>
#include <bitset>
#include <deque>
#include <memory>

const long long LINF = (5e17);
const int INF = 1000000000;
#define EPS 1e-7
const int MOD = 1000000007;

using namespace std;

class ShufflingCardsDiv1 {

public:

	int shuffle(vector <int> permutation) {
		vector<int> ref(permutation);
		sort(ref.begin(), ref.end());
		if (ref == permutation)
			return 0;
		int N = (int)permutation.size() / 2;
		int bB = 0;
		for (int i=0; i<2*N; i+=2)
			if (permutation[i] <= N)
				++bB;
		if (bB == N)
			return 1;
		if (bB == (N+1)/2)
			return 2;
		if (N&1 && bB==0)
			return 4;
		return 3;
	}


	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, shuffle(Arg0)); }
	void test_case_1() { int Arr0[] = {1,4,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, shuffle(Arg0)); }
	void test_case_2() { int Arr0[] = {6,3,5,2,4,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, shuffle(Arg0)); }
	void test_case_3() { int Arr0[] = {8,5,4,9,1,7,6,10,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, shuffle(Arg0)); }
	void test_case_4() { int Arr0[] = {9,1,7,2,10,3,6,4,8,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, shuffle(Arg0)); }

	// END CUT HERE


};



// BEGIN CUT HERE

int main() {

	ShufflingCardsDiv1 ___test;

	___test.run_test(-1);

}

// END CUT HERE
