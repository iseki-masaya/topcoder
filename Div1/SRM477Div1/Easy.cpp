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

const long long LINF = (1e15);
const int INF = (1<<27);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

const int dx[2][3] = { {1,-1,0} , {1,0,1} };
const int dy[3] = {0,1,1};

class Islands {

public:

    int beachLength(vector <string> kingdom) {
        int Y = (int)kingdom.size();
        int X = (int)kingdom[0].size();

        int res = 0;
        for (int x=0; x<X; ++x) {
            for (int y=0; y<Y; ++y) {
                for (int i=0; i<3; ++i) {
                    int cx = x + dx[y&1][i];
                    int cy = y + dy[i];
                    if (0 <= cx && cx < X && cy < Y && kingdom[y][x] != kingdom[cy][cx])
                        ++res;
                }
            }
        }
        return res;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {".#...#.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, beachLength(Arg0)); }
    void test_case_1() { string Arr0[] = {"..#.##",
        ".##.#.",
        "#.#..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(1, Arg1, beachLength(Arg0)); }
    void test_case_2() { string Arr0[] = {"#...#.....",
        "##..#...#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(2, Arg1, beachLength(Arg0)); }
    void test_case_3() { string Arr0[] = {"....#.",
        ".#....",
        "..#..#",
        "####.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(3, Arg1, beachLength(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    Islands ___test;

    ___test.run_test(-1);

}

// END CUT HERE
