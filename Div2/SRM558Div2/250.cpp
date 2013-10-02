#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isDominated[21][21] = {false};
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

class SurroundingGameEasy
{
public:
	void fillSurrounded(int sizeX,int sizeY,const vector <string> &stone)
	{
		int nx,ny;
		bool isEnclose = true;
		for (int x=0; x<sizeX; ++x) {
			for (int y=0; y<sizeY; ++y) {
				for (int i=0; i<4; ++i) {
					nx = x + dx[i];
					ny = y + dy[i];
					if(nx < 0 || nx >= sizeX || ny < 0 || ny >= sizeY)
						continue;
					if(stone[ny][nx] == '.') {
						isEnclose = false;
						break;
					}
				}
				
				if (isEnclose) {
					isDominated[y][x] = true;
				}
				isEnclose = true;
			}
		}
	}
	
	void fillDominated(int sizeX,int sizeY,const vector <string> &stone)
	{
		for (int y=0;y<sizeY;++y) {
			for (int x=0; x<sizeX; ++x) {
				if(stone[y][x] == 'o')
					isDominated[y][x] = true;
			}
		}
	}
	
	int calcCost(int sizeX,int sizeY,const vector <string> cost,const vector <string> stone)
	{
		int sum = 0;
		for (int y=0; y<sizeY; ++y) {
			for (int x=0; x<sizeX; ++x) {
				if(stone[y][x] == 'o'){
					sum += (int)(cost[y][x] - '0');
				}
			}
		}
		return sum;
	}
	
	int calcBenefit(int sizeX,int sizeY,const vector <string> benefit)
	{
		int sum = 0;
		for (int y=0; y<sizeY; ++y) {
			for (int x=0; x<sizeX; ++x) {
				if(isDominated[y][x]){
					sum += (int)(benefit[y][x] - '0');
				}
			}
		}
		return sum;
	}
	
	int score(vector <string> cost, vector <string> benefit, vector <string> stone)
	{
		int sizeY = (int)cost.size();
		int sizeX = (int)cost.at(0).size();
		fillSurrounded(sizeX, sizeY,stone);
		fillDominated(sizeX, sizeY,stone);
		int sumCost = calcCost(sizeX, sizeY,cost,stone);
		int sumBenefit = calcBenefit(sizeX, sizeY, benefit);
		return sumBenefit - sumCost;
	}
};