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

class KleofasTail {

public:
    long long
    count(long long K,long long N)
    {
        long long res = 0 , lb = K , ub = K;
        if (!(K&1))
            ++ub;
        while (lb <= N) {
            res += min(N,ub) - lb + 1;
            lb = 2*lb;
            ub = 2*ub+1;
        }
        return res;
    }

    long long
    countGoodSequences(long long K, long long A, long long B)
    {
        if (K == 0) {
            return B - A + 1;
        }
        return count(K, B) - count(K,A-1);
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { long long Arg0 = 3LL; long long Arg1 = 4LL; long long Arg2 = 8LL; long long Arg3 = 2LL; verify_case(0, Arg3, countGoodSequences(Arg0, Arg1, Arg2)); }
    void test_case_1() { long long Arg0 = 1LL; long long Arg1 = 23457LL; long long Arg2 = 123456LL; long long Arg3 = 100000LL; verify_case(1, Arg3, countGoodSequences(Arg0, Arg1, Arg2)); }
    void test_case_2() { long long Arg0 = 1234567890123456LL; long long Arg1 = 10LL; long long Arg2 = 1000000LL; long long Arg3 = 0LL; verify_case(2, Arg3, countGoodSequences(Arg0, Arg1, Arg2)); }
    void test_case_3() { long long Arg0 = 0LL; long long Arg1 = 0LL; long long Arg2 = 2LL; long long Arg3 = 3LL; verify_case(3, Arg3, countGoodSequences(Arg0, Arg1, Arg2)); }
    void test_case_4() { long long Arg0 = 2LL; long long Arg1 = 3LL; long long Arg2 = 3LL; long long Arg3 = 1LL; verify_case(4, Arg3, countGoodSequences(Arg0, Arg1, Arg2)); }
    void test_case_5() { long long Arg0 = 13LL; long long Arg1 = 12345LL; long long Arg2 = 67890123LL; long long Arg3 = 8387584LL; verify_case(5, Arg3, countGoodSequences(Arg0, Arg1, Arg2)); }
    void test_case_6() { long long Arg0 = 3LL; long long Arg1 = 0LL; long long Arg2 = 1000000000000000000LL; long long Arg3 = 423539247696576512LL; verify_case(6, Arg3, countGoodSequences(Arg0, Arg1, Arg2)); }
    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    KleofasTail ___test;

    ___test.run_test(-1);

}

// END CUT HERE
