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

#define MAX 55

class Painting {

public:

	bool
	check(int s,vector<string> &p)
	{
		vector<vector<int> > used(p.size(),vector<int>(p[0].size(),false));
		for (int y=0; y<p.size(); ++y) {
			for (int x=0; x<p[0].size(); ++x) {
				if (p[y][x]=='B') {
					bool is_fill = true;
					for (int dy=0; dy<s ; ++dy) {
						for (int dx=0; dx<s ; ++dx) {
							if (x+dx>=p[0].size() || y+dy>=p.size() || p[y+dy][x+dx] != 'B') {
								is_fill = false;
							}
						}
					}
					if (is_fill) {
						for (int dy=0; dy<s ; ++dy) {
							for (int dx=0; dx<s ; ++dx) {
								used[y+dy][x+dx] = true;
							}
						}
					}
				}
			}
		}
		for (int y=0; y<p.size(); ++y) {
			for (int x=0; x<p[0].size(); ++x) {
				if (p[y][x]=='B' && !used[y][x]) {
					return false;
				}
			}
		}
		return true;
	}

	int
	largestBrush(vector <string> picture) {
		int left=0 , right = 120;
		for (int i=0; i<100; ++i) {
			int mid = (left+right)/2;
			if (check(mid, picture)) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
		return left;
	}


	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BBBB",
		"BBBB",
		"BBBB",
		"BBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, largestBrush(Arg0)); }
	void test_case_1() { string Arr0[] = {"BBBB",
		"BWWB",
		"BWWB",
		"BBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, largestBrush(Arg0)); }
	void test_case_2() { string Arr0[] = {"WBBBBB",
		"BBBBBB",
		"BBBBBB",
		"BBBBBB"}
		; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, largestBrush(Arg0)); }
	void test_case_3() { string Arr0[] = {"BBBB",
		"BBBB",
		"WBBB",
		"BBBB",
		"BBBB",
		"BBBB"}
		; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, largestBrush(Arg0)); }
	void test_case_4() { string Arr0[] = {"WBBBBBWWWWWWWWW",
		"WBBBBBBWWWWWWWW",
		"WBBBBBBBBBBBWWW",
		"WBBBBBBBBBBBWWW",
		"BBBBBBBBBBBBBBB",
		"BBBBBBBBBBBBBBB",
		"BBBBBBBBBBBBBBB",
		"BBBBBBBBWWBBBBB",
		"BBBBBBBBWBBBBBB",
		"WBBBBBBBWBBBBBW",
		"BBBBBBBWWBBBBBW",
		"BBBBBBBWWBBBBBW",
		"BBBBBBWWWBBBBBW",
		"BBBBBWWWWWWWWWW",
		"BBBBBWWWWWWWWWW"}
		; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, largestBrush(Arg0)); }
	void test_case_5() { string Arr0[] = {"BBWW",
		"BBWW",
		"WBBW",
		"WWBB",
		"WWBB"}
		; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(5, Arg1, largestBrush(Arg0)); }

	// END CUT HERE


};



// BEGIN CUT HERE

int main() {

	Painting ___test;

	___test.run_test(-1);

}

// END CUT HERE
