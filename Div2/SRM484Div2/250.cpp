#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

int card[4][8] = {
	{1,2,3,4,5,6,7,8},
	{1,2,3,4,9,10,11,12},
	{1,2,5,6,9,10,13,14},
	{1,3,5,7,9,11,13,15}
};

class NumberMagicEasy
{
public:
	bool isNotCorrectCardNum(char answer,int cardNum,int num)
	{
		if(answer == 'N'){
			for (int i=0; i<8; ++i) {
				if(card[cardNum][i] == num)
					return true;
			}
			return false;
		} else {
			for (int i=0; i<8; ++i) {
				if(card[cardNum][i] == num)
					return false;
			}
			return true;
		}
	}
	
	bool checkCard(const string answer,int num)
	{
		for (int i=0; i<4; ++i) {
			if(isNotCorrectCardNum(answer[i], i, num)){
				return false;
			}
		}
		return true;
	}
	
	int theNumber(string answer)
	{
		for (int num=1; num<16; ++num) {
			if(checkCard(answer, num)){
				return num;
			}
		}
		return 16;
	}
};