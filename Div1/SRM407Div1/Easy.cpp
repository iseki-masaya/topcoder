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

class CorporationSalary {

public:
    vector<string> relations;
    vector<long long> salary;

    long long calculate(int p) {
        if (salary[p] != -1)
            return salary[p];

        int N = (int)salary.size();
        long long res = 0;
        for (int j=0; j<N; ++j) {
            if (relations[p][j] == 'Y') {
                res += calculate(j);
            }
        }
        if (res == 0)
            res = 1;
        return salary[p] = res;
    }

    long long totalSalary(vector <string> relations) {
        this->relations = relations;
        int N = (int)relations.size();
        salary.clear();
        salary.resize(N,-1);
        long long ans = 0;
        for (int i=0; i<N; ++i) {
            ans += calculate(i);
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(0, Arg1, totalSalary(Arg0)); }
    void test_case_1() { string Arr0[] = {"NNYN",
        "NNYN",
        "NNNN",
        "NYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5LL; verify_case(1, Arg1, totalSalary(Arg0)); }
    void test_case_2() { string Arr0[] = {"NNNNNN",
        "YNYNNY",
        "YNNNNY",
        "NNNNNN",
        "YNYNNN",
        "YNNYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 17LL; verify_case(2, Arg1, totalSalary(Arg0)); }
    void test_case_3() { string Arr0[] = {"NYNNYN",
        "NNNNNN",
        "NNNNNN",
        "NNYNNN",
        "NNNNNN",
        "NNNYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 8LL; verify_case(3, Arg1, totalSalary(Arg0)); }
    void test_case_4() { string Arr0[] = {"NNNN",
        "NNNN",
        "NNNN",
        "NNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4LL; verify_case(4, Arg1, totalSalary(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    CorporationSalary ___test;

    ___test.run_test(-1);

}

// END CUT HERE
