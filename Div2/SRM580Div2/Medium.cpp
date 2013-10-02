#include <vector>
#include <iostream>
#include <memory>

using namespace std;

class EelAndRabbit {
public:
	int getmax(vector <int> l, vector <int> t)
	{
		int size = static_cast<int>(l.size());

		int cnt = 0,mx = 0;
		for (int i=0; i<size; ++i) {
			for (int j=0; j<size; ++j) {
				cnt = 0;
				for (int k=0; k<size; ++k)
					if ((t[k]<=t[i] && t[i]<=t[k]+l[k]) || (t[k]<=t[j] && t[j]<=t[k]+l[k]))
						++cnt;

				mx = max(mx,cnt);
			}
		}

		return mx;
	}
};