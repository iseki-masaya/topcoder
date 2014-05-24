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

class MagicWords {

public:
    string make(vector<string> &S, vector<int> &p) {
        string res = "";
        for (int v : p) {
            res += S[v];
        }
        return res;
    }

    int isMagic(string &c, vector<int> &f) {
        int N = (int)c.size();
        int n = (int)f.size();
        string str = "";
        for (int i=0; i<n; ++i) {
            bool isMagic = true;
            for (int j=0; j<N; ++j) {
                if (c[j] != c[(j+f[i])%N]) {
                    isMagic = false;
                    break;
                }
            }
            if (isMagic)
                return N / f[i];
        }
        return 1;
    }

    int count(vector <string> S, int K) {
        int N = (int)S.size();
        vector<int> p(N);
        for (int i=0; i<N; ++i)
            p[i] = i;

        int len = 0;
        for (string s : S)
            len += s.size();
        vector<int> f;
        for (int i=1; i<len; ++i) {
            if (len%i == 0) {
                f.push_back(i);
            }
        }

        int ans = 0;
        do {
            string candidate = make(S, p);
            if (isMagic(candidate, f) == K)
                ++ans;
        } while (next_permutation(p.begin(), p.end()));
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6();  if ((Case == -1) || (Case == 7)) test_case_7(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"CAD","ABRA","ABRA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 6; verify_case(0, Arg2, count(Arg0, Arg1)); }
    void test_case_1() { string Arr0[] = {"AB","RAAB","RA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, count(Arg0, Arg1)); }
    void test_case_2() { string Arr0[] = {"AA","AA","AAA","A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(2, Arg2, count(Arg0, Arg1)); }
    void test_case_3() { string Arr0[] = {"AA","AA","AAA","A","AAA","AAAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; int Arg2 = 720; verify_case(3, Arg2, count(Arg0, Arg1)); }
    void test_case_4() { string Arr0[] = {"ABC","AB","ABC","CA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 0; verify_case(4, Arg2, count(Arg0, Arg1)); }
    void test_case_5() { string Arr0[] = {"A","B","C","A","B","C"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 672; verify_case(5, Arg2, count(Arg0, Arg1)); }
    void test_case_6() { string Arr0[] = {"AAAAAAAAAAAAAAAAAAAA",
        "AAAAAAAAAAAAAAAAAAAA",
        "AAAAAAAAAAAAAAAAAAAA",
        "AAAAAAAAAAAAAAAAAAAA",
        "AAAAAAAAAAAAAAAAAAAA",
        "AAAAAAAAAAAAAAAAAAAA",
        "AAAAAAAAAAAAAAAAAAAA",
        "AAAAAAAAAAAAAAAAAAAB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 40320; verify_case(6, Arg2, count(Arg0, Arg1)); }
    void test_case_7() { string Arr0[] = {"XEHCEFKQCKFHBQXE", "SGEBQIQGAMQHSXVEMHI", "IHGQCVL", "HSXVEMHIXEHCEFKQCKF", "QCIIHGQCVLA", "HBQXECLEES", "CLEESQCI", "ASGEBQIQGAMQ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 8; verify_case(7, Arg2, count(Arg0, Arg1)); }

    // END CUT HERE



};



// BEGIN CUT HERE

int main() {

    MagicWords ___test;

    ___test.run_test(-1);

}

// END CUT HERE
