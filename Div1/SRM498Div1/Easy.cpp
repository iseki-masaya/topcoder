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

class FoxSequence {

public:

    string isValid(vector <int> seq) {
        int N = (int)seq.size();
        if (N < 5)
            return "NO";

        vector<int> cd(N-1);
        for (int i=1; i<N; ++i) {
            cd[i-1] = seq[i] - seq[i-1];
        }
        --N;
        int cnt = 0;
        int condition = 0;
        int diff = cd[0];
        for (int i=0; i<N; ++i) {
            switch (condition) {
                case 0:
                    if (cd[i] < 0 && cnt > 0) {
                        condition = 1;
                        cnt = 0;
                        diff = cd[i];
                        --i;
                    }
                    else if (cd[i] == diff && diff > 0) {
                        ++cnt;
                    }
                    else {
                        condition = -1;
                    }
                    break;
                case 1:
                    if (cd[i] >= 0 && cnt > 0) {
                        condition = 2;
                        cnt = 0;
                        diff = cd[i];
                        --i;
                    }
                    else if (cd[i] == diff) {
                        ++cnt;
                    }
                    else {
                        condition = -1;
                    }
                    break;
                case 2:
                    if (cd[i] > 0) {
                        condition = 3;
                        cnt = 0;
                        diff = cd[i];
                        --i;
                    }
                    else if (cd[i] < 0) {
                        condition = -1;
                    }
                    break;
                case 3:
                    if (cd[i] < 0 && cnt > 0) {
                        condition = 4;
                        cnt = 0;
                        diff = cd[i];
                        --i;
                    }
                    else if (cd[i] == diff) {
                        ++cnt;
                    }
                    else {
                        condition = -1;
                    }
                    break;
                case 4:
                    if (cd[i] != diff) {
                        return "NO";
                    }
                    break;
                default:
                    return "NO";
            }
        }

        return condition == 4 ? "YES" : "NO";
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {1,3,5,7,5,3,1,1,1,3,5,7,5,3,1}
        ; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, isValid(Arg0)); }
    void test_case_1() { int Arr0[] = {1,2,3,4,5,4,3,2,2,2,3,4,5,6,4}
        ; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(1, Arg1, isValid(Arg0)); }
    void test_case_2() { int Arr0[] = {3,6,9,1,9,5,1}
        ; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(2, Arg1, isValid(Arg0)); }
    void test_case_3() { int Arr0[] = {1,2,3,2,1,2,3,2,1,2,3,2,1}
        ; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(3, Arg1, isValid(Arg0)); }
    void test_case_4() { int Arr0[] = {1,3,4,3,1,1,1,1,3,4,3,1}
        ; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(4, Arg1, isValid(Arg0)); }
    void test_case_5() { int Arr0[] = {6,1,6}
        ; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(5, Arg1, isValid(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    FoxSequence ___test;

    ___test.run_test(-1);

}

// END CUT HERE
