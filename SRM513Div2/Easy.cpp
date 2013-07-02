#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include <sstream>
#include <set>
#include <cmath>

#define INF (1<<20)
#define MAX 101

using namespace std;

class TrainingCamp {
public:
	vector <string> determineSolvers(vector <string> attendance, vector <string> problemTopics)
	{
		vector<string> ans;
		for (int snum=0; snum<attendance.size(); ++snum) {
			string stu;
			for (int pnum=0; pnum<problemTopics.size(); ++pnum) {
				bool isSolve = true;
				for (int day=0; day<problemTopics[0].size(); ++day) {
					if (problemTopics[pnum][day]=='X' && attendance[snum][day]=='-') {
						isSolve = false;
						break;
					}
				}
				stu += isSolve?'X':'-';
			}
			ans.push_back(stu);
		}
		return ans;
	}
};