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
#include <stdio.h>
#include <string.h>
#include <numeric>

#define L_INF (1)
#define INF (1<<29)
#define EPS 1e-6

using namespace std;

class Inequalities {

public:

    int
    maximumSubset(vector <string> inequalities)
    {
        typedef pair<string, float> P;
        vector<P> vec(inequalities.size());

        for (int i=0; i<inequalities.size(); ++i) {
            string query = inequalities[i].substr(2,inequalities[i].size()-2);
            stringstream ss;
            string ineq;
            float c;
            int pos = (int)query.find(" ");
            ineq = query.substr(0,pos);
            query = query.substr(pos+1,query.size()-pos-1);
            ss << query;
            ss >> c;
            vec[i] = P(ineq,c);
        }

        int ans = 0;
        for (float i = -0.5; i <1002; i += 0.5) {
            int res = 0;
            for (int j=0; j<vec.size(); ++j) {
                string ineq = vec[j].first;
                float v = vec[j].second;
                if (ineq == "<" && i < v) {
                    ++res;
                }
                else if (ineq == "<=" && i <= v) {
                    ++res;
                }
                else if (ineq == "=" && i == v) {
                    ++res;
                }
                else if (ineq == ">=" && i >= v) {
                    ++res;
                }
                else if (ineq == ">" && i > v) {
                    ++res;
                }
            }
            ans = max(res,ans);
        }

        return ans;
    }

    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"X <= 12","X = 13","X > 9","X < 10","X >= 14"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, maximumSubset(Arg0)); }
    void test_case_1() { string Arr0[] = {"X < 0","X <= 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, maximumSubset(Arg0)); }
    void test_case_2() { string Arr0[] = {"X = 1","X = 2","X = 3","X > 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, maximumSubset(Arg0)); }
    void test_case_3() { string Arr0[] = {"X <= 521","X >= 521","X = 521","X > 902","X > 12","X <= 1000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, maximumSubset(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    Inequalities ___test;

    ___test.run_test(-1);

}

// END CUT HERE
