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
const int INF = (1<<30);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class MinimumSquare {

public:
    long long getY(vector<int> &ys, int K) {
        sort(ys.begin(), ys.end());
        long long res = numeric_limits<long long>::max();
        int N = (int)ys.size();
        for (int i=0; i<=N-K; ++i) {
            res = min<long long>(res, ys[i+K-1] - ys[i]);
        }
        return res;
    }

    long long minArea(vector <int> x, vector <int> y, int K) {
        typedef pair<int, int> P;
        vector<P> ps;
        transform(x.begin(), x.end(), y.begin(), back_inserter(ps), function<P(int,int)>( make_pair<int,int> ) );
        sort(ps.begin(), ps.end());

        long long ans = numeric_limits<long long>::max();
        int N = (int)ps.size();
        for (int i=0; i<N; ++i) {
            for (int j=i+K; j<=N; ++j) {
                vector<int> ys;
                transform(ps.begin()+i, ps.begin()+j, back_inserter(ys), [](const P &p){return p.second;} );

                long long l = max<long long>(ps[j-1].first - ps[i].first, getY(ys, K) ) + 2;
                ans = min<long long>(ans, l*l);
            }
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {0, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; long long Arg3 = 81LL; verify_case(0, Arg3, minArea(Arg0, Arg1, Arg2)); }
    void test_case_1() { int Arr0[] = {-4, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3 , -1, -2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; long long Arg3 = 16LL; verify_case(1, Arg3, minArea(Arg0, Arg1, Arg2)); }
    void test_case_2() { int Arr0[] = {0, 0, 1, 1, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 0, 1, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; long long Arg3 = 9LL; verify_case(2, Arg3, minArea(Arg0, Arg1, Arg2)); }
    void test_case_3() { int Arr0[] = {1000000000, 1000000000, 1000000000, -1000000000, -1000000000, -1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000000000, 0, -1000000000, 1000000000, 0, -1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; long long Arg3 = 4000000008000000004LL; verify_case(3, Arg3, minArea(Arg0, Arg1, Arg2)); }
    void test_case_4() { int Arr0[] = {-47881, 28623, 1769, -38328, -16737, 16653, -23181, 37360, 41429, 26282, 254, 728, 8299, -41080, -29498, 17488, -23937, -11, 33319, 25232}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-46462, 48985, -43820, -19587, -33593, -28337, 13667, -48131, -5568, -2332, -41918, -31370, -3695, 42599, -37788, -40096, 39049, 25045, -2122, 3874}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; long long Arg3 = 1695545329LL; verify_case(4, Arg3, minArea(Arg0, Arg1, Arg2)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    MinimumSquare ___test;

    ___test.run_test(-1);

}

// END CUT HERE
