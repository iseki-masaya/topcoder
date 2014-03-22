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

const long long LINF = (1e15);
const int INF = (1<<27);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class FoxAndChess {

public:

    string ableToMove(string begin, string target) {
        string B,T;
        for (int i=0; i<begin.size(); ++i) {
            if (begin[i] != '.')
                B.push_back(begin[i]);
            if (target[i] != '.')
                T.push_back(target[i]);
        }
        if (B != T)
            return "Impossible";


        vector<int> bR,tR,bL,tL;
        for (int i=0; i<begin.size(); ++i) {
            if (begin[i] == 'R')
                bR.push_back(i);
            else if (begin[i] == 'L')
                bL.push_back(i);

            if (target[i] == 'R')
                tR.push_back(i);
            else if (target[i] == 'L')
                tL.push_back(i);
        }

        if (bR.size() != tR.size() || bL.size() != tL.size())
            return "Impossible";

        for (int i=0; i<bR.size(); ++i)
            if (bR[i] > tR[i])
                return "Impossible";

        for (int i=0; i<bL.size(); ++i)
            if (bL[i] < tL[i])
                return "Impossible";

        return "Possible";
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "R..."; string Arg1 = "..R."; string Arg2 = "Possible"; verify_case(0, Arg2, ableToMove(Arg0, Arg1)); }
    void test_case_1() { string Arg0 = "..R."; string Arg1 = "R..."; string Arg2 = "Impossible"; verify_case(1, Arg2, ableToMove(Arg0, Arg1)); }
    void test_case_2() { string Arg0 = ".L.R.R."; string Arg1 = "L...R.R"; string Arg2 = "Possible"; verify_case(2, Arg2, ableToMove(Arg0, Arg1)); }
    void test_case_3() { string Arg0 = ".L.R."; string Arg1 = ".R.L."; string Arg2 = "Impossible"; verify_case(3, Arg2, ableToMove(Arg0, Arg1)); }
    void test_case_4() { string Arg0 = "LRLLRLRLLRLLRLRLRL"; string Arg1 = "LRLLRLRLLRLLRLRLRL"; string Arg2 = "Possible"; verify_case(4, Arg2, ableToMove(Arg0, Arg1)); }
    void test_case_5() { string Arg0 = "L"; string Arg1 = "."; string Arg2 = "Impossible"; verify_case(5, Arg2, ableToMove(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    FoxAndChess ___test;

    ___test.run_test(-1);

}

// END CUT HERE
