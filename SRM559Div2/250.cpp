#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BlockTower
{
public:
	
	int getSum(vector<int> &tower)
	{
		int sum=0;
		for (int i=0; i<tower.size(); ++i) {
			sum += tower.at(i);
		}
		return sum;
	}
	
	int getTallest(vector <int> blockHeights)
	{
		int max = 0,sum;
		int point = 0,cnt = 0;
		bool isContinue = true;
		vector<int> tower;
		vector<int>::iterator start = blockHeights.begin(),end = blockHeights.end(),oddStart;
		
		while(isContinue){
			isContinue = false;
			oddStart = end;
			// push even
			for (vector<int>::iterator it = start; it != end; ++it)	{
				if((*it)%2 != 0) {
					if(point == cnt) {
						isContinue = true;
						oddStart = it;
						break;
					}
					++cnt;
				}
				else {
					tower.push_back(*it);
				}
			}
			// push odd
			for (vector<int>::iterator it = oddStart; it != end; ++it)	{
				if((*it)%2 != 0) {
					tower.push_back(*it);
				}
			}
			
			++point; cnt = 0;
			sum = getSum(tower);
			tower.clear();
			if(max < sum){
				max = sum;
			}
		}
		return max;
	}
};