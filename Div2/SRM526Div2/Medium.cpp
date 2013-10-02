#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

#define MAX 50000

class DucksAlignment {
	struct point {
		int x,y;
	};

	static
	bool compX(const point &lhs,const point &rhs)
	{
		return lhs.x < rhs.x;
	}
	static
	bool compY(const point &lhs,const point &rhs)
	{
		return lhs.y < rhs.y;
	}

	int calcCostVer(int num,point tar,vector<point> &p)
	{
		int ret = 0;
		for (int i=0; i<p.size(); ++i) {
			ret += abs(tar.x-p[i].x);
		}
		for (int i=0; i<p.size(); ++i) {
			int offset = abs(num-i);
			ret += abs(tar.y-p[i].y)-offset;
		}

		return ret;
	}

	int calcCostHor(int num,point tar,vector<point> &p)
	{
		int ret = 0;
		for (int i=0; i<p.size(); ++i) {
			ret += abs(tar.y-p[i].y);
		}
		for (int i=0; i<p.size(); ++i) {
			int offset = abs(num-i);
			ret += abs(tar.x-p[i].x)-offset;
		}

		return ret;
	}

public:
	int minimumTime(vector <string> grid)
	{
		vector<point> px,py;
		point work;
		for (int y=0; y<grid.size(); ++y) {
			for (int x=0; x<grid[y].size(); ++x) {
				if (grid[y][x] == 'o') {
					work.x = x;
					work.y = y;
					px.push_back(work);
					py.push_back(work);
				}
			}
		}

		sort(px.begin(), px.end(), compX);
		sort(py.begin(), py.end(), compY);
		int ans = MAX;

		for (int y=0; y<grid.size(); ++y) {
			for (int x=0; x<grid[y].size(); ++x) {
				int xi=0;
				int yi=0;
				int mn = MAX;
				for (int i=0;i<px.size();++i) {
					int dist = abs(x-px[i].x);
					if (mn > dist) {
						xi = i;
						mn = dist;
					}
				}
				mn = MAX;
				for (int i=0;i<py.size();++i) {
					int dist = abs(y-py[i].y);
					if (mn > dist) {
						yi = i;
						mn = dist;
					}
				}

				work.x = x;
				work.y = y;
				ans = min(ans,calcCostVer(yi,work, py));
				ans = min(ans,calcCostHor(xi,work, px));
			}
		}

		return ans;
	}
};
