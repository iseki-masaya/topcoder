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
const int INF = (1<<28);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class DNAString {

public:

    int minChanges(int maxPeriod, vector <string> dna) {
        string DNA = accumulate(dna.begin(), dna.end(), string(""));
        int N = (int)DNA.size();
        int ans = N;
        for (int p=1; p<=maxPeriod; ++p) {
            int t = N;
            for (int s=0; s<p; ++s) {
                map<char, int> c;
                int mx = 0;
                for (int i=s; i<N; i+=p) {
                    c[DNA[i]]++;
                    mx = max(mx, c[DNA[i]]);
                }
                t -= mx;
            }
            ans = min(ans, t);
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 3; string Arr1[] = {"ATAGATA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, minChanges(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 2; string Arr1[] = {"ACGTGCA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(1, Arg2, minChanges(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 13; string Arr1[] = {"ACGCTGACAGATA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, minChanges(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 1; string Arr1[] = {"AAAATTTCCG"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(3, Arg2, minChanges(Arg0, Arg1)); }
    void test_case_4() { int Arg0 = 12; string Arr1[] = {"ACGTATAGCATGACA","ACAGATATTATG","ACAGATGTAGCAGTA","ACCA","GAC"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; verify_case(4, Arg2, minChanges(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    DNAString ___test;

    ___test.run_test(-1);

}

// END CUT HERE
