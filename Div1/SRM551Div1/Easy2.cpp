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
#include <numeric>
#include <stdio.h>
#include <string.h>

#define INF (1<<28)

using namespace std;

class ColorfulChocolates {

public:

    vector<int>
    calc_sum_cost(string &chocolates,int p,char target)
    {
        int N = (int)chocolates.size();
        vector<int> cost;
        int lsize = 0;
        for (int l=p-1; l>=0; --l) {
            if (chocolates[l] == target) {
                ++lsize;
                cost.push_back(p-l-lsize);
            }
        }
        int rsize = 0;
        for (int r=p+1; r<N; ++r) {
            if (chocolates[r] == target) {
                ++rsize;
                cost.push_back(r-p-rsize);
            }
        }
        sort(cost.begin(), cost.end());
        vector<int> sum(cost.size()+1);
        int M = (int)cost.size();
        sum[0] = 0;
        for (int i=0; i<M; ++i) {
            sum[i+1] = sum[i]+cost[i];
        }
        return sum;
    }

    int
    maximumSpread(string chocolates, int maxSwaps)
    {
        int N = (int)chocolates.size();
        int ans = 0;
        for (int p=0; p<N; ++p) {
            char target = chocolates[p];
            vector<int> cost(calc_sum_cost(chocolates, p, target));
            int res = (int)distance(cost.begin(),upper_bound(cost.begin(), cost.end(), maxSwaps));
            ans = max(ans,res);
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5();}
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "ABCDCBC"; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, maximumSpread(Arg0, Arg1)); }
    void test_case_1() { string Arg0 = "ABCDCBC"; int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, maximumSpread(Arg0, Arg1)); }
    void test_case_2() { string Arg0 = "ABBABABBA"; int Arg1 = 3; int Arg2 = 4; verify_case(2, Arg2, maximumSpread(Arg0, Arg1)); }
    void test_case_3() { string Arg0 = "ABBABABBA"; int Arg1 = 4; int Arg2 = 5; verify_case(3, Arg2, maximumSpread(Arg0, Arg1)); }
    void test_case_4() { string Arg0 = "QASOKZNHWNFODOQNHGQKGLIHTPJUVGKLHFZTGPDCEKSJYIWFOO"; int Arg1 = 77; int Arg2 = 5; verify_case(4, Arg2, maximumSpread(Arg0, Arg1)); }
    void test_case_5() { string Arg0 = "SKAURDVVZH"; int Arg1 = 32; int Arg2 = 2; verify_case(5, Arg2, maximumSpread(Arg0, Arg1)); }

    // END CUT HERE

};



// BEGIN CUT HERE

int main() {

    ColorfulChocolates ___test;

    ___test.run_test(-1);

}

// END CUT HERE
