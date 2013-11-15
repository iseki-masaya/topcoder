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
#include <numeric>
#include <stdio.h>
#include <string.h>

#define INF (1<<28)
#define LINF (1e17)

using namespace std;

class CasketOfStar {

public:

    int maxEnergy(vector <int> weight){
        int N = (int)weight.size();
        vector<vector<int> > dp(N,vector<int>(N,0));
        for (int d=1; d<N; ++d) {
            for (int i=0; i<N-d; ++i) {
                if (d == 1) {
                    dp[i][i+d] = 0;
                }
                else {
                    for (int j=i+1; j<i+d; ++j) {
                        int v = dp[i][j] + dp[j][i+d] + weight[i]*weight[i+d];
                        dp[i][i+d] = max(dp[i][i+d],v);
                    }
                }
            }
        }
        return dp[0][N-1];
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(0, Arg1, maxEnergy(Arg0)); }
    void test_case_1() { int Arr0[] = {100,2,1,3,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10400; verify_case(1, Arg1, maxEnergy(Arg0)); }
    void test_case_2() { int Arr0[] = {2,2,7,6,90,5,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1818; verify_case(2, Arg1, maxEnergy(Arg0)); }
    void test_case_3() { int Arr0[] = {477,744,474,777,447,747,777,474}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2937051; verify_case(3, Arg1, maxEnergy(Arg0)); }
    void test_case_4() { int Arr0[] = {54, 64, 24, 24, 72, 33, 30, 40, 22, 17, 40, 21, 41, 64, 8, 46, 18, 65, 48, 32, 52, 54, 75, 5, 18, 37, 41, 22, 68, 42, 55}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 96202; verify_case(4, Arg1, maxEnergy(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    CasketOfStar ___test;

    ___test.run_test(-1);

}

// END CUT HERE
