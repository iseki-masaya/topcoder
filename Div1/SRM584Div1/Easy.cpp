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

class Egalitarianism {

public:

    int maxDifference(vector <string> isFriend, int d) {
        int N = (int)isFriend.size();
        vector<vector<int> > cost(N,vector<int>(N,INF));
        for (int i=0; i<N; ++i) {
            cost[i][i] = 0;
        }
        for (int i=0; i<N; ++i) {
            for (int j=i+1; j<N; ++j) {
                if (isFriend[i][j] == 'Y') {
                    cost[i][j] = 1;
                    cost[j][i] = 1;
                }
            }
        }

        for (int j=0; j<N; ++j) {
            for (int i=0; i<N; ++i) {
                for (int k=0; k<N; ++k) {
                    cost[i][k] = min(cost[i][k], cost[i][j] + cost[j][k]);
                }
            }
        }

        int ans = 0;
        for (int i=0; i<N; ++i) {
            for (int j=i+1; j<N; ++j) {
                if (cost[i][j] == INF) {
                    return -1;
                }
                ans = max(cost[i][j], ans);
            }
        }

        return ans*d;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"NYN",
        "YNY",
        "NYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 20; verify_case(0, Arg2, maxDifference(Arg0, Arg1)); }
    void test_case_1() { string Arr0[] = {"NN",
        "NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = -1; verify_case(1, Arg2, maxDifference(Arg0, Arg1)); }
    void test_case_2() { string Arr0[] = {"NNYNNN",
        "NNYNNN",
        "YYNYNN",
        "NNYNYY",
        "NNNYNN",
        "NNNYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 3000; verify_case(2, Arg2, maxDifference(Arg0, Arg1)); }
    void test_case_3() { string Arr0[] = {"NNYN",
        "NNNY",
        "YNNN",
        "NYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 584; int Arg2 = -1; verify_case(3, Arg2, maxDifference(Arg0, Arg1)); }
    void test_case_4() { string Arr0[] = {"NYNYYYN",
        "YNNYYYN",
        "NNNNYNN",
        "YYNNYYN",
        "YYYYNNN",
        "YYNYNNY",
        "NNNNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 20; verify_case(4, Arg2, maxDifference(Arg0, Arg1)); }
    void test_case_5() { string Arr0[] = {"NYYNNNNYYYYNNNN",
        "YNNNYNNNNNNYYNN",
        "YNNYNYNNNNYNNNN",
        "NNYNNYNNNNNNNNN",
        "NYNNNNYNNYNNNNN",
        "NNYYNNYNNYNNNYN",
        "NNNNYYNNYNNNNNN",
        "YNNNNNNNNNYNNNN",
        "YNNNNNYNNNNNYNN",
        "YNNNYYNNNNNNNNY",
        "YNYNNNNYNNNNNNN",
        "NYNNNNNNNNNNNNY",
        "NYNNNNNNYNNNNYN",
        "NNNNNYNNNNNNYNN",
        "NNNNNNNNNYNYNNN"}
        ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 747; int Arg2 = 2988; verify_case(5, Arg2, maxDifference(Arg0, Arg1)); }
    void test_case_6() { string Arr0[] = {"NY",
        "YN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; verify_case(6, Arg2, maxDifference(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    Egalitarianism ___test;

    ___test.run_test(-1);

}

// END CUT HERE
