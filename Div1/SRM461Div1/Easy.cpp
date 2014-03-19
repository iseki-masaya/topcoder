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

class ColoringRectangle {

public:

    int chooseDisks(int width, int height, vector <int> red, vector <int> blue) {
        vector<double> rd, bd;
        int R = (int)red.size();
        for (int i=0; i<R; ++i)
            if (red[i] >= height)
                rd.push_back(sqrt(red[i]*red[i] - height*height));

        int B = (int)blue.size();
        for (int i=0; i<B; ++i)
            if (blue[i] >= height)
                bd.push_back(sqrt(blue[i]*blue[i] - height*height));

        sort(rd.begin(), rd.end(), greater<double>());
        sort(bd.begin(), bd.end(), greater<double>());

        int Rd = (int)rd.size() , Bd = (int)bd.size();
        double w = 0;
        for (int i=0; i<min(Rd,Bd); ++i) {
            double mx = max(rd[i] , bd[i]);
            double mn = min(rd[i] , bd[i]);
            if (w + mx > width - EPS)
                return i*2 + 1;
            if (w + mx + mn > width - EPS)
                return i*2 + 2;
            w += mx + mn;
        }
        if (Rd > Bd && w + rd[Bd] > width - EPS)
            return 2*Bd + 1;
        if (Bd > Rd && w + bd[Rd] > width - EPS)
            return 2*Rd +   1;
        return -1;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 11; int Arg1 = 3; int Arr2[] = {5,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(0, Arg4, chooseDisks(Arg0, Arg1, Arg2, Arg3)); }
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
