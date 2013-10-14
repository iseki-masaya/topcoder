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

#define INF (1<<28)
#define EPS 1e-8

using namespace std;

class FoxAndHandle {

public:

    bool
    check(string S,char c,map<char, int> &cs)
    {
        map<char, int> ss;
        for (int i=(int)S.find(c); i<S.size(); ++i) {
            ++ss[S[i]];
        }
        for (map<char, int>::iterator it = cs.begin(); it != cs.end(); ++it) {
            if ((*it).second == 0) {
                continue;
            }
            if (ss[(*it).first] < (*it).second) {
                return false;
            }
        }
        return true;
    }

    string
    lexSmallestName(string S)
    {
        map<char,int> cs;
        for (int i=0; i<S.size(); ++i) {
            cs[S[i]]++;
        }
        for (map<char,int>::iterator it = cs.begin(); it != cs.end(); ++it) {
            (*it).second /= 2;
        }
        string ans = "";
        int N = (int)S.size();
        while (true) {
            if (2*ans.size() == N) {
                return ans;
            }
            for (map<char,int>::iterator it = cs.begin(); it != cs.end(); ++it) {
                if ((*it).second != 0 && check(S,(*it).first,cs)) {
                    ans += (*it).first;
                    --(*it).second;
                    S = S.substr(S.find((*it).first)+1);
                    break;
                }
            }
        }
        return "-1";
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6();}
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "foxfox"; string Arg1 = "fox"; verify_case(0, Arg1, lexSmallestName(Arg0)); }
    void test_case_1() { string Arg0 = "ccieliel"; string Arg1 = "ceil"; verify_case(1, Arg1, lexSmallestName(Arg0)); }
    void test_case_2() { string Arg0 = "abaabbab"; string Arg1 = "aabb"; verify_case(2, Arg1, lexSmallestName(Arg0)); }
    void test_case_3() { string Arg0 = "bbbbaaaa"; string Arg1 = "bbaa"; verify_case(3, Arg1, lexSmallestName(Arg0)); }
    void test_case_4() { string Arg0 = "fedcbafedcba"; string Arg1 = "afedcb"; verify_case(4, Arg1, lexSmallestName(Arg0)); }
    void test_case_5() { string Arg0 = "nodevillivedon"; string Arg1 = "deilvon"; verify_case(5, Arg1, lexSmallestName(Arg0)); }
    void test_case_6() { string Arg0 = "bkbkaajaajkkmfmfliffajaelhihlihajaeohggholihoggo"; string Arg1 = "baaaajkkfmfehhlihjgglioo"; verify_case(6, Arg1, lexSmallestName(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    FoxAndHandle ___test;

    ___test.run_test(-1);

}

// END CUT HERE
