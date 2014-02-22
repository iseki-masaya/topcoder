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

class TheCoffeeTimeDivOne {

public:

    long long serve(vector<bool> wantTea, bool isTea) {
        long long res = 0;
        int i = (int)wantTea.size()-1;
        while (i > 0) {
            int cnt = 0;
            int v = 0;
            while (i > 0) {
                if (wantTea[i] == isTea) {
                    if (cnt == 0)
                        v = i;
                    ++cnt;
                }
                --i;
                if (cnt == 7)
                    break;
            }
            if (v != 0)
                res += 47 + 2*v;
        }

        return res;
    }

    long long find(int n, vector <int> tea) {
        int N = (int)tea.size();

        long long ans = 4*n;
        vector<bool> wantTea(n+1,false);
        for (int i=0; i<N; ++i)
            wantTea[tea[i]]=true;

        ans += serve(wantTea, true);
        ans += serve(wantTea, false);

        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 2; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 108LL; verify_case(0, Arg2, find(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 2; int Arr1[] = {2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 59LL; verify_case(1, Arg2, find(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 15; int Arr1[] = {1, 2, 3, 4, 5, 6, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 261LL; verify_case(2, Arg2, find(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 16177770; int Arr1[] = {3953997, 14034575, 13458310, 6713667, 6127747, 14786801, 1740977, 6698337, 9815509, 9859739, 942916, 10073431, 12894853, 8618765, 4276273, 3550381, 14816731, 10650403, 3300373, 9574006, 9630391, 12197525, 250903, 1267942, 12088302, 2288971, 7919301, 5819382, 3579661, 11171725, 5731487, 14555683, 9782928, 13883317, 15797443, 7591809, 12635781, 11927892, 2114611, 5353692}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 37388809134855LL; verify_case(3, Arg2, find(Arg0, Arg1)); }
    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    TheCoffeeTimeDivOne ___test;

    ___test.run_test(-1);

}

// END CUT HERE
