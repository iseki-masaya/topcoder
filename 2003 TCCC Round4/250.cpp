#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define SIZE 16
int dx[] = {-2,-2,-1,-1,-1,-1,-1, 0, 0, 1, 1, 1, 1, 1, 2, 2};
int dy[] = {1 ,-1, 2, 1, 0,-1,-2, 1,-1, 2, 1, 0,-1,-2, 1,-1};
long long int ways[101][101][51] = {0};

class ChessMetric
{
public:
	
	long long howMany(int size, vector <int> start, vector <int> end, int numMoves)
	{
		int sx = start.at(0), sy = start.at(1);
		int ex = end.at(0), ey = end.at(1);
		
		ways[sy][sx][0] = 1;
		
		for (int i=1; i<=numMoves; ++i) {
			for (int y=0; y<size; ++y) {
				for (int x=0; x<size; ++x) {
					for (int j=0; j<SIZE; ++j) {
						int nx = x + dx[j];
						int ny = y + dy[j];
						if(nx < 0 || nx > size || ny < 0 || ny > size)
							continue;
						ways[ny][nx][i] += ways[y][x][i-1];
					}
				}
			}
		}
		
		return ways[ey][ex][numMoves];
	}
};