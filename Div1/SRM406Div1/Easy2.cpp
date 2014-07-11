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

const long long LINF = (5e18);
const int INF = (1<<28);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class SymmetricPie {

public:
    bool ok[55];
    vector<int> dogs;

    int dfs(int sum, int mask) {
        int res = 0;
        for (int i=0; i<dogs.size(); ++i) if ( !(mask&(1<<i)) ) {
            sum += dogs[i];
            if (sum <= 50)
                ok[sum] = true;
            res = max(res, (sum > 50 && ok[sum-50] ? 1 : 0) + dfs(sum, mask|(1<<i)) );
            if (sum <= 50)
                ok[sum] = false;
            sum -= dogs[i];
        }
        return res;
    }

    int getLines(vector <int> dogs) {
        memset(ok, false, sizeof(ok));
        this->dogs = dogs;
        return dfs(0, 0);
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {10,40,10,40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, getLines(Arg0)); }
    void test_case_1() { int Arr0[] = {10,50,40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getLines(Arg0)); }
    void test_case_2() { int Arr0[] = {50,25,25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, getLines(Arg0)); }
    void test_case_3() { int Arr0[] = {1,48,1,1,48,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, getLines(Arg0)); }
    void test_case_4() { int Arr0[] = {2,2,96}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(4, Arg1, getLines(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    SymmetricPie ___test;

    ___test.run_test(-1);

}

// END CUT HERE
