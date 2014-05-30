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
const int INF = (1<<30);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class SubrectanglesOfTable {

public:

    vector<long long> getQuantity(vector <string> &table) {
        int Y = 2*(int)table.size();
        int X = 2*(int)table[0].size();
        vector<long long> ans(26,0);
        for (int x=0; x<X; ++x) {
            for (int y=0; y<Y; ++y) {
                long long sum = (long long)(x+1)*(y+1)*(X-x)*(Y-y);
                int cx = x==0 ? 0 : x%(X/2);
                int cy = y==0 ? 0 : y%(Y/2);
                ans[ table[cy][cx]-'A' ] += sum;
            }
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
    void test_case_0() { string Arr0[] = {"OK"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getQuantity(Arg0)); }
    void test_case_1() { string Arr0[] = {"GOOD", "LUCK"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {0, 0, 320, 280, 0, 0, 280, 0, 0, 0, 280, 280, 0, 0, 640, 0, 0, 0, 0, 0, 320, 0, 0, 0, 0, 0 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getQuantity(Arg0)); }
    void test_case_2() { string Arr0[] = {"TANYA",
        "HAPPY",
        "BIRTH",
        "DAYYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {5168, 1280, 0, 1120, 0, 0, 0, 2560, 1472, 0, 0, 0, 0, 1344, 0, 3008, 0, 1536, 0, 2592, 0, 0, 0, 0, 6320, 0 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getQuantity(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    SubrectanglesOfTable ___test;

    ___test.run_test(-1);

}

// END CUT HERE
