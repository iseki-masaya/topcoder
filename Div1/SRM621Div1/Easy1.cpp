#include <string>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <list>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <bitset>
#include <deque>
//#include <random>
#include <string.h>
#include <stdlib.h>
#include <vector>

const long long LINF = (1e18);
const int INF = (1<<28);
const int sINF = (1<<23);
const int MOD = 1000000007;
const double EPS = 1e-6;

using namespace std;

class RadioRange {

public:
    typedef pair<double, double> P;

    double dist(long long x, long long y) {
        return sqrt(x*x + y*y);
    }

    P calc(int x, int y, int r) {
        double R = dist(x, y);
        return P( max(0.0, R-r), R+r);
    }

    double RadiusProbability(vector <int> X, vector <int> Y, vector <int> R, int Z) {
        int N = (int)X.size();
        double z = Z;
        vector<P> ps;
        for (int i=0; i<N; ++i) {
            P p = calc(abs(X[i]), abs(Y[i]), R[i]);
            ps.push_back(p);
        }
        ps.push_back(P(1e20, 1e20));
        N++;

        sort(ps.begin(), ps.end());

        double mn = -1, mx = -1, sum = 0;
        for (int i=0; i<N && mn < z; ++i) {
            if (mx < ps[i].first) {
                sum += mx - mn;
                mn = ps[i].first;
                mx = min(z, ps[i].second);
            }
            else if (mx < ps[i].second) {
                mx = min(z, ps[i].second);
            }
        }
        return (z - sum) / z;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8();}
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; double Arg4 = 0.5; verify_case(0, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_1() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; double Arg4 = 0.0; verify_case(1, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_2() { int Arr0[] = {10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; double Arg4 = 0.4142135623730951; verify_case(2, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_3() { int Arr0[] = {11, -11, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 11, -11}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10, 10, 10, 10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 31; double Arg4 = 0.3548387096774194; verify_case(3, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_4() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; double Arg4 = 1.0; verify_case(4, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_5() { int Arr0[] = {1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1000000000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1000000000; double Arg4 = 0.41421356237309503; verify_case(5, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_6() { int Arr0[] = {20, -20, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 20, -20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {50, 50, 50, 50}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 100; double Arg4 = 0.3; verify_case(6, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_7() { int Arr0[] = {0, -60, -62, -60, 63, -97}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-72, 67, 61, -8, -32, 89}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6, 7, 8, 7, 5, 6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 918; double Arg4 = 0.9407071068962471; verify_case(7, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_8() { int Arr0[] = {-196, 450, 79, -220, -916, 991, -451, 462, -58, -353, -500, 783, 816, 511}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {188, 681, -234, -330, -14, 991, -969, 347, -458, -940, 454, -28, 767, -620}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {64, 31, 60, 49, 65, 100, 1, 98, 33, 66, 52, 45, 69, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1484; double Arg4 = 0.22007657635156566; verify_case(7, Arg4, RadiusProbability(Arg0, Arg1, Arg2, Arg3)); }


    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    RadioRange ___test;

    ___test.run_test(-1);

}

// END CUT HERE
