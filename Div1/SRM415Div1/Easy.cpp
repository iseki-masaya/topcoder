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
const int INF = (1<<29);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class ShipLoading {

public:

    vector<int> parse(string s) {
        vector<int> res;
        while (!s.empty()) {
            size_t p = s.find(" ");
            string n = p == string::npos ? s : s.substr(0,p);
            s = p == string::npos ? "" : s.substr(p+1);

            int v;
            stringstream ss;
            ss << n;
            ss >> v;
            res.push_back(v);
        }
        return res;
    }

    bool simulate(vector<int> &cranes, vector<int> &boxes, int time) {
        int N = (int)cranes.size();
        int M = (int)boxes.size();
        int b = 0;
        for (int c=0; c<N; ++c) {
            for (int t=0; t<time && b<M && cranes[c] >= boxes[b] ; ++t)
                ++b;
        }
        return b>=M;
    }

    int minimumTime(vector <int> cranes, vector <string> boxes) {
        vector<int> b(parse(accumulate(boxes.begin(), boxes.end(), string(""))));
        sort(cranes.rbegin(), cranes.rend());
        sort(b.rbegin(), b.rend());
        int lb = 0, ub = 10000, md;
        while (lb < ub) {
            md = (lb + ub)>>1;
            if (simulate(cranes, b, md))
                ub = md;
            else
                lb = md + 1;
        }
        return lb < 10000 ? lb : -1;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {6,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2 5 2 4 7"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, minimumTime(Arg0, Arg1)); }
    void test_case_1() { int Arr0[] = {19,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"14 12 16 19 16 1 5"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, minimumTime(Arg0, Arg1)); }
    void test_case_2() { int Arr0[] = {23,32,25,28}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"5 27 10 16 24 20 2 32 18 7"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, minimumTime(Arg0, Arg1)); }
    void test_case_3() { int Arr0[] = {11,17,5,2,20,7,5,5,20,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"18 18 15 15 17"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, minimumTime(Arg0, Arg1)); }
    void test_case_4() { int Arr0[] = {56,114,979,120,120,87,480}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"221 882 504 358 642 674 212 679 203 279 632 799 79","6 502 275 823 372 594 482 343"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(4, Arg2, minimumTime(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    ShipLoading ___test;

    ___test.run_test(-1);

}

// END CUT HERE
