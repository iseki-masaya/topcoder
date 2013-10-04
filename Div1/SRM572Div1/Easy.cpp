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

#define INF (1<<29)
#define EPS 1e-6

using namespace std;

class NewArenaPassword {

public:
    int
    diff(string a,string b)
    {
        int N = (int)a.size();
        int ans = 0;
        for (int i=0; i<N; ++i) {
            if (a[i] != b[i]) {
                ++ans;
            }
        }
        return ans;
    }

    int
    diff(string a,string b,int d)
    {
        int N = (int)a.size();
        int ans = 0;
        map<char, int> m;
        for (int i=0; i<d; ++i) {
            m.clear();
            m[a[i]]++;
            for (int j=i; j<N; j+=d) {
                m[b[j]]++;
            }
            int sum = 0;
            int mx = 0;
            for (map<char, int>::iterator it = m.begin(); it != m.end() ; ++it) {
                sum += (*it).second;
                mx = max(mx,(*it).second);
            }
            ans += sum - mx;
        }
        return ans;
    }

    int
    minChange(string oldPassword, int K)
    {
        int N = (int)oldPassword.size();
        if (2*K <= N) {
            string s = oldPassword.substr(0,K);
            string l = oldPassword.substr(N-K,K);
            return diff(s, l);
        }
        else {
            string s = oldPassword.substr(0,K);
            string l = oldPassword.substr(N-K,K);
            return diff(s,l,N-K);
        }
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "ppppppbppppppppppcpvpppppempppeppipppsppxpvppcpppb"; int Arg1 = 40; int Arg2 = 12; verify_case(0, Arg2, minChange(Arg0, Arg1)); }
    void test_case_1() { string Arg0 = "puyopuyo"; int Arg1 = 4; int Arg2 = 0; verify_case(1, Arg2, minChange(Arg0, Arg1)); }
    void test_case_2() { string Arg0 = "loool"; int Arg1 = 3; int Arg2 = 1; verify_case(2, Arg2, minChange(Arg0, Arg1)); }
    void test_case_3() { string Arg0 = "arena"; int Arg1 = 5; int Arg2 = 0; verify_case(3, Arg2, minChange(Arg0, Arg1)); }
    void test_case_4() { string Arg0 = "ppppppbppppppppppcpvpppppempppeppipppsppxpvppcpppb"; int Arg1 = 40; int Arg2 = 12; verify_case(4, Arg2, minChange(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    NewArenaPassword ___test;

    ___test.run_test(-1);

}

// END CUT HERE
