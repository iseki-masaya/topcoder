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
#include <memory>

const long long LINF = (5e18);
const int INF = (1<<30);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

bool comp(const int a, const int b) {
    return abs(a) < abs(b);
}

class TheConsecutiveIntegersDivOne {

public:

    int find(vector <int> numbers, int k) {
        sort(numbers.begin(), numbers.end());
        int N = (int)numbers.size();
        vector<int> nn(N);
        int ans = INF;
        for (int v: numbers) {
            for (int i=0; i<N; ++i)
                nn[i] = numbers[i] - v;
            int negative = 1, positive = 1;
            sort(nn.begin(), nn.end(), comp);
            int c = 0;
            for (int i=0; i<k; ++i) {
                if (nn[i] < 0)
                    c += abs(nn[i]) - negative++;
                if (nn[i] > 0)
                    c += abs(nn[i]) - positive++;
            }
            ans = min(ans, c);
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {4, 7, 47}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, find(Arg0, Arg1)); }
    void test_case_1() { int Arr0[] = {1, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(1, Arg2, find(Arg0, Arg1)); }
    void test_case_2() { int Arr0[] = {-96, -53, 82, -24, 6, -75}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 20; verify_case(2, Arg2, find(Arg0, Arg1)); }
    void test_case_3() { int Arr0[] = {64, -31, -56}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 24; verify_case(3, Arg2, find(Arg0, Arg1)); }
    void test_case_4() { int Arr0[] = {-96, -53, 82, -24, 6, -75}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 90; verify_case(4, Arg2, find(Arg0, Arg1)); }
    void test_case_5() { int Arr0[] = {-70, -30, 5, 10, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 17; verify_case(5, Arg2, find(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    TheConsecutiveIntegersDivOne ___test;

    ___test.run_test(-1);

}

// END CUT HERE
