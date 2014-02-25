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

typedef pair<int, int> P;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

class SequenceOfCommands {

public:
    P simulate(P p, string command, int &dir) {
        int N = (int)command.size();
        for (int i=0; i<N; ++i) {
            switch (command[i]) {
                case 'S':
                    p.first += dx[dir];
                    p.second += dy[dir];
                    break;
                case 'R':
                    dir = (dir+1)%4;
                    break;
                case 'L':
                    dir = (4+dir-1)%4;
                    break;
                default:
                    cout << "command error" << endl;
                    break;
            }
        }
        return p;
    }

    string whatHappens(vector <string> commands) {
        P p = P(0,0);
        string command = accumulate(commands.begin(), commands.end(), string(""));
        int dir = 0;
        for (int i=0; i<4; ++i) {
            p = simulate(p,command, dir);
            if (p.first == 0 && p.second == 0) {
                return "bounded";
            }
        }
        return "unbounded";
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"L"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "bounded"; verify_case(0, Arg1, whatHappens(Arg0)); }
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
