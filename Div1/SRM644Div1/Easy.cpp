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
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <cstdio>
//#include <cstdlib>
#include <cstring>
#include <numeric>
#include <bitset>
#include <deque>
#include <memory>

const long long LINF = (5e17);
const int INF = 1000000000;
#define EPS 1e-7
const int MOD = 1000000007;

using namespace std;

class OkonomiyakiParty {

public:

    int exp_mod(long long a, long long b, int m) {
        long long res = 1;
        while (b > 0) {
            if (b&1)
                res = (res * a)%m;
            a = (a * a)%m;
            b >>= 1;
        }
        return (int)res;
    }

    int fact_mod(int n, int m) {
        long long res = 1;
        for (int i=n; i>0; --i)
            res = (res * i)%m;
        return (int)res;
    }

    int comb_mod(int n, int r) {
        long long res = 1;
        if (n < r || n < 0 || r  < 0)
            return 0;
        for (int i=0; i<r; ++i)
            res = (res * (n - i) )%MOD;
        return ( res * exp_mod(fact_mod(r, MOD), MOD-2, MOD) ) % MOD;
    }

    int count(vector <int> osize, int M, int K) {
        long long ans = 0;
        sort(osize.begin(), osize.end());
        int N = (int)osize.size();
        for (int i=0; i<N; ++i) {
            int j = i;
            while (j < N && osize[j] <= osize[i]+K ) ++j;
            ans = ( ans + comb_mod(j - i - 1, M - 1) )%MOD;
        }
        return (int)ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {1,4,6,7,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; int Arg3 = 6; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
    void test_case_1() { int Arr0[] = {1,6,2,7,4,2,6,1,5,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 3; int Arg3 = 60; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
    void test_case_2() { int Arr0[] = {1,4,5,7,10,11,13,16,18}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 5; int Arg3 = 0; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
    void test_case_3() { int Arr0[] = {55,2,7,232,52,5,5332,623,52,6,532,5147}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 10000; int Arg3 = 924; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
    void test_case_4() { int Arr0[] = {5781,8708,1754,4750,9888,3675,4810,1020,922,9834,5695,1101,1236,2496,8431,6727,
        1376,3373,4423,1839,7438,9407,1851,6966,8715,2905,542,535,8980,2602,2603,3117,3452,
        5682,7775,4356,5140,8923,9801,3729}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; int Arg2 = 4003; int Arg3 = 114514; verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }

    // END CUT HERE


};


// BEGIN CUT HERE

int main() {

    OkonomiyakiParty ___test;

    ___test.run_test(-1);

}

// END CUT HERE