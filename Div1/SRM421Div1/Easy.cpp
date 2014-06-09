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
const int INF = (1<<30);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class EquilibriumPoints {

public:

    double calc(int s, int e, double p, vector<int> x, vector<int> m) {
        double res = 0.0;
        for (int i=s; i<e; ++i) {
            double d = abs(p-x[i])*abs(p-x[i]);
            res += (double)m[i] / d;
        }
        return res;
    }

    double simulate(int index, double p, vector<int> x, vector<int> m) {
        return calc(index+1, (int)x.size(), p, x, m) - calc(0, index+1, p, x, m);
    }

    vector <double> getPoints(vector <int> x, vector <int> m) {
        int N = (int)x.size();
        vector<double> ans(N-1);
        for (int i=0; i<N-1; ++i) {
            double lb = x[i], ub = x[i+1];
            for (int j=0; j<200; ++j) {
                double md = (lb+ub) / 2.0;
                double t = simulate(i, md, x, m);
                if (t < 0.0)
                    lb = md;
                else
                    ub = md;
            }
            ans[i] = lb;
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
    void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arr2[] = {1.5 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getPoints(Arg0, Arg1)); }
    void test_case_1() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arr2[] = {1.0306534300317156 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getPoints(Arg0, Arg1)); }
    void test_case_2() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arr2[] = {1.4060952084922507, 2.5939047915077493 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getPoints(Arg0, Arg1)); }
    void test_case_3() { int Arr0[] = {2, 3, 5, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 2, 7, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arr2[] = {2.532859446114924, 3.7271944335152813, 6.099953640852538 }; vector <double> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getPoints(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    EquilibriumPoints ___test;

    ___test.run_test(-1);

}

// END CUT HERE
