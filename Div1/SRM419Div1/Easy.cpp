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
const int INF = (1<<29);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

typedef pair<string, string> P;
typedef pair<int, int> T;

class Undo {

public:
    P parse(string s) {
        string command = s.substr(0,4);
        string arg = s.substr(5);
        return P(command, arg);
    }

    int conv(string n) {
        int c;
        stringstream ss;
        ss << n;
        ss >> c;
        return c;
    }

    string getText(vector <string> commands, vector <int> time) {
        int N = (int)commands.size();
        vector<int> use(N,1);
        vector<string> type(N,"");
        vector<T> step(N,T(-1,0));
        for (int i=N-1; i>=0; --i) {
            P p = parse(commands[i]);
            if (p.first == "type") {
                type[i] = p.second;
            }
            else if (p.first == "undo" && use[i] == 1) {
                int n = conv(p.second);
                int t = time[i] - n;
                int p = (int)distance(time.begin(), lower_bound(time.begin(), time.end(), t));
                for (int j=p; j<i; ++j) {
                    use[j] = -use[j];
                }
            }
        }

        string ans = "";
        for (int i=0; i<N; ++i) {
            if (use[i] == 1) {
                ans += type[i];
            }
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"type a", "type b", "type c", "undo 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "a"; verify_case(0, Arg2, getText(Arg0, Arg1)); }
    void test_case_1() { string Arr0[] = {"type a", "type b", "undo 2", "undo 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "a"; verify_case(1, Arg2, getText(Arg0, Arg1)); }
    void test_case_2() { string Arr0[] = {"type a", "undo 1", "undo 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "a"; verify_case(2, Arg2, getText(Arg0, Arg1)); }
    void test_case_3() { string Arr0[] = {"type a", "type b", "type c", "undo 10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "abc"; verify_case(3, Arg2, getText(Arg0, Arg1)); }
    void test_case_4() { string Arr0[] = {"undo 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = ""; verify_case(4, Arg2, getText(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    Undo ___test;

    ___test.run_test(-1);

}

// END CUT HERE
