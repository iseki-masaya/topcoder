#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class FoxAndFlowerShopDivTwo
{
public:
	int calcFlowerNum(const vector <string> &flowers,int left,int right,int up,int down)
	{
		int sum = 0;
		for (int y=up; y<down ; ++y) {
			for (int x = left; x<right; ++x) {
				if (flowers.at(y).at(x) == 'F') {
					++sum;
				}
			}
		}
		
		return sum;
	}
	
	int theMaxFlowers(vector <string> flowers, int r, int c)
	{
		int max = 0;
		
		int sizeY = static_cast<int>(flowers.size());
		int sizeX = static_cast<int>(flowers.at(0).size());
		
		int left[4] = {c+1,0,0,0};
		int right[4] = {sizeX,sizeX,c,sizeX};
		int up[4] = {0,0,0,r+1};
		int down[4] = {sizeY,r,sizeY,sizeY};
		for (int i=0; i<4; ++i) {
			int num = calcFlowerNum(flowers, left[i], right[i], up[i], down[i]);
			if (num > max) {
				max = num;
			}
		}
		
		return max;
	}
};