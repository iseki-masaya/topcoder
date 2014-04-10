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

class TheBasketballDivOne {

public:
    int find(int n, int m)
    {
        int t = 0;
        int host[20];
        int guest[20];
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i!=j){
                    host[t] = i;
                    guest[t] = j;
                    t++;
                }
            }
        }

        set<vector<int> > validWSequences;
        for (int mask = 0; mask < (1<<t) ; mask++) {
            vector<int> wins(n , 0);
            for (int i=0; i<t; i++) {
                if( mask&(1<<i) )
                    wins[ host[i] ]++;
                else
                    wins[ guest[i] ]++;
            }
            sort( wins.rbegin(), wins.rend() );
            if ( wins[0] == m) {
                if(validWSequences.count(wins) == 0) {
                    validWSequences.insert(wins);
                }
            }
        }
        return (int)validWSequences.size();
    }

    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, find(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 0; verify_case(1, Arg2, find(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 2; verify_case(2, Arg2, find(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 5; int Arg1 = 7; int Arg2 = 20; verify_case(3, Arg2, find(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    TheBasketballDivOne ___test;

    ___test.run_test(-1);

}

// END CUT HERE
