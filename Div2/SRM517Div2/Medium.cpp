#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <sstream>
#include <stack>
#include <fstream>
#include <istream>

using namespace std;

class CompositeSmash {
public:
	map<int, int>
	primeDecomposition(int n)
	{
		map<int , int> res;
		for (int i=2; i<=n; ++i) {
			while (n%i == 0) {
				++res[i];
				n /= i;
			}
		}
		return res;
	}

	bool isPrime(int n)
	{
		for (int i=2; i*i<=n; ++i) {
			if (n % i == 0) {
				return false;
			}
		}
		return n != 1;
	}

	string thePossible(int N, int target)
	{
		if (N < target) {
			return "No";
		}
		if (N%target != 0) {
			return "No";
		}
		if (N == target) {
			return "Yes";
		}

		if (isPrime(target)) {
			return "Yes";
		}

		map<int , int> pd = primeDecomposition(N);
		if (pd.size() == 1 && target == (pd.begin())->first*(pd.begin())->first) {
			return "Yes";
		}

		return "No";
	}
};