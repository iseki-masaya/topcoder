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

class TheBlackJackDivOne {

public:
    vector<int> cnt;

    double rec(int have, int C) {
        if (have >= 21)
            return 0.0;
        double ans = 1.0;
        for (int i=2; i<12; ++i) {
            if (cnt[i]) {
                double prob = cnt[i]*1.0/accumulate(cnt.begin(), cnt.end(), 0);
                cnt[i]--;
                ans += prob*rec(have+i, C+1);
                cnt[i]++;
            }
        }
        return ans;
    }

    double expected(vector <string> cards) {
        cnt.clear();
        cnt.resize(12,4);
        cnt[0] = cnt[1] = 0;
        cnt[10] = 16;
        int N = (int)cards.size();
        int have = 0;
        for (int i=0; i<N; ++i) {
            int p = 0;
            if ('2' <= cards[i][0] && cards[i][0] <= '9')
                p = cards[i][0] - '0';
            else if (cards[i][0] == 'A')
                p = 11;
            else
                p = 10;
            have += p;
            cnt[p]--;
        }

        return rec(have, 1);
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"JS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.105854341736695; verify_case(0, Arg1, expected(Arg0)); }
    void test_case_1() { string Arr0[] = {"KD", "8S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.08; verify_case(1, Arg1, expected(Arg0)); }
    void test_case_2() { string Arr0[] = {"KD", "2S", "2C", "2D", "2H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(2, Arg1, expected(Arg0)); }
    void test_case_3() { string Arr0[] = {"AS", "KS", "9S", "JC", "2D"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(3, Arg1, expected(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    TheBlackJackDivOne ___test;

    ___test.run_test(-1);

}

// END CUT HERE
