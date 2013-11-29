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

const long long LINF = (1e11);
const int INF = (1<<30);
#define EPS 1e-6

using namespace std;

class PermutationSignature {

public:
    int find_min(vector<bool> &used) {
        int N = (int)used.size();
        for (int i=0; i<N; ++i)
            if (!used[i])
                return i + 1;
        return -INF;
    }

    vector <int> reconstruct(string signature) {
        int N = (int)signature.size();
        vector<int> ans(N+1,0);
        vector<bool> used(N+1,false);

        for (int i=0; i<N; ++i) {
            if (signature[i] == 'I') {
                int v = find_min(used);
                ans[i] = v;
                used[v-1] = true;
            } else {
                int v = find_min(used) + 1;
                int p = i + 1;
                while (p < N && signature[p] == 'D') {
                    ++p;
                    ++v;
                }
                for (int j=i; j<p; ++j) {
                    used[v-1] = true;
                    ans[j] = v--;
                }
            }
        }
        ans[N] = find_min(used);
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
    void test_case_0() { string Arg0 = "IIIII"; int Arr1[] = {1, 2, 3, 4, 5, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, reconstruct(Arg0)); }
    void test_case_1() { string Arg0 = "DI"; int Arr1[] = {2, 1, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, reconstruct(Arg0)); }
    void test_case_2() { string Arg0 = "IIIID"; int Arr1[] = {1, 2, 3, 4, 6, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, reconstruct(Arg0)); }
    void test_case_3() { string Arg0 = "DIIDID"; int Arr1[] = {2, 1, 3, 5, 4, 7, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, reconstruct(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    PermutationSignature ___test;

    ___test.run_test(-1);

}

// END CUT HERE
