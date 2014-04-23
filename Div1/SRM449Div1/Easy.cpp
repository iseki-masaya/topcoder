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

typedef pair<int, int> P;

class MaxTriangle {

public:

    vector<P> getVector(int x) {
        vector<P> res;
        for (int i=0; i*i<=x; ++i) {
            int y = sqrt(x-i*i);
            if (x == i*i + y*y) {
                res.push_back(P(i,y));
                res.push_back(P(-i,y));
                res.push_back(P(i,-y));
                res.push_back(P(-i,-y));
            }
        }
        return res;
    }

    double calculateArea(int A, int B) {
        vector<P> a(getVector(A));
        vector<P> b(getVector(B));
        double ans = -1;
        int N = (int)a.size();
        int M = (int)b.size();
        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                double x1 = a[i].first;
                double y1 = a[i].second;
                double x2 = b[j].first;
                double y2 = b[j].second;
                ans = max(ans, 0.5*abs(x1*y2-x2*y1));
            }
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 1; int Arg1 = 1; double Arg2 = 0.5; verify_case(0, Arg2, calculateArea(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 3; int Arg1 = 7; double Arg2 = -1.0; verify_case(1, Arg2, calculateArea(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 41; int Arg1 = 85; double Arg2 = 29.5; verify_case(2, Arg2, calculateArea(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    MaxTriangle ___test;

    ___test.run_test(-1);

}

// END CUT HERE
