#include <iostream>
#include <vector>
#include <string>

using namespace std;

class NinjaTurtles
{
		
public:
	int countPizza(int K,int N)
	{
		return (N/K)*3+(N/3);
	}
	
	bool isFill(int P,int K,int N)
	{
		if(countPizza(K, N) < P){
			return false;
		}
		return true;
	}
	
	bool isFit(int P,int K,int N)
	{
		if(countPizza(K, N) == P){
			return true;
		}
		return false;
	}
	
  int countOpponents(int P, int K)
	{
		int large = 3000000;
		int small = 0;

		int mid;
		while (small < large) {
			mid = (small+large)/2;
			if (isFill(P, K, mid)) {
				large = mid;
			}
			else {
				small = mid + 1;
			}
		}
		mid = (small+large)/2;
		if (!isFit(P, K, mid)) {
			return -1;
		}
		
		return mid;
	}
};