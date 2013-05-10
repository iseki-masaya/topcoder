#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TypingDistance
{
public:
	vector<int> convertDist(string keybord, string word)
	{
		vector<int> dist;
		for(int wCur=0;wCur<word.size();++wCur) {
			for (int kCur=0; kCur<keybord.size(); ++kCur) {
				if(word.at(wCur) == keybord.at(kCur)){
					dist.push_back(kCur);
					break;
				}
			}
		}
		
		return dist;
	}
	
	int getSum(vector<int> &dist)
	{
		int sum=0;
		int previous = dist.at(0);
		for (int i=1;i<dist.size();++i) {
			sum += abs(previous - dist.at(i));
			previous = dist.at(i);
		}
		return sum;
	}
	
	int minDistance(string keyboard, string word)
	{
		vector<int> dist(convertDist(keyboard, word));
		int sum = getSum(dist);
		return sum;
	}
};