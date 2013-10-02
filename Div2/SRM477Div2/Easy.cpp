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
#include <numeric>

using namespace std;

#define INF (1<<29)

class VacationTime {

public:

    int
    bestSchedule(int N, int K, vector <int> workingDays)
    {
        int res = INF;
        for (int s=1; s+K-1<=N; ++s) {
            int t = 0;
            for (int i=0; i<K; ++i) {
                int d = s+i;
                for (int j=0; j<workingDays.size(); ++j) {
                    if (workingDays[j] == d) {
                        ++t;
                        break;
                    }
                }
            }
            res = min(res,t);
        }
        return res;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 3; int Arg1 = 3; int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, bestSchedule(Arg0, Arg1, Arg2)); }
    void test_case_1() { int Arg0 = 4; int Arg1 = 3; int Arr2[] = {3, 1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, bestSchedule(Arg0, Arg1, Arg2)); }
    void test_case_2() { int Arg0 = 5; int Arg1 = 3; int Arr2[] = {4, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(2, Arg3, bestSchedule(Arg0, Arg1, Arg2)); }
    void test_case_3() { int Arg0 = 9; int Arg1 = 2; int Arr2[] = {7, 4, 5, 6, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(3, Arg3, bestSchedule(Arg0, Arg1, Arg2)); }
    void test_case_4() { int Arg0 = 1000; int Arg1 = 513; int Arr2[] = {808, 459, 792, 863, 715, 70, 336, 731}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(4, Arg3, bestSchedule(Arg0, Arg1, Arg2)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    VacationTime ___test;

    ___test.run_test(-1);

}

// END CUT HERE
