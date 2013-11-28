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

#define INF (1<<28)
#define MOD (1000000007)

using namespace std;

class LittleElephantAndString {

public:

    int getNumber(string A, string B) {
        string C = A;
        string D = B;
        sort(C.begin(), C.end());
        sort(D.begin(), D.end());
        if (C != D)
            return -1;

        int N = (int)A.size();
        int ans = N;
        int p = N-1;
        for (int i=N-1; i>=0; --i) {
            if (A[i] == B[p]) {
                --p;
                --ans;
            }
        }

        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "ABC"; string Arg1 = "CBA"; int Arg2 = 2; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
    void test_case_1() { string Arg0 = "A"; string Arg1 = "B"; int Arg2 = -1; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
    void test_case_2() { string Arg0 = "AAABBB"; string Arg1 = "BBBAAA"; int Arg2 = 3; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
    void test_case_3() { string Arg0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; string Arg1 = "ZYXWVUTSRQPONMLKJIHGFEDCBA"; int Arg2 = 25; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
    void test_case_4() { string Arg0 = "A"; string Arg1 = "A"; int Arg2 = 0; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }
    void test_case_5() { string Arg0 = "DCABA"; string Arg1 = "DACBA"; int Arg2 = 2; verify_case(5, Arg2, getNumber(Arg0, Arg1)); }
    void test_case_6() { string Arg0 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAZAAAAAAAAAAAAAAAAAAA"; string Arg1 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAZ"; int Arg2 = 19; verify_case(6, Arg2, getNumber(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    LittleElephantAndString ___test;

    ___test.run_test(6);

}

// END CUT HERE
