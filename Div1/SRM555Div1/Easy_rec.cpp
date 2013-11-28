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

class CuttingBitString {

public:
    long long exp(long long v,int n) {
        long long res = 1;
        while (n > 0) {
            if (n&1)
                res *= v;
            v *= v;
            n >>= 1;
        }
        return res;
    }

    int can_split(const string &S,int n) {
        long long sq = exp(5, n);
        int size = 0;
        for (long long i=1; i<=sq; i*=2) ++size;
        if (size > S.size())
            return -1;
        for (int i=0; i<size; ++i)
            if (S[i] - '0' != ( (sq>>(size-i-1))&1 ) )
                return -1;

        return size;
    }

    int rec(string S,int n) {
        if (S.size() == 0)
            return n;

        int res = INF;
        // 2^50 < 5^23
        for (int i=0; i<=23; ++i) {
            int s = can_split(S, i);
            if (s != -1)
                res = min(res, rec(S.substr(s,S.size()-s), n+1));
        }
        return res;
    }

    int getmin(string S) {
        int ans = rec(S, 0);
        return ans == INF ? -1 : ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6();}
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "101101101"; int Arg1 = 3; verify_case(0, Arg1, getmin(Arg0)); }
    void test_case_1() { string Arg0 = "1111101"; int Arg1 = 1; verify_case(1, Arg1, getmin(Arg0)); }
    void test_case_2() { string Arg0 = "00000"; int Arg1 = -1; verify_case(2, Arg1, getmin(Arg0)); }
    void test_case_3() { string Arg0 = "110011011"; int Arg1 = 3; verify_case(3, Arg1, getmin(Arg0)); }
    void test_case_4() { string Arg0 = "1000101011"; int Arg1 = -1; verify_case(4, Arg1, getmin(Arg0)); }
    void test_case_5() { string Arg0 = "111011100110101100101110111"; int Arg1 = 5; verify_case(5, Arg1, getmin(Arg0)); }
    void test_case_6() { string Arg0 = "11111111111111111111111111111111111111111111111111"; int Arg1 = 50; verify_case(6, Arg1, getmin(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    CuttingBitString ___test;

    ___test.run_test(6);

}

// END CUT HERE
