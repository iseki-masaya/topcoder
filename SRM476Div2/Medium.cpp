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
#include <time.h>
#include <numeric>

using namespace std;

#define INF (1<<26)

class Badgers {

public:

    int
    feedMost(vector <int> hunger, vector <int> greed, int totalFood)
    {
        vector<int> b;
        int res = 0;
        for (int i=1; i<=hunger.size(); ++i) {
            b.clear();
            for (int j=0; j<hunger.size(); ++j) {
                int t = hunger[j] + greed[j]*(i-1);
                b.push_back(t);
            }
            sort(b.begin(), b.end());
            int sum = 0;
            for (int k=0; k<i; ++k) {
                sum += b[k];
            }
            if (sum <= totalFood) {
                res = i;
            }
        }

        return res;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; int Arg3 = 2; verify_case(0, Arg3, feedMost(Arg0, Arg1, Arg2)); }
    void test_case_1() { int Arr0[] = {5,2,1,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,2,4,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 19; int Arg3 = 3; verify_case(1, Arg3, feedMost(Arg0, Arg1, Arg2)); }
    void test_case_2() { int Arr0[] = {1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000,1000,1000,1000,1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; int Arg3 = 1; verify_case(2, Arg3, feedMost(Arg0, Arg1, Arg2)); }
    void test_case_3() { int Arr0[] = {803, 925, 256, 465, 665, 537, 896, 293, 279, 491, 31, 891, 688, 616, 722, 962, 474, 456, 589, 18, 380, 772, 925, 367, 264, 693, 741, 516, 403, 859, 394, 948, 413, 129, 684, 474, 310, 697, 569, 624, 477, 681, 891}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {244, 257, 908, 393, 5, 286, 840, 815, 798, 58, 519, 883, 112, 367, 835, 240, 648, 86, 464, 515, 673, 920, 777, 689, 565, 959, 268, 70, 575, 929, 221, 336, 102, 223, 495, 399, 49, 92, 640, 74, 52, 605, 752}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 933698; int Arg3 = 43; verify_case(3, Arg3, feedMost(Arg0, Arg1, Arg2)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    Badgers ___test;

    ___test.run_test(-1);

}

// END CUT HERE
