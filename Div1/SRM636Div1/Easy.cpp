#include <string>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <list>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <bitset>
#include <deque>
//#include <random>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <thread>

const long long LINF = (1e18);
const int INF = (1<<28);
const int sINF = (1<<23);
const int MOD = 1000000007;
const double EPS = 1e-6;

using namespace std;

class ChocolateDividingEasy {

public:

    int findBest(vector <string> chocolate) {
        int H = (int)chocolate.size();
        int W = (int)chocolate[0].size();

        vector<vector<int> > S(H+1, vector<int>(W+1,0));

        for (int x=1; x<=W; ++x) {
            for (int y=1; y<=H; ++y) {
                int c = chocolate[y-1][x-1] - '0';
                S[y][x] = S[y-1][x] + S[y][x-1] - S[y-1][x-1] + c;
            }
        }

        int ans = 0;
        for (int y1=1; y1<H; ++y1) {
            for (int y2=y1+1; y2<H; ++y2) {
                for (int x1=1; x1<W; ++x1) {
                    for (int x2=x1+1; x2<W; ++x2) {
                        vector<int> X = {0, x1, x2, W};
                        vector<int> Y = {0, y1, y2, H};
                        int mn = INF;
                        for (int i=0; i<3; ++i) {
                            for (int j=0; j<3; ++j) {
                                int sx = X[i], ex = X[i+1];
                                int sy = Y[j], ey = Y[j+1];
                                int s = S[ey][ex] + S[sy][sx] - S[ey][sx] - S[sy][ex];
                                mn = min(mn, s);
                            }
                        }
                        ans = max(ans, mn);
                    }
                }
            }
        }
        return ans;
    }

    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {
        "9768",
        "6767",
        "5313"
    }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, findBest(Arg0)); }
    void test_case_1() { string Arr0[] = {
        "36753562",
        "91270936",
        "06261879",
        "20237592",
        "28973612",
        "93194784"
    }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(1, Arg1, findBest(Arg0)); }
    void test_case_2() { string Arr0[] = {
        "012",
        "345",
        "678"
    }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, findBest(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    ChocolateDividingEasy ___test;

    ___test.run_test(-1);

}

// END CUT HERE
