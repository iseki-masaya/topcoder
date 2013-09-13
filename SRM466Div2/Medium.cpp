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
#include <numeric>

#define INF (1<<28)

using namespace std;

class LotteryCheating {

public:
    int
    minimalChange(string ID)
    {
        int digit[10];
        int d = (int)ID.size();
        int ans = d;
        for (long long i=0; i <= 100000; ++i) {
            long long sq = i*i;

            for (int j=0; j<d; ++j) {
                digit[d-1-j] = sq%10;
                sq /= 10;
            }
            if (sq == 0) {
                int res = 0;
                for (int j=0; j<d; ++j) {
                    if (digit[j] != ID[j]-'0') {
                        ++res;
                    }
                }
                ans = min(ans,res);
            }
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "4"; int Arg1 = 0; verify_case(0, Arg1, minimalChange(Arg0)); }
    void test_case_1() { string Arg0 = "8"; int Arg1 = 1; verify_case(1, Arg1, minimalChange(Arg0)); }
    void test_case_2() { string Arg0 = "9000000000"; int Arg1 = 1; verify_case(2, Arg1, minimalChange(Arg0)); }
    void test_case_3() { string Arg0 = "4294967296"; int Arg1 = 0; verify_case(3, Arg1, minimalChange(Arg0)); }
    void test_case_4() { string Arg0 = "7654321"; int Arg1 = 3; verify_case(4, Arg1, minimalChange(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    LotteryCheating ___test;

    ___test.run_test(-1);

}

// END CUT HERE
