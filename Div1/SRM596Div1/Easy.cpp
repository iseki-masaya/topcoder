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

class IncrementAndDoubling {

public:
    bool isAllZero(vector<int> &d) {
        int N = (int)d.size();
        for (int i=0; i<N; ++i) {
            if (d[i] != 0) {
                return false;
            }
        }
        return true;
    }

    int getMin(vector <int> desiredArray) {
        int ans =  0;
        int N = (int)desiredArray.size();
        while (true) {
            for (int i=0; i<N; ++i) {
                if (desiredArray[i]&1) {
                    desiredArray[i]--;
                    ++ans;
                }
            }
            if (isAllZero(desiredArray))
                break;
            ++ans;
            for (int i=0; i<N; ++i) {
                desiredArray[i] /= 2;
            }
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, getMin(Arg0)); }
    void test_case_1() { int Arr0[] = {16, 16, 16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, getMin(Arg0)); }
    void test_case_2() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(2, Arg1, getMin(Arg0)); }
    void test_case_3() { int Arr0[] = {0, 0, 1, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, getMin(Arg0)); }
    void test_case_4() { int Arr0[] = {123, 234, 345, 456, 567, 789}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 40; verify_case(4, Arg1, getMin(Arg0)); }
    void test_case_5() { int Arr0[] = {7,5,8,1,8,6,6,5,3,5,5,2,8,9,9,4,6,9,4,4,1,9,9,2,8,4,7,4,8,8,6,3,9,4,3,4,5,1,9,8,3,8,3,7,9,3,8,4,4,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 84; verify_case(5, Arg1, getMin(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    IncrementAndDoubling ___test;

    ___test.run_test(-1);

}

// END CUT HERE
