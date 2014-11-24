#include <string>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <list>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <bitset>
#include <deque>
//#include <random>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <thread>

const long long LINF = (1e18);
const int INF = (1<<28);
const int sINF = (1<<23);
const int MOD = 1000000007;
const double EPS = 1e-6;

using namespace std;

class SuffixArrayDiv1 {

public:

    bool check(vector<int> &SA, vector<int> &s) {
        vector<string> c;
        string str = "";
        for (int v: s)
            str += v + '0';
        int N = (int)s.size();
        for (int i=0; i<N; ++i)
            c.push_back(str.substr(i));


        sort(c.begin(), c.end());

        for (int i=0; i<N; ++i)
            if (SA[i] != (N-c[i].size()) )
                return false;

        return true;
    }

    int minimalCharacters(vector <int> SA) {
        int N = (int)SA.size();
        vector<int> s(N);

        for (int i=0; i<N; ++i)
            s[SA[i]] = i;

        while (true) {
            bool change = false;
            for (int i=0; i<N; ++i) {
                if (s[i] == 0)
                    continue;
                s[i]--;
                if (check(SA, s)) {
                    change = true;
                    break;
                } else {
                    s[i]++;
                }
            }
            if (!change)
                break;
        }

        set<int > ss;
        for (int v: s)
            ss.insert(v);

        return (int)ss.size();
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {3,0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minimalCharacters(Arg0)); }
    void test_case_1() { int Arr0[] = {3,2,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minimalCharacters(Arg0)); }
    void test_case_2() { int Arr0[] = {0,1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, minimalCharacters(Arg0)); }
    void test_case_3() { int Arr0[] = {7,4,8,6,1,5,2,9,3,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, minimalCharacters(Arg0)); }
    void test_case_4() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, minimalCharacters(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    SuffixArrayDiv1 ___test;

    ___test.run_test(-1);

}

// END CUT HERE
