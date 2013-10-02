#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <errno.h>
#include <sstream>

using namespace std;

#define MAX 99999

class FloorBoards
{
public:
	int addLine(int now,int prev,int obs,int sizeX)
	{
		int cnt = 0;
		bool isHorizon = false;

		for (int i=0; i<sizeX; ++i) {
			if(((now >> i)&1) == 1) { //vertical stick
				if(((prev >> i)&1) != 1) ++cnt;
				isHorizon	= false;
			}
			else { //horizon stick
				if(((obs >> i)&1) == 1) {
					isHorizon = false;
				}
				else {
					if(!isHorizon) ++cnt;
					isHorizon = true;
				}
			}
		}

		return cnt;
	}

	int layout(vector <string> room)
	{
		int sizeX = static_cast<int>(room[0].size());
		int sizeY = static_cast<int>(room.size());

		vector<vector<int> > dp(sizeY+1,vector<int>(1<<sizeX,MAX));

		dp[0][0] = 0;
		for (int y=0; y<sizeY; ++y) {
			int obs = 0;
			for(int x=0;x<sizeX;++x)
				if(room[y][x] == '#')
					obs += 1 << x;

			for (int prev = 0; prev< 1<<sizeX; ++prev) {
				if(dp[y][prev] == MAX) continue; //for avoid first calculation
				for (int now = 0; now< 1<<sizeX; ++now) {
					if((obs&now) != 0) continue;
					dp[y+1][now] = min(dp[y+1][now],dp[y][prev]+addLine(now,prev,obs,sizeX));
				}
			}
		}

		int ret = MAX;
		for(int i=0;i< 1<<sizeX;++i)
			ret = min(ret,dp[sizeY][i]);
		return ret;
	}
};