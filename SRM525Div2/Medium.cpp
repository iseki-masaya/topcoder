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

#define INF (1<<10)

class DropCoins {
	int count(int vw,int vp,int hw,int hp,vector<string> &board)
	{
		int ret = 0;
		for (int v=vp; v < vp+vw; ++v)
			for (int h=hp; h < hp+hw; ++h)
				if (board[v][h]=='o')
					++ret;

		return ret;
	}
	int calcCost(int p,int w,int size)
	{
		int small = p;
		int large = size - (p+w);
		if (small > large)
			swap(small, large);

		return large + 2*small;
	}
public:
	int getMinimum(vector <string> board, int K)
	{
		int ans=INF;
		int sizeV = static_cast<int>(board.size());
		int sizeH = static_cast<int>(board[0].size());
		for (int vw=1; vw <= sizeV; ++vw) {
			for (int vp=0; vp+vw <= sizeV; ++vp) {
				for (int hw=1; hw <= sizeH; ++hw) {
					for (int hp=0; hp+hw <= sizeH; ++hp) {
						if (K == count(vw, vp, hw, hp,board)) {
							ans = min(ans,calcCost(vp, vw, sizeV)+calcCost(hp, hw, sizeH));
						}
					}
				}
			}
		}

		return ans==INF?-1:ans;
	}
};