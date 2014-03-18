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

class PiecewiseLinearFunction {

public:

    int maximumSolutions(vector <int> Y) {
        vector<int> idx(Y);
        sort(idx.begin(), idx.end());
        idx.erase(unique(idx.begin(), idx.end()), idx.end());

        int N = (int)Y.size();
        vector<int> y(N);
        for (int i=0; i<N; ++i) {
            int n = (int)distance(idx.begin(), find(idx.begin(), idx.end(), Y[i]));
            y[i] = 2*n;
        }

        vector<int> c(200,0);
        c[y[0]]++;
        for (int i=1; i<N; ++i) {
            c[y[i-1]]--;
            int mn = min(y[i], y[i-1]);
            int mx = max(y[i], y[i-1]);
            if (mn == mx)
                return -1;
            for (int j=mn; j<=mx; ++j)
                c[j]++;
        }

        return *max_element(c.begin(), c.end());
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, maximumSolutions(Arg0)); }
    void test_case_1() { int Arr0[] = {4, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, maximumSolutions(Arg0)); }
    void test_case_2() { int Arr0[] = {1, 4, -1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, maximumSolutions(Arg0)); }
    void test_case_3() { int Arr0[] = {2, 1, 2, 1, 3, 2, 3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, maximumSolutions(Arg0)); }
    void test_case_4() { int Arr0[] = {125612666, -991004227, 0, 6, 88023, -1000000000, 1000000000, -1000000000, 1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(4, Arg1, maximumSolutions(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    PiecewiseLinearFunction ___test;

    ___test.run_test(-1);

}

// END CUT HERE
