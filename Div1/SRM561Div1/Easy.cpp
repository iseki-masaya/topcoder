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

#define INF (1<<28)
#define EPS 1e-8

using namespace std;

typedef pair<int, char> P;
const char ch[2] = {'L','M'};

class ICPCBalloons {

public:
    int
    calc(vector<int> l_rest,vector<int> m_rest,vector<int> &l_req,vector<int> &m_req)
    {
        int res = 0;
        for (int n=0; n<2; ++n) {
            int N = n ? (int)l_rest.size() : (int)m_rest.size();
            int M = n ? (int)l_req.size()  : (int)m_req.size();
            vector<int> &rest = n ? l_rest : m_rest;
            vector<int> &req  = n ? l_req  : m_req;
            for (int i=N; i<M; ++i) {
                rest.push_back(0);
            }

            int sum = 0;
            int sub = 0;
            for (int i=0; i<M; ++i) {
                sum += rest[i] - req[i];
                if (rest[i] < req[i])
                    sub += req[i] - rest[i];
            }
            for (int i=M; i<N; ++i) {
                sum += rest[i];
            }
            if (sum < 0) {
                return INF;
            }
            res += sub;
        }
        return res;
    }

    int
    minRepaintings(vector <int> balloonCount, string balloonSize, vector <int> maxAccepted)
    {
        int N = (int)balloonCount.size();
        int M = (int)maxAccepted.size();
        vector<int> l_rest,m_rest;
        for (int i=0; i<N; ++i) {
            if (balloonSize[i] == 'L') {
                l_rest.push_back(balloonCount[i]);
            }
            else {
                m_rest.push_back(balloonCount[i]);
            }
        }
        sort(l_rest.begin(), l_rest.end(), greater<int>());
        sort(m_rest.begin(), m_rest.end(), greater<int>());
        sort(maxAccepted.begin(), maxAccepted.end(), greater<int>());

        int limit = (1<<M);
        int ans = INF;
        for (int mask=0; mask<limit; ++mask) {
            vector<int> l_req,m_req;
            for (int i=0; i<M; ++i) {
                if ((mask>>i)&1) {
                    l_req.push_back(maxAccepted[i]);
                }
                else {
                    m_req.push_back(maxAccepted[i]);
                }
            }
            ans = min( ans ,  calc(l_rest,m_rest,l_req,m_req) );
        }
        return ans == INF ? -1 : ans;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "L"; int Arr2[] = {1,2,3,4,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(0, Arg3, minRepaintings(Arg0, Arg1, Arg2)); }
    void test_case_1() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "M"; int Arr2[] = {10,20,30,40,50}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(1, Arg3, minRepaintings(Arg0, Arg1, Arg2)); }
    void test_case_2() { int Arr0[] = {5,6,1,5,6,1,5,6,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "MLMMLMMLM"; int Arr2[] = {7,7,4,4,7,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(2, Arg3, minRepaintings(Arg0, Arg1, Arg2)); }
    void test_case_3() { int Arr0[] = {100,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ML"; int Arr2[] = {50,51,51}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(3, Arg3, minRepaintings(Arg0, Arg1, Arg2)); }
    void test_case_4() { int Arr0[] = {8,5,1,4,1,1,3,1,3,3,5,4,5,6,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "MMMLLLMMLLMLMLM"; int Arr2[] = {3,5,3,3,5,6,4,6,4,2,3,7,1,5,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(4, Arg3, minRepaintings(Arg0, Arg1, Arg2)); }
    void test_case_5() { int Arr0[] = {1,18,4,7,19,7,7,1,4,8,10,5,14,13,8,22,6,3,13,5,3,4,2,1,3,15,19,4,5,9,4,11,2,7,12,20,11,26,22,7,2,10,9,20,13,20,2,9,11,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "LLMLLLLMLLLLLLLLLLLLMLLLLLLLLLLMMLMLLLMLLLLLLLLMLL"; int Arr2[] = {44,59,29,53,16,23,13,14,29,42,13,15,66,4,47}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 210; verify_case(5, Arg3, minRepaintings(Arg0, Arg1, Arg2)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    ICPCBalloons ___test;

    ___test.run_test(-1);

}

// END CUT HERE
