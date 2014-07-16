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

class InstantRunoffVoting {

public:

    int winner(vector <string> voters) {
        int N = (int)voters[0].size();
        int M = (int)voters.size();
        vector<bool> active(N,true);
        while (true) {
            vector<int> c(N,0);
            for (string s: voters) {
                for (char ch: s) {
                    int v = ch - '0';
                    if (active[v]) {
                        c[v]++;
                        break;
                    }
                }
            }
            int mx = *max_element(c.begin(), c.end());
            vector<int> candidate;
            for (int i=0; i<N; ++i)
                if (c[i] == mx)
                    candidate.push_back(i);

            if (2*mx>M && candidate.size() == 1)
                return candidate[0];

            int cn = 0;
            for (int i=0; i<N; ++i)
                if (active[i])
                    ++cn;

            if (cn == candidate.size())
                break;

            int mn = INF;
            for (int i=0; i<N; ++i)
                if (active[i])
                    mn = min(mn, c[i]);
            for (int i=0; i<N; ++i)
                if (c[i] == mn)
                    active[i] = false;
        }
        return -1;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"01","10","01","01","10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, winner(Arg0)); }
    void test_case_1() { string Arr0[] = {"120","102","210","021","012"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, winner(Arg0)); }
    void test_case_2() { string Arr0[] = {"10","01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, winner(Arg0)); }
    void test_case_3() { string Arr0[] = {"3120","3012","1032"
        ,"3120","2031","2103"
        ,"1230","1230"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, winner(Arg0)); }
    void test_case_4() { string Arr0[] = {"24103","30412","32014","21043","30412"
        ,"32401","14203","04123","30241","02413"
        ,"13042","01432","01342","32401","24301"
        ,"12430","41023","02413","42310","12043"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, winner(Arg0)); }
    void test_case_5() { string Arr0[] = {"0123456789", "9876543210", "9876543210"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(5, Arg1, winner(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    InstantRunoffVoting ___test;

    ___test.run_test(-1);

}

// END CUT HERE
