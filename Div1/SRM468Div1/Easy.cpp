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

typedef pair<string, int> P;

class T9 {

public:
    int count(string &stroke) {
        int p = 0;
        int res = 0;
        int N = (int)stroke.size();
        for (; p<N; ++p) {
            if (stroke[p] == '#') {
                ++res;
            }
            else if (stroke[p] == '*') {
                res += 5;
            }
            else {
                break;
            }
        }
        stroke = stroke.substr(p);
        return res;
    }

    void parse(vector<P> &res, string &stroke) {
        vector<char> delimiter = {'0','#','*'};
        vector<char> stepper = {'#','*'};
        while (!stroke.empty()) {
            while (stroke[0] == '0') {
                res.push_back(P("0",0));
                stroke = stroke.substr(1);
            }
            int N = (int)stroke.size();
            bool hit = false;
            for (int i=0; i<N; ++i) {
                if (find(delimiter.begin(), delimiter.end(), stroke[i]) != delimiter.end()) {
                    hit = true;
                    string value = stroke.substr(0,i);
                    stroke = stroke.substr(i);
                    int step = count(stroke);
                    res.push_back(P(value,step));
                    break;
                }
            }
            if (!hit && !stroke.empty()) {
                res.push_back(P(stroke,0));
                stroke = "";
            }
        }
    }

    void make_map(map<string, vector<string> > &m, vector<string> &part, vector<string> &dict) {
        int N = (int)dict.size();
        for (int i=0; i<N; ++i) {
            int M = (int)dict[i].size();
            string key(M,'0');
            for (int j=0; j<M; ++j) {
                int p = 0;
                while (part[p].find(dict[i][j]) == string::npos) ++p;
                key[j] = (p+1) + '0';
            }
            m[key].push_back(dict[i]);
        }
        for (map<string, vector<string> >::iterator it = m.begin(), end = m.end(); it != end; ++it) {
            vector<string> &a = it->second;
            sort(a.begin(), a.end());
        }
    }

    string message(vector <string> part, vector <string> dict, vector <string> keystr) {
        string stroke = accumulate(keystr.begin(), keystr.end(), string());
        vector<P> token;
        parse(token, stroke);

        map<string, vector<string> > m;
        m["0"].push_back(" ");
        make_map(m, part, dict);

        string ans = "";
        int N = (int)token.size();
        for (int i=0; i<N; ++i) {
            string key = token[i].first;
            int step = token[i].second;
            ans += m[key][step];
        }

        return ans;
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
    void test_case_5() { string Arr0[] = {"w", "okr", "cx", "tu", "qnas", "ldfh", "yvj", "pibe", "mgz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"wjnghtdgkyytbdwzwtvcbvszidowmrcztxgs", "otoggmicstomzeawslbcourwsnzetpeupptz", "nvhtegvztsxzhxjvjspdtjxewpnojxihwps", "otogzgbcqtomziawadpcrukwqqzpupbuiptz", "wyamhtdgkyytblwgwuvxpvsgbdrwgoxmuxza", "ouomzmixquomgiqwahpcotkwssgptppupetg", "rukgzgixnurgmpawnfpckukwaqgeteiupitz", "ktkmgzbxnurmmbqwqfixktrwqagetpbteeuz", "ktkgggexqukgmbqwslecourwqambtbitpitm", "wynglufgkvyuedwzwtvxijqgpfrwzkcgtxzs", "wjsghthzrjjuidwzwtyxeynmihowzoxmtxma", "ourmzmpxaukzgbqwsfpcrurwnnmbubitibtg", "otrzmzbcatkgmbnwnhixkuowanziubetbbum", "otogzgicstrzgiqwnlixrukwsszetiptipug", "wyngltfzkvjupdwgwuyceyagidrwgoxmucgs", "rtrzmmpxnukzzenwsficrukwnambtipuebuz", "qjdupgymtqxgfcjjvapfuyciwiqkjcpfwbs", "kuogzmexnukmgiswadixotrwaqgeuebtbeug", "wysgltdzkjytifwmwtvceyngifrwmrxgucgq", "rtrzgmbcaukmgbqwalixrtowqsgbueetibtm", "wyszdtdmrjvtihwmwtvxijambhrwmkxmtcgq", "rtrmmgbcnukzmpqwalpxouownqzptiptietm", "ruogzmixatkmmenwslixktowsqmbtpptebtm", "ouozmmecsukmziswndixkuownamiteptbiuz", "kurzmmpcqtkzgeswsdbcoukwsqmiupptiitg", "ruozzzpcqurzgeawafixrtrwnsmbtbeupeuz", "rukmgzbcnukmmbqwqficrtowssmiteiupitm", "ourgmzbxsuoggiqwqlbcrtkwqsmbueptiitm", "mzfkxhyxyldmvx", "zzlrcdvcydlmyx", "otrmmzpxsurgzpqwqhpxrtrwnsgitpbteitm", "zzfoxdvcydfzvx", "rtrgmgpxatrmzpswqhpcktrwsnmbtiptiitg", "yojnagsuohwlwhoacxsitoqwuxpxknqqougpebbwzw", "wvszduhzrjjtbhwgwtvcbvqgblowzkxmuxgn", "wyazhudzrvvtilwgwtvceyazifrwmoxmucza", "zmlocfvxvfdgyc", "ktkzggpcaurmziawqdpcrukwanzitiptieug", "rtkgzgexatrmmiswndicoukwnqmbtppupbtg", "rtrzgmpxauozmiswndbxrurwanmeubeteptg", "gmhkxdvcylfgyc", "ktrmmmpcaukmzenwqhecourwanziueitepug", "vkvsqznurhwlwhkqccnptkawtcpcrssnrumbiiiwmw", "rtkzmzbxsukzmeswadpcrukwnngbtiiupbum", "ruogmzecqtkggiawnlbcktkwnngbtibubpug", "rtogmgecatozzpqwnlpxotkwqqzpteitbptz", "rurzzzixqtommenwshickurwaqgitpbteitg", "wvnzdufmkyjtbfwgwtjxbynmplrwmoxmtxms", "vkvsamstrlwhwlkncxsbuknwucixrqnsougeeppwmw", "wvqmdthmojytpdwzwujcbyszelowmrxguxgn"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"05764897945396377758647381852738618500017596469277", "4861914738759862192394395#0000099623673766973###00", "00576489794539637775864738185273861850000024299983", "5429985156832421559848848849#000242999835429985156", "832421559848848849**##*####*#000175964692774861914", "738759862192394395##000099623673766973##0000576489", "79453963777586473818527386185000242999835429985156", "83242", "1559848848849####000017596469277486191473875986219", "2394395####*00000576489794539637775864738185273861", "8500057648979453963777586473818527386185#000017596", "4692774861914738759862192394395###0000576489794539", "63777586473818527386185000099623673766973##0001759", "64692774861914738759862192394395*#0000576489794539", "63777586473818527386185#00002429998354299851568324", "21559848848849*#*000002429998354299851568324215598", "48848849#*#*#*000000175964692774861914738759862192", "394395*##0000175964692774861914738759862192394395#", "##00099623673766973####000242999835429985156832421", "559848848849##000727559542616162533584251438325552", "498888191000242999835429985156832421559848848849##", "#*###*###00057648979453963777586473818527386185#00"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = " nvhtegvztsxzhxjvjspdtjxewpnojxihwps   wjsghthzrjjuidwzwtyxeynmihowzoxmtxma     zzfoxdvcydfzvx    nvhtegvztsxzhxjvjspdtjxewpnojxihwps     ktkmgzbxnurmmbqwqfixktrwqagetpbteeuz   ruozzzpcqurzgeawafixrtrwnsmbtbeupeuz   wvnzdufmkyjtbfwgwtjxbynmplrwmoxmtxms    zmlocfvxvfdgyc    nvhtegvztsxzhxjvjspdtjxewpnojxihwps   kuogzmexnukmgiswadixotrwaqgeuebtbeug    wysgltdzkjytifwmwtvceyngifrwmrxgucgq     nvhtegvztsxzhxjvjspdtjxewpnojxihwps   qjdupgymtqxgfcjjvapfuyciwiqkjcpfwbs    wvqmdthmojytpdwzwujcbyszelowmrxguxgn    nvhtegvztsxzhxjvjspdtjxewpnojxihwps    zmlocfvxvfdgyc   wyazhudzrvvtilwgwtvceyazifrwmoxmucza    qjdupgymtqxgfcjjvapfuyciwiqkjcpfwbs    ouomzmixquomgiqwahpcotkwssgptppupetg     rtrgmgpxatrmzpswqhpcktrwsnmbtiptiitg      wyngltfzkvjupdwgwuyceyagidrwgoxmucgs    wvqmdthmojytpdwzwujcbyszelowmrxguxgn   zzlrcdvcydlmyx   ktkzggpcaurmziawqdpcrukwanzitiptieug   vkvsamstrlwhwlkncxsbuknwucixrqnsougeeppwmw   rtrmmgbcnukzmpqwalpxouownqzptiptietm   qjdupgymtqxgfcjjvapfuyciwiqkjcpfwbs  "; verify_case(5, Arg3, message(Arg0, Arg1, Arg2)); }


    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    T9 ___test;

    ___test.run_test(-1);

}

// END CUT HERE
