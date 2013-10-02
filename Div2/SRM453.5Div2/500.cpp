#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int map[51][51];
int sizeX,sizeY;
vector<string> globalMaze;
vector<int> vx,vy;

class MazeMaker
{
public:
	struct Point
	{
		int x;
		int y;
		int depth;
	};
//	void makeMap(int x,int y,int depth)
//	{
//		//終了条件
//		if(x < 0 || sizeX <= x)
//			return;
//		if(y < 0 || sizeY <= y)
//			return;
//		if(globalMaze[y][x] == 'X')
//			return;
//		if(map[y][x] < depth  && map[y][x] != 0)
//			return;
//		
//		map[y][x] = depth;
//		for (int i=0; i<vx.size(); ++i) {
//			makeMap(x + vx[i], y + vy[i],depth + 1);
//		}
//	}

	void makeMap(int x,int y)
	{
		queue<Point> pointQueue;
		Point p;
		int depth;
		p.x = x; p.y = y; p.depth = 1;
		map[p.y][p.x] = 1;
		pointQueue.push(p);
		
		int xx,yy;
		while(!pointQueue.empty())
		{
			p = pointQueue.front();
			pointQueue.pop();
			
			depth = p.depth;
			xx = p.x; yy = p.y;
			for (int i=0; i<vx.size(); ++i) {
				p.x = xx + vx[i]; p.y = yy + vy[i];
				p.depth = depth+1;
				
				if(p.x < 0 || sizeX <= p.x)
					continue;
				if(p.y < 0 || sizeY <= p.y)
					continue;
				if(globalMaze[p.y][p.x] == 'X')
					continue;
				if(map[p.y][p.x] != 0)
					continue;
				
				map[p.y][p.x] = p.depth;
				pointQueue.push(p);
			}
		}
	}
	
	void setTree()
	{
		for (int y=0; y<sizeY; ++y) {
			for (int x=0; x<sizeX; ++x) {
				if(globalMaze[y][x] == 'X')
					map[y][x] = -2;
			}
		}
	}
	
	int getPath()
	{
		int max = 0;
		for (int y = 0; y < sizeY; ++y) {
			for (int x = 0; x < sizeX; ++x) {
				if(max < map[y][x] && map[y][x] > 0)
					max = map[y][x];
				if(map[y][x] == 0)
					return -1;
			}
		}
		return max - 1;
	}
	
	int longestPath(vector <string> maze, int startRow, int startCol, vector <int> moveRow, vector <int> moveCol)
	{
		globalMaze = maze;
		sizeY = (int)maze.size();
		sizeX = (int)maze.at(0).size();
		vx = moveCol;
		vy = moveRow;
		setTree();
		
		makeMap(startCol, startRow);
		int path = getPath();
		return path;
	}
};