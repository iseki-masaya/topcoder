#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <sstream>
#include <stack>
#include <istream>

#define INF 2000000001
#define SIZE 8

using namespace std;

typedef pair<int, int> P;

vector<vector<long long> > es(SIZE,vector<long long>(SIZE,INF));

class ThreeTeleports {
public:
	int shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports)
	{
		vector<pair<long long, long long> > point;
		point.push_back(make_pair(xMe, yMe));
		point.push_back(make_pair(xHome, yHome));
		vector<int> p(4);
		for (int i=0; i<teleports.size(); ++i) {
			for (int j=0; j<4; ++j) {
				size_t pos = teleports[i].find(" ");
				string s = teleports[i].substr(0,pos);
				stringstream ss;
				ss << s;
				ss >> p[j];
				teleports[i] = teleports[i].substr(pos+1,teleports[i].size());
			}
			point.push_back(make_pair(p[0], p[1]));
			point.push_back(make_pair(p[2], p[3]));
			es[(i+1)*2][(i+1)*2+1] = 10;
			es[(i+1)*2+1][(i+1)*2] = 10;
		}

		for (int from=0; from<SIZE; ++from) {
			for (int to=0; to<SIZE; ++to) {
				if (from == to) {
					continue;
				}
				if (es[from][to] == INF) {
					es[from][to] = abs(point[from].first-point[to].first) + abs(point[from].second - point[to].second);
					es[to][from] = es[from][to];
				}
			}
		}

		vector<long long> d(9,INF);
		d[0] = 0;
		priority_queue<P,vector<P>,greater<P> > q;
		q.push(P(0,0));
		while (!q.empty()) {
			P p = q.top(); q.pop();
			int v = p.second;
			if (d[v] < p.first) {
				continue;
			}
			for (int i=0; i<es[v].size(); ++i) {
				if (d[i] > d[v] + es[v][i]) {
					d[i] = d[v] + es[v][i];
					q.push(P(d[i],i));
				}
			}
		}
		return static_cast<int>(d[1]);
	}
};