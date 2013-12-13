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

const long long LINF = (1e15);
const int INF = (1<<28);
#define EPS 1e-6
const int MOD = 1000000009;

using namespace std;

typedef pair<int, int> P;

class MysteriousRestaurant {

public:

    vector<vector<int> > conv(vector<string> &p) {
        int N = (int)p.size();
        int M = (int)p[0].size();

        vector<vector<int> > res(N,vector<int>(M,0));
        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                char ch = p[i][j];
                if ('0' <= ch && ch <= '9')
                    res[i][j] = ch - '0';
                else if ('A' <= ch && ch <= 'Z')
                    res[i][j] = ch - 'A' + 10;
                else if ('a' <= ch && ch <= 'z')
                    res[i][j] = ch - 'a' + 36;
                else
                    res[i][j] = -1 , printf("error\n");
            }
        }

        return res;
    }

    int maxDays(vector <string> prices_str, int budget) {
        int N = (int)prices_str.size();
        int M = (int)prices_str[0].size();

        vector<vector<int> > prices(conv(prices_str));

        int dp[8][7][55];
        int ans = 0;
        for (int n=0; n<8; ++n) {
            int cost = 0;
            for (int i=0; i<7; ++i) {
                int day = n*7 + i;
                if (day >= N)
                    return N;

                int mn = INF;
                for (int j=0; j<M; ++j) {
                    if (n == 0)
                        dp[n][i][j] = prices[day][j];
                    else
                        dp[n][i][j] = dp[n-1][i][j] + prices[day][j];
                    mn = min(mn,dp[n][i][j]);
                }
                cost += mn;

                int nc = cost;
                for (int k=i+1; n!=0 && k<7; ++k) {
                    int pmn = INF;
                    for (int j=0; j<M; ++j) {
                        pmn = min(pmn, dp[n-1][k][j]);
                    }
                    nc += pmn;
                }

                if (nc <= budget)
                    ans = n*7 + i + 1;

            }
        }

        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"26", "14", "72", "39", "32", "85", "06"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; int Arg2 = 5; verify_case(0, Arg2, maxDays(Arg0, Arg1)); }
    void test_case_1() { string Arr0[] = {"26", "14", "72", "39", "32", "85", "06", "91"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; int Arg2 = 8; verify_case(1, Arg2, maxDays(Arg0, Arg1)); }
    void test_case_2() { string Arr0[] = {"SRM", "512"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 0; verify_case(2, Arg2, maxDays(Arg0, Arg1)); }
    void test_case_3() { string Arr0[] = {"Dear", "Code", "rsHa", "veFu", "nInT", "heCh", "alle", "ngeP", "hase", "andb", "ecar", "eful"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 256; int Arg2 = 10; verify_case(3, Arg2, maxDays(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    MysteriousRestaurant ___test;

    ___test.run_test(-1);

}

// END CUT HERE
