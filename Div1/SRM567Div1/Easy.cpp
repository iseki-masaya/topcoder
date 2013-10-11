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

#define INF (1<<30)
#define EPS 1e-6

using namespace std;

#define MAX_N 55

class PenguinSledding {

public:
    long long
    countDesigns(int numCheckpoints, vector <int> checkpoint1, vector <int> checkpoint2)
    {
        bool conn[MAX_N][MAX_N];
        memset(conn, false, sizeof(conn));
        int N = (int)checkpoint1.size();
        for (int i=0; i<N; ++i) {
            int s = checkpoint1[i]-1;
            int t = checkpoint2[i]-1;
            conn[s][t] = true;
            conn[t][s] = true;
        }

        long long res = 1;
        res += N;
        for (int i=0; i<numCheckpoints; ++i) {
            int n = 0;
            for (int k=0; k<numCheckpoints; ++k) {
                if (conn[i][k]) {
                    ++n;
                }
            }
            res += (1LL<<n) - n - 1;
        }

        for (int i=0; i<numCheckpoints; ++i) {
            for (int j=i+1; j<numCheckpoints; ++j) {
                for (int k=j+1; k<numCheckpoints; ++k) {
                    if (conn[i][j] && conn[j][k] && conn[k][i]) {
                        ++res;
                    }
                }
            }
        }

        return res;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 2; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 2LL; verify_case(0, Arg3, countDesigns(Arg0, Arg1, Arg2)); }
    void test_case_1() { int Arg0 = 4; int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 6LL; verify_case(1, Arg3, countDesigns(Arg0, Arg1, Arg2)); }
    void test_case_2() { int Arg0 = 6; int Arr1[] = {1,3,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 5LL; verify_case(2, Arg3, countDesigns(Arg0, Arg1, Arg2)); }
    void test_case_3() { int Arg0 = 50; int Arr1[] = {40, 40, 40, 40, 40, 40, 40, 40,
        40, 40, 40, 40, 50, 40, 40, 40,
        23, 4, 24, 40, 22, 40, 8, 40, 40,
        40, 34, 21, 40, 40, 38, 40, 40,
        40, 40, 40, 28, 40, 40, 40, 40,
        46, 13, 40, 40, 40, 47, 40, 40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {45, 42, 20, 48, 12, 32, 25, 10,
            26, 39, 16, 2, 19, 43, 37, 17,
            19, 19, 19, 18, 19, 27, 19, 29,
            11, 36, 19, 19, 1, 41, 19, 35,
            14, 33, 49, 3, 19, 7, 5, 19, 31,
            19, 19, 6, 9, 15, 19, 44, 30}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 68719493118LL; verify_case(3, Arg3, countDesigns(Arg0, Arg1, Arg2)); }
    void test_case_4() { int Arg0 = 36; int Arr1[] = {13, 24, 24, 20, 31, 16, 10, 36, 34, 32,
        28, 5, 20, 29, 23, 2, 14, 4, 9, 5, 19,
        21, 8, 1, 26, 27, 25, 15, 22, 30, 30,
        6, 11, 7, 2, 35, 13, 29, 4, 12, 33, 18,
        13, 14, 17, 35, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10, 15, 27, 1, 29, 11, 5, 18, 33, 1, 9,
            2, 31, 6, 19, 10, 33, 18, 6, 27, 3, 22,
            4, 12, 31, 30, 34, 16, 7, 24, 3, 28, 15,
            21, 22, 8, 26, 20, 14, 32, 25, 17, 35,
            8, 36, 26, 23}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 162LL; verify_case(4, Arg3, countDesigns(Arg0, Arg1, Arg2)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    PenguinSledding ___test;

    ___test.run_test(-1);

}

// END CUT HERE
