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

class NegativeGraphDiv2 {

public:

    long long findMin(int N, vector <int> s, vector <int> t, vector <int> weight, int charges) {
        vector<vector<int> > dist(N , vector<int>(N, INF));
        int E = (int)s.size();
        for (int i=0; i<N; ++i)
            dist[i][i] = 0;

        for (int i=0; i<E; ++i) {
            int u = s[i] - 1;
            int v = t[i] - 1;
            int w = weight[i];
            dist[u][v] = min(dist[u][v], w);
        }

        for (int k=0; k<N; ++k) {
            for (int i=0; i<N; ++i) {
                for (int j=0; j<N; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        vector<vector<int> > xdist(charges+1, vector<int>(N));
        for (int i=0; i<N; ++i) {
            xdist[0][i] = dist[i][N-1];
        }
        for (int k=1; k<=charges; ++k) {
            for (int i=0; i<N; ++i) {
                xdist[k][i] = xdist[k-1][i];

                for (int j=0; j<E; ++j) {
                    int u = s[j] - 1;
                    int v = t[j] - 1;
                    int w = -weight[j];
                    xdist[k][i] = min(xdist[k][i], dist[i][u] + w + xdist[k-1][v]);
                }
            }
        }

        return xdist[charges][0];
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 3; int Arr1[] = {1,1,2,2,3,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,1,3,1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,5,1,10,1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; long long Arg5 = -9LL; verify_case(0, Arg5, findMin(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_1() { int Arg0 = 1; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {100}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1000; long long Arg5 = -100000LL; verify_case(1, Arg5, findMin(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_2() { int Arg0 = 2; int Arr1[] = {1,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,2,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6,1,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; long long Arg5 = -9LL; verify_case(2, Arg5, findMin(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_3() { int Arg0 = 2; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {98765}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 100; long long Arg5 = -98765LL; verify_case(3, Arg5, findMin(Arg0, Arg1, Arg2, Arg3, Arg4)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    NegativeGraphDiv2 ___test;

    ___test.run_test(-1);

}

// END CUT HERE
