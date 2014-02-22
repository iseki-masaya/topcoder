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

class OneRegister {

public:
    set<long long> used;

    string getProgram(int s, int t) {
        used.clear();
        queue<long long> Q;
        queue<string> QS;
        Q.push(s);
        QS.push("");

        while (!Q.empty()) {
            long long k = Q.front();
            string l = QS.front();
            Q.pop() , QS.pop();
            if (k == t)
                return l;
            if (k*k <= 1000000000 && used.find(k*k) == used.end()) {
                Q.push(k*k);
                QS.push(l+"*");
                used.insert(k*k);
            }
            if (2*k <= 1000000000 && used.find(2*k) == used.end()) {
                Q.push(2*k);
                QS.push(l+"+");
                used.insert(2*k);
            }
            if (used.find(1) == used.end()) {
                Q.push(1);
                QS.push(l+'/');
                used.insert(1);
            }
        }

        return ":-(";
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 7; int Arg1 = 392; string Arg2 = "+*+"; verify_case(0, Arg2, getProgram(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 7; int Arg1 = 256; string Arg2 = "/+***"; verify_case(1, Arg2, getProgram(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 4; int Arg1 = 256; string Arg2 = "**"; verify_case(2, Arg2, getProgram(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 7; int Arg1 = 7; string Arg2 = ""; verify_case(3, Arg2, getProgram(Arg0, Arg1)); }
    void test_case_4() { int Arg0 = 7; int Arg1 = 9; string Arg2 = ":-("; verify_case(4, Arg2, getProgram(Arg0, Arg1)); }
    void test_case_5() { int Arg0 = 10; int Arg1 = 1; string Arg2 = "/"; verify_case(5, Arg2, getProgram(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    OneRegister ___test;

    ___test.run_test(-1);

}

// END CUT HERE
