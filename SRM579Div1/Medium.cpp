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

#define INF (1<<28)

class TravellingPurchasingMan {

public:
    vector<int>
    getVal(string r)
    {
        vector<int> d(3);
        for (int i=0; i<3; ++i) {
            stringstream ss;
            ss << r.substr(0,r.find(" "));
            ss >> d[i];
            r = r.substr(r.find(" ")+1,r.size());
        }
        return d;
    }

    int
    maxStores(int N, vector <string> interestingStores, vector <string> roads)
    {
        vector<vector<int> > cost(N,vector<int>(N,INF));
        for (int i=0; i<roads.size(); ++i) {
            vector<int> c(getVal(roads[i]));
            cost[c[0]][c[1]] = cost[c[1]][c[0]] = min(c[2],cost[c[1]][c[0]]);
        }
        for (int i=0; i<N; ++i) {
            cost[i][i] = 0;
        }

        for (int k=0; k<N; ++k) {
            for (int j=0; j<N; ++j) {
                for (int i=0; i<N; ++i) {
                    cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j]);
                }
            }
        }

        int m = static_cast<int>(interestingStores.size());
        vector<int> open(m+1),duration(m+1),close(m+1),store(N,-1),storeid(m+1);
        for (int i=0; i<m; ++i) {
            vector<int> c(getVal(interestingStores[i]));
            open[i] = c[0];
            close[i] = c[1];
            duration[i] = c[2];
            store[i] = i;
            storeid[i] = i;
        }
        if (store[N-1] == -1) {
            store[N-1] = m;
            storeid[m] = N-1;
            open[m] = -2;
            close[m] = -1;
            duration[m] = 0;
            ++m;
        }

        int mask_limit = (1<<(m));
        vector<vector<int> > dp(mask_limit,vector<int>(m,INF));
        dp[0][store[N-1]] = 0;

        for (int mask = 0; mask < mask_limit; ++mask) {
            for (int x = 0; x < m; ++x) {
                if (dp[mask][x] < INF) {
                    int t = dp[mask][x];
                    for (int nx=0; nx<m; ++nx) {
                        int nt = t + cost[storeid[x]][storeid[nx]];
                        if (nt <= close[nx]) {
                            nt = max(nt,open[nx]) + duration[nx];
                            if (dp[mask|(1<<nx)][nx] > nt) {
                                dp[mask|(1<<nx)][nx] = nt;
                            }
                        }
                    }
                }
            }
        }

        int res = 0;
        for (int j=0; j<mask_limit; ++j) {
            int c = 0;
            for (int i=0; i<m; ++i) {
                if ((j&(1<<i)) != 0) {
                    ++c;
                }
            }
            for (int i=0; i<m; ++i) {
                if (dp[j][i] != INF) {
                    res = max(res,c);
                }
            }
        }

        return res;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2();if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 3; string Arr1[] = {"1 10 10" , "1 55 31", "10 50 100" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 2 10"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, maxStores(Arg0, Arg1, Arg2)); }
    void test_case_1() { int Arg0 = 3; string Arr1[] = {"1 10 10" , "1 55 30", "10 50 100" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 2 10"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, maxStores(Arg0, Arg1, Arg2)); }
    void test_case_2() { int Arg0 = 5; string Arr1[] = {"0 1000 17"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"2 3 400", "4 1 500", "4 3 300", "1 0 700", "0 2 400"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, maxStores(Arg0, Arg1, Arg2)); }
    void test_case_3() { int Arg0 = 47; string Arr1[] = {"44981 82910 7574", "15439 68562 5524", "22779 25958 24580", "31231 75777 11697", "50647 95911 29469", "4062 25185 22327", "20995 74589 29025", "49564 86172 45831", "54877 61972 42337", "6789 45917 49832", "55983 105975 7547", "25537 51040 28255", "1846 20617 43506"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0 1 19613", "1 3 1809", "1 5 3955", "5 4 6884", "1 7 30084", "7 8 19371", "1 11 47713", "1 13 16863", "13 14 18642", "0 12 35182", "7 15 15527", "11 17 22712", "1 10 47090", "0 2 4947", "2 25 10080", "8 31 27617", "3 24 6719", "11 22 60420", "13 35 6366", "7 29 5779", "17 20 60039", "17 34 20750", "35 33 11472", "33 32 25933", "13 9 4091", "33 40 9680", "40 36 947", "40 41 41230", "25 27 866", "41 37 4131", "41 21 56553", "33 46 37881", "22 19 28107", "4 30 47921", "7 6 28156", "13 23 34708", "14 6 55870"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(3, Arg3, maxStores(Arg0, Arg1, Arg2)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    TravellingPurchasingMan ___test;

    ___test.run_test(-1);

}

// END CUT HERE
