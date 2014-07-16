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

class FoxAndChess {

public:

    bool checkDir(string &a, string &b, char dir) {
        int N = (int)a.size();
        int p = 0;
        for (int i=0; i<N; ++i) {
            if (a[i] == dir) {
                bool match = false;
                while (p < N && !match) {
                    if (i<=p && b[p] == dir)
                        match = true;
                    ++p;
                }
                if (!match)
                    return false;
            }
        }
        return true;
    }

    bool checkOrder(string a, string b) {
        string c = "", d = "";
        for (char ch: a)
            if (ch != '.')
                c.push_back(ch);
        for (char ch: b)
            if (ch != '.')
                d.push_back(ch);
        return c == d;
    }

    string ableToMove(string begin, string target) {
        bool f = true;
        f &= checkDir(target, begin, 'L');
        f &= checkDir(begin, target, 'R');
        f &= checkOrder(begin, target);
        return f ? "Possible" : "Impossible";
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
    void test_case_5() { string Arg0 = "L.R.RR"; string Arg1 = "L.RR.R"; string Arg2 = "Impossible"; verify_case(5, Arg2, ableToMove(Arg0, Arg1)); }
    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    FoxAndChess ___test;

    ___test.run_test(5);

}

// END CUT HERE
