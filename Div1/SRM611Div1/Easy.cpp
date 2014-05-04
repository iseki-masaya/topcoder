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

class LCMSet {

public:
    int gcd(int a, int b) {
        while (b != 0) {
            int c = b;
            b = a%b;
            a = c;
        }
        return a;
    }

    bool include(vector<int> A, int x) {
        int lcm = 1;
        for (int y : A) {
            if (x%y == 0) {
                lcm = lcm / gcd(lcm, y) * y;
            }
        }
        return lcm == x;
    }

    vector<int> compress(vector<int> A) {
        sort(A.begin(), A.end());
        vector<int> res(1,A[0]);
        for (int x : A) {
            if (!include(res, x)) {
                res.push_back(x);
            }
        }
        return res;
    }

    string equal(vector <int> A, vector <int> B) {
        return compress(A) == compress(B) ? "Equal" : "Not equal";
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {2,3,4,12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Equal"; verify_case(0, Arg2, equal(Arg0, Arg1)); }
    void test_case_1() { int Arr0[] = {4,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6,36}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Not equal"; verify_case(1, Arg2, equal(Arg0, Arg1)); }
    void test_case_2() { int Arr0[] = {2,3,5,7,14,105}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,5,6,7,30,35}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Equal"; verify_case(2, Arg2, equal(Arg0, Arg1)); }
    void test_case_3() { int Arr0[] = {2,3,5,7,14,105}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,5,6,7,30,36}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Not equal"; verify_case(3, Arg2, equal(Arg0, Arg1)); }
    void test_case_4() { int Arr0[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Equal"; verify_case(4, Arg2, equal(Arg0, Arg1)); }
    void test_case_5() { int Arr0[] = {999999999,1953125,512,1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {999999999,1953125,512}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Equal"; verify_case(5, Arg2, equal(Arg0, Arg1)); }
    void test_case_6() { int Arr0[] = {161, 1453360, 18, 22781370, 8722, 3164153, 34622953, 10, 792323, 42821, 29950, 40, 179080, 64311, 50, 7574, 9273, 582, 37863540, 6, 598, 4195669, 394, 9, 7856, 7111240, 963, 484, 934036170, 8, 2720, 47, 25006, 41, 201274, 185, 781, 72, 5482741, 20, 5, 7284, 4840, 5734, 96, 748, 295, 39616150, 58967613}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {18, 37863540, 58967613, 3164153, 41, 9, 582, 394, 484, 8, 7111240, 5, 25006, 7856, 10, 5482741, 748, 201274, 781, 50, 9273, 31126524, 2720, 72, 5734, 185, 8722, 6, 963, 34622953, 42821, 598, 40, 7574, 7284, 29950, 64311, 20, 47, 22781370, 295, 1640, 161, 96, 4195669, 792323}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Equal"; verify_case(6, Arg2, equal(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    LCMSet ___test;

    ___test.run_test(6);

}

// END CUT HERE
