#include <vector>
#include <string>
#include <map>

using namespace std;

class RabbitVoting
{
public:
	string getWinner(vector <string> names, vector <string> votes)
	{
		string winner;
		map<string, int> list;
		for (vector<string>::iterator it = names.begin(); it != names.end(); ++it) {
			list[*it] = 0;
		}
		for (vector<string>::iterator votesIt = votes.begin(),namesIt = names.begin(); votesIt != votes.end(); ++votesIt,++namesIt) {
			if (*votesIt != *namesIt) {
				++list[*votesIt];
			}
		}
		int max = 0;
		for (map<string, int>::iterator it = list.begin(); it != list.end(); ++it) {
			if(max < (*it).second){
				max = (*it).second;
				winner = (*it).first;
			}
			else if(max == (*it).second){
				winner = "";
			}
		}
		return winner;
	}
};