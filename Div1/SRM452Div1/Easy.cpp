#include <iostream>
#include <vector>
#include <string>


using namespace std;

bool map[1001][1001] = {false};
int dx[4] = {0,0,2,-2};
int dy[4] = {2,-2,0,0};

class NotTwo
{
public:
	int width,height;
	int sizeX,sizeY;

	bool checkPut(int x,int y)
	{
		int cx,cy;
		for (int i=0; i<4; ++i) {
			cx = x + dx[i];
			cy = y + dy[i];
			if (0 <= cx && cx < this->width && 0 <= cy && cy < this->height) {
				if (map[cy][cx]) {
					return false;
				}
			}
		}
		map[y][x] = true;
		return true;
	}

	int maxStones(int width, int height)
	{
		this->width = width;
		this->height = height;
		int x,y;
		int cnt = 0;
		for (y=0 ; y < this->height; ++y) {
			for (x=0; x < this->width; ++x) {
				if (checkPut(x, y)) {
					++cnt;
				}
			}
		}
		return cnt;
	}
};