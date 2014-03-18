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

class ColorfulStrings {
public:
    int n,k;
    int num;

    bool isOk(string n) {
        set<int> s;
        int N = (int)n.size();
        for (int i=1; i<=N; ++i) {
            for (int j=0; j+i<=N; ++j) {
                int v= 1;
                for (int k=0; k<i; ++k)
                    v *= (n[k+j]-'0');
                if (s.find(v) != s.end())
                    return false;
                s.insert(v);
            }
        }

        return true;
    }

    bool rec(string &s, int m) {
        if (s.size() == n) {
            if (isOk(s))
                ++num;

            if (num == k)
                return true;
            return false;
        }

        for (int i=2; i<10; ++i) if ( !((m>>i)&1) ) {
            s.push_back(i+'0');
            if (rec(s, m | (1<<i)))
                return true;
            s.pop_back();
        }

        return false;
    }

    string getKth(int n, int k) {
        this->n = n;
        this->k = k;
        this->num = 0;

        if (n > 9)
            return "";
        if (n == 1 && k <= 10) {
            char ch = '0' + (k-1);
            string ans = "";
            ans.push_back(ch);
            return ans;
        }

        string ans = "";
        return rec(ans, 0) ? ans : "";
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 3; int Arg1 = 4; string Arg2 = "238"; verify_case(0, Arg2, getKth(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 4; int Arg1 = 2000; string Arg2 = ""; verify_case(1, Arg2, getKth(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 5; int Arg1 = 1; string Arg2 = "23457"; verify_case(2, Arg2, getKth(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 2; int Arg1 = 22; string Arg2 = "52"; verify_case(3, Arg2, getKth(Arg0, Arg1)); }
    void test_case_4() { int Arg0 = 6; int Arg1 = 464; string Arg2 = "257936"; verify_case(4, Arg2, getKth(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    ColorfulStrings ___test;

    ___test.run_test(-1);

}

// END CUT HERE
