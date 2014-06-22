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
const int INF = (1<<29);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class SentenceDecomposition {

public:
    string s;
    vector<string> vw;
    int dp[200];

    int check(string &buf, string &candidate) {
        if (buf.size() != candidate.size())
            return -1;

        string A(buf), B(candidate);
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        if (A != B)
            return -1;
        int res = 0;
        int N = (int)buf.size();
        for (int i=0; i<N; ++i) {
            if (buf[i] != candidate[i]) {
                ++res;
            }
        }
        return res;
    }

    int dfs(int len) {
        if (dp[len] != -1)
            return dp[len];
        if (len == 0 )
            return 0;

        int res = INF;
        for (string candidate: vw) {
            int len1 = (int)candidate.size();
            if (len < len1)
                continue;
            string buf = s.substr(len - len1, len1);
            int diff = check(buf, candidate);
            if (diff != -1) {
                res = min(res, diff + dfs(len - len1));
            }
        }

        return dp[len] = res;
    }

    int decompose(string sentence, vector <string> validWords) {
        this->s = sentence;
        this->vw = validWords;
        memset(dp, -1, sizeof(dp));
        string buf = "";
        int ans = dfs(int(sentence.size()) );
        return ans == INF ? -1 : ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "neotowheret"; string Arr1[] = {"one", "two", "three", "there"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(0, Arg2, decompose(Arg0, Arg1)); }
    void test_case_1() { string Arg0 = "abba"; string Arr1[] = {"ab", "ac", "ad"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, decompose(Arg0, Arg1)); }
    void test_case_2() { string Arg0 = "thisismeaningless"; string Arr1[] = {"this", "is", "meaningful"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, decompose(Arg0, Arg1)); }
    void test_case_3() { string Arg0 = "ommwreehisymkiml"; string Arr1[] = {"we", "were", "here", "my", "is", "mom", "here", "si", "milk", "where", "si"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(3, Arg2, decompose(Arg0, Arg1)); }
    void test_case_4() { string Arg0 = "ogodtsneeencs"; string Arr1[] = {"go", "good", "do", "sentences", "tense", "scen"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(4, Arg2, decompose(Arg0, Arg1)); }
    void test_case_5() { string Arg0 = "sepawaterords"; string Arr1[] = {"separate","words"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(5, Arg2, decompose(Arg0, Arg1)); }
    void test_case_6() { string Arg0 = "noonnonnmnnomoonnmooonmnmnnommnomoomommooonommonn"; string Arr1[] = {"mmo", "omon", "mmno", "non", "ono", "nono", "n", "mon", "nomn", "ooonomomnmnmmmnmononmoonomnonnoonoonmonnnmonommon", "mnn", "omom", "moo", "nonn", "oono", "ooo"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(6, Arg2, decompose(Arg0, Arg1)); }
    void test_case_7() { string Arg0 = "asddsaasddsaasddsaasddssdasdadadasddsaasddsaasddsa"; string Arr1[] = {"asddsa", "asd", "asdasdasd", "dsadsadsa", "adsasdasdasd", "dsadasdaaddasdadsa", "asdasdasddas", "dsaadsasddsaasdasd", "dsadsadadsadsadas", "adasdasddsa", "sadasdasdas", "dasdasd", "sdadasda", "aasd", "dadads", "asdad", "asdadasdasd", "asddddd", "sdadadad", "asd", "d", "asd", "asdadsadas", "adasdadada", "adasdadasdsad", "asdasdadasda", "adsadasdasda", "dasdadasdad", "dasadsdasadsdas", "daadsadsads", "das", "sadasdadsdsaads", "dasasdadsads", "asasd", "dasdasdasadsdsa", "dasadsadsds", "adsadssa", "ads", "das", "dasads", "ads", "dasdasdsadsa", "dasadsadsasd", "das", "adsdasasdasdads", "adsadsdasdasdasads", "asdadssadadsasd", "adsdasadsads", "dsadsadsadsadda", "asdasd"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(7, Arg2, decompose(Arg0, Arg1)); }



    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    SentenceDecomposition ___test;

    ___test.run_test(-1);

}

// END CUT HERE
