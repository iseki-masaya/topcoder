#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

class FauxPalindromes
{
public:
	bool isPalindrome(const string &word){
		int size = (int)word.size();
		for (int i=0,j=size-1; i<size; ++i,--j) {
			if (word[i] != word[j])
				return false;
		}
		return true;
	}
	
	string classifyIt(string word)
	{
		if (isPalindrome(word)) {
			return "PALINDROME";
		}
		
		//concat
		string concatWord = "";
	  char prev = ' ';
		for (int i=0; i<word.size(); ++i) {
			if(prev == word[i])
				continue;
			concatWord.push_back(word[i]);
			prev = word[i];
		}
		
		if (isPalindrome(concatWord)) {
			return "FAUX";
		}

		return "NOT EVEN FAUX";
	}
};