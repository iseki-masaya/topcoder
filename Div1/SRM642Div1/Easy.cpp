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
#include <memory>

const long long LINF = (5e18);
const int INF = (1<<30);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class WaitingForBus {

public:

    double whenWillBusArrive(vector <int> time, vector <int> prob, int s) {
        const int M = 100005*2;
        int N = (int)time.size();
        vector<double> memo(M,0);
        memo[0] = 1.0;
        for (int t=1; t<M; ++t) {
            for (int i=0; i<N; ++i) {
                if (t < time[i] || (t - time[i]) >= s)
                    continue;
                int ct = t - time[i];
                double p = (double)prob[i] / 100.0;
                memo[t] += memo[ct]*p;
            }
        }

        double ans = 0.0;
        for (int t=s; t<M; ++t)
            ans += (t-s)*memo[t];

        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {5,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {90,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; double Arg3 = 9.5; verify_case(0, Arg3, whenWillBusArrive(Arg0, Arg1, Arg2)); }
    void test_case_1() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 101; double Arg3 = 4.0; verify_case(1, Arg3, whenWillBusArrive(Arg0, Arg1, Arg2)); }
    void test_case_2() { int Arr0[] = {5,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50,50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 88888; double Arg3 = 3.666666666666667; verify_case(2, Arg3, whenWillBusArrive(Arg0, Arg1, Arg2)); }
    void test_case_3() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,20,30,40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; double Arg3 = 1.166666666666667; verify_case(3, Arg3, whenWillBusArrive(Arg0, Arg1, Arg2)); }
    void test_case_4() { int Arr0[] = {10,100,1000,10000,100000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {90,4,3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100000; double Arg3 = 21148.147303578935; verify_case(4, Arg3, whenWillBusArrive(Arg0, Arg1, Arg2)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    WaitingForBus ___test;

    ___test.run_test(-1);

}

// END CUT HERE