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

typedef pair<int, int> P;

class RabbitStepping {

public:

    int bit_count(int n) {
        int res = 0;
        while (n > 0) {
            if (n&1) {
                ++res;
            }
            n >>= 1;
        }
        return res;
    }

    void move(vector<P> &next, int i, int c, int p) {
        next[i].first += c;
        next[i].second = p;
    }

    int simulate(string &f, int p) {
        int N = (int)f.size();
        vector<P> prev(N), next(N);
        for (int i=0; i<N; ++i) {
            prev[i] = P((p>>i)&1, -1);
        }

        while (N > 1) {
            for (int i=0; i<N; ++i) {
                int c = prev[i].first;
                int p = prev[i].second;
                if (c != 0) {
                    if (i == 0) {
                        move(next, i+1, c, i);
                    }
                    else if (i >= N-2) {
                        move(next, i-1, c, i);
                    }
                    else if (f[i] == 'W') {
                        move(next, i-1, c, i);
                    }
                    else if (f[i] == 'B') {
                        move(next, i+1, c, i);
                    }
                    else if (f[i] == 'R') {
                        if (p == -1) {
                            move(next, i-1, c, i);
                        }
                        else {
                            move(next, p, c, i);
                        }
                    }
                }
            }

            for (int i=0; i<N; ++i) {
                if (next[i].first == 1) {
                    prev[i] = next[i];
                }
                else {
                    prev[i] = P(0,-1);
                }
                next[i] = P(0,-1);
            }

            N--;
        }

        return prev[0].first + prev[1].first;
    }

    double getExpected(string field, int r) {
        int cnt = 0;
        int sumRabbit = 0;
        int N = (int)field.size();
        int mask = (1<<N);

        for (int i=0; i<mask; ++i) {
            if (bit_count(i) == r) {
                ++cnt;
                sumRabbit += simulate(field, i);
            }
        }

        return (double)sumRabbit / cnt;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "WRBRW"; int Arg1 = 4; double Arg2 = 0.8; verify_case(0, Arg2, getExpected(Arg0, Arg1)); }
    void test_case_1() { string Arg0 = "WWB"; int Arg1 = 2; double Arg2 = 1.3333333333333333; verify_case(1, Arg2, getExpected(Arg0, Arg1)); }
    void test_case_2() { string Arg0 = "WW"; int Arg1 = 1; double Arg2 = 1.0; verify_case(2, Arg2, getExpected(Arg0, Arg1)); }
    void test_case_3() { string Arg0 = "BBBBBBBBBB"; int Arg1 = 4; double Arg2 = 0.9523809523809523; verify_case(3, Arg2, getExpected(Arg0, Arg1)); }
    void test_case_4() { string Arg0 = "RRBRRWRRBRRW"; int Arg1 = 8; double Arg2 = 0.9696969696969697; verify_case(4, Arg2, getExpected(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    RabbitStepping ___test;

    ___test.run_test(-1);

}

// END CUT HERE
