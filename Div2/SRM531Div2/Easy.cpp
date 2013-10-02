#include <iostream>
#include <vector>

using namespace std;

class UnsortedSequence {
public:
  vector <int> getUnsorted(vector <int> s)
	{
		sort(s.begin(), s.end());
		int last = s.back();
		int n = static_cast<int>(s.size());
		for (int i = n-1;i>=0; --i) {
			if (s.at(i)!=last) {
				swap(s.at(i), s.at(i+1));
				return s;
			}
		}
		return vector<int>();
	}
};