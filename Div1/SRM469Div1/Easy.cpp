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

class TheMoviesLevelOneDivOne {

public:

    long long find(int n, int m, vector <int> row, vector <int> seat) {
        map<int, vector<int> > s;
        int N = (int)row.size();
        for (int i=0; i<N; ++i) {
            s[row[i]].push_back(seat[i]);
        }
        int sub = 0;
        for (map<int, vector<int> >::iterator it = s.begin(), end = s.end(); it != end; ++it) {
            vector<int> &t = it->second;
            sort(t.begin(), t.end());
            int M = (int)t.size();
            int tmpSub = 0;
            for (int i=0; i<M; ++i) {
                int p = t[i];
                if (p == m && (i!=0 && t[i]-t[i-1]==1)) {
                    continue;
                }
                else if (p == 1 || p == m || (i!=0 && t[i]-t[i-1]==1) ) {
                    tmpSub++;
                }
                else {
                    tmpSub += 2;
                }
            }
            sub += tmpSub >= m ? m-1 : tmpSub;
        }

        return (long long)n*(m-1) - sub;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 2; int Arg1 = 3; int Arr2[] = {1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2, 3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 1LL; verify_case(0, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_1() { int Arg0 = 2; int Arg1 = 3; int Arr2[] = {1, 1, 1, 2, 2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 2, 3, 1, 2, 3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 0LL; verify_case(1, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_2() { int Arg0 = 4; int Arg1 = 7; int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 23LL; verify_case(2, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_3() { int Arg0 = 25; int Arg1 = 4; int Arr2[] = {20, 16, 23, 15, 20, 12, 3, 13, 4, 22, 25, 3, 22, 7, 9, 24, 13, 3, 4, 18, 15, 17, 21, 23, 5, 2, 13, 24, 5, 10, 13, 16, 7, 5, 23, 22, 4, 6, 18, 11, 24, 19, 7, 14, 19, 19, 17}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4, 2, 3, 1, 1, 4, 2, 1, 4, 3, 1, 3, 1, 4, 4, 2, 4, 1, 1, 3, 3, 1, 3, 1, 3, 4, 3, 1, 4, 3, 2, 3, 2, 2, 2, 2, 3, 2, 4, 3, 3, 3, 1, 3, 1, 4, 4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); long long Arg4 = 22LL; verify_case(3, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    TheMoviesLevelOneDivOne ___test;

    ___test.run_test(-1);

}

// END CUT HERE
