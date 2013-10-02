#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class ValueHistogram
{
public:
	int getMax(map<int, int> list)
	{
		int max = 0;
		for (int i=0; i<10; ++i) {
			if(max < list[i]){
				max = list[i];
			}
		}
		return max;
	}
	
	vector <string> build(vector <int> values)
	{
		map<int,int> list;
		for (int i=0; i<10; ++i) {
			list[i] = 0;
		}
		for (vector<int>::iterator it = values.begin(); it != values.end(); ++it) {
			list[*it]++;
		}
		
		int max = getMax(list);
		vector<string> ret(max+1);
		string tmp ="..........";
		for (vector<string>::iterator it = ret.begin(); it != ret.end(); ++it) {
			*it = tmp;
		}
		int size = (int)ret.size() - 1;
		for (int i=0; i<10; ++i) {
			for (int j=0; j<list[i]; ++j) {
				ret[size-j][i] = 'X';
			}
		}
		return ret;
	}
};