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

using namespace std;

class BinPacking {

public:

    int minBins(vector <int> item) {
        sort(item.begin(), item.end());
        int N = (int)item.size();
        int ans = INF;

        for (int i=0; i<=N; i += 3) {
            if (i != 0 && item[i-1] != 100)
                break;
            int res = i/3;
            int start = i;
            int end = N - 1;
            while (start < end) {
                if (item[start] + item[end] <= 300) {
                    ++start;
                    --end;
                    ++res;
                }
                else {
                    --end;
                    ++res;
                }
            }
            if (start == end)
                ++res;
            ans = min(ans, res);
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {150, 150, 150, 150, 150}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, minBins(Arg0)); }
    void test_case_1() { int Arr0[] = {130, 140, 150, 160}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, minBins(Arg0)); }
    void test_case_2() { int Arr0[] = {100, 100, 100, 100, 100, 100, 100, 100, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, minBins(Arg0)); }
    void test_case_3() { int Arr0[] = {100, 200, 100, 100, 100, 100, 200, 100, 200}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, minBins(Arg0)); }
    void test_case_4() { int Arr0[] = {157, 142, 167, 133, 135, 157, 143, 160, 141, 123, 162, 159, 165, 137, 138, 152}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(4, Arg1, minBins(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    BinPacking ___test;

    ___test.run_test(-1);

}

// END CUT HERE
