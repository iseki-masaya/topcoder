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
//#include <random>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <thread>

const long long LINF = (1e18);
const int INF = (1<<28);
const int sINF = (1<<23);
const int MOD = 1000000007;
const double EPS = 1e-6;

using namespace std;

struct edge {
    int to, cap, rev;
    edge(int t, int c, int r) : to(t), cap(c), rev(r) {}
};

class FordFulkerson {
    vector<vector<edge> > G;
    vector<bool> used;
    int _N;

    int dfs(int v, int t, int f) {
        if (v == t) {
            return f;
        }
        used[v] = true;
        for (int i=0; i<G[v].size(); ++i) {
            edge &e = G[v][i];
            if (!used[e.to] && e.cap > 0) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

public:
    FordFulkerson(int N) {
        init(N);
    }

    void init(int N) {
        _N = N;
        G.clear();
        G.resize(_N);
    }

    void add_edge(int from, int to, int cap) {
        G[from].push_back(edge(to, cap, (int)G[to].size()));
        G[to].push_back(edge(from, 0, (int)G[from].size()-1));
    }

    int max_flow(int s, int t) {
        int flow = 0;
        while (true) {
            used.clear();
            used.resize(_N, false);
            int f = dfs(s, t, INF);
            if (f == 0) {
                return flow;
            }
            flow += f;
        }
    }
};

class BlockTheBlockPuzzle {

public:

    int minimumHoles(vector <string> board) {
        int N = (int)board.size();
        int gx = 0, gy = 0;
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                if (board[i][j] == '$') {
                    gx = i, gy = j;
                }
            }
        }

        //0: sorce == goal
        //1: sink == start
        unique_ptr<FordFulkerson> G(new FordFulkerson(N*N));
        int source = 0, sink = 1;
        vector<vector<int> > From(N, vector<int>(N)), To(N, vector<int>(N));
        int vertex = 2;
        for (int i=gx%3; i<N; i+=3) {
            for (int j=gy%3; j<N; j+=3) {
                if (board[i][j] != 'H') {
                    From[i][j] = vertex++;
                    To[i][j] = vertex++;

                    if (board[i][j] == '.') {
                        G->add_edge(From[i][j], To[i][j], 1);
                    } else {
                        G->add_edge(From[i][j], To[i][j], INF);
                    }

                    if (i == gx && j == gy) {
                        G->add_edge(source, From[i][j], INF);
                    }
                    if (board[i][j] == 'b') {
                        G->add_edge(To[i][j], sink, INF);
                    }
                }
            }
        }

        const int dx[] = {1,0,-1,0};
        const int dy[] = {0,1,0,-1};

        for (int i=gx%3; i<N; i+=3) {
            for (int j=gy%3; j<N; j+=3) {
                for (int dir=0; dir<4; ++dir) {
                    int nx = i + 3*dx[dir];
                    int ny = j + 3*dy[dir];
                    if ( (0 <= nx && nx < N) && (0 <= ny && ny <N) &&
                            board[i][j] != 'H' && board[nx][ny] != 'H' ) {
                        char s1 = board[i + dx[dir]][j + dy[dir]];
                        char s2 = board[i + 2*dx[dir]][j + 2*dy[dir]];
                        int cap = 0;
                        if (s1 == 'b' || s2 == 'b') {
                            cap = INF;
                        } else {
                            if (s1 == '.')
                                ++cap;
                            if (s2 == '.')
                                ++cap;
                        }
                        G->add_edge(To[i][j], From[nx][ny], cap);
                    }
                }
            }
        }

        int f = G->max_flow(source, sink);
        if (f >= INF)
            return -1;
        else
            return f;
    }


    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"b..$",
        "....",
        "HHHH",
        "HHHH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minimumHoles(Arg0)); }
    void test_case_1() { string Arr0[] = {"............H..",
        "...............",
        "...............",
        "HHH$HHH.....H..",
        "HHHHHHH........",
        "HHHHHHHH.......",
        "......b..H.....",
        "...............",
        "...............",
        "...H..H..H.....",
        "...............",
        "...............",
        "...............",
        "...............",
        "..............."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, minimumHoles(Arg0)); }
    void test_case_2() { string Arr0[] = {"............H..",
        "...............",
        "...............",
        "HHH$HHH........",
        "HHHHHHH........",
        "HHHHHHHH.......",
        "......b..H.....",
        "...............",
        "...............",
        "...H..H..H.....",
        "...............",
        "...............",
        "...............",
        "...............",
        "..............."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, minimumHoles(Arg0)); }
    void test_case_3() { string Arr0[] = {"b..$...",
        "...H...",
        ".......",
        "b..b..b",
        "...H...",
        ".......",
        "b..b..b"}

        ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, minimumHoles(Arg0)); }
    void test_case_4() { string Arr0[] = {"b..b..b",
        "..b..b.",
        ".......",
        "b..$bbb",
        ".b.....",
        "....b..",
        "b..b..b"}
        ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, minimumHoles(Arg0)); }

    // END CUT HERE


};



// BEGIN CUT HERE

int main() {

    BlockTheBlockPuzzle ___test;

    ___test.run_test(-1);

}

// END CUT HERE
