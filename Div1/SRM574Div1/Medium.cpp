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

using namespace std;

#define MAX_MASK 1<<18
#define MAX_N 18

long long dp[MAX_MASK][MAX_N];

class PolygonTraversal {

public:
    int N;
    int start;


    bool
    is_intersect(int m,int a,int b)
    {
        if (a > b) {
            std::swap(a,b);
    }

    bool part1 = false, part2 = false;
    for (int i = 0; i < N; i++) {
            if ( m & (1 << i) ) {
                part1 = (part1 ||  (a <  i && i <  b) );
                part2 = (part2 || !(a <= i && i <= b) );
            }
    }
    return part1 && part2;
    }

    long long
    rec(int mask,int p)
    {
        long long &res = dp[mask][p];
        if (res == -1) {
            if (mask == (1<<N)-1) {
                res = is_intersect(mask, p, start);
            }
            else {
                res = 0;
                for (int q=0; q<N; ++q) {
                    if (!(mask>>q & 1) && is_intersect(mask, p, q)) {
                        res += rec(mask|(1<<q), q);
                    }
                }
            }
        }
        return res;
    }

    long long
    count(int N, vector <int> points)
    {
        memset(dp, -1, sizeof(dp));
        this->N = N;
        this->start = points[0]-1;

        int init_mask = 0;
        for (int i=0; i<points.size(); ++i) {
            init_mask += 1<<(points[i]-1);
        }
        int tail = points[points.size()-1] - 1;
        return rec(init_mask, tail);
    }

    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 5; int Arr1[] = {1, 3, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; verify_case(0, Arg2, count(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 6; int Arr1[] = {1, 4, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; verify_case(1, Arg2, count(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 7; int Arr1[] = {2, 4, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(2, Arg2, count(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 7; int Arr1[] = {1, 2, 3, 4, 6, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(3, Arg2, count(Arg0, Arg1)); }
    void test_case_4() { int Arg0 = 18; int Arr1[] = {1, 7, 18}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 4374612736LL; verify_case(4, Arg2, count(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    PolygonTraversal ___test;
    ___test.run_test(-1);

}

// END CUT HERE
