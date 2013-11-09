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

const long long LINF = (1e11);
const int INF = (1<<30);
#define EPS 1e-6

using namespace std;

class ImportantSequence {

public:

    int
    getCount(vector <int> B, string operators)
    {
        int N = (int)B.size();
        if (operators.find('+') == string::npos) {
            return -1;
        }

        long long mn = 1 , mx = LINF , pmn = mn,pmx = mx;
        for (int i=0; i<N; ++i) {
            int V = B[i];
            if (operators[i] == '+') {
                mn = max(V-pmx,1LL);
                mx = max(V-pmn,0LL);
            }
            else {
                mn = max(pmn-V,1LL);
                mx = max(pmx-V,0LL);
            }
            if (mx == 0) {
                return 0;
            }
            pmn = mn;
            pmx = mx;
        }
        return int(mx - mn + 1LL);
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {3, -1, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "+-+"; int Arg2 = 2; verify_case(0, Arg2, getCount(Arg0, Arg1)); }
    void test_case_1() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "-"; int Arg2 = -1; verify_case(1, Arg2, getCount(Arg0, Arg1)); }
    void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "+"; int Arg2 = 0; verify_case(2, Arg2, getCount(Arg0, Arg1)); }
    void test_case_3() { int Arr0[] = {10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "+"; int Arg2 = 9; verify_case(3, Arg2, getCount(Arg0, Arg1)); }
    void test_case_4() { int Arr0[] = {7, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 999999999, 1234, 4311}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "-------+--"; int Arg2 = 999994453; verify_case(4, Arg2, getCount(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    ImportantSequence ___test;

    ___test.run_test(-1);

}

// END CUT HERE
