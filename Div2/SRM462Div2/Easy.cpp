/*
          mem   time
 bfs      464k  157ms
 dijkstra 384k  94ms
 */

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

#define L_INF (1)
#define INF (1<<29)
#define EPS 1e-6

//#define DEB

using namespace std;

class Archery {

public:

    double
    expectedPoints(int N, vector <int> ringPoints)
    {
        int r = N+1;
        vector<double> prob(r);
        double deno = (r*r);
        for (int i=0; i<r; ++i) {
            double nume = (i+1)*(i+1) - i*i;
            prob[i] = nume/deno;
        }

        double ans = 0;
        for (int i=0; i<r; ++i) {
            ans += prob[i]*ringPoints[i];
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 1; int Arr1[] = {10, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.5; verify_case(0, Arg2, expectedPoints(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 3; int Arr1[] = {1, 1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(1, Arg2, expectedPoints(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 4; int Arr1[] = {100, 0, 100, 0, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 60.0; verify_case(2, Arg2, expectedPoints(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 9; int Arr1[] = {69, 50, 79, 16, 52, 71, 17, 96, 56, 32}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 51.96; verify_case(3, Arg2, expectedPoints(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    Archery ___test;

    ___test.run_test(-1);

}

// END CUT HERE
