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

class SquareScores {

public:

	double exp(double a, int b) {
		double res = 1.0;
		while (b > 0) {
			if (b&1)
				res *= a;
			a *= a;
			b >>= 1;
		}
		return res;
	}

	double calcexpectation(vector <int> p, string s) {
		int N = (int)s.size();
		double ans = N;
		while (p.size() < 26)
			p.push_back(0);

		for (int len=2; len<=N; ++len) {
			map<char, int> m;
			for (int i=0; i+len<=N; ++i) {
				if (i == 0) {
					for (int j=0; j<len; ++j)
						m[s[j]]++;
				} else {
					if (m[s[i-1]] != 1)
						m[s[i-1]]--;
					else
						m.erase(s[i-1]);
					m[s[i+len-1]]++;
				}

				if (m.size() > 2)
					continue;

				if (m.count('?')) {
					if (m.size() == 1) {
						for (double r: p)
							ans += exp(r/100.0, m['?']);
					} else {
						char ch = 'a';
						for (auto cnt: m)
							if (cnt.first != '?')
								ch = cnt.first;

						double res = 1.0;
						for (int j=0; j<m['?']; ++j)
							res *= ( (double)p[ch-'a'] / 100.0 );
						ans += res;
					}
				} else if (m.size() == 1) {
					ans++;
				}
			}
		}
		return ans;
	}


	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 99}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aaaba"; double Arg2 = 8.0; verify_case(0, Arg2, calcexpectation(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {10, 20, 70}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aa?bbbb"; double Arg2 = 15.0; verify_case(1, Arg2, calcexpectation(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {10, 20, 30, 40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "a??c?dc?b"; double Arg2 = 11.117; verify_case(2, Arg2, calcexpectation(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {25, 25, 21, 2, 2, 25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "a??b???????ff??e"; double Arg2 = 21.68512690712425; verify_case(3, Arg2, calcexpectation(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "??????????????????????????????"; double Arg2 = 31.16931963781721; verify_case(4, Arg2, calcexpectation(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {4, 3, 4, 3, 8, 2, 4, 3, 4, 4, 3, 2, 4, 4, 3, 4, 2, 4, 7, 6, 4, 4, 3, 4, 4, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "makigotapresentfromniko"; double Arg2 = 23.0; verify_case(5, Arg2, calcexpectation(Arg0, Arg1)); }

	// END CUT HERE


};



// BEGIN CUT HERE

int main() {

	SquareScores ___test;

	___test.run_test(-1);

}

// END CUT HERE
