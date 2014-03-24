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
const int INF = (1<<27);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class TheQuestionsAndAnswersDivOne {

public:
    int solve(vector<string> &answer, int pos, int un, int yn , int nn) {
        if (answer.size() == pos) {
            if (un == 0)
                return 1;
            else
                return 0;
        }
        int res = 0;
        if (un > 0) {
            if (answer[pos] == "Yes")
                res += un * solve(answer, pos+1, un-1, yn+1, nn);
            else
                res += un * solve(answer, pos+1, un-1, yn, nn+1);
        }
        if (answer[pos] == "Yes" && yn > 0)
            res += yn * solve(answer, pos+1, un, yn, nn);
        if (answer[pos] == "No" && nn > 0)
            res += nn * solve(answer, pos+1, un, yn, nn);
        return res;
    }

    int find(int questions, vector <string> answers) {
        return solve(answers, 0, questions, 0, 0);
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 2; string Arr1[] = {"No", "Yes"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, find(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 2; string Arr1[] = {"No", "No", "No"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(1, Arg2, find(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 3; string Arr1[] = {"Yes", "No", "No", "Yes"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(2, Arg2, find(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 3; string Arr1[] = {"Yes", "Yes", "Yes", "No"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 18; verify_case(3, Arg2, find(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    TheQuestionsAndAnswersDivOne ___test;

    ___test.run_test(-1);

}

// END CUT HERE
