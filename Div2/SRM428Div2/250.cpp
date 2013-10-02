#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ThePalindrome
{
public:
	bool isPalindrome(string s)
	{
		string::iterator it = s.begin();
		string::reverse_iterator rit = s.rbegin();

		for (int i=0; i<s.size(); ++i) {
			if (*it != *rit) {
				return false;
			}
			++ it; ++ rit;
		}
		return true;
	}
	
	void reversePush(string &pushedStr,string s,int pos)
	{
		string::reverse_iterator rit = s.rbegin();
		advance(rit, pos);
		for (; rit != s.rend() ; ++rit) {
			pushedStr.push_back(*rit);
		}
	}
	
	int find(string s)
	{
		string work;
		int size = (int)s.size();
		for (int i=0; i<size; ++i) {
			work = s;
			reversePush(work, s, size-i);
			if (isPalindrome(work)) {
				break;
			}
		}
		return (int)work.size();
	}
};