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

#define MAX_N 55
#define MOD 1000000007

int X,Y;
bool used[MAX_N][MAX_N];
vector<string> f;

typedef pair<int, int> P;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

class GooseInZooDivOne {

public:
    bool
    bfs(int x,int y,int D)
    {
        queue<P> q;
        q.push(P(x,y));
        int c = 1;
        while (!q.empty()) {
            P p = q.front(); q.pop();
            for (int cx = p.first-D; cx <= p.first+D; ++cx) {
                for (int cy = p.second-D; cy <= p.second+D; ++cy) {
                    if (abs(p.first-cx)+abs(p.second-cy) <= D && 0 <= cx && cx < X && 0 <= cy && cy < Y && f[cy][cx] == 'v' && !used[cy][cx]) {
                        q.push(P(cx,cy));
                        used[cy][cx] = true;
                        ++c;
                    }
                }
            }
        }
        return c&1;
    }

    long long
    modPow(long long x,long long n,long long m)
    {
        if (n == 0) return 1;
        long long res = modPow((x*x)%m, n/2, m);
        if (n&1) res = (res*x)%m;
        return res;
    }

    long long
    inv(long long x)
    {
        return modPow(x, MOD-2, MOD);
    }

    long long
    factorial(int a)
    {
        long long res = 1;
        for (int i=a; i>1; --i) {
            res *= i%MOD;
            res = res%MOD;
        }
        return res;
    }

    int
    count(vector <string> field, int dist)
    {
        memset(used, false, sizeof(used));
        f = field;
        Y = (int)field.size() , X = (int)field[0].size();
        int odd = 0 , even = 0;
        for (int y=0; y<Y; ++y) {
            for (int x=0; x<X; ++x) {
                if (field[y][x] == 'v' && !used[y][x]) {
                    used[y][x] = true;
                    if(bfs(x, y, dist))
                        ++odd;
                    else
                        ++even;
                }
            }
        }

        int cnt = even;
        if (odd) cnt += odd-1;
        long long ans = modPow(2, cnt, MOD);

        if (even == 0 && odd == 0) {
            return 0;
        }
        ans = (ans-1 + MOD)%MOD;
        return (int)ans;

        //      int ans = 1;
//      int n = odd;
//      for (int r = 2; r<odd_cnt; r += 2) {
//          ans += (MOD+factorial(n)*inv((factorial(r)*factorial(n-r))%MOD))%MOD;
//          ans = ans%MOD;
//      }
//
//      if (even_cnt == 0 && odd_cnt < 2) {
//          return 0;
//      }
//
//      return (((ans*e)%MOD)-1 + MOD)%MOD;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) {
        if ((Case == -1) || (Case == 0)) test_case_0();
        if ((Case == -1) || (Case == 1)) test_case_1();
        if ((Case == -1) || (Case == 2)) test_case_2();
        if ((Case == -1) || (Case == 3)) test_case_3();
        if ((Case == -1) || (Case == 4)) test_case_4();
    }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"vvv"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 3; verify_case(0, Arg2, count(Arg0, Arg1)); }
    void test_case_1() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 0; verify_case(1, Arg2, count(Arg0, Arg1)); }
    void test_case_2() { string Arr0[] = {"vvv"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(2, Arg2, count(Arg0, Arg1)); }
    void test_case_3() {
        string Arr0[] =
        {"v.v..................v............................"
        ,".v......v..................v.....................v"
        ,"..v.....v....v.........v...............v......v..."
        ,".........vvv...vv.v.........v.v..................v"
        ,".....v..........v......v..v...v.......v..........."
        ,"...................vv...............v.v..v.v..v..."
        ,".v.vv.................v..............v............"
        ,"..vv.......v...vv.v............vv.....v.....v....."
        ,"....v..........v....v........v.......v.v.v........"
        ,".v.......v.............v.v..........vv......v....."
        ,"....v.v.......v........v.....v.................v.."
        ,"....v..v..v.v..............v.v.v....v..........v.."
        ,"..........v...v...................v..............v"
        ,"..v........v..........................v....v..v..."
        ,"....................v..v.........vv........v......"
        ,"..v......v...............................v.v......"
        ,"..v.v..............v........v...............vv.vv."
        ,"...vv......v...............v.v..............v....."
        ,"............................v..v.................v"
        ,".v.............v.......v.........................."
        ,"......v...v........................v.............."
        ,".........v.....v..............vv.................."
        ,"................v..v..v.........v....v.......v...."
        ,"........v.....v.............v......v.v............"
        ,"...........v....................v.v....v.v.v...v.."
        ,"...........v......................v...v..........."
        ,"..........vv...........v.v.....................v.."
        ,".....................v......v............v...v...."
        ,".....vv..........................vv.v.....v.v....."
        ,".vv.......v...............v.......v..v.....v......"
        ,"............v................v..........v....v...."
        ,"................vv...v............................"
        ,"................v...........v........v...v....v..."
        ,"..v...v...v.............v...v........v....v..v...."
        ,"......v..v.......v........v..v....vv.............."
        ,"...........v..........v........v.v................"
        ,"v.v......v................v....................v.."
        ,".v........v................................v......"
        ,"............................v...v.......v........."
        ,"........................vv.v..............v...vv.."
        ,".......................vv........v.............v.."
        ,"...v.............v.........................v......"
        ,"....v......vv...........................v........."
        ,"....vv....v................v...vv..............v.."
        ,".................................................."
        ,"vv........v...v..v.....v..v..................v...."
        ,".........v..............v.vv.v.............v......"
        ,".......v.....v......v...............v............."
        ,"..v..................v................v....v......"
        ,".....v.....v.....................v.v......v......."};
        vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 898961330; verify_case(3, Arg2, count(Arg0, Arg1));
    }
        void test_case_4() {
            string Arr0[] =
            {".v..."
                , "v.v.v", ".....", "....."};vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 1; verify_case(4, Arg2, count(Arg0, Arg1));
        }

        // END CUT HERE


    };



    // BEGIN CUT HERE

    int main() {

        GooseInZooDivOne ___test;

        ___test.run_test(-1);

    }

    // END CUT HERE
