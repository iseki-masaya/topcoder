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

class PrimeSoccer {

public:

    bool isPrime(int a) {
        if (a < 2)
            return false;
        for (int i=2; i*i<=a; ++i) {
            if (a%i == 0) {
                return false;
            }
        }
        return true;
    }

    double calc(double p) {
        double res = 0.0;
        for (int i=2; i<=18; ++i) if (isPrime(i)) {
            double t = 1.0;
            for (int n=18; n>18-i; --n) t *= (double)n;
            for (int n=1; n<=i; ++n) t /= (double)n;
            res += t*pow(p, i)*pow(1.0-p, 18-i);
        }
        return res;
    }

    double getProbability(int skillOfTeamA, int skillOfTeamB) {
        double Pa = calc((double)skillOfTeamA/100.0);
        double Pb = calc((double)skillOfTeamB/100.0);
        return Pa + Pb - Pa*Pb;
    }

    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 50; int Arg1 = 50; double Arg2 = 0.5265618908306351; verify_case(0, Arg2, getProbability(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 100; int Arg1 = 100; double Arg2 = 0.0; verify_case(1, Arg2, getProbability(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 12; int Arg1 = 89; double Arg2 = 0.6772047168840167; verify_case(2, Arg2, getProbability(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    PrimeSoccer ___test;

    ___test.run_test(-1);

}

// END CUT HERE
