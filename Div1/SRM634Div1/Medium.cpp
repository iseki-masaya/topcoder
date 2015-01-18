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
#include <memory>

const long long LINF = (5e18);
const int INF = (1<<30);
#define EPS 1e-6
const int MOD = 1000000007;

using namespace std;

struct edge {
    int to, cap, rev;
    edge(int t, int c, int r) : to(t),cap(c),rev(r) {}
};

class Dinic {
    vector<vector<edge> > G;
    vector<int> level, iter;
    int N;

    void bfs(int s) {
        level.clear(); level.resize(N, -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int u=0; u<G[v].size(); ++u) {
                edge &e = G[v][u];
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    int dfs(int v, int t, int f) {
        if (v == t)
            return f;
        for (int &u=iter[v]; u<G[v].size(); ++u) {
            edge &e = G[v][u];
            if (e.cap <= 0 || level[v] >= level[e.to])
                continue;
            int d = dfs(e.to, t, min(f, e.cap));
            if (d <= 0)
                continue;
            e.cap -= d;
            G[e.to][e.rev].cap += d;
            return d;
        }
        return 0;
    }

public:
    void init(int n) {
        N = n;
        G.clear(); G.resize(N);
        level.clear(); level.resize(N);
        iter.clear(); iter.resize(N);
    }

    void add_edge(int from, int to, int cap) {
        G[from].push_back(edge(to, cap, (int)G[to].size()));
        G[to].push_back(edge(from, 0, (int)G[from].size()-1));
    }

    int max_flow(int s, int t) {
        int flow = 0;
        while (true) {
            bfs(s);
            if (level[t] < 0 )
                return flow;
            iter.clear(); iter.resize(N, 0);
            int f;
            while ((f = dfs(s, t, INF)) > 0)
                flow += f;
        }
    }
};

class SegmentDrawing {

public:
    struct P {
        int x,y;
        P(int cx, int cy) : x(cx), y(cy) {}
    };

    long long cross(P v, P u) {
        return v.x*u.y - v.y*u.x;
    }

    P sub(P &u, P &v) {
        return P(u.x-v.x, u.y-v.y);
    }

    bool intersect(int ax0, int ay0, int ax1, int ay1, int bx0, int by0, int bx1, int by1) {
        P a0 = P(ax0, ay0);
        P a1 = P(ax1, ay1);
        P b0 = P(bx0, by0);
        P b1 = P(bx1, by1);
        return cross(sub(a1, a0), sub(a1, b0)) * cross(sub(a1, a0), sub(a1, b1)) <= 0 &&
                     cross(sub(b1, b0), sub(b1, a0)) * cross(sub(b1, b0), sub(b1, a1)) <= 0;
    }

    bool segmentsIntersect(const int&x1, const int&y1, const int&x2,const int&y2,const int&x3,const int&y3,const int&x4,const int&y4)
    {
        int dx1=x2-x1;
        int dx2=y2-y1;

        int dy1=x3-x4;
        int dy2=y3-y4;

        int dz1=x3-x1;
        int dz2=y3-y1;

        int D=/*determinant*/ dx1*dy2-dy1*dx2;
        int E=/*determinant*/ dz1*dy2-dy1*dz2;
        int F=/*determinant*/ dx1*dz2-dz1*dx2;

        if(D==0) return false; //pararell
        if(D<0) { D*=-1; E*=-1; F*=-1; }
        if (E<0) return false;
        if (F<0) return false;
        if (E>D) return false;
        if (F>D) return false;
        return true;
    }

    int maxScore(vector <int> x, vector <int> y, vector <int> redScore, vector <int> blueScore) {
        int n = (int)x.size();
        int N = (int)redScore.size();
        int sum = 0;
        int source = 2*N, sink = 2*N+1;
        unique_ptr<Dinic>   f(new Dinic);
        f->init(2*N+2);
        for(int i=0; i<N; ++i) {
            if (i/n >= i%n)
                continue;

            sum += redScore[i] + blueScore[i];
            f->add_edge(source, i, redScore[i]);
            f->add_edge(i+N, sink, blueScore[i]);
            f->add_edge(i, i+N, INF);

            for (int j=0; j<N; ++j) {
                if (j/n >= j%n || i == j)
                    continue;
                int ax0 = x[i/n], ay0 = y[i/n];
                int ax1 = x[i%n], ay1 = y[i%n];
                int bx0 = x[j/n], by0 = y[j/n];
                int bx1 = x[j%n], by1 = y[j%n];
                if (segmentsIntersect(ax0, ay0, ax1, ay1, bx0, by0, bx1, by1))
                    f->add_edge(i, j+N, INF);
            }
        }
        return sum - f->max_flow(source, sink);
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {0,1,0,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,0,-1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 3,
        1, 0, 6, 4,
        2, 6, 0, 5,
        3, 4, 5, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 2, 3, 7,
            2, 0, 4, 6,
            3, 4, 0, 5,
            7, 6, 5, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 27; verify_case(0, Arg4, maxScore(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_1() { int Arr0[] = {0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 101, 101, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 100, 100, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 101; verify_case(1, Arg4, maxScore(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_2() { int Arr0[] = {-3, -1, -1,  1,  1,  3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 0, -2,  2, -2,  2,  0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 2, 1, 2, 1, 2,
        2, 0, 2, 1, 2, 1,
        1, 2, 0, 2, 1, 2,
        2, 1, 2, 0, 2, 1,
        1, 2, 1, 2, 0, 2,
        2, 1, 2, 1, 2, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0,
            0, 0, 0, 21, 0, 0,
            0, 0, 21, 0, 0, 0,
            0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 25; verify_case(2, Arg4, maxScore(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_3() { int Arr0[] = {-100, 100, 0, -10, 10, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 100, 10, 10, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0, 96, 96, 25, 25, 25,
        96,  0, 96, 25, 25, 25,
        96, 96,  0, 25, 25, 25,
        25, 25, 25,  0, 10, 10,
        25, 25, 25, 10,  0, 10,
        25, 25, 25, 10, 10,  0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 0, 30, 30, 20, 20, 20,
            30,  0, 30, 20, 20, 20,
            30, 30,  0, 20, 20, 20,
            20, 20, 20,  0, 86, 86,
            20, 20, 20, 86,  0, 86,
            20, 20, 20, 86, 86,  0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 546; verify_case(3, Arg4, maxScore(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_4() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 15, 2, 3, 4, 5, 6, 7, 8, 9,
        15, 0, 15, 2, 3, 4, 5, 6, 7, 8,
        2, 15, 0, 15, 2, 3, 4, 5, 6, 7,
        3, 2, 15, 0, 15, 2, 3, 4, 5, 6,
        4, 3, 2, 15, 0, 15, 2, 3, 4, 5,
        5, 4, 3, 2, 15, 0, 15, 2, 3, 4,
        6, 5, 4, 3, 2, 15, 0, 15, 2, 3,
        7, 6, 5, 4, 3, 2, 15, 0, 15, 2,
        8, 7, 6, 5, 4, 3, 2, 15, 0, 15,
        9, 8, 7, 6, 5, 4, 3, 2, 15, 0}
        ; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 0, 2, 3, 4, 5, 6, 7, 8, 9,
            0, 0, 0, 2, 3, 4, 5, 6, 7, 8,
            2, 0, 0, 0, 2, 3, 4, 5, 6, 7,
            3, 2, 0, 0, 0, 2, 3, 4, 5, 6,
            4, 3, 2, 0, 0, 100, 2, 3, 4, 5,
            5, 4, 3, 2, 100, 0, 0, 2, 3, 4,
            6, 5, 4, 3, 2, 0, 0, 0, 2, 3,
            7, 6, 5, 4, 3, 2, 0, 0, 0, 2,
            8, 7, 6, 5, 4, 3, 2, 0, 0, 0,
            9, 8, 7, 6, 5, 4, 3, 2, 0, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 300; verify_case(4, Arg4, maxScore(Arg0, Arg1, Arg2, Arg3)); }
    void test_case_5() { int Arr0[] = {49, 880, 519, -888, -636, 188, -346, -379, -232, -125, -311, -824, 571, -638, 893, 298}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {343, 25, -699, 603, 172, 672, 668, -786, -398, 584, -184, 563, 43, -314, 239, 881}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 5, 3223, 11, 4118, 1350, 2, 1598, 1509, 7858, 403, 1562, 654, 53406, 64280, 18722, 5, 0, 231, 38, 69264, 21, 24, 19, 4, 61754, 1, 13775, 1430, 2, 17, 13249, 3223, 231, 0, 14, 16720, 34, 7355, 999, 562, 1, 1, 1399, 30299, 65184, 9, 12, 11, 38, 14, 0, 22627, 4311, 1, 10, 335, 156, 7344, 1, 1221, 2935, 47, 146, 4118, 69264, 16720, 22627, 0, 60842, 8967, 2940, 347, 36979, 58, 13617, 1, 115, 263, 4, 1350, 21, 34, 4311, 60842, 0, 35, 4153, 29108, 1, 372, 139, 27, 69, 12, 7702, 2, 24, 7355, 1, 8967, 35, 0, 171, 10, 195, 39, 5882, 9678, 107, 322, 2502, 1598, 19, 999, 10, 2940, 4153, 171, 0, 56307, 179, 33338, 6092, 12, 3250, 5812, 26634, 1509, 4, 562, 335, 347, 29108, 10, 56307, 0, 1115, 16780, 359, 16043, 2858, 5, 1835, 7858, 61754, 1, 156, 36979, 1, 195, 179, 1115, 0, 7, 4, 90, 14617, 2906, 4, 403, 1, 1, 7344, 58, 372, 39, 33338, 16780, 7, 0, 63597, 1, 7, 1, 2086, 1562, 13775, 1399, 1, 13617, 139, 5882, 6092, 359, 4, 63597, 0, 65393, 26527, 5871, 5, 654, 1430, 30299, 1221, 1, 27, 9678, 12, 16043, 90, 1, 65393, 0, 5, 2, 43, 53406, 2, 65184, 2935, 115, 69, 107, 3250, 2858, 14617, 7, 26527, 5, 0, 2236, 15, 64280, 17, 9, 47, 263, 12, 322, 5812, 5, 2906, 1, 5871, 2, 2236, 0, 1, 18722, 13249, 12, 146, 4, 7702, 2502, 26634, 1835, 4, 2086, 5, 43, 15, 1, 0}
        ; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] =    {0, 324, 31, 11035, 2, 436, 1, 574, 4, 199, 86654, 40, 76, 5568, 15554, 9, 324, 0, 23, 15026, 14, 4, 6, 4, 32257, 3, 740, 1050, 28051, 82, 3674, 1161, 31, 23, 0, 45075, 95, 16367, 4739, 3, 1335, 718, 543, 3, 63843, 31, 637, 47, 11035, 15026, 45075, 0, 3, 3946, 96203, 256, 13424, 69, 620, 3106, 429, 4, 2745, 553, 2, 14, 95, 3, 0, 1529, 2353, 5982, 4724, 4074, 12464, 4172, 3003, 81, 1, 193, 436, 4, 16367, 3946, 1529, 0, 3, 25, 39454, 16611, 41, 54854, 1814, 71, 17636, 2, 1, 6, 4739, 96203, 2353, 3, 0, 96047, 1, 751, 723, 35158, 145, 1212, 122, 9612, 574, 4, 3, 256, 5982, 25, 96047, 0, 1, 52, 55, 199, 28257, 98, 349, 2631, 4, 32257, 1335, 13424, 4724, 39454, 1, 1, 0, 15736, 2, 7, 2, 6853, 1233, 51, 199, 3, 718, 69, 4074, 16611, 751, 52, 15736, 0, 2473, 6630, 5241, 26015, 7, 15, 86654, 740, 543, 620, 12464, 41, 723, 55, 2, 2473, 0, 22827, 53, 12909, 40201, 28796, 40, 1050, 3, 3106, 4172, 54854, 35158, 199, 7, 6630, 22827, 0, 708, 1, 8600, 268, 76, 28051, 63843, 429, 3003, 1814, 145, 28257, 2, 5241, 53, 708, 0, 1397, 264, 104, 5568, 82, 31, 4, 81, 71, 1212, 98, 6853, 26015, 12909, 1, 1397, 0, 1, 9466, 15554, 3674, 637, 2745, 1, 17636, 122, 349, 1233, 7, 40201, 8600, 264, 1, 0, 9978, 9, 1161, 47, 553, 193, 2, 9612, 2631, 51, 15, 28796, 268, 104, 9466, 9978, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1040659; verify_case(5, Arg4, maxScore(Arg0, Arg1, Arg2, Arg3)); }


    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    SegmentDrawing ___test;

    ___test.run_test(5);

}

// END CUT HERE
