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
const int INF = (1<<28);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

class RelativePath {

public:
    vector<string> parse(string path) {
        vector<string> res;
        string buff = "";
        for (int i=0; i<path.size(); ++i) {
            if (path[i] == '/') {
                res.push_back(buff);
                buff.clear();
            }
            else {
                buff += path[i];
            }
        }
        if (!buff.empty())
            res.push_back(buff);
        return res;
    }

    string makeRelative(string path, string currentDir) {
        vector<string> a(parse(path)), b(parse(currentDir));
        int common = 0;
        for (; common < min(a.size(), b.size()); ++common) {
            if (a[common] != b[common]) {
                break;
            }
        }
        string ans = "";
        for (int i=common; i<b.size(); ++i) {
            ans += "../";
        }
        for (int i=common; i<a.size(); ++i) {
            ans += a[i];
            if (i != a.size()-1)
                ans += "/";
        }
        return ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arg0 = "/home/top/data/file"; string Arg1 = "/home/user/pictures"; string Arg2 = "../../top/data/file"; verify_case(0, Arg2, makeRelative(Arg0, Arg1)); }
    void test_case_1() { string Arg0 = "/home/user/movies/title"; string Arg1 = "/home/user/pictures"; string Arg2 = "../movies/title"; verify_case(1, Arg2, makeRelative(Arg0, Arg1)); }
    void test_case_2() { string Arg0 = "/file"; string Arg1 = "/"; string Arg2 = "file"; verify_case(2, Arg2, makeRelative(Arg0, Arg1)); }
    void test_case_3() { string Arg0 = "/a/b/a/b/a/b"; string Arg1 = "/a/b/a/a/b/a/b"; string Arg2 = "../../../../b/a/b"; verify_case(3, Arg2, makeRelative(Arg0, Arg1)); }
    void test_case_4() { string Arg0 = "/root/root/root"; string Arg1 = "/root"; string Arg2 = "root/root"; verify_case(4, Arg2, makeRelative(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    RelativePath ___test;

    ___test.run_test(-1);

}

// END CUT HERE
