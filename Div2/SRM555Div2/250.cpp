#include <iostream>
#include <vector>
#include <string>

using namespace std;

class XorBoardDivTwo
{
public:
	int countOne(const vector <string> &board)
	{
		int sizeY = (int)board.size();
		int sizeX = (int)board.at(0).size();
		int cnt = 0;
		for (int y=0; y<sizeY; ++y) {
			for (int x=0; x<sizeX; ++x) {
				if(board[y][x] == '1')
					++cnt;
			}
		}
		return cnt;
	}
	
	void flipBoard(int x,int y,vector <string> &board)
	{
		int sizeY = (int)board.size();
		int sizeX = (int)board.at(0).size();
		//flip y
		for (int cy = 0; cy<sizeY; ++cy) {
			if(board[cy][x] == '1')
				board[cy][x] = '0';
			else
				board[cy][x] = '1';
		}
		//flip x
		for (int cx = 0; cx<sizeX; ++cx) {
			if(board[y][cx] == '1')
				board[y][cx] = '0';
			else
				board[y][cx] = '1';
		}
	}
	
	int theMax(vector <string> board)
	{
		int sizeY = (int)board.size();
		int sizeX = (int)board.at(0).size();
		int max = 0;
		int work;
		vector <string> tmp;
		
		for (int y=0; y<sizeY; ++y) {
			for (int x=0; x<sizeX; ++x) {
				tmp = board;
				flipBoard(x, y, tmp);
				work = countOne(tmp);
				if(max < work)
					max = work;
			}
		}
		
		return max;
	}
};