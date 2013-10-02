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

class ColorfulTilesEasy {

public:

    int
    theMin(string room)
    {
        int ans = 0;
        for (int i=1; i<room.size(); ++i) {
            if (room[i] == room[i-1]) {
                ++ans;
                room[i] = 'K';
            }
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "RRRRRR"; int Arg1 = 3; verify_case(0, Arg1, theMin(Arg0)); }
    void test_case_1() { string Arg0 = "GGGGGGG"; int Arg1 = 3; verify_case(1, Arg1, theMin(Arg0)); }
    void test_case_2() { string Arg0 = "BBBYYYYYY"; int Arg1 = 4; verify_case(2, Arg1, theMin(Arg0)); }
    void test_case_3() { string Arg0 = "BRYGYBGRYR"; int Arg1 = 0; verify_case(3, Arg1, theMin(Arg0)); }
    void test_case_4() { string Arg0 = "RGGBBBRYYB"; int Arg1 = 3; verify_case(4, Arg1, theMin(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    ColorfulTilesEasy ___test;

    ___test.run_test(-1);

}

// END CUT HERE
