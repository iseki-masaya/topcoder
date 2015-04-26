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
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <cstdio>
//#include <cstdlib>
#include <cstring>
#include <numeric>
#include <bitset>
#include <deque>
#include <memory>

const long long LINF = (5e17);
const int INF = 1000000000;
#define EPS 1e-7
const int MOD = 1000000007;

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

class TaroCutting {

public:

	int getNumber(vector <int> height, vector <int> add, vector <int> device, int time) {
		int H = (int)height.size();
		int D = (int)device.size();

		unique_ptr<MinCostFlow> mcf(new MinCostFlow(H + D + time + 5));
		int source = H + D + time + 1;
		int sink = H + D + time + 2;
		int none = H + D + time + 3;

		for (int h=0; h<H; ++h) {
			mcf->add_edge(source, h, 1, 0);
			mcf->add_edge(h, none, 1, height[h] + add[h]*time);
		}
		mcf->add_edge(none, sink, H, 0);
		for (int h=0; h<H; ++h) {
			for (int k=0; k<time; ++k) {
				mcf->add_edge(h, H+k, 1, add[h]*(time - k - 1));
			}
		}
		for (int k=0; k<time; ++k) {
			for (int d=0; d<D; ++d) {
				mcf->add_edge(H+k, H+time+d, 1, device[d]);
			}
		}
		for (int d=0; d<D; ++d) {
			mcf->add_edge(H+time+d, sink, time, 0);
		}
		return mcf->min_cost_flow(source, sink, H);
	}


	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {4, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arg4 = 15; verify_case(0, Arg4, getNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {3, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7, 7, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 12; verify_case(1, Arg4, getNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {100, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {75, 30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {200, 100, 50}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 130; verify_case(2, Arg4, getNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {7, 10, 1, 7, 5, 4, 11, 5, 7, 9, 10, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 4, 10, 2, 1, 6, 4, 8, 7, 5, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {7, 1, 5, 10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 96; verify_case(3, Arg4, getNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {35, 45, 32, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 25, 31, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {29, 28, 3, 11, 28, 37}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; int Arg4 = 29; verify_case(4, Arg4, getNumber(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {614, 649, 977, 808, 821, 356, 801, 493, 669, 650, 652, 627, 129, 261, 883, 513, 62, 698, 83, 772,
		779, 719, 83, 105, 774, 867, 412, 892, 142, 851, 743, 66, 221, 494, 125, 905, 638, 342, 723, 680,
		407, 197, 111, 368, 676, 694, 765, 482, 712, 188, 325, 535, 6, 49, 655, 595, 958, 805, 659, 893,
		370, 904, 276, 156, 29, 458, 757, 632, 731, 289, 582, 207, 843, 365, 387, 521, 69, 269, 459, 428,
		423, 885, 744, 199, 998, 968, 296, 473, 50, 752, 492, 919, 473, 981, 380, 896, 769, 991, 269, 93,
		108, 184, 762, 312, 511, 256, 374, 600, 643, 445, 908, 250, 384, 518, 119, 464, 499, 124, 82, 999,
		881, 767, 177, 796, 2, 620, 759, 380, 901, 221, 407, 622, 260, 622, 729, 264, 768, 79, 236, 524,
		437, 215, 108, 518, 820, 725, 490, 796, 986, 318}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {391, 938, 772, 630, 54, 775, 379, 613, 647, 8, 946, 885, 604, 822, 663, 559, 452, 565, 637, 695, 24,
			515, 92, 956, 194, 551, 813, 362, 190, 268, 440, 781, 450, 789, 566, 372, 402, 860, 531, 608, 434,
			761, 754, 26, 504, 873, 132, 756, 206, 93, 284, 807, 642, 637, 936, 954, 205, 303, 582, 822, 134,
			269, 967, 147, 589, 549, 24, 670, 403, 105, 40, 531, 486, 695, 898, 287, 443, 542, 599, 151, 45,
			567, 548, 945, 912, 764, 451, 404, 700, 522, 227, 954, 84, 347, 625, 278, 377, 730, 635, 604, 959,
			845, 41, 193, 459, 532, 429, 216, 473, 415, 85, 933, 90, 643, 94, 927, 692, 99, 771, 594, 318, 627,
			89, 340, 110, 488, 909, 253, 20, 114, 179, 177, 116, 42, 676, 91, 787, 437, 551, 51, 880, 336, 759,
			795, 243, 727, 279, 620, 488, 607}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {942, 79, 387, 184, 104, 981, 766, 678, 715, 998, 161, 125, 439, 532, 550, 415, 4, 467, 211, 852, 781,
				577, 728, 592, 40, 971, 852, 592, 338, 555, 662, 636, 823, 122, 728, 69, 701, 476, 346, 190, 36,
				535, 826, 739, 517, 551, 257, 36, 906, 171, 629, 292, 49, 29, 109, 151, 299, 180, 193, 731, 655,
				877, 174, 688, 866, 957, 57, 89, 513, 765, 68, 245, 454, 968, 224, 417, 657, 383, 769, 809, 13, 51,
				813, 970, 632, 357, 787, 717, 254, 645, 352, 636, 370, 950, 917, 959, 364, 453, 890, 43, 98, 438,
				748, 277, 115, 298, 431, 709, 312, 49, 553, 395, 798, 58, 419, 355, 770, 818, 460, 89, 880, 515,
				952, 219, 608, 284, 532, 254, 361, 524, 199, 265, 407, 782, 737, 928, 977, 729, 510, 175, 609, 81,
				155, 24, 425, 186, 999, 839, 896, 721}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 150; int Arg4 = 43325; verify_case(5, Arg4, getNumber(Arg0, Arg1, Arg2, Arg3)); }

	// END CUT HERE


};



// BEGIN CUT HERE

int main() {

	TaroCutting ___test;

	___test.run_test(-1);

}

// END CUT HERE
