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
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <numeric>

#define INF (1<<30)

using namespace std;

#define MAX_N 55
#define MAX_K 1005
#define MOD 1000000007

class EllysPlaylists {

public:
    bool
    isSmooth(int from,int to,vector<string> &s)
    {
        int fs = (int)s[from].size();
        string last = s[from].substr(fs-3,3);
        string start = s[to].substr(0,3);
        if (last == start) {
            return true;
        }
        return false;
    }

    int
    countPlaylists(vector <string> songs, int K)
    {
        const int N = (int)songs.size();
        const int k = K;
        int dp[k+1][N+1];
        memset(dp, 0, sizeof(dp));
        fill(dp[0], dp[0]+N+1, 1);

        bool r[N+1][N+1];
        memset(r, false, sizeof(r));
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                if (isSmooth(i, j, songs)) {
                    r[i][j] = true;
                }
            }
        }

        for (int i=1; i<k; ++i) {
            for (int j=0; j<N; ++j) {
                int v = 0;
                for (int k=0; k<N; ++k) {
                    if (r[j][k]) {
                        v = (v+dp[i-1][k])%MOD;
                    }
                }
                dp[i][j] = v;
            }
        }

        int ans = 0;
        for (int i=0; i<N; ++i) {
            ans = (ans+dp[k-1][i])%MOD;
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = { "abcxxx", "xxxabc", "entersandman", "toxicity", "maneater", "heavensalie",
        "liebe", "citylights", "fadetoblack", "breakingthehabit", "yyydefg", "defgyyy" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 5; verify_case(0, Arg2, countPlaylists(Arg0, Arg1)); }
    void test_case_1() { string Arr0[] = { "aaaaaa", "aaabcd", "bcdaaa" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 13; verify_case(1, Arg2, countPlaylists(Arg0, Arg1)); }
    void test_case_2() { string Arr0[] = { "aaa", "aaaa", "aaaaa" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 27; verify_case(2, Arg2, countPlaylists(Arg0, Arg1)); }
    void test_case_3() { string Arr0[] = { "elly", "looks", "lovely" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 3; verify_case(3, Arg2, countPlaylists(Arg0, Arg1)); }
    void test_case_4() { string Arr0[] = { "life", "universe", "everything" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 42; int Arg2 = 0; verify_case(4, Arg2, countPlaylists(Arg0, Arg1)); }
    void test_case_5() { string Arr0[] = { "aaaaaaaaa", "aaabbbaaa", "aaacccaaa", "aaadddaaa", "aaaeeeaaa", "aaafffaaa" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; int Arg2 = 176782322; verify_case(5, Arg2, countPlaylists(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    EllysPlaylists ___test;

    ___test.run_test(-1);

}

// END CUT HERE
