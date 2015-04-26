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

class TheKingsArmyDiv1 {

public:

	int getNumber(vector <string> state) {
		int N = (int)state[0].size();
		vector<string> diffs;
		int countHH = 0, countSS = 0;
		for (int i=0; i<N; ++i)	 {
			if (state[0][i] == 'S' && state[1][i] == 'S')
				++countSS;
			else if (state[0][i] == 'S')
				diffs.push_back("SH");
			else if (state[1][i] == 'S')
				diffs.push_back("HS");
			else
				++countHH;
		}
		if (countSS == N)
			return -1;
		else if (countHH == N)
			return 0;
		else if (diffs.size() == 0)
			return countSS;
		int c = 0;
		for (int i=1; i<diffs.size(); ++i)
			if (diffs[i] != diffs[i-1])
				++c;
		return countSS + (c + 1)/2 + 1;
	}


	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"HSH",
		"SHS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { string Arr0[] = {"HH",
		"HH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { string Arr0[] = {"HHHHH",
		"HSHSH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { string Arr0[] = {"S",
		"S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { string Arr0[] = {"HSHHSHSHSHHHSHSHSH",
		"SSSSHSSHSHSHHSSSSH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(4, Arg1, getNumber(Arg0)); }
	void test_case_5() { string Arr0[] = {"HS",
		"HS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(5, Arg1, getNumber(Arg0)); }
	void test_case_6() { string Arr0[] = {"HHHSHSHSHSSSSSS",
		"HSSSSSHHSSHHHSS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(6, Arg1, getNumber(Arg0)); }


	// END CUT HERE


};



// BEGIN CUT HERE

int main() {

	TheKingsArmyDiv1 ___test;

	___test.run_test(-1);

}

// END CUT HERE
