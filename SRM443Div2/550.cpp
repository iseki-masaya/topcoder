#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class CirclesCountry
{
public:
	struct Point
	{
		int x;
		int y;
	};
	
	bool isIn(int R,Point center,Point p)
	{
		int dist = (center.x - p.x)*(center.x - p.x) + (center.y - p.y)*(center.y - p.y);
		if (dist < R*R) {
			return true;
		}
		return false;
	}
	
	int calcBorders(const multimap<int, Point> &circle,Point src,Point dst)
	{
		vector<int> srcStack,dstStack;
		int index = 0;
		for (multimap<int, Point>::const_iterator it = circle.begin(),end = circle.end();
				 it != end;++it) {
			bool isSrcIn = isIn((*it).first, (*it).second, src);
			bool isDstIn = isIn((*it).first, (*it).second, dst);
			if (isSrcIn && isDstIn) {
				break;
			}
			else if(isSrcIn) {
				srcStack.push_back(index);
			}
			else if(isDstIn) {
				dstStack.push_back(index);
			}
			++index;
		}
		
		return static_cast<int>(srcStack.size()+dstStack.size());
	}
	
	int leastBorders(vector <int> X, vector <int> Y, vector <int> R, int x1, int y1, int x2, int y2)
	{
		Point src,dst;
		src.x = x1; src.y = y1;
		dst.x = x2; dst.y = y2;
		int size = static_cast<int>(X.size());
		multimap<int, Point> circle;
		for (int i=0; i<size; ++i) {
			Point p;
			p.x = X.at(i); p.y = Y.at(i);
			circle.insert(make_pair(R.at(i), p));
		}
		
		return calcBorders(circle, src, dst);
	}
};