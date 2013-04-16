#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TheJediTestDiv2
{
public:
	int getCount(vector<int> students, int Y, int J,int pos)
	{
		int count = 0;
		students[pos] -= Y;
		for (vector<int>::iterator it = students.begin(); it != students.end(); ++it) {
			while (*it>0) {
				++count;
				*it -= J;
			}
		}
		return count;
	}
	
	int countSupervisors(vector<int> students, int Y, int J)
	{
		int minCount=1000000;
		int count;
		for (int i=0; i<students.size(); ++i) {
			count = getCount(students, Y, J, i);
			if (minCount > count) {
				minCount = count;
			}
		}
		
		return minCount;
	}
};