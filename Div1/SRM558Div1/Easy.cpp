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

#define INF (1<<28)
#define EPS 1e-8
#define MOD 100000000

using namespace std;

class Stamp {

public:
    int
    getMinimumCost(string desiredColor, int stampCost, int pushCost)
    {
        int N = (int)desiredColor.size();
        vector<int> cost(N+1,0);
        vector<int> a(N);
        for (int i=0; i<N; ++i) {
            char c = desiredColor[i];
            if (c == '*') a[i] = 7;
            if (c == 'R') a[i] = 1;
            if (c == 'G') a[i] = 2;
            if (c == 'B') a[i] = 4;
        }

        int res = INF;
        for (int len=1; len<=N; ++len) {
            cost[0] = 0;
            fill(cost.begin()+1, cost.end(), INF);
            for (int i=0; i<N; ++i) {
                int color = 7;
                for (int j=i; j<N; ++j) {
                    color &= a[j];
                    if (!color) break;
                    int seg = j - i + 1;
                    if (seg < len) continue;
                    if (cost[i] != INF) {
                        cost[j+1] = min(cost[j+1],cost[i] + ( (seg+len-1) / len )*pushCost);
                    }
                }
            }
            if (cost[N] != INF) {
                res = min(res,cost[N] + stampCost*len);
            }
        }
        return res;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "RRGGBB"; int Arg1 = 1; int Arg2 = 1; int Arg3 = 5; verify_case(0, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
    void test_case_1() { string Arg0 = "R**GB*"; int Arg1 = 1; int Arg2 = 1; int Arg3 = 5; verify_case(1, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
    void test_case_2() { string Arg0 = "BRRB"; int Arg1 = 2; int Arg2 = 7; int Arg3 = 30; verify_case(2, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
    void test_case_3() { string Arg0 = "R*RR*GG"; int Arg1 = 10; int Arg2 = 58; int Arg3 = 204; verify_case(3, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
    void test_case_4() { string Arg0 = "*B**B**B*BB*G*BBB**B**B*"; int Arg1 = 5; int Arg2 = 2; int Arg3 = 33; verify_case(4, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
    void test_case_5() { string Arg0 = "*R*RG*G*GR*RGG*G*GGR***RR*GG"; int Arg1 = 7; int Arg2 = 1; int Arg3 = 30; verify_case(5, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    Stamp ___test;

    ___test.run_test(-1);

}

// END CUT HERE
