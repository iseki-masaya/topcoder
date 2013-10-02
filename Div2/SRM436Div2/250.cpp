#include <iostream>
#include <vector>
#include <string>

using namespace std;

class FriendScore
{
public:
	void countFriends(vector <string> friends,int pos,vector<int> &passed,int depth)
	{
		passed[pos] = 1;
		if(depth == 2)
			return;
		
		for (int i=0;i<friends.at(pos).size();++i) {
			if (friends.at(pos).at(i) == 'Y') {
				countFriends(friends, i, passed, depth+1);
			}
		}
		return;
	}
	
	void clearPassed(vector<int> &vec)
	{
		for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
			*it = 0;
		}
	}
	
	int highestScore(vector <string> friends)
	{
		int max=0;
		int cnt=0;
		int size = (int)friends.size();
		vector<int> passed(size);
		for (int i=0;i<size;++i){
			countFriends(friends,i,passed,0);
			for (vector<int>::iterator it = passed.begin(); it != passed.end(); ++it) {
				if (*it == 1) {
					++cnt;
				}
			}
			if (max < cnt) {
				max = cnt;
			}
			cnt = 0;
			clearPassed(passed);
		}
		return max - 1;
	}
};