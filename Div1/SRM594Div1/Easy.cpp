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

#define INF (1<<28)
#define EPS 1e-8

using namespace std;

class AstronomicalRecords {

public:
    int
    calc(vector<int> &A,vector<int> &B,int a0,int b0)
    {
        int N = (int)A.size();
        int M = (int)B.size();
        vector<int> a(A);
        vector<int> b(B);
        for (int i=0; i<N; ++i) {
            a[i] *= b0;
        }
        for (int i=0; i<M; ++i) {
            b[i] *= a0;
        }
        int dp[55][55];
        memset(dp, 0, sizeof(dp));
        for (int i=1; i<=N; ++i) {
            for (int j=1; j<=M; ++j) {
                if (a[i-1] == b[j-1]) {
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1] + 1);
                }
                dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
            }
        }
        int res = 0;
        for (int i=0; i<=M; ++i) {
            res = max(res, dp[N][i]);
        }
        return res;
    }

    int
    minimalPlanets(vector <int> A, vector <int> B)
    {
        int N = (int)A.size();
        int M = (int)B.size();
        int res = 0;
        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                res = max(res, calc(A, B, A[i], B[j]));
            }
        }
        return N+M-res;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4();if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {1,2,1,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,1,2,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(0, Arg2, minimalPlanets(Arg0, Arg1)); }
    void test_case_1() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,4,6,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, minimalPlanets(Arg0, Arg1)); }
    void test_case_2() { int Arr0[] = {2,3,2,3,2,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {600,700,600,700,600,700,600}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(2, Arg2, minimalPlanets(Arg0, Arg1)); }
    void test_case_3() { int Arr0[] = {1,2,3,4,5,6,7,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6,7,8,9,10,11,12}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(3, Arg2, minimalPlanets(Arg0, Arg1)); }
    void test_case_4() { int Arr0[] = {100000000,200000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {200000000,100000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(4, Arg2, minimalPlanets(Arg0, Arg1)); }
        void test_case_5() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 75; verify_case(5, Arg2, minimalPlanets(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    AstronomicalRecords ___test;

    ___test.run_test(-1);

}

// END CUT HERE
