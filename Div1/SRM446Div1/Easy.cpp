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

#include <random>

const long long LINF = (1e15);
const int INF = (1<<27);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

class CubeWalking {

public:

    string finalPosition(string movement) {
        int N = (int)movement.size();
        int p = 0;
        int x = 0 , y = 0;
        for (int i=0; i<N; ++i) {
            switch (movement[i]) {
                case 'R':
                    p = (p+1)%4;
                    break;
                case 'L':
                    p = (4+p-1)%4;
                    break;
                case 'W':
                    x += dx[p];
                    y += dy[p];
                    break;
            }
        }
        if (x%3 == 0 && y%3 == 0)
            return "GREEN";
        else if (x%3 == 0 || y%3 == 0)
            return "BLUE";
        else
            return "RED";
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "LLRR"; string Arg1 = "GREEN"; verify_case(0, Arg1, finalPosition(Arg0)); }
    void test_case_1() { string Arg0 = "WWWWWWWWWWWW"; string Arg1 = "GREEN"; verify_case(1, Arg1, finalPosition(Arg0)); }
    void test_case_2() { string Arg0 = "WLWRW"; string Arg1 = "RED"; verify_case(2, Arg1, finalPosition(Arg0)); }
    void test_case_3() { string Arg0 = "WWLLWRWLWLLRWW"; string Arg1 = "BLUE"; verify_case(3, Arg1, finalPosition(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    CubeWalking ___test;

    ___test.run_test(-1);

}

// END CUT HERE
