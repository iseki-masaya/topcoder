#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <cstdio>

using namespace std;

#define MAX 3001

vector<int> prime(MAX);

class MagicStonesStore {
	void makePrime()
	{
		bool isPrime = false;
		int cnt = 0;
		for (int n=2; n<MAX; ++n) {
			if (n==2) {
				prime[cnt] = n;
				++cnt;
			}

			if (n%2==0)
				continue;

			isPrime = true;
			for (int i=2; i*i <= n; ++i) {
				if (n%i==0) {
					isPrime = false;
					break;
				}
			}
			if (isPrime) {
				prime[cnt] = n;
				++cnt;
			}
		}
	}

public:
  string ableToDivide(int n)
	{
		makePrime();
		n = 2*n;

		for (int i=0; i<MAX; ++i) {
			int s = n - prime[i];
			if (s <= 1) {
				break;
			}

			if (find(prime.begin(),prime.end(),s) != prime.end())
				return "YES";
		}

		return "NO";
	}
};