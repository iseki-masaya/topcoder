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

class StrIIRec {

public:
    int
    inversion(string &s)
    {
        int N = (int)s.size();
        int res = 0;
        for (int i=0; i<N; ++i) {
            for (int j=i+1; j<N; ++j) {
                if (s[i] > s[j]) {
                    ++res;
                }
            }
        }
        return res;
    }

    string
    next(string &s)
    {
        int N = (int)s.size();
        for (int i=N-2; i>=0; --i) {
            for (int j=N-1; j>i; --j) {
                if (s[i] < s[j]) {
                    swap(s[j], s[i]);
                    return s;
                }
            }
        }
        return s;
    }

    string
    recovstr(int n, int minInv, string minStr)
    {
        for (int i=0; i<n; ++i) {
            char ch = 'a'+i;
            if (minStr.find(ch) == string::npos) {
                minStr += ch;
            }
        }
        string s = minStr;
        while (inversion(s) < minInv) {
            s = next(s);
        }
        return s;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 2; int Arg1 = 1; string Arg2 = "ab"; string Arg3 = "ba"; verify_case(0, Arg3, recovstr(Arg0, Arg1, Arg2)); }
    void test_case_1() { int Arg0 = 9; int Arg1 = 1; string Arg2 = "efcdgab"; string Arg3 = "efcdgabhi"; verify_case(1, Arg3, recovstr(Arg0, Arg1, Arg2)); }
    void test_case_2() { int Arg0 = 11; int Arg1 = 55; string Arg2 = "debgikjfc"; string Arg3 = "kjihgfedcba"; verify_case(2, Arg3, recovstr(Arg0, Arg1, Arg2)); }
    void test_case_3() { int Arg0 = 15; int Arg1 = 0; string Arg2 = "e"; string Arg3 = "eabcdfghijklmno"; verify_case(3, Arg3, recovstr(Arg0, Arg1, Arg2)); }
    void test_case_4() { int Arg0 = 9; int Arg1 = 20; string Arg2 = "fcdebiha"; string Arg3 = "fcdehigba"; verify_case(4, Arg3, recovstr(Arg0, Arg1, Arg2)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    StrIIRec ___test;

    ___test.run_test(-1);

}

// END CUT HERE
