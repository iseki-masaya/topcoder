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
#include <stdio.h>
#include <string.h>
#include <numeric>

#define INF (1<<28)

using namespace std;

class LotteryTicket {

public:

    string
    buy(int price, int b1, int b2, int b3, int b4)
    {
        vector<int> b;
        b.push_back(b1);
        b.push_back(b2);
        b.push_back(b3);
        b.push_back(b4);
        sort(b.begin(), b.end());

        do {
            for (int i=1; i<=4; ++i) {
                int ret = 0;
                for (int j=0; j<i; ++j) {
                    ret += b[j];
                }
                if (ret == price) {
                    return "POSSIBLE";
                }
            }
        } while (next_permutation(b.begin(), b.end()));
        return "IMPOSSIBLE";
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 5; int Arg3 = 10; int Arg4 = 50; string Arg5 = "POSSIBLE"; verify_case(0, Arg5, buy(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_1() { int Arg0 = 15; int Arg1 = 1; int Arg2 = 5; int Arg3 = 10; int Arg4 = 50; string Arg5 = "POSSIBLE"; verify_case(1, Arg5, buy(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_2() { int Arg0 = 65; int Arg1 = 1; int Arg2 = 5; int Arg3 = 10; int Arg4 = 50; string Arg5 = "POSSIBLE"; verify_case(2, Arg5, buy(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_3() { int Arg0 = 66; int Arg1 = 1; int Arg2 = 5; int Arg3 = 10; int Arg4 = 50; string Arg5 = "POSSIBLE"; verify_case(3, Arg5, buy(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_4() { int Arg0 = 1000; int Arg1 = 999; int Arg2 = 998; int Arg3 = 997; int Arg4 = 996; string Arg5 = "IMPOSSIBLE"; verify_case(4, Arg5, buy(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_5() { int Arg0 = 20; int Arg1 = 5; int Arg2 = 5; int Arg3 = 5; int Arg4 = 5; string Arg5 = "POSSIBLE"; verify_case(5, Arg5, buy(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_6() { int Arg0 = 668; int Arg1 = 913; int Arg2 = 668; int Arg3 = 300; int Arg4 = 36; string Arg5 = "POSSIBLE"; verify_case(6, Arg5, buy(Arg0, Arg1, Arg2, Arg3, Arg4)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    LotteryTicket ___test;

    ___test.run_test(-1);

}

// END CUT HERE
