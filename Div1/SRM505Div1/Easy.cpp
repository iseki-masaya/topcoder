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

const long long LINF = (1e15);
const int INF = (1<<27);
#define EPS 1e-6
const int MOD = 1000000009;

using namespace std;

class RectangleArea {

public:
    vector<string> k;
    size_t X,Y;

    void rec(int x,int y) {
        k[y][x] = 'Y';

        for (int cy=0; cy<Y; ++cy) {
            for (int cx=0; cx<X; ++cx) {
                int N = (k[y][x] == 'Y') + (k[cy][x] == 'Y') + (k[y][cx] == 'Y') + (k[cy][cx] == 'Y');
                if (N == 3) {
                    if (k[cy][x]  == 'N') rec(cx, y );
                    if (k[y][cx]  == 'N') rec(x , cy);
                    if (k[cy][cx] == 'N') rec(cx, cy);
                }
            }
        }
    }

    int minimumQueries(vector <string> known) {
        this->k=known;
        this->X=known[0].size();
        this->Y=known.size();

        for (int y=0; y<Y; ++y)
            for (int x=0; x<X; ++x)
                if (k[y][x] == 'Y')
                    rec(x, y);

        int ans = 0;
        for (int y=0; y<Y; ++y) {
            for (int x=0; x<X; ++x) {
                if (k[y][x] == 'N') {
                    rec(x, y);
                    ++ans;
                }
            }
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"NN",
        "NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, minimumQueries(Arg0)); }
    void test_case_1() { string Arr0[] = {"YNY",
        "NYN",
        "YNY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minimumQueries(Arg0)); }
    void test_case_2() { string Arr0[] = {"YY",
        "YY",
        "YY",
        "YY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, minimumQueries(Arg0)); }
    void test_case_3() { string Arr0[] = {"NNNNNNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, minimumQueries(Arg0)); }
    void test_case_4() { string Arr0[] = {"NNYYYNN",
        "NNNNNYN",
        "YYNNNNY",
        "NNNYNNN",
        "YYNNNNY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, minimumQueries(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    RectangleArea ___test;

    ___test.run_test(-1);

}

// END CUT HERE
