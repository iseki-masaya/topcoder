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

class ShufflingMachine {

public:

    double stackDeck(vector <int> shuffle, int maxShuffles, vector <int> cardsReceived, int K) {
        map<int, int> cnt;
        int N = (int)shuffle.size();
        int M = (int)cardsReceived.size();

        vector<int> c(N);
        for (int i=0; i<N; ++i)
            c[i] = i;

        for (int i=0; i<maxShuffles; ++i) {
            for (int j=0; j<M; ++j) {
                int p = c[ cardsReceived[j] ];
                cnt[p]++;
            }

            vector<int> tmp(c);
            for (int j=0; j<N; ++j) {
                c[j] = tmp[ shuffle[j] ];
            }
        }

        vector<int> appear;
        for (pair<int, int> p: cnt)
            appear.push_back(p.second);
        sort(appear.rbegin(), appear.rend());
        double ans = 0.0;
        for (int i=0; i<K && i<appear.size(); ++i)
            ans += (double)appear[i] / maxShuffles;

        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; double Arg4 = 0.6666666666666666; verify_case(0, Arg4, stackDeck(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_1() { int Arr0[] = {1,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; double Arg4 = 0.8; verify_case(1, Arg4, stackDeck(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_2() { int Arr0[] = {1,2,0,4,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arr2[] = {0,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; double Arg4 = 1.0; verify_case(2, Arg4, stackDeck(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_3() { int Arr0[] = {0,4,3,5,2,6,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; int Arr2[] = {1,3,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; double Arg4 = 1.0526315789473684; verify_case(3, Arg4, stackDeck(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_4() { int Arr0[] = {3,4,7,2,8,5,6,1,0,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 47; int Arr2[] = {6,3,5,2,8,7,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; double Arg4 = 6.297872340425532; verify_case(4, Arg4, stackDeck(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_5() { int Arr0[] = {45, 3, 20, 6, 32, 47, 19, 11, 28, 38, 27, 5, 4, 49, 23, 44, 15, 29, 24, 34, 39, 13, 25, 30, 41, 33, 46, 35, 1, 31, 9, 10, 40, 43, 7, 16, 12, 42, 8, 2, 0, 37, 14, 36, 48, 17, 18, 26, 21, 22}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 84; int Arr2[] = {32, 48, 40, 22, 13, 25}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 39; double Arg4 = 6.0; verify_case(5, Arg4, stackDeck(Arg0, Arg1, Arg2, Arg3)); }

    // END CUT HERE

};



// BEGIN CUT HERE

int main() {

    ShufflingMachine ___test;

    ___test.run_test(-1);

}

// END CUT HERE
