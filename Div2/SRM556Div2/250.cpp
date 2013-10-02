#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <set>

using namespace std;

class ChocolateBar
{
public:
	bool check(string letters)
	{
		set<char> word;
		char work;
		for (int i=0; i<letters.size(); ++i) {
			work = letters.at(i);
			if (word.find(work) != word.end()){
				return false;
			}
			word.insert(work);
		}
		return true;
	}
	int maxLength(string letters)
	{
		string tmp;
		int size = (int)letters.size();
		for (int i=0; i<size; ++i) {
			for (int j=0; j<=i;++j){
				tmp = letters.substr(j,size);
				tmp.erase(tmp.size()-(i-j));
				if(check(tmp)){
					return size - i;
				}
			}
		}
		return 1;
	}
};