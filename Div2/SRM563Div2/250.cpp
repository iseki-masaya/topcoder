#include <iostream>
#include <vector>
#include <string>

using namespace std;

class FoxAndHandleEasy
{
public:
	string isPossible(string S, string T)
	{
		string work = S;
		for (int i=0; i<S.size(); ++i) {
			work.insert(i, S);
			if (work == T) {
				return "Yes";
			}
			work = S;
		}
		return "No";
	}
};