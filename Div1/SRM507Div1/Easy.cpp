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

class CubeStickers {

public:

    bool numCheck(map<string, int> &s, int req) {
        int cntOverTwo = 0;
        for (map<string, int>::iterator it = s.begin(); it != s.end(); ++it)
            if ((*it).second > 1)
                ++cntOverTwo;

        return cntOverTwo >= req;
    }

    string isPossible(vector <string> sticker) {
        map<string,int> s;
        int N = (int)sticker.size();

        for (int i=0; i<N; ++i)
            s[sticker[i]]++;

        if (s.size() > 4 || ( s.size() > 2 && numCheck(s, 6 - (int)s.size()) ))
            return "YES";
        return "NO";
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"cyan","magenta","yellow","purple","black","white","purple"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, isPossible(Arg0)); }
    void test_case_1() { string Arr0[] = {"blue","blue","blue","blue","blue","blue","blue","blue","blue","blue"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(1, Arg1, isPossible(Arg0)); }
    void test_case_2() { string Arr0[] = {"red","yellow","blue","red","yellow","blue","red","yellow","blue"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(2, Arg1, isPossible(Arg0)); }
    void test_case_3() { string Arr0[] = {"purple","orange","orange","purple","black","orange","purple"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(3, Arg1, isPossible(Arg0)); }
    void test_case_4() { string Arr0[] = {"white","gray","green","blue","yellow","red","target","admin"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(4, Arg1, isPossible(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    CubeStickers ___test;

    ___test.run_test(-1);

}

// END CUT HERE
