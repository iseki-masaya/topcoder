#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class BatchSystem
{
public:
	vector<int> schedule(vector <int> duration, vector <string> user)
	{
		int size = static_cast<int>(duration.size());
		map<string,long long> eachSum;
		for(int i=0;i<size;++i) eachSum[user[i]] += duration[i];
		
		vector<int> ans;
		vector<bool> done(size);
		while(ans.size() < size) {
			string next;
			for (int i=0; i<size; ++i) {
				if(!done[i] && (next.empty() || eachSum[user[i]] < eachSum[next])) {
					next = user[i];
				}
			}
			
			for (int i=0; i<size; ++i) {
				if(user[i] == next) {
					done[i] = true;
					ans.push_back(i);
				}
			}
		}
		return ans;
	}
};
