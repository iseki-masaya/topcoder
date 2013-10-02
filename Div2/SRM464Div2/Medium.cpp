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
#define EPS 1e-6

using namespace std;

class ColorfulStrings {

public:
    bool
    diff(vector<int> &prev,vector<int> &perm)
    {
        for (int i=0; i<prev.size(); ++i) {
            if (prev[i] != perm[i]) {
                return true;
            }
        }
        return false;
    }

    string
    getKth(int n, int k)
    {
        if (n >= 9) {
            return "";
        }
        if (n == 1) {
            string ans;
            ans = '0' + k-1;
            if (k > 10) {
                return "";
            }
            return ans;
        }

        vector<int> perm(8);
        for (int i=0; i<8; ++i) {
            perm[i] = i+2;
        }

        vector<int> prev(n,0);
        int cnt = 0;
        do {
            bool update = false;
            if (diff(prev, perm)) {
                update = true;
                for (int i=0; i<n; ++i) {
                    prev[i] = perm[i];
                }
            }
            if (!update) {
                continue;
            }
            bool hit = true;
            set<int> es;
            for (int size = 1; size <= n && hit; ++size) {
                for (int pos = 0; size+pos-1 < n && hit; ++pos) {
                    int res = 1;
                    for (int i=0; i<size ; ++i) {
                        res *= perm[i+pos];
                    }
                    if (es.find(res) != es.end()) {
                        hit = false;
                    }
                    es.insert(res);
                }
            }
            for (int i=0; i+1<n && hit; ++i) {
                int k = perm[i]*perm[i+1];
                for (int j=0; j<n && hit; ++j) {
                    if (perm[j] == k) {
                        hit = false;
                    }
                }
            }
//          if (hit){
//              for (int i : prev)
//                  cout << i;
//              cout << endl;
//          }
            if (hit && ++cnt == k) {
                string ans = "";
                for (int i=0; i<n; ++i) {
                    ans += '0'+perm[i];
                }
                return ans;
            }
        } while (next_permutation(perm.begin(), perm.end()));

        return "";
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 3; int Arg1 = 4; string Arg2 = "238"; verify_case(0, Arg2, getKth(Arg0, Arg1)); }
    void test_case_1() { int Arg0 = 4; int Arg1 = 2000; string Arg2 = ""; verify_case(1, Arg2, getKth(Arg0, Arg1)); }
    void test_case_2() { int Arg0 = 5; int Arg1 = 1; string Arg2 = "23457"; verify_case(2, Arg2, getKth(Arg0, Arg1)); }
    void test_case_3() { int Arg0 = 2; int Arg1 = 22; string Arg2 = "52"; verify_case(3, Arg2, getKth(Arg0, Arg1)); }
    void test_case_4() { int Arg0 = 6; int Arg1 = 464; string Arg2 = "257936"; verify_case(4, Arg2, getKth(Arg0, Arg1)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    ColorfulStrings ___test;

    ___test.run_test(-1);

}

// END CUT HERE
