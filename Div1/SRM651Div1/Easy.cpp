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

class RobotOnMoon {

public:

	typedef pair<int, int> P;

	bool isIn(int x, int y, int X, int Y) {
		return 0 <= x && x < X && 0 <= y && y < Y;
	}

	bool isInf(P p, int x, int y, int X, int Y, const vector<string> &board) {
		do {
			if (board[y][x] == '#')
				return true;
			x += p.first;
			y += p.second;
		} while (isIn(x, y, X, Y));
		return false;
	}

	int longestSafeCommand(vector <string> board) {
		int Y = (int)board.size();
		int X = (int)board[0].size();

		int sx = -1, sy = -1;
		for (int y=0; y<Y; ++y) {
			for (int x=0; x<X; ++x) {
				if (board[y][x] == 'S') {
					sx = x;
					sy = y;
				}
			}
		}

		bool inf = isInf(P(1,0), sx, sy, X, Y, board) |
		isInf(P(0,1), sx, sy, X, Y, board) |
		isInf(P(-1,0), sx, sy, X, Y, board)|
		isInf(P(0,-1), sx, sy, X, Y, board);
		if(inf)
			return -1;

		int w = X-sx-1 + sx;
		int h = Y-sy-1 + sy;
		return w+h;
	}


	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"#####",
		"#...#",
		"#.S.#",
		"#...#",
		"#####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(0, Arg1, longestSafeCommand(Arg0)); }
	void test_case_1() { string Arr0[] = {"S......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, longestSafeCommand(Arg0)); }
	void test_case_2() { string Arr0[] = {"#.######",
		"#.#..S.#",
		"#.#.##.#",
		"#......#",
		"########"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, longestSafeCommand(Arg0)); }
	void test_case_3() { string Arr0[] = {"S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, longestSafeCommand(Arg0)); }

	// END CUT HERE


};



// BEGIN CUT HERE

int main() {

	RobotOnMoon ___test;

	___test.run_test(-1);

}

// END CUT HERE
