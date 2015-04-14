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

class AB {

public:

    string createString(int N, int K) {
        int a = N/2, b = (N+1)/2;
        if (a * b < K)
            return "";
        while (a*b > K)
            --a;

        string res = "";
        for (int i=0; i<a; ++i)
            res.append("A");
        if (K - a*b != 0) {
            for (int i=0; i<b - (K - a*b); ++i)
                res.append("B");
            b = K - a*b;
            res.append("A");
        }
        for (int i=0; i<b; ++i)
            res.append("B");
        while (res.size() < N)
            res.append("A");
        return res;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 3; int Arg1 = 2; string Arg2 = "ABB"; verify_case(0, Arg2, createString(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 2; int Arg1 = 0; string Arg2 = "BA"; verify_case(1, Arg2, createString(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 5; int Arg1 = 8; string Arg2 = ""; verify_case(2, Arg2, createString(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 10; int Arg1 = 12; string Arg2 = "BAABBABAAB"; verify_case(3, Arg2, createString(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    AB ___test;

    ___test.run_test(3);

}

// END CUT HERE
