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

class SurveillanceSystem {

public:

    int calc(string &c, int p, int L) {
        int res = 0;
        while (L > 0) {
            if (c[p++] == 'X') {
                ++res;
            }
            --L;
        }
        return res;
    }

    void plus(vector<string> &c, string &ans) {
        int N = (int)ans.size();
        int M = (int)c.size();

        for (int j=0; j<M; ++j) {
            for (int i=0; i<N; ++i) {
                if (c[j][i] == '+') {
                    ans[i] = '+';
                }
            }
        }
    }

    char get(vector<string> &c, int i, int n) {
        int M = (int)c.size();
        int threshold = M - n;

        int cnt = 0;
        for (int j=0; j<M; ++j) {
            if (c[j][i] == '+') {
                ++cnt;
            }
        }

        return cnt > threshold ? '+' : cnt == 0 ? '-' : '?';
    }

    char comp(char lhs, char rhs) {
        if (lhs == '+' || rhs == '+') {
            return '+';
        }
        else if (lhs == '?' || rhs == '?') {
            return '?';
        }
        return '-';
    }

    void question(vector<string> &c, string &ans, int n) {
        int N = (int)ans.size();

        for (int i=0; i<N; ++i) if (ans[i] != '+') {
            ans[i] = comp(ans[i], get(c, i, n));
        }
    }

    string getContainerInfo(string containers, vector <int> reports, int L) {
        int N = (int)containers.size();
        vector<vector<string> > con(N+1);

        for (int i=0; i<=N-L; ++i) {
            string res = string(N,'-');
            for (int j=0; j<L; ++j) {
                res[i+j] = '+';
            }
            int c = calc(containers, i, L);
            con[c].push_back(res);
        }

        int M = (int)reports.size();
        vector<int> cnt(N+1,0);
        for (int i=0; i<M; ++i) {
            cnt[reports[i]]++;
        }

        string ans = string(N,'-');
        for (int i=0; i<=N; ++i) if (cnt[i] != 0) {
        if (cnt[i] == con[i].size()) {
                plus(con[i], ans);
            }
            else {
                question(con[i], ans, cnt[i]);
            }
        }

        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "-X--XX"; int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "??++++"; verify_case(0, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
    void test_case_1() { string Arg0 = "-XXXXX-"; int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "???-???"; verify_case(1, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
    void test_case_2() { string Arg0 = "------X-XX-"; int Arr1[] = {3, 0, 2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; string Arg3 = "++++++++++?"; verify_case(2, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
    void test_case_3() { string Arg0 = "-XXXXX---X--"; int Arr1[] = {2, 1, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "???-??++++??"; verify_case(3, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
    void test_case_4() { string Arg0 = "-XX--X-XX-X-X--X---XX-X---XXXX-----X"; int Arr1[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; string Arg3 = "???++++?++++++++++++++++++++??????--"; verify_case(4, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    SurveillanceSystem ___test;

    ___test.run_test(-1);

}

// END CUT HERE
