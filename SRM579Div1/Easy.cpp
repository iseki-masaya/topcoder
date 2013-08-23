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

using namespace std;

class UndoHistory {

public:

    int
    minPresses(vector <string> lines)
    {
        set<string> rec;
        int ans = 0;
        string buff = "";
        rec.insert("");

        bool isUsedRec = false;
        for (int i=0; i<lines.size(); ++i) {
            isUsedRec = false;
            string rec_buff = "";
            for (int j=0; j<=lines[i].size(); ++j) {
                if (rec.find(lines[i].substr(0,j)) != rec.end()) {
                    rec_buff = lines[i].substr(0,j);
                }
            }
            if (buff != lines[i].substr(0,buff.size()) || buff.size()+2 < rec_buff.size()) {
                isUsedRec = true;
                buff = rec_buff;
            }

            ans += static_cast<int>(lines[i].size()-buff.size()) + (isUsedRec?2:0);
            buff = lines[i];

            for (int j=0; j<=lines[i].size(); ++j) {
                rec.insert(lines[i].substr(0,j));
            }
            ++ans;
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"tomorrow", "topcoder"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 18; verify_case(0, Arg1, minPresses(Arg0)); }
    void test_case_1() { string Arr0[] = {"a","b"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, minPresses(Arg0)); }
    void test_case_2() { string Arr0[] = {"a", "ab", "abac", "abacus" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, minPresses(Arg0)); }
    void test_case_3() { string Arr0[] = {"pyramid", "sphinx", "sphere", "python", "serpent"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 39; verify_case(3, Arg1, minPresses(Arg0)); }
    void test_case_4() { string Arr0[] = {"ba","a","a","b","ba"}
        ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(4, Arg1, minPresses(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    UndoHistory ___test;

    ___test.run_test(-1);

}

// END CUT HERE
