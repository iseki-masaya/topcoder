#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <list>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <bitset>
#include <deque>
#include <random>

const long long LINF = (1e18);
const int INF = (1<<28);
const int sINF = (1<<23);
const int MOD = 1000000007;
const double EPS = 1e-6;


using namespace std;

class SurveillanceSystem {

public:

    bool valid(vector<int> &available, vector<int> &needed) {
        for (int i=0; i<available.size(); ++i)
            if (available[i] < needed[i])
                return false;
        return true;
    }

    string getContainerInfo(string containers, vector <int> &reports, int L) {
        int N = (int)containers.size();
        vector<int> count(L+1, 0);
        for (int v: reports)
            count[v]++;
        vector<int> watched(N-L+1, 0);
        for (int i=0; i<N-L+1; ++i) {
            for (int j=i; j<i+L; ++j) {
                watched[i] += (containers[j] == 'X' ? 1 : 0);
            }
        }

        string ans(N, '?');
        for (int i=0; i<N; ++i) {
            vector<int> witout(L+1, 0);
            for (int j=0; j+L<=N; ++j)
                if (i<j || j<=i-L)
                    witout[watched[j]]++;

            bool canWithout = valid(witout, count);
            if (!canWithout) {
                ans[i] = '+';
            }
            else {
                bool canWith = false;
                for (int j=0; j+L<=N; ++j) {
                    if (i-L < j && j <= i) {
                        int c = watched[j];
                        canWith |= (count[c]>=1);
                    }
                }
                ans[i] = canWith ? '?' : '-';
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
    void test_case_0() { string Arg0 = "-X--XX"; int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "??++++"; verify_case(0, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
    void test_case_1() { string Arg0 = "-XXXXX-"; int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "???-???"; verify_case(1, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
    void test_case_2() { string Arg0 = "------X-XX-"; int Arr1[] = {3, 0, 2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; string Arg3 = "++++++++++?"; verify_case(2, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
    void test_case_3() { string Arg0 = "-XXXXX---X--"; int Arr1[] = {2, 1, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "???-??++++??"; verify_case(3, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
    void test_case_4() { string Arg0 = "-XX--X-XX-X-X--X---XX-X---XXXX-----X"; int Arr1[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; string Arg3 = "???++++?++++++++++++++++++++??????--"; verify_case(4, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    SurveillanceSystem ___test;

    ___test.run_test(-1);

}

// END CUT HERE
