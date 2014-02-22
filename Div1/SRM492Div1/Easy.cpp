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

class TimeTravellingGardener {

public:
    int calc(int i, int j, vector<int> &d, vector<int> &h) {
        int res = 0;
        int L = accumulate(d.begin(), d.begin()+i, 0);
        int D = accumulate(d.begin()+i, d.begin()+j, 0);
        int N = (int)h.size();

        for (int k=0; k<N; ++k) if (k != i && k != j) {
            int dist = accumulate(d.begin(), d.begin()+k, 0);
            int t = (dist-L)*(h[j]-h[i]);
            if ( h[i]*D + t < 0 ) {
                return INF;
            }
            if ( t%D == 0 && h[i]+t/D == h[k]) {
                continue;
            }
            if (t > D*(h[k] - h[i])) {
                return INF;
            }
            ++res;
        }

        return res;
    }

    int determineUsage(vector <int> distance, vector <int> height) {
        int N = (int)height.size();

        int ans = INF;
        for (int i=0; i<N; ++i) {
            for (int j=i+1; j<N; ++j) {
                ans = min(ans,calc(i,j,distance,height));
            }
        }

        return ans == INF ? N-1 : ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {24, 19, 5, 24, 6, 6, 12, 24, 9, 3, 12, 5, 19, 3, 21, 24, 2, 19, 3, 24, 24, 24, 24, 24, 1, 21, 2, 1, 23, 24, 2, 8, 14, 17, 7, 24, 24, 24, 24, 24, 24, 24, 11, 13, 24, 24, 22, 2, 24}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {997, 967, 942, 937, 907, 968, 928, 877, 847, 995, 985, 817, 903, 787, 963, 757, 727, 983, 927, 697, 667, 637, 607, 577, 547, 923, 927, 517, 940, 487, 457, 946, 901, 427, 933, 397, 367, 337, 307, 277, 247, 217, 187, 942, 157, 127, 97, 921, 67, 37}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 48; verify_case(0, Arg2, determineUsage(Arg0, Arg1)); }
    void test_case_1() { int Arr0[] = {3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, determineUsage(Arg0, Arg1)); }
    void test_case_2() { int Arr0[] = {1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,4,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, determineUsage(Arg0, Arg1)); }
    void test_case_3() { int Arr0[] = {4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9,8,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(3, Arg2, determineUsage(Arg0, Arg1)); }
    void test_case_4() { int Arr0[] = {476,465,260,484}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {39,13,8,72,80}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(4, Arg2, determineUsage(Arg0, Arg1)); }
    void test_case_5() { int Arr0[] = {173,36,668,79,26,544}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {488,743,203,446,444,91,453}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(5, Arg2, determineUsage(Arg0, Arg1)); }
    void test_case_6() { int Arr0[] = {2,4,2,2,4,2,4,2,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,2,10,10,10,16,16,22,22,28,28}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(6, Arg2, determineUsage(Arg0, Arg1)); }

    // END CUT HERE

};



// BEGIN CUT HERE

int main() {

    TimeTravellingGardener ___test;

    ___test.run_test(-1);

}

// END CUT HERE
