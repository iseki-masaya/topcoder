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
#include <numeric>
#include <stdio.h>
#include <string.h>
#include <iomanip>

#define INF (1<<30)
#define LINF (5e18)

const double EPS = 1.0e-8;

using namespace std;

class Cut {

public:
    template<class T>
    struct comp {
        bool operator()(const T& lhs, const T& rhs) const {
            if (lhs == 20) {
                return false;
            }
            else if (rhs == 20) {
                return true;
            }
            else if (lhs%10 == 0 || rhs %10 == 0) {
                if (lhs%10 != 0) return true;
                if (rhs%10 != 0) return false;
                return lhs > rhs;
            }
            else {
                return lhs > rhs;
            }
        }
    };

    int getMaximum(vector <int> eelLengths, int maxCuts) {
        int N = (int)eelLengths.size();
        int ans = 0;
        priority_queue<int,vector<int>,comp<int> > que;

        for (int i=0; i<N; ++i) {
            if (eelLengths[i] == 10)            ++ans;
            else if (eelLengths[i] > 10)    que.push(eelLengths[i]);
        }

        for (int i=0; i<maxCuts; ++i) {
            if (que.empty()) break;
            int p = que.top(); que.pop();
            if (p == 20)
                ans += 2;
            else if (p < 20)
                ++ans;
            else
                ++ans , que.push(p-10);
        }

        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {13, 20, 13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(0, Arg2, getMaximum(Arg0, Arg1)); }
    void test_case_1() { int Arr0[] = {5, 5, 5, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 0; verify_case(1, Arg2, getMaximum(Arg0, Arg1)); }
    void test_case_2() { int Arr0[] = {34, 10, 48}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 5; verify_case(2, Arg2, getMaximum(Arg0, Arg1)); }
    void test_case_3() { int Arr0[] = {13, 15, 13, 15, 20, 20, 20, 23, 25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 350; int Arg2 = 14; verify_case(3, Arg2, getMaximum(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    Cut ___test;

    ___test.run_test(3);

}

// END CUT HERE
