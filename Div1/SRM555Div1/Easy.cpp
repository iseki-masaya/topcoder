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

#define INF (1<<28)
#define EPS 1e-8
#define MOD 100000000

using namespace std;

class CuttingBitString {

public:
    bool
    check(string s)
    {
        if (s[0] == '0') {
            return false;
        }
        long long k = 0;
        for (int i=0; i<s.size(); ++i) {
            k = k*2 + (s[i]=='1');
        }

        while ((k%5) == 0) {
            k /= 5;
        }
        return k == 1;
    }

    int
    getmin(string S)
    {
        int dp[100];
        int N = (int)S.size();

        for (int i=0; i<N; ++i) {
            dp[i] = -1;
            if ( check(S.substr(0,i+1)) ) {
                dp[i] = 1;
            }
            else {
                for (int j=1; j<=i; ++j) {
                    if (dp[j-1] != -1 && check(S.substr(j,i-j+1))) {
                        if (dp[i] == -1 || dp[i] > dp[j-1]+1 ) {
                            dp[i] = dp[j-1] + 1;
                        }
                    }
                }
            }
        }
        return dp[N-1];
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "101101101"; int Arg1 = 3; verify_case(0, Arg1, getmin(Arg0)); }
    void test_case_1() { string Arg0 = "1111101"; int Arg1 = 1; verify_case(1, Arg1, getmin(Arg0)); }
    void test_case_2() { string Arg0 = "00000"; int Arg1 = -1; verify_case(2, Arg1, getmin(Arg0)); }
    void test_case_3() { string Arg0 = "110011011"; int Arg1 = 3; verify_case(3, Arg1, getmin(Arg0)); }
    void test_case_4() { string Arg0 = "1000101011"; int Arg1 = -1; verify_case(4, Arg1, getmin(Arg0)); }
    void test_case_5() { string Arg0 = "111011100110101100101110111"; int Arg1 = 5; verify_case(5, Arg1, getmin(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    CuttingBitString ___test;

    ___test.run_test(-1);

}

// END CUT HERE
