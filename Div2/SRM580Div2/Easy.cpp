#include <vector>
#include <iostream>
#include <memory>

using namespace std;

class ShoutterDiv2 {
public:
	int count(vector <int> s, vector <int> t)
	{
		int cnt = 0;
		int size = static_cast<int>(s.size());
		for (int i=0; i<size; ++i)
			for (int j=i+1; j<size; ++j)
				if (t[i]<s[j] || t[j]<s[i]);
				else ++cnt;

		return cnt;
	}
};