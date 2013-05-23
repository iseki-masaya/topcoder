#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int memo[51][51] = {0};

class GooseInZooDivTwo
{
private:
	vector<string> gField;
	int sizeX,sizeY;
	int dist;

	void print()
	{
		for (int y=0; y<this->sizeY; ++y) {
			for (int x=0; x<this->sizeX; ++x) {
				cout << memo[y][x];
			}
			cout << endl;
		}
	}
public:
	bool isConnect(int x,int y,int rest,int number)
	{
		if (x < 0 || this->sizeX <= x || y < 0 || this->sizeY <= y) return false;
		if (memo[y][x] != 0 || rest < 0) return false;

		if (this->gField[y][x] == 'v') {
			memo[y][x] = number;
			rest = this->dist;
		}


		for (int j=0; j<4; ++j) {
			isConnect(x+dx[j], y+dy[j], rest-1, number);
		}


		return true;
	}

	int count(vector <string> field, int dist)
	{
		this->gField = field;
		this->sizeY = static_cast<int>(field.size());
		this->sizeX = static_cast<int>(field.at(0).size());
		this->dist = dist;

		int number = 1;
		for (int y=0; y<this->sizeY; ++y) {
			for (int x=0; x<this->sizeX; ++x) {
				if (this->gField[y][x] == 'v') {
					if (isConnect(x,y,this->dist, number)) {
						++number;
					}
				}
			}
		}

		int ans = 1;
		for (int i=1; i<number; ++i) {
			ans = ans << 1;
			ans = ans%1000000007;
		}

		return ans-1;
	}
};