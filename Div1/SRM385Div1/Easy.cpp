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
const int INF = (1<<28);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class UnderscoreJustification {

public:

    string justifyLine(vector <string> words, int width) {
        int N = (int)words.size();
        int dN = N -1;
        int c = 0;
        for (int i=0; i<N; ++i)
            c += words[i].size();
        int r = width - c;
        vector<int> more(N,0);
        int m = r%dN;
        for (int i=1; i<N; ++i) {
            if (m > 0 && words[i][0] >= 'a')
                more[i-1]++, --m;
        }
        int back = N-2;
        while (m > 0) {
            if (more[back] > 0) {
                --back;
                continue;
            }
            more[back--]++;
            --m;
        }

        string ans = "";
        for (int i=0; i<N; ++i) {
            ans += words[i];
            if (i == N-1)
                break;
            for (int j=0; j<r/dN + more[i]; ++j)
                ans += '_';
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"A", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; string Arg2 = "A___quick__brown__fox__jumps__over__the__lazy__dog"; verify_case(0, Arg2, justifyLine(Arg0, Arg1)); }
    void test_case_1() { string Arr0[] = {"Alpha", "Beta", "Gamma", "Delta", "Epsilon"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32; string Arg2 = "Alpha_Beta_Gamma__Delta__Epsilon"; verify_case(1, Arg2, justifyLine(Arg0, Arg1)); }
    void test_case_2() { string Arr0[] = {"ur", "j", "RDc", "c", "E", "eKX", "Daj", "W", "PFba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 34; string Arg2 = "ur__j_RDc__c__E__eKX__Daj__W__PFba"; verify_case(2, Arg2, justifyLine(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    UnderscoreJustification ___test;

    ___test.run_test(2);

}

// END CUT HERE
