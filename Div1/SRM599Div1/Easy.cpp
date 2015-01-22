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
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <bitset>
#include <deque>
#include <memory>

const long long LINF = (5e18);
const int INF = (1<<30);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class BigFatInteger {
	
public:
	
	int clog(long long c) {
		int res = 0;
		long long t = 1;
		while (c > t) {
			t <<= 1;
			++res;
		}
		return res;
	}
	
	map<int, int> decomp(int n) {
		map<int, int> res;
		for (int i=2; i<=n; ++i) {
			while (n%i==0) {
				res[i]++;
				n /= i;
			}
		}
		return res;
	}
	
	int minOperations(int A, int B) {
		map<int, int> d(decomp(A));
		int mx = 0;
		for (auto p: d)
			mx = max(mx, p.second);
		return (int)d.size() + clog((long long)mx*B);
	}
	
	
	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, minOperations(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 162; int Arg1 = 1; int Arg2 = 4; verify_case(1, Arg2, minOperations(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 999983; int Arg1 = 9; int Arg2 = 5; verify_case(2, Arg2, minOperations(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 360; int Arg1 = 8; int Arg2 = 8; verify_case(3, Arg2, minOperations(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 16384; int Arg1 = 599186; int Arg2 = 24; verify_case(4, Arg2, minOperations(Arg0, Arg1)); }
	
	// END CUT HERE
	
	
};



// BEGIN CUT HERE

int main() {
	
	BigFatInteger ___test;
	
	___test.run_test(-1);
	
}

// END CUT HERE
