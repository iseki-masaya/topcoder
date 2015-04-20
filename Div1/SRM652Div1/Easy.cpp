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

class ThePermutationGame {

public:

	map<int, int> decomp(int N) {
		map<int, int> res;
		for (int i=2; i<=N/i; ++i) {
			while (N%i == 0) {
				N /= i;
				res[i]++;
			}
		}
		if (N != 1)
			res[N]++;
		return res;
	}

	void calc(map<int, int> &m, int N) {
		map<int, int> fact(decomp(N));
		for (auto p: fact) {
			int v = p.first;
			m[v] = max(fact[v], m[v]);
		}
	}

	int findMin(int N) {
		map<int, int> ansm;
		for (int i=2; i<=N; ++i)
			calc(ansm, i);
		long long ans = 1;
		for (auto p: ansm)
			for (int i=0; i<p.second; ++i)
				ans = (ans * (long long)p.first)%MOD;

		return (int)ans;
	}


	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; verify_case(0, Arg1, findMin(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 6; verify_case(1, Arg1, findMin(Arg0)); }
	void test_case_2() { int Arg0 = 11; int Arg1 = 27720; verify_case(2, Arg1, findMin(Arg0)); }
	void test_case_3() { int Arg0 = 102; int Arg1 = 53580071; verify_case(3, Arg1, findMin(Arg0)); }
	void test_case_4() { int Arg0 = 9999; int Arg1 = 927702802; verify_case(4, Arg1, findMin(Arg0)); }

	// END CUT HERE


};



// BEGIN CUT HERE

int main() {

	ThePermutationGame ___test;

	___test.run_test(-1);

}

// END CUT HERE
