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
#include <stdio.h>
#include <string.h>
#include <numeric>

#define INF (1<<28)

using namespace std;

class NumberNeighbours {

public:

    int
    numPairs(vector <int> numbers)
    {
        map<string, int> m;
        for (int i=0; i<numbers.size(); ++i) {
            string str = "";
            int s = numbers[i];
            while (s != 0) {
                int t = s%10;
                s /= 10;
                if (t != 0) {
                    str += t+'0';
                }
            }
            sort(str.begin(), str.end());
            m[str]++;
        }

        int ans = 0;
        map<string, int>::iterator it = m.begin();
        for (; it != m.end() ; ++it) {
            int s = (*it).second;
            if (s > 1) {
                ans += s*(s-1)/2;
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
    void test_case_0() { int Arr0[] = {10, 1, 100, 20, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, numPairs(Arg0)); }
    void test_case_1() { int Arr0[] = {204, 42, 40020, 200}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, numPairs(Arg0)); }
    void test_case_2() { int Arr0[] = {1, 10, 100, 1000, 10000, 100000, 1000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 21; verify_case(2, Arg1, numPairs(Arg0)); }
    void test_case_3() { int Arr0[] = {3, 33, 333, 3333}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, numPairs(Arg0)); }
    void test_case_4() { int Arr0[] = {1024, 4021, 204, 303, 33, 603, 36, 55, 505}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, numPairs(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    NumberNeighbours ___test;

    ___test.run_test(-1);

}

// END CUT HERE
