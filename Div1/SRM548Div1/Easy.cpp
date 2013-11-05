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
const int MOD = 10007;

using namespace std;

class KingdomAndTrees {

public:
    bool
    check(int v,vector<int> &h)
    {
        int N = (int)h.size();
        int prev = 0;

        for (int i=0; i<N; ++i) {
            if (h[i] + v <= prev) {
                return false;
            }
            prev = max(prev + 1,h[i] - v);
        }
        return true;
    }

    int
    minLevel(vector <int> heights)
    {
        int lb = -1 ,ub = 1<<30;
        while (ub - lb > 1) {
            int mid = (ub+lb)/2;
            if (check(mid, heights)) {
                ub = mid;
            }
            else {
                lb = mid;
            }
        }
        return ub;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {9, 5, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, minLevel(Arg0)); }
    void test_case_1() { int Arr0[] = {5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, minLevel(Arg0)); }
    void test_case_2() { int Arr0[] = {1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, minLevel(Arg0)); }
    void test_case_3() { int Arr0[] = {8, 5, 100, 90}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(3, Arg1, minLevel(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    KingdomAndTrees ___test;

    ___test.run_test(-1);

}

// END CUT HERE
