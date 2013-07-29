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

vector<int> prime;
vector<int> not_prime;
bool is_prime[1003];

class ColorfulCards {

public:
	void
	sieve(int n)
	{
		memset(is_prime, false, sizeof(is_prime));
		not_prime.clear();
		prime.clear();
		not_prime.push_back(1);
		for (int i=2; i<=n; ++i) {
			if (!is_prime[i]) {
				for (int j=i; j<=n; j+=i) {
					is_prime[j] = true;
				}
				prime.push_back(i);
			}
			else {
				not_prime.push_back(i);
			}
		}
	}

	int
	count(string s,char target)
	{
		int ret = 0;
		for (int i=0; i<s.size(); ++i) {
			if (s[i] == target) {
				++ret;
			}
		}
		return ret;
	}

	vector <int>
	theCards(int N, string colors)
	{
		sieve(N);
		vector<int> front(colors.size()),back(colors.size());

		int pnum = 0;
		while (true) {
			bool isOk = true;
			int prev = 0;
			int p = pnum;
			int b = 0;
			for (int i=0; i<colors.size(); ++i) {
				if (colors[i] == 'R') {
					while (prime[p]<=prev) ++p;
					if (p>=prime.size()) {
						isOk = false;
						break;
					}
					front[i] = prime[p];
					prev = front[i];
				}
				else {
					while (not_prime[b]<=prev) ++b;
					if (b>=not_prime.size()) {
						isOk = false;
						break;
					}
					front[i] = not_prime[b];
					prev = front[i];
				}
			}
			if (isOk) {
				break;
			}
			++pnum;
		}

		pnum = (int)prime.size()-1;
		while (true) {
			bool isOk = true;
			int prev = N+1;
			int p = pnum;
			int b = (int)not_prime.size()-1;
			for (int i=(int)colors.size()-1; i>=0; --i) {
				if (colors[i] == 'R') {
					while (prime[p]>=prev) --p;
					if (p<0) {
						isOk = false;
						break;
					}
					back[i] = prime[p];
					prev = back[i];
				}
				else {
					while (not_prime[b]>=prev) --b;
					if (b<0) {
						isOk = false;
						break;
					}
					back[i] = not_prime[b];
					prev = back[i];
				}
			}
			if (isOk) {
				break;
			}
			--pnum;
		}
		vector<int> ans(colors.size());
		for (int i=0; i<ans.size(); ++i) {
			if (front[i]==back[i]) {
				ans[i] = front[i];
			}
			else {
				ans[i] = -1;
			}
		}
		return ans;
	}


	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 5; string Arg1 = "RRR"; int Arr2[] = {2, 3, 5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, theCards(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 7; string Arg1 = "BBB"; int Arr2[] = {1, 4, 6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, theCards(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; string Arg1 = "RBR"; int Arr2[] = {-1, 4, 5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, theCards(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 58; string Arg1 = "RBRRBRBBRBRRBBRRBBBRRBBBRR"; int Arr2[] = {-1, -1, -1, -1, -1, -1, -1, -1, 17, 18, 19, 23, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 47, 53 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, theCards(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 495; string Arg1 = "RBRRBRBBRBRRBBRRBBBRRBBBRR"; int Arr2[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, theCards(Arg0, Arg1)); }

	// END CUT HERE


};



// BEGIN CUT HERE

int main() {

	ColorfulCards ___test;

	___test.run_test(-1);

}

// END CUT HERE
