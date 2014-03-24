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

class TheTree {

public:

    int maximumDiameter(vector <int> cnt) {
        int res = 0 , N = (int)cnt.size();
        for (int i=0; i<N; ++i) {
            bool cut = false;
            for (int j=i; j<N; ++j) {
                if (cnt[j] == 1) {
                    res = max(res, N-i+j-i);
                    cut = true;
                    break;
                }
            }
            if (!cut) {
                res = max(res, 2*(N-i));
            }
        }
        return res;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4();}
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, maximumDiameter(Arg0)); }
    void test_case_1() { int Arr0[] = {2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, maximumDiameter(Arg0)); }
    void test_case_2() { int Arr0[] = {4, 1, 2, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, maximumDiameter(Arg0)); }
    void test_case_3() { int Arr0[] = {1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, maximumDiameter(Arg0)); }
    void test_case_4() { int Arr0[] = {253, 1, 663, 237, 218, 1, 1, 1, 1, 738, 977, 1, 295, 1, 1, 839, 1, 1, 195, 908, 43, 44, 1, 1, 548, 1, 888, 811, 434, 97, 888, 1, 181, 67, 621, 238, 1, 199, 1, 182, 495, 28, 120, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 46; verify_case(4, Arg1, maximumDiameter(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    TheTree ___test;

    ___test.run_test(-1);

}

// END CUT HERE
