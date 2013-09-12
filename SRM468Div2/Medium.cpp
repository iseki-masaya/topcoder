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
#include <numeric>

#define INF (1<<28)

using namespace std;

typedef pair<string, string> P;
typedef pair<string, int> C;

class T9 {

public:
    string
    message(vector <string> part, vector <string> dict, vector <string> keystr)
    {
        sort(dict.begin(), dict.end());

        char toPress[26];
        for (int i=0;i<part.size();++i)
            for (int j=0;j<part[i].size();++j)
                toPress[part[i][j]-'a'] = i + '1';

        vector<string> dictN(dict.size());
        for (int i=0;i<dict.size();++i)
            for (int j=0;j<dict[i].size();++j)
                dictN[i] += toPress[dict[i][j] - 'a'];

        for (int i=0;i<dictN.size();++i)
            for (int j=i+1;j<dictN.size();++j)
                if (dictN[i] == dictN[j])
                    dictN[j] += '#';

        map<string, string> dictR;
        for (int i=0;i<dictN.size();++i)
            dictR[dictN[i]] = dict[i];

        string text, acc;
        for (int i = 0; i < keystr.size(); ++i) {
            for (int j = 0; j < keystr[i].size(); ++j) {
                if (keystr[i][j] == '0') {
                    text += " " + dictR[acc];
                    acc = "";
                }
                else if (keystr[i][j] == '*') {
                    acc += "#####";
                }
                else {
                    acc += keystr[i][j];
                }
            }
        }
        text += " " + dictR[acc];

        return text.substr(1);
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"bad"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"2230223"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "bad bad"; verify_case(0, Arg3, message(Arg0, Arg1, Arg2)); }
    void test_case_1() { string Arr0[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"the", "tie"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0843#000843#000"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = " tie   tie   "; verify_case(1, Arg3, message(Arg0, Arg1, Arg2)); }
    void test_case_2() { string Arr0[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"bad", "ace", "aad", "aae", "aaf", "acf", "acd", "the", "tie"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"223#02", "23*#00843#0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "aae bad  tie "; verify_case(2, Arg3, message(Arg0, Arg1, Arg2)); }
    void test_case_3() { string Arr0[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"the", "tie", "bad", "ace", "aad", "aae", "aaf", "acf", "acd"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"84300223#02", "23#*"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "the  aae bad"; verify_case(3, Arg3, message(Arg0, Arg1, Arg2)); }
    void test_case_4() { string Arr0[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"bad", "ace", "aad", "aae", "tie", "aaf", "acf", "acd", "the"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"223#02", "23######"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "aae bad"; verify_case(4, Arg3, message(Arg0, Arg1, Arg2)); }
    void test_case_5() { string Arr0[] = {"", "rq", "lde", "yoauz", "cbfgn", "tjkpx", "wvs", "ih", "m"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"xktgmfmoqlmivm",
        "hmthr",
        "tpjgmnmaremiwm",
        "tpjcmnmyrlmhvm",
        "xkpnmgmzqdmhsm",
        "wqopvvmiig",
        "melbcbqeeg",
        "jkxnmbmardmhwm",
        "kpxnmcmyqlmism",
        "wrztvsmhhf",
        "srztssmiic",
        "pxtgmfmyrdmhwm",
        "vqoxswmiin",
        "wryksvmihb",
        "ptjfmbmoremhvm"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"00",
            "7246779885##00000089682000007246779885##0000724677",
            "9885#000089682000093355523350066659594239879###000"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "  wqopvvmiig      hmthr     wqopvvmiig    vqoxswmiin    hmthr    melbcbqeeg  pxtgmfmyrdmhwm   "; verify_case(5, Arg3, message(Arg0, Arg1, Arg2)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    T9 ___test;

    ___test.run_test(-1);

}

// END CUT HERE
