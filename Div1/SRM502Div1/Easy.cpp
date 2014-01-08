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

const long long LINF = (1e15);
const int INF = (1<<27);
#define EPS 1e-6
const int MOD = 1000000009;

using namespace std;

class TheLotteryBothDivs {

public:
    static bool comp(const string &lhs,const string &rhs) {
        if (lhs.size() == rhs.size())
            return lhs < rhs;
        return lhs.size() < rhs.size();
    }

    bool is_include(string lhs,string rhs) {
        for (string::reverse_iterator lh=lhs.rbegin() , rh=rhs.rbegin(); lh!=lhs.rend() && rh != rhs.rend() ; ++lh,++rh)
            if (*lh != *rh)
                return false;

        return true;
    }

    int exp_ten(int n) {
        int res = 1;
        for (int i=0; i<n; ++i)
            res *= 10;
        return res;
    }

    double find(vector <string> goodSuffixes) {
        int N = (int)goodSuffixes.size();
        sort(goodSuffixes.begin(), goodSuffixes.end(), comp);
        vector<bool> used(N,false);
        for (int i=0; i<N; ++i) if (!used[i])
            for (int j=i+1; j<N; ++j) if (!used[j])
                if (is_include(goodSuffixes[i], goodSuffixes[j]))
                    used[j] = true;

        int denominator = exp_ten(9);
        int numerator = 0;
        for (int i=0; i<N; ++i)
            if (!used[i])
                numerator += exp_ten(9-(int)goodSuffixes[i].size());

        return (double)numerator/denominator;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.1; verify_case(0, Arg1, find(Arg0)); }
    void test_case_1() { string Arr0[] = {"4", "7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.2; verify_case(1, Arg1, find(Arg0)); }
    void test_case_2() { string Arr0[] = {"47", "47"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.01; verify_case(2, Arg1, find(Arg0)); }
    void test_case_3() { string Arr0[] = {"47", "58", "4747", "502"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.021; verify_case(3, Arg1, find(Arg0)); }
    void test_case_4() { string Arr0[] = {"8542861", "1954", "6", "523", "000000000", "5426", "8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.201100101; verify_case(4, Arg1, find(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    TheLotteryBothDivs ___test;

    ___test.run_test(-1);

}

// END CUT HERE
