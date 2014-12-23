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

const long long LINF = (5e18);
const int INF = (1<<30);
const int sINF = (1<<23);
const int MOD = 1000000009;
const double EPS = 1e-6;

using namespace std;

struct edge {
	int to, cap, cost, rev;
	edge(int t, int cap, int cost, int r) : to(t), cap(cap), cost(cost), rev(r) {}
};

class MinCostFlow {
	vector<vector<edge>> G;
	vector<int> prevv, preve;
	int dist[1000];
	int V;
	
public:
	MinCostFlow(int n) {
		init(n);
	}
	
	void init(int n) {
		V = n;
		preve.clear(); preve.resize(V);
		prevv.clear(); prevv.resize(V);
		G.clear(); G.resize(V);
	}
	
	void add_edge(int from, int to, int cap, int cost) {
		G[from].push_back(edge(to, cap, cost, (int)G[to].size()));
		G[to].push_back(edge(from, 0, -cost, (int)G[from].size()-1));
	}
	
	int min_cost_flow(int s, int t, int f) {
		int res = 0;
		while (f > 0) {
			fill(dist, dist+V, INF);
			dist[s] = 0;
			bool update = true;
			while (update) {
				update = false;
				for (int v=0; v<V; ++v) {
					if (dist[v] == INF)
						continue;
					for (int i=0; i<G[v].size(); ++i) {
						edge &e = G[v][i];
						if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
							dist[e.to] = dist[v] + e.cost;
							prevv[e.to] = v;
							preve[e.to] = i;
							update = true;
						}
					}
				}
			}
			
			if (dist[t] == INF) {
				return -1;
			}
			
			int d = f;
			for (int v=t; v!=s; v=prevv[v])
				d = min(d, G[prevv[v]][preve[v]].cap);
			f -= d;
			res += d * dist[t];
			for (int v=t; v!=s; v=prevv[v]) {
				edge &e = G[prevv[v]][preve[v]];
				e.cap -= d;
				G[v][e.rev].cap += d;
			}
		}
		
		return res;
	}
};

class GoodCompanyDivOne {
	
public:
	vector<int> superior, training;
	int dp[35][35];
	int N, K;
	
	int f(int x, int p) {
		if (dp[x][p] != -1)
			return dp[x][p];
		vector<int> y(1, x);
		for (int i=0; i<N; ++i) {
			if (superior[i] == x) {
				y.push_back(i);
			}
		}
		int m = (int)y.size();
		vector<vector<int>> table(m, vector<int>(K, INF));
		for (int i=0; i<K; ++i) {
			if (i == p)
				continue;
			table[0][p] = min(table[0][p], training[i]);
			table[0][i] = training[i];
		}
		for (int j=1; j<m; ++j) {
			for (int i=0; i<K; ++i) {
				table[j][i] = f(y[j], i);
			}
		}
		unique_ptr<MinCostFlow> G(new MinCostFlow(m+K+2));
		int source = m+K, sink = m+K+1;
		for(int i=0; i<m; ++i)
			G->add_edge(source, i, 1, 0);
		for(int i=0; i<K; ++i)
			G->add_edge(m+i, sink, 1, 0);
		for (int j=0; j<m; ++j) {
			for (int i=0; i<K; ++i) {
				G->add_edge(j, m+i, 1, table[j][i]);
			}
		}
		int t = G->min_cost_flow(source, sink, m);
		int res;
		if (t == -1)
			res = sINF;
		else
			res = t + training[p];
		return dp[x][p] = res;
	}
	
	int minimumCost(vector <int> superior, vector <int> training) {
		this->superior = superior;
		this->training = training;
		memset(dp, -1, sizeof(dp));
		
		this->N = (int)superior.size();
		int root = -1;
		for (int i=0; i<N; ++i)
			if (superior[i] == -1)
				root = i;
		
		this->K = (int)training.size();
		int ans = sINF;
		for (int i=0; i<K; ++i)
			ans = min(ans, f(root, i));
		return ans == sINF ? -1 : ans;
	}
	
	
	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(0, Arg2, minimumCost(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-1, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(1, Arg2, minimumCost(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-1, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, minimumCost(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-1, 0, 0, 2, 2, 2, 1, 1, 6, 0, 5, 4, 11, 10, 3, 6, 11, 7, 0, 2, 13, 14, 2, 10, 9, 11, 22, 10, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 2, 6, 6, 8, 3, 3, 1, 1, 5, 8, 6, 8, 2, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 71; verify_case(3, Arg2, minimumCost(Arg0, Arg1)); }
	
	// END CUT HERE
	
	
};



// BEGIN CUT HERE

int main() {
	
	GoodCompanyDivOne ___test;
	
	___test.run_test(-1);
	
}

// END CUT HERE
