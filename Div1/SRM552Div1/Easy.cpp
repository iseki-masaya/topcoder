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

const int INF = (1<<30);
#define EPS 1e-8
const int MOD = 10007;

using namespace std;

class FoxPaintingBalls {
    long long R,G,B,T;
    int Q;

public:
    long long
    over_flow(long long c,long long T)
    {
        long long k = c*T;
        if (k/T == c) return k;
        else return 1.5e18;
    }

    bool
    check(long long c)
    {
        long long restR = R - over_flow(c, T);
        long long restG = G - over_flow(c, T);
        long long restB = B - over_flow(c, T);
        if (restR < 0 || restG < 0 || restB < 0) {
            return false;
        }
        return restR + restG + restB >= (Q==1 ? c : 0);
    }

    long long
    theMax(long long R, long long G, long long B, int N)
    {
        if (N == 1) {
            return R+B+G;
        }

        this->R = R;
        this->G = G;
        this->B = B;
        long long S = (long long)N*(N+1)/2;
        this->T = S/3;
        this->Q = S%3;

        long long lb = 0 , ub = 1.5e18;
        while (ub - lb > 1) {
            long long mid = (lb+ub)/2;
            if (check(mid)) {
                lb = mid;
            }
            else {
                ub = mid;
            }
        }
        return lb;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6();if ((Case == -1) || (Case == 7)) test_case_7(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { long long Arg0 = 2LL; long long Arg1 = 2LL; long long Arg2 = 2LL; int Arg3 = 3; long long Arg4 = 1LL; verify_case(0, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_1() { long long Arg0 = 1LL; long long Arg1 = 2LL; long long Arg2 = 3LL; int Arg3 = 3; long long Arg4 = 0LL; verify_case(1, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_2() { long long Arg0 = 8LL; long long Arg1 = 6LL; long long Arg2 = 6LL; int Arg3 = 4; long long Arg4 = 2LL; verify_case(2, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_3() { long long Arg0 = 7LL; long long Arg1 = 6LL; long long Arg2 = 7LL; int Arg3 = 4; long long Arg4 = 2LL; verify_case(3, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_4() { long long Arg0 = 100LL; long long Arg1 = 100LL; long long Arg2 = 100LL; int Arg3 = 4; long long Arg4 = 30LL; verify_case(4, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_5() { long long Arg0 = 19330428391852493LL; long long Arg1 = 48815737582834113LL; long long Arg2 = 11451481019198930LL; int Arg3 = 3456; long long Arg4 = 5750952686LL; verify_case(5, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_6() { long long Arg0 = 1LL; long long Arg1 = 1LL; long long Arg2 = 1LL; int Arg3 = 1; long long Arg4 = 3LL; verify_case(6, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_7() { long long Arg0 = 434532807763425372LL; long long Arg1 = 912245252707409536LL; long long Arg2 = 721365743254593093LL; int Arg3 = 31414801; long long Arg4 = 2641LL; verify_case(7, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    FoxPaintingBalls ___test;

    ___test.run_test(-1);

}

// END CUT HERE
