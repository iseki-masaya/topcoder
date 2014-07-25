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

class CandidateKeys {

public:

    bool isUnique(vector<string> &table, int mask) {
        set<string> sc;
        int N = (int)table[0].size();
        int M = (int)table.size();
        for (int i=0; i<M; ++i) {
            string s = "";
            for (int j=0; j<N; ++j) {
                if (mask & (1<<j)) {
                    s += table[i][j];
                }
            }
            if (sc.count(s))
                return false;
            sc.insert(s);
        }
        return true;
    }

    int count(int n) {
        int res = 0;
        while (n > 0) {
            if (n&1)
                ++res;
            n >>= 1;
        }
        return res;
    }

    bool hasSuperKey(int i, set<int> &s) {
        for (int v: s) {
            int u = v&i;
            if (v == u)
                return true;
        }
        return false;
    }

    vector <int> getKeys(vector <string> table) {
        int N = (int)table[0].size();
        int mn = INF;
        int mx = -1;
        int lim = (1<<N);
        set<int> s;
        for (int c=1; c<=N; ++c) {
            for (int i=1; i<lim; ++i) {
                if (count(i) == c && !hasSuperKey(i, s) && isUnique(table, i)) {
                    s.insert(i);
                    mn = min(mn, c);
                    mx = max(mx, c);
                }
            }
        }
        return mx == -1 ? vector<int>() : vector<int>{mn, mx};
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
    void test_case_0() { string Arr0[] = {
        "ABC",
        "ABC",
        "ABC"
    }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getKeys(Arg0)); }
    void test_case_1() { string Arr0[] = {
        "ABC",
        "ABD",
        "ABE"
    }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getKeys(Arg0)); }
    void test_case_2() { string Arr0[] = {
        "ABC",
        "ACD",
        "BBE"
    }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getKeys(Arg0)); }
    void test_case_3() { string Arr0[] = {"A","B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getKeys(Arg0)); }
    void test_case_4() { string Arr0[] =    { "BDC",
        "AFC",
        "BFG",
        "GAD",
        "DBA",
        "BCB",
        "ACC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getKeys(Arg0)); }

    // END CUT HERE



};



// BEGIN CUT HERE

int main() {

    CandidateKeys ___test;

    ___test.run_test(-1);

}

// END CUT HERE
