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
#include <time.h>

#define INF (1<<28)

using namespace std;

#define MAX_N 55

class LinearTravellingSalesman {

public:

    int
    findMinimumDistance(vector <int> x, vector <int> y)
    {
        int dist[MAX_N][MAX_N];
        int N = (int)x.size();
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                dist[i][j] = abs(x[i]-x[j]) + abs(y[i]-y[j]);
            }
        }
        bool used[MAX_N] = {false};

        int ans = INF;
        for (int k=0; k<N; ++k) {
            int cpos = k;
            int tans = 0;
            memset(used, false, sizeof(used));
            for (int i=1; i<N; ++i) {
                used[cpos] = true;
                int res = INF;
                int pos = 0;
                for (int j=0; j<N; ++j) {
                    if (!used[j]) {
                        if (res > dist[cpos][j]) {
                            res = dist[cpos][j];
                            pos = j;
                        }
                    }
                }
                tans += res;
                cpos = pos;
            }
            ans = min(tans,ans);
        }

        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {1,3,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, findMinimumDistance(Arg0, Arg1)); }
    void test_case_1() { int Arr0[] = {3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, findMinimumDistance(Arg0, Arg1)); }
    void test_case_2() { int Arr0[] = {0,100,1000,10000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,10,100,1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 11000; verify_case(2, Arg2, findMinimumDistance(Arg0, Arg1)); }
    void test_case_3() { int Arr0[] = {80,60,70,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50,70,60,80}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 60; verify_case(3, Arg2, findMinimumDistance(Arg0, Arg1)); }
    void test_case_4() { int Arr0[] = {7,7,7,7,7,7,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {105,1231,5663,295,3062,380,7777}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7672; verify_case(4, Arg2, findMinimumDistance(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    LinearTravellingSalesman ___test;

    ___test.run_test(-1);

}

// END CUT HERE
