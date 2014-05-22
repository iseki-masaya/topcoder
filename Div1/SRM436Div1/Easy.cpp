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
const int INF = (1<<30);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class BestView {

public:

    int numberOfBuildings(vector <int> heights) {
        int N = (int)heights.size();
        int ans = 0;
        for (int i=0; i<N; ++i) {
            int cnt = 0;
            for (int j=0; j<N; ++j) if (i != j) {
                bool visible = true;
                int left = min(i,j), right = max(i,j);
                double a = double(heights[left] - heights[right]) / (left - right);
                for (int k=left+1; k<right; ++k) {
                    if (heights[k] >= heights[left] + a*(k-left)) {
                        visible = false;
                        break;
                    }
                }
                if (visible)
                    ++cnt;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, numberOfBuildings(Arg0)); }
    void test_case_1() { int Arr0[] = {5,5,5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, numberOfBuildings(Arg0)); }
    void test_case_2() { int Arr0[] = {1,2,7,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, numberOfBuildings(Arg0)); }
    void test_case_3() { int Arr0[] = {1,5,3,2,6,3,2,6,4,2,5,7,3,1,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(3, Arg1, numberOfBuildings(Arg0)); }
    void test_case_4() { int Arr0[] = {1000000000,999999999,999999998,999999997,999999996,1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(4, Arg1, numberOfBuildings(Arg0)); }
    void test_case_5() { int Arr0[] = {244645169,956664793,752259473,577152868,605440232,569378507,111664772,653430457,454612157,397154317}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(5, Arg1, numberOfBuildings(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    BestView ___test;

    ___test.run_test(-1);

}

// END CUT HERE
