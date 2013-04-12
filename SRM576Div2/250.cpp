#include <vector>

using namespace std;

class TheExperimentDiv2
{
public:
	vector <int> determineHumidity(vector <int> intensity, int L, vector <int> leftEnd)
	{
		vector<int>drop(leftEnd.size());
		for (int i=0; i<leftEnd.size(); ++i) {
			drop[i] = 0;
			for (int j=leftEnd.at(i); j<leftEnd.at(i)+L; ++j) {
				drop[i] += intensity[j];
				intensity[j] = 0;
			}
		}
		return drop;
	}
};