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

#define L_INF (1)
#define INF (1<<29)
#define EPS 1e-6

using namespace std;

class ColoringRectangle {

public:

    int
    chooseDisks(int width, int height, vector <int> red, vector <int> blue)
    {
        vector<double> r(red.size(),-1),b(blue.size(),-1);
        double h = (height/2.0)*(height/2.0);
        for (int n=0; n<2; ++n) {
            vector<double> &t = n&1 ? r : b;
            vector<int> &u = n&1 ? red : blue;
            for (int i=0; i<t.size(); ++i) {
                double l = (u[i]/2.0)*(u[i]/2.0);
                if (l-h >= 0) {
                    t[i] = 2.0*sqrt(l-h);
                }
            }
            sort(t.begin(), t.end(),greater<double>());
        }

        int ans = INF;
        int lim = min((int)red.size(),(int)blue.size());
        red.push_back(-1) , blue.push_back(-1);
        for (int n=0; n<2; ++n) {
            bool isPossible = false;
            double res = 0;
            int i=0;
            for (; i<=2*lim;) {
                double t = (i+n)&1 ? r[i/2] : b[i/2];
                if (t == -1) {
                    break;
                }
                res += (i+n)&1 ? r[i/2] : b[i/2];
                ++i;
                if (width <= res) {
                    isPossible = true;
                    break;
                }
            }
            if (isPossible) {
                ans = min(ans,i);
            }
        }

        return ans != INF ? ans : -1;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 10; int Arg1 = 5; int Arr2[] = {10,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4,3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(0, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_1() { int Arg0 = 30; int Arg1 = 5; int Arr2[] = {4,10,7,8,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5,6,11,7,5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(1, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_2() { int Arg0 = 16; int Arg1 = 4; int Arr2[] = {6,5,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(2, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_3() { int Arg0 = 4; int Arg1 = 4; int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(3, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_4() { int Arg0 = 6; int Arg1 = 2; int Arr2[] = {6,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(4, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    ColoringRectangle ___test;

    ___test.run_test(-1);

}

// END CUT HERE
