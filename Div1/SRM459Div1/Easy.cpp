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

class Inequalities {

public:
    typedef pair<string, int> P;

    vector<P> split(vector<string> &s) {
        int N = (int)s.size();
        vector<P> res(N);
        for (int i=0; i<N; ++i) {
            string str = s[i].substr(s[i].find(" ")+1);
            size_t p = str.find(" ");
            string op = str.substr(0, p);
            string number = str.substr(p+1);
            int n;
            stringstream ss;
            ss << number;
            ss >> n;
            res[i] = P(op, 2*n);
        }
        return res;
    }

    int calc(vector<P> &p, int c) {
        int res = 0;
        int N = (int)p.size();
        for (int i=0; i<N; ++i) {
            if ( (p[i].first == "<" && c < p[i].second) ||
                    (p[i].first == "<=" && c <= p[i].second ) ||
                    (p[i].first == "=" && c == p[i].second ) ||
                    (p[i].first == ">" && c > p[i].second )||
                    (p[i].first == ">=" && c >= p[i].second ) ) {
                ++res;
            }
        }
        return res;
    }

    int maximumSubset(vector <string> inequalities) {
        vector<P> p(split(inequalities));
        int ans = 0;
        for (int i = -1; i<2100; ++i) {
            ans = max(ans, calc(p, i));
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"X <= 12","X = 13","X > 9","X < 10","X >= 14"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, maximumSubset(Arg0)); }
    void test_case_1() { string Arr0[] = {"X < 0","X <= 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, maximumSubset(Arg0)); }
    void test_case_2() { string Arr0[] = {"X = 1","X = 2","X = 3","X > 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, maximumSubset(Arg0)); }
    void test_case_3() { string Arr0[] = {"X <= 521","X >= 521","X = 521","X > 902","X > 12","X <= 1000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, maximumSubset(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    Inequalities ___test;

    ___test.run_test(-1);

}

// END CUT HERE
