#include <vector>
#include <iostream>

using namespace std;

class FoxAndIntegers
{
public:
	vector <int> get(int AminusB, int BminusC, int AplusB, int BplusC)
	{
		vector<int> empty;
		if ((AminusB+AplusB)%2!=0 || (BminusC+BplusC)%2!=0)
			return empty;

		int A = (AminusB + AplusB)/2;
		int B = (BminusC + BplusC)/2;
		int C = BplusC - B;

		if (A-B!=AminusB || A+B!=AplusB || B-C!=BminusC || B+C!=BplusC)
			return empty;

		vector<int> ans;// = {A,B,C};
		ans.push_back(A);
		ans.push_back(B);
		ans.push_back(C);
		return ans;
	}
};