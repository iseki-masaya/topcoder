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

class ClosestRabbit {

public:

    double getExpected(vector <string> board, int r) {
        int h = (int)board.size();
        int w = (int)board[0].size();
        vector<int> x,y;
        for (int i=0; i<h; ++i) {
            for (int j=0; j<w; ++j) {
                if (board[i][j] == '.') {
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }
        const int n = (int)x.size();
        int dist[n][n];
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                int dx = x[i] - x[j];
                int dy = y[i] - y[j];
                dist[i][j] = dx*dx + dy*dy;
            }
        }
        double C[n+1][n+1];
        memset(C, 0, sizeof(C));
        for (int i=0; i<=n; ++i) {
            C[i][0] = 1;
            for (int j=1; j<=i; ++j)
                C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
        double res = 0;
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                int b = 0;
                for (int k=0; k<n; ++k) {
                    if ((k == i) || (k == j))
                        continue;
                    if (dist[i][k] < dist[i][j] || (dist[i][k] == dist[i][j] && k < j) ||
                            dist[j][k] < dist[j][i] || (dist[j][k] == dist[j][i] && k < i) )
                        ++b;
                }
                res += C[n - 2 - b][r - 2] / C[n][r];
            }
        }

        return res;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {".#.#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 1.0; verify_case(0, Arg2, getExpected(Arg0, Arg1)); }
    void test_case_1() { string Arr0[] = {"..###.",
        ".###.#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = 1.6; verify_case(1, Arg2, getExpected(Arg0, Arg1)); }
    void test_case_2() { string Arr0[] = {"..###.",
        ".###.#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; double Arg2 = 2.0; verify_case(2, Arg2, getExpected(Arg0, Arg1)); }
    void test_case_3() { string Arr0[] = {".....",
        "#...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = 1.253968253968254; verify_case(3, Arg2, getExpected(Arg0, Arg1)); }
    void test_case_4() { string Arr0[] = {".#####.#####..#....#",
        "#......#....#.##..##",
        ".####..#####..#.##.#",
        ".....#.#...#..#....#",
        "#####..#....#.#....#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; double Arg2 = 5.77311527122319; verify_case(4, Arg2, getExpected(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    ClosestRabbit ___test;

    ___test.run_test(-1);

}

// END CUT HERE
