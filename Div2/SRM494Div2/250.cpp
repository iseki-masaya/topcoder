#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

class InterestingParty
{
public:
	int getCount(vector <string> first, vector <string> second,int pos)
	{
		int countFirst = 1;
		vector<string>::iterator firstInterest = first.begin();
		advance(firstInterest, pos);
		
		for (vector<string>::iterator firstIt = first.begin(), secondIt = second.begin(); firstIt != first.end(); ++firstIt,++secondIt) {
			if (firstInterest == firstIt)
				continue;
			if (*firstIt == *firstInterest || *secondIt == *firstInterest) {
				++countFirst;
			}
		}
		
		int countSecond = 1;
		vector<string>::iterator secondInterest = second.begin();
		advance(secondInterest, pos);
		
		for (vector<string>::iterator firstIt = first.begin(), secondIt = second.begin(); firstIt != first.end(); ++firstIt,++secondIt) {
			if (firstInterest == firstIt)
				continue;
			if (*firstIt == *secondInterest || *secondIt == *secondInterest) {
				++countSecond;
			}
		}
		
		int count;
		if (countFirst > countSecond) {
			count = countFirst;
		} else {
			count = countSecond;
		}
		
		return count;
	}
	
	int bestInvitation(vector <string> first, vector <string> second)
	{
		int max=0;
		int count;
		for (int i=0; i<first.size(); ++i) {
			count = getCount(first, second, i);
			if (max < count) {
				max = count;
			}
		}
		return max;
	}
};