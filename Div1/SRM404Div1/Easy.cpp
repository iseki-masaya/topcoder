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

class RevealTriangle {

public:
    bool includeQuestionMark(string s) {
        for (char ch: s)
            if (ch == '?')
                return true;
        return false;
    }

    int calc(char cb, char cc) {
        int b = cb - '0';
        int c = cc - '0';
        for (int a=0; a<10; ++a) {
            int r = (a+b)%10;
            if (r == c) {
                return a;
            }
        }
        return -1;
    }

    vector <string> calcTriangle(vector <string> questionMarkTriangle) {
        int N = (int)questionMarkTriangle.size();
        for (int i=N-1; i>=0; --i) {
            int M = N - i;
            while (includeQuestionMark(questionMarkTriangle[i])) {
                for (int j=0; j<M; ++j) {
                    if (questionMarkTriangle[i][j] != '?') {
                        if (j != 0 && questionMarkTriangle[i][j-1] == '?') {
                            int v = calc(questionMarkTriangle[i][j], questionMarkTriangle[i+1][j-1]);
                            questionMarkTriangle[i][j-1] = (v+'0');
                        }
                        if (j != M-1 && questionMarkTriangle[i][j+1] == '?') {
                            int v = calc(questionMarkTriangle[i][j], questionMarkTriangle[i+1][j]);
                            questionMarkTriangle[i][j+1] = (v+'0');
                        }
                    }
                }
            }
        }
        return questionMarkTriangle;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
    void test_case_0() { string Arr0[] = {"4??",
        "?2",
        "1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"457", "92", "1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, calcTriangle(Arg0)); }
    void test_case_1() { string Arr0[] = {"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, calcTriangle(Arg0)); }
    void test_case_2() { string Arr0[] = {"???2", "??2", "?2", "2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0002", "002", "02", "2" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, calcTriangle(Arg0)); }
    void test_case_3() { string Arr0[] = {"??5?", "??9", "?4", "6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"7054", "759", "24", "6" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, calcTriangle(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    RevealTriangle ___test;

    ___test.run_test(-1);

}

// END CUT HERE
