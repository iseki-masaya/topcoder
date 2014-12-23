#include <string>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <list>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <bitset>
#include <deque>
//#include <random>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <thread>

const long long LINF = (5e18);
const int INF = (1<<30);
const int sINF = (1<<23);
const int MOD = 1000000009;
const double EPS = 1e-6;

using namespace std;

class BracketExpressions {

public:

    const string br = "(){}[]";
    map<char, char> r;

    bool check(string expression) {
        stack<char> s;
        for (char ch: expression) {
            if (!s.empty() && (r[s.top()] == ch || ch == 'X') )
                s.pop();
            else
                s.push(ch);
        }
        return s.empty();
    }

    bool dfs(string expression, int p) {
        bool inX = false;
        bool res = false;
        for (int i=p; i<expression.size(); ++i) {
            if (expression[i] != 'X')
                continue;
            inX = true;
            for (char ch: br) {
                expression[i] = ch;
                res |= dfs(expression, i);
            }
        }
        return !inX ? check(expression) : res;
    }

    string ifPossible(string expression) {
        for (int i=0; i<br.size(); i+=2)
            r[br[i]] = br[i+1];
        return dfs(expression, 0) ? "possible" : "impossible";
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "([]{})"; string Arg1 = "possible"; verify_case(0, Arg1, ifPossible(Arg0)); }
    void test_case_1() { string Arg0 = "(())[]"; string Arg1 = "possible"; verify_case(1, Arg1, ifPossible(Arg0)); }
    void test_case_2() { string Arg0 = "({])"; string Arg1 = "impossible"; verify_case(2, Arg1, ifPossible(Arg0)); }
    void test_case_3() { string Arg0 = "[]X"; string Arg1 = "impossible"; verify_case(3, Arg1, ifPossible(Arg0)); }
    void test_case_4() { string Arg0 = "([]X()[()]XX}[])X{{}}]"; string Arg1 = "possible"; verify_case(4, Arg1, ifPossible(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    BracketExpressions ___test;

    ___test.run_test(-1);

}

// END CUT HERE
