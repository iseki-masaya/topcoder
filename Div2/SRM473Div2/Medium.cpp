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
#include <time.h>
#include <numeric>

using namespace std;

typedef pair<int, int> P;

class SequenceOfCommands {

public:

    string
    whatHappens(vector <string> commands)
    {
        int dir = 0;
        P p = P(0,0);
        for (int i=0; i<commands.size(); ++i) {
            for (int j=0; j<commands[i].size(); ++j) {
                if (commands[i][j] == 'R') {
                    dir = abs(dir+1)%4;
                }
                else if (commands[i][j] == 'L') {
                    dir = (dir-1+4)%4;
                }
                else {
                    p.first += (dir&1)*(dir==1? 1 : -1);
                    p.second += ((dir+1)&1)*(dir==0? 1 : -1);
                }
            }
        }
        if ((p.first==0 && p.second==0) || dir != 0) {
            return "bounded";
        }
        else {
            return "unbounded";
        }
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"SRSRSRSR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "bounded"; verify_case(0, Arg1, whatHappens(Arg0)); }
    void test_case_1() { string Arr0[] = {"SRSL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "unbounded"; verify_case(1, Arg1, whatHappens(Arg0)); }
    void test_case_2() { string Arr0[] = {"SSSS","R"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "bounded"; verify_case(2, Arg1, whatHappens(Arg0)); }
    void test_case_3() { string Arr0[] = {"SRSL","LLSSSSSSL","SSSSSS","L"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "unbounded"; verify_case(3, Arg1, whatHappens(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    SequenceOfCommands ___test;

    ___test.run_test(-1);

}

// END CUT HERE
