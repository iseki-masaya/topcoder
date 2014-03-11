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

class LotteryCheating {

public:
    int minimalChange(string ID) {
        int ans = 10;
        int N = (int)ID.size();
        for (long long i=0; i<100000; ++i) {
            stringstream ss;
            string str;
            long long v = i*i;
            ss << v;
            ss >> str;

            if (str.size() > N) {
                break;
            }

            int nz = N - (int)str.size();
            if (nz != 0) {
                string zero(nz,'0');
                str = zero + str;
            }

            int res = 0;
            for (int j=0; j<N; ++j) {
                if (ID[j] != str[j]) {
                    ++res;
                }
            }
            ans = min(ans, res);
        }

        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "1"; int Arg1 = 0; verify_case(0, Arg1, minimalChange(Arg0)); }
    void test_case_1() { string Arg0 = "1234"; int Arg1 = 2; verify_case(1, Arg1, minimalChange(Arg0)); }
    void test_case_2() { string Arg0 = "9000000000"; int Arg1 = 1; verify_case(2, Arg1, minimalChange(Arg0)); }
    void test_case_3() { string Arg0 = "4294967296"; int Arg1 = 0; verify_case(3, Arg1, minimalChange(Arg0)); }
    void test_case_4() { string Arg0 = "7654321"; int Arg1 = 3; verify_case(4, Arg1, minimalChange(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    LotteryCheating ___test;

    ___test.run_test(-1);

}

// END CUT HERE
