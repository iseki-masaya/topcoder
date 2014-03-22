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

class GooseTattarrattatDiv1 {

public:
    bool visited[55];
    string conn,S;
    int N;

    void rec(int i) {
        if (!visited[i]) {
            visited[i] = true;
            conn.push_back(S[i]);
            for (int j=0; j<N; ++j) {
                if (S[i] == S[j] || j == N - i - 1 ) {
                    rec(j);
                }
            }
        }
    }

    int calc() {
        int n = (int)conn.size(), m = 0;
        for (char s : conn)
            m = max(m, (int)count(conn.begin(), conn.end(), s));

        return n - m;
    }

    int getmin(string S) {
        memset(visited, false, sizeof(visited));
        this->N = (int)S.size();
        this->S = S;

        int res = 0;
        for (int i=0; i<N; ++i) if (!visited[i]) {
            conn = "";
            rec(i);
            res += calc();
        }
        return res;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "geese"; int Arg1 = 2; verify_case(0, Arg1, getmin(Arg0)); }
    void test_case_1() { string Arg0 = "tattarrattat"; int Arg1 = 0; verify_case(1, Arg1, getmin(Arg0)); }
    void test_case_2() { string Arg0 = "xyyzzzxxx"; int Arg1 = 2; verify_case(2, Arg1, getmin(Arg0)); }
    void test_case_3() { string Arg0 = "xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag"; int Arg1 = 11; verify_case(3, Arg1, getmin(Arg0)); }
    void test_case_4() { string Arg0 = "abaabb"; int Arg1 = 3; verify_case(4, Arg1, getmin(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    GooseTattarrattatDiv1 ___test;

    ___test.run_test(-1);

}

// END CUT HERE
