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
const int INF = (1<<30);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class TheSwap {

public:
    typedef pair<int, int> P;
    map<P, int> memo;

    vector<int> make(int n) {
        vector<int> res;
        while (n > 0) {
            res.push_back(n%10);
            n /= 10;
        }
        return res;
    }

    int value(vector<int> &v) {
        int res = 0;
        int N = (int)v.size();
        int d = 1;
        for (int i=0; i<N; ++i) {
            res += d*v[i];
            d *= 10;
        }
        return res;
    }

    int go(vector<int> &V, int K) {
        int n = value(V);
        if (K == 0) {
            return n;
        }
        if ( memo.count(P(n,K)) ) {
            return memo[P(n,K)];
        }
        int a = -1;
        int N =(int)V.size();
        for (int i=N-1; i>=0; --i) {
            for (int j=i-1; j>=0; --j) {
                if (i == N-1 && V[j] == 0) {
                    continue;
                }
                swap(V[i], V[j]);
                a = max(a, go(V, K-1));
                swap(V[j], V[i]);
            }
        }

        return memo[P(n,K)] = a;
    }

    int findMax(int n, int k) {
        vector<int> V(make(n));
        return go(V, k);
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 16375; int Arg1 = 1; int Arg2 = 76315; verify_case(0, Arg2, findMax(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 432; int Arg1 = 1; int Arg2 = 423; verify_case(1, Arg2, findMax(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 90; int Arg1 = 4; int Arg2 = -1; verify_case(2, Arg2, findMax(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 5; int Arg1 = 2; int Arg2 = -1; verify_case(3, Arg2, findMax(Arg0, Arg1)); }
    void test_case_4() { int Arg0 = 436659; int Arg1 = 2; int Arg2 = 966354; verify_case(4, Arg2, findMax(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    TheSwap ___test;

    ___test.run_test(-1);

}

// END CUT HERE
