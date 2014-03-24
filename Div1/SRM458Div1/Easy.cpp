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

class BouncingBalls {

public:
    //0:right 1:left

    bool checkDirection(int l,int r, int state) {
        return !((state>>l)&1) && (state>>r)&1;
    }

    int calc(vector<int> &x, int T, int state) {
        int N = (int)x.size();
        int res = 0;
        for (int i=0; i<N; ++i) {
            for (int j=i+1; j<N; ++j) {
                int t = x[j] - x[i];
                if (checkDirection(i, j, state) && (t+1)/2 <= T)
                    ++res;
            }
        }
        return res;
    }

    double expectedBounces(vector <int> x, int T) {
        sort(x.begin(), x.end());

        int collision = 0;
        int lim = 1<<x.size();
        for (int state=0; state<lim; ++state) {
            collision += calc(x,T,state);
        }
        return double(collision) / lim;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 0.25; verify_case(0, Arg2, expectedBounces(Arg0, Arg1)); }
    void test_case_1() { int Arr0[] = {5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 0.0; verify_case(1, Arg2, expectedBounces(Arg0, Arg1)); }
    void test_case_2() { int Arr0[] = {91, 857, 692, 54, 8679, 83, 792, 86, 9537, 913, 64, 592}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 458; double Arg2 = 11.5; verify_case(2, Arg2, expectedBounces(Arg0, Arg1)); }
    void test_case_3() { int Arr0[] = {75432}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 386; double Arg2 = 0.0; verify_case(3, Arg2, expectedBounces(Arg0, Arg1)); }
    void test_case_4() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; double Arg2 = 12.75; verify_case(4, Arg2, expectedBounces(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    BouncingBalls ___test;

    ___test.run_test(-1);

}

// END CUT HERE
