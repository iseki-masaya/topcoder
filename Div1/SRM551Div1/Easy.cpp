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

const int INF = (1<<30);
#define EPS 1e-8
const int MOD = 10007;

using namespace std;

const int M = 27;
const int MAX_N = 2505;
int A[M][MAX_N];

class ColorfulChocolates {

public:
    void
    calc(vector<int> &inter,int alpha)
    {
        int N = (int)inter.size();
        vector<int> mn(N,INF);
        for (int i=0; i<=N; ++i) {
            vector<int> sum;
            int t = 0;
            for (int j=i-1; j>=0; --j) {
                t += inter[j];
                sum.push_back(t);
            }
            t = 0;
            for (int j=i; j<N; ++j) {
                t += inter[j];
                sum.push_back(t);
            }
            sort(sum.begin(), sum.end());
            t = 0;
            for (int i=0; i<sum.size(); ++i) {
                t += sum[i];
                mn[i] = min(mn[i],t);
            }
        }

        int k=0;
        mn.push_back(-1);
        while (mn[k] == 0) ++k;
        for (int i=1; i<MAX_N; ++i) {
            if (i == mn[k]) {
                k++;
                A[alpha][i] = max(A[alpha][i-1],k+1);
            }
            else {
                A[alpha][i] = A[alpha][i-1];
            }
        }
    }

    int
    maximumSpread_self(string chocolates, int maxSwaps)
    {
        int N = (int)chocolates.size();
        memset(A, -1, sizeof(A));
        int p = -1;
        int adj = 0;
        for (int i=0; i<N; ++i) {
            if(p == chocolates[i] - 'A') {
                ++adj;
                A[p][0] = max(A[p][0],adj);
            }
            else {
                p = chocolates[i] - 'A';
                adj = 1;
                A[p][0] = max(A[p][0],adj);
            }
        }

        for (int i=0; i<M; ++i) {
            int prev = -1;
            vector<int> inter;
            for (int j=0; j<N; ++j) {
                if (i == chocolates[j] - 'A') {
                    if (prev == -1) {
                        prev = j;
                        continue;
                    }
                    inter.push_back(j - prev - 1);
                    prev = j;
                }
            }
            if(inter.size() > 0)
                calc(inter, i);
        }

        int ans = 0;
        for (int i=0; i<M; ++i) {
            ans = max(ans,A[i][maxSwaps]);
        }
        return ans == 0 ? 1 : ans;
    }

    int
    maximumSpread(string C, int maxSwaps)
    {
        int N = (int)C.size();
        int best = 0;

        for (int c=0; c<N; ++c) {
            for (int p=0; p<N; ++p) {
                char color = C[c];
                int l=p,k=c;
                int cost = 0, spread = 0;
                while (l < N && k < N) {
                    if (cost + abs(k-l) > maxSwaps) {
                        break;
                    }
                    spread++;
                    cost += abs(k-l);
                    ++k;
                    while (k < N && color != C[k]) ++k;
                    l++;
                }
                best = max(best,spread);
            }
        }
        return best;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4();if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "ABCDCBC"; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, maximumSpread(Arg0, Arg1)); }
    void test_case_1() { string Arg0 = "ABCDCBC"; int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, maximumSpread(Arg0, Arg1)); }
    void test_case_2() { string Arg0 = "ABBABABBA"; int Arg1 = 3; int Arg2 = 4; verify_case(2, Arg2, maximumSpread(Arg0, Arg1)); }
    void test_case_3() { string Arg0 = "ABBABABBA"; int Arg1 = 4; int Arg2 = 5; verify_case(3, Arg2, maximumSpread(Arg0, Arg1)); }
    void test_case_4() { string Arg0 = "QASOKZNHWNFODOQNHGQKGLIHTPJUVGKLHFZTGPDCEKSJYIWFOO"; int Arg1 = 77; int Arg2 = 5; verify_case(4, Arg2, maximumSpread(Arg0, Arg1)); }
    void test_case_5() { string Arg0 = "ZWYZ"; int Arg1 = 2; int Arg2 = 2; verify_case(5, Arg2, maximumSpread(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    ColorfulChocolates ___test;

    ___test.run_test(-1);

}

// END CUT HERE
