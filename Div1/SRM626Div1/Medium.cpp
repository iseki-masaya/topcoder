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

class NegativeGraphDiv1 {

public:

    typedef vector<vector<long> > matrix;

    matrix comb(matrix A, matrix B) {
        int N = (int)A.size();
        matrix C(N, vector<long>(N, INF));
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                for (int k=0; k<N; ++k) {
                    C[i][j] = min(C[i][j], A[i][k] + B[k][j]);
                }
            }
        }
        return C;
    }

    long long findMin(int N, vector <int> from, vector <int> to, vector <int> weight, int charges) {
        vector<vector<int> >    dist(2*N, vector<int>(2*N, INF));
        int M = (int)from.size();
        for (int i=0; i<M; ++i) {
            int u = from[i] - 1;
            int v = to[i] - 1;
            int w = weight[i];
            dist[u][v] = min(dist[u][v], w);
            dist[u+N][v+N] = min(dist[u+N][v+N], w);
            dist[u+N][v] = min(dist[u+N][v], -w);
        }

        for (int k=0; k<2*N; ++k) {
            for (int i=0; i<2*N; ++i) {
                for (int j=0; j<2*N; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        if (charges == 0) {
            return dist[0][N-1];
        }

        matrix A(N, vector<long>(N));
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                A[i][j] = dist[i+N][j];
            }
            A[i][i] = min(A[i][i], 0L);
        }

        int k = charges;
        matrix D(N, vector<long>(N, INF));
        for(int i=0; i<N; ++i)
            D[i][i] = 0;

        while (k > 0) {
            if (k&1)
                D = comb(D, A);
            A = comb(A, A);
            k >>= 1;
        }
        return D[0][N-1];
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 3; int Arr1[] = {1,1,2,2,3,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,1,3,1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,5,1,10,1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; long long Arg5 = -9LL; verify_case(0, Arg5, findMin(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_1() { int Arg0 = 1; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {100}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 100000; long long Arg5 = -10000000LL; verify_case(1, Arg5, findMin(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_2() { int Arg0 = 2; int Arr1[] = {1,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,2,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {6,1,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; long long Arg5 = -9LL; verify_case(2, Arg5, findMin(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_3() { int Arg0 = 2; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {98765}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1000000000; long long Arg5 = -98765LL; verify_case(3, Arg5, findMin(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_4() { int Arg0 = 40; int Arr1[] = {21,2,36,21,32,1,34,1,40,38,19,10,39,40,31,29,22,18,24,8,25,1,12,31,1,34,16,13,39,39,26,30,4,28,8,9,27,13,6,16,7,11,7,38,30,20,22,29,19,5,22,13,12,7,
        33,5,10,31,10,39,18,18,3,19,17,17,34,9,7,17,21,13,12,16,36,39,9,7,3,5,26,16,32,4,26,12,27,24,19,1,19,17,9,22,16,12,31,37,32,9,31,8,2,39,18,26,32,12,
        28,11,32,34,2,12,12,33,27,24,5,5,40,34,4,8,10,17,39,30,26,24,10,37,23,40,38,17,4,28,33,31,28,19,36,5,24,17,11,19,4,40,20,16,11,10,9,22,23,23,8,30,10,
        23,16,21,10,18,8,28,15,20,38,5,22,4,29,32,13,13,15,24,28,27,11,24,24,23,40,34,20,28,18,26,34,21,13,11,33,28,8,5,9,31,1,32,7,22,12,8,12,8,12,31,35,33,
        27,18,6,22,38,9,40,35,15,16,30,4,3,29,2,34,40,3,12,20,29,14,2,3,8,37,12,28,25,7,22,33,4,15,5,14,26,22,16,33,12,11,14,11,5,25,30,21,20,30,25,30,28,37,
        23,31,30,3,15,5,25,14,8,13,12,4,18,9,20,17,11,21,5,25,15,9,40,26,28,36,1,10,33,34,5,3,21,32,15,30,33,32,31,19,12,2,16,13,15,4,33,33,26,6,7,36,20,14,7,
        39,17,33,4,5,22,21,13,29,38,34,6,24,18,29,4,20,33,16,14,30,20,20,7,21,13,5,20,1,8,18,9,12,24,10,22,33,40,28,30,23,7,36,27,38,36,15,3,36,8,20,27,12,5,
        33,40,7,25,20,13,36,30,13,9,3,15,38,33,27,36,4,9,18,39,7,12,30,17,2,21,17,11,26,14,29,26,31,15,13,12,19,35,11,25,19,15,34,9,12,17,37,22,22,16,10,13,
        17,12,12,32,1,40,10,34,29,39,7,17,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {27,37,32,14,19,25,4,14,40,9,36,23,21,25,39,13,4,30,11,32,22,12,29,40,35,32,4,15,25,8,17,18,17,19,34,1,16,16,26,28,2,28,21,16,6,3,12,39,24,31,3,25,26,
            30,9,35,29,20,4,21,25,15,32,27,24,13,3,10,21,40,12,39,4,10,2,39,28,23,21,19,21,11,32,20,36,7,11,21,16,29,17,24,18,32,17,38,23,35,1,19,28,20,31,37,16,
            20,7,31,3,7,36,15,36,10,6,37,26,39,39,26,31,8,36,26,10,21,24,33,13,29,31,10,12,20,31,39,35,29,39,30,34,26,15,30,4,36,16,38,2,31,22,18,17,12,21,4,11,
            32,3,27,14,22,16,37,40,18,25,28,20,27,27,30,11,19,16,18,25,4,21,14,14,13,22,34,25,9,31,27,14,32,23,21,3,1,24,15,30,35,1,24,37,7,28,8,21,40,6,29,36,37,
            21,8,17,20,20,28,22,22,13,29,34,20,26,11,10,8,33,10,37,11,16,5,9,18,39,1,8,4,5,2,20,30,4,23,30,23,19,25,30,37,40,31,31,33,33,8,36,40,15,11,31,37,5,40,
            2,11,19,32,1,32,27,7,23,9,13,18,12,36,11,32,34,38,35,15,6,36,32,28,6,40,2,33,2,6,7,27,40,30,40,12,39,13,1,22,17,36,1,4,34,25,25,6,20,25,30,4,24,35,7,5,
            29,20,28,37,1,30,6,5,5,1,10,40,13,14,21,32,19,25,37,21,28,34,28,29,27,24,33,35,12,25,3,4,12,31,12,7,28,27,10,35,35,18,6,5,16,24,39,26,15,29,13,5,14,36,
            35,14,2,39,22,21,2,2,19,38,15,25,10,13,2,39,31,13,5,39,11,33,4,18,18,38,19,39,39,32,23,34,30,21,30,16,36,22,25,14,13,16,10,8,27,29,40,1,29,4,20,25,32,
            21,40,1,10,2,17,5,8,5,31,18,18,25,13,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {93486,55539,34680,56705,10415,99106,26365,51838,20794,93178,33943,80260,60780,2405,78346,71929,24723,37614,62649,83486,32073,83866,88345,83213,28266,
                12730,27623,25353,89948,55002,36720,87151,39759,66091,3690,83881,82635,69084,54138,65876,54205,10236,90478,37230,22337,8209,14258,18375,5268,21824,
                76819,4094,63971,1454,21318,44848,92540,26354,18611,2394,68363,64345,60985,725,33692,21195,60992,10243,62006,74884,7822,66830,16114,14663,60701,38174,
                30493,26360,7745,7165,47668,83884,89463,46615,7729,22187,78818,10817,31141,79159,24280,67585,48039,3000,98743,39455,12030,27595,55470,14617,93275,
                21233,72418,26911,74250,13704,68327,89871,72035,3437,97910,2325,83391,39732,79248,22431,93095,65547,74205,33341,2112,93431,32198,96772,20187,71348,
                19102,10840,27306,76027,86368,55373,40192,49370,90597,21685,23630,68099,50880,84474,61907,8446,30127,80977,53007,36125,47411,16950,7445,17166,71035,
                20293,24724,7404,6579,11282,83421,37466,80598,53398,15720,66117,28965,90631,44004,27582,29003,65915,35683,48237,66625,50977,82957,54602,3610,431,36560,
                38034,5948,72313,16772,81862,11871,33534,91097,93908,57721,91890,46009,21400,41257,66253,90004,56285,85267,23486,6953,66722,69568,74398,32371,15307,
                26503,31676,50683,46103,43963,90273,8938,41054,90794,95115,11689,61662,72089,12258,2816,4029,36441,17784,53116,4444,93653,63726,57293,38647,59684,
                72212,770,60745,25817,47807,85312,27451,51063,83640,2978,49906,744,69457,20244,8799,7,89118,78421,58827,38689,21327,32558,35756,53505,30526,39049,
                63417,24967,54923,62001,38920,59719,65486,174,52231,84176,83531,39896,70918,52397,5169,14876,92511,70020,88390,1168,35311,56953,12966,94805,3885,
                14103,24615,10710,27635,24064,23022,4506,29939,2044,48330,53688,41320,21646,62598,41367,22910,70284,11512,64411,16215,41072,87263,38301,81731,41930,
                96029,93359,32457,98487,62899,51282,8656,45002,83345,36991,77420,37086,53484,18823,74711,81453,81394,79933,38466,61198,98665,5528,9196,40298,55089,
                24162,99257,58066,90088,66809,53472,73237,31964,4792,42336,88141,80467,96893,44276,76106,79430,17072,85727,49790,84394,47215,16792,44544,75123,4203,
                6283,49250,54852,27312,42709,97204,16834,80593,27523,31700,44435,25338,43513,84894,43514,90145,74675,54302,85249,10281,44231,28994,63813,24198,24686,
                7082,46471,3025,57872,57510,13666,48726,3907,12500,53578,28346,15804,32122,89396,15406,11207,59571,78192,84950,84280,84597,27811,56165,69239,53400,
                32562,95679,32377,5909,29805,85810,31593,85985,27637,24974,41557,56442,48912,62362,98580,59154,78739,75721,72097,90622,91334,79685,19371,15487,67804,
                2582,26623,14347,98894,92041,83228,58089,96181,3913,75974,18569,11428,95165,27563}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 160743953; long long Arg5 = -15328623718914LL; verify_case(4, Arg5, findMin(Arg0, Arg1, Arg2, Arg3, Arg4)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    NegativeGraphDiv1 ___test;

    ___test.run_test(-1);

}

// END CUT HERE
