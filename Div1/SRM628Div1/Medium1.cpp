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

class CircuitsConstruction {

public:

    int maximizeResistance(string circuit, vector <int> conductors) {
        stack<int> s;
        for (int i=(int)circuit.size()-1; i>=0; --i) {
            if (circuit[i] == 'X') {
                s.push(1);
            } else {
                int p = s.top(); s.pop();
                int q = s.top(); s.pop();
                if (circuit[i] == 'A')
                    s.push(p+q);
                else
                    s.push(max(p, q));
            }
        }
        int c = s.top();
        sort(conductors.rbegin(), conductors.rend());
        return accumulate(conductors.begin(), conductors.begin()+c, 0);
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "BXBXX"; int Arr1[] = {8, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; verify_case(0, Arg2, maximizeResistance(Arg0, Arg1)); }
    void test_case_1() { string Arg0 = "AAXXAXAXX"; int Arr1[] = {1, 1, 2, 8, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 22; verify_case(1, Arg2, maximizeResistance(Arg0, Arg1)); }
    void test_case_2() { string Arg0 = "AXBXX"; int Arr1[] = {8, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 11; verify_case(2, Arg2, maximizeResistance(Arg0, Arg1)); }
    void test_case_3() { string Arg0 = "BAAXBXXBXAXXBBAXXBXXAAXXX"; int Arr1[] = {17, 7, 21, 102, 56, 72, 88, 15, 9, 192, 16, 8, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 454; verify_case(3, Arg2, maximizeResistance(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    CircuitsConstruction ___test;

    ___test.run_test(-1);

}

// END CUT HERE
