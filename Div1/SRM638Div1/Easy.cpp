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

int dx[] = {1,0,0,-1,0,0};
int dy[] = {0,1,0,0,-1,0};
int dz[] = {0,0,1,0,0,-1};

class ShadowSculpture {

public:

    typedef tuple<int, int, int> P;
    vector<string> XY, YZ, ZX;

    bool correct(set<P> &s) {
        int N = (int)XY.size();
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                bool xyf = false, yzf = false, zxf = false;
                for (int k=0; k<N; ++k) {
                    xyf |= s.count(P(i,j,k));
                    yzf |= s.count(P(k,i,j));
                    zxf |= s.count(P(j,k,i));
                }
                if ( (XY[i][j] == 'Y') != xyf )
                    return false;
                if ( (YZ[i][j] == 'Y') != yzf )
                    return false;
                if ( (ZX[i][j] == 'Y') != zxf )
                    return false;
            }
        }
        return true;
    }

    bool exist(int x, int y, int z) {
        int N = (int)XY.size();
        if ( (0<=x && x<N) && (0<=y && y<N) && (0<=z && z<N) )
            return (XY[x][y] == 'Y') && (YZ[y][z] == 'Y') && (ZX[z][x] == 'Y');
        return false;
    }

    void dfs(int x, int y, int z, set<P> &c, set<P> &visited) {
        if (visited.count(P(x,y,z)))
            return;
        visited.insert(P(x,y,z));
        c.insert(P(x,y,z));
        for (int i=0; i<6; ++i) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            int cz = z + dz[i];
            if (exist(cx, cy, cz)) {
                dfs(cx, cy, cz, c, visited);
            }
        }
    }

    string possible(vector <string> XY, vector <string> YZ, vector <string> ZX) {
        this->XY = XY;
        this->YZ = YZ;
        this->ZX = ZX;
        int N = (int)XY.size();
        set<P> empty;
        if (correct(empty))
            return "Possible";

        set<P> visited;
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                for (int k=0; k<N; ++k) {
                    if (exist(i, j, k) && !visited.count(P(i,j,k))) {
                        set<P> c;
                        dfs(i, j, k, c, visited);
                        if (correct(c)) {
                            return "Possible";
                        }
                    }
                }
            }
        }
        return "Impossible";
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"YN","NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YN","NN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YN","NN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(0, Arg3, possible(Arg0, Arg1, Arg2)); }
    void test_case_1() { string Arr0[] = {"YN","NY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YN","NY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YN","NY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Impossible"; verify_case(1, Arg3, possible(Arg0, Arg1, Arg2)); }
    void test_case_2() { string Arr0[] = {"YYY","YNY","YYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YYY","YNY","YYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YYY","YNY","YYY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(2, Arg3, possible(Arg0, Arg1, Arg2)); }
    void test_case_3() { string Arr0[] = {"YYY","YNY","YYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYY","YNY","YYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YYY","YNY","YYN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Impossible"; verify_case(3, Arg3, possible(Arg0, Arg1, Arg2)); }
    void test_case_4() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"N"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"N"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(4, Arg3, possible(Arg0, Arg1, Arg2)); }

    void test_case_5() { string Arr0[] = {"YYYYY", "YYNYY", "YYYYY", "YYNYY", "YYYYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YYYYY", "YYNYY", "YYYYY", "YYNYY", "YYYYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YYYYY", "YYNYY", "YYYYY", "YYNYY", "YYYYY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(5, Arg3, possible(Arg0, Arg1, Arg2)); }



    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    ShadowSculpture ___test;

    ___test.run_test(-1);

}

// END CUT HERE
