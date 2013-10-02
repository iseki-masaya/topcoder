#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class EllysTSP
{
public:
	int getMax(string places)
	{
		map<char, int> procudure;
		for (string::const_iterator it=places.begin(),end=places.end(); it!=end; ++it) {
			procudure[*it]++;
		}
		if (procudure['C']>procudure['V']) {
			return procudure['V']*2+1;
		}
		else if (procudure['C']<procudure['V']) {
			return procudure['C']*2+1;
		}
		else {
			return procudure['C']*2;
		}
	}
};