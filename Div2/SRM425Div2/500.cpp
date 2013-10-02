#include <iostream>
#include <vector>
#include <string>

using namespace std;

int vx[] = {1,-1,0,0};
int vy[] = {0,0,1,-1};
bool map[100][100] = {false};

class CrazyBot
{
public:
	struct Point
	{
		int x;
		int y;
	};
	
	double dirProb[4];
	
	void setDirProb(int east, int west, int south, int north)
	{
		this->dirProb[0] = east/100.0;
		this->dirProb[1] = west/100.0;
		this->dirProb[2] = south/100.0;
		this->dirProb[3] = north/100.0;
	}

	double calcProbability(int x ,int y,int n)
	{
		if(n==0)
			return 1.0;
		
		map[y][x] = true;
		double ret = 0;
		for (int i=0; i<4; ++i) {
			if (map[y+vy[i]][x+vx[i]])
				continue;
			
			ret += calcProbability(x+vx[i], y+vy[i], n-1) * dirProb[i];
		}
		map[y][x] = false;
		return ret;
	}
	
	double getProbability(int n, int east, int west, int south, int north)
	{
		setDirProb(east, west, south, north);
		return calcProbability(n+1, n+1, n);
	}
};