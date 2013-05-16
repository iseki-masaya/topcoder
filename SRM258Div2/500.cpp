#include <iostream>
#include <vector>
#include <string>

using namespace std;

class AutoLoan
{
public:
	double calcLoan(double price,double monthlyPayment,int loanTerm,double rate)
	{
		rate /= 100.0;
		for (int i=0; i<loanTerm; ++i) {
			price += price*rate;
			price -= monthlyPayment;
		}
		
		return price;
	}
	
	double interestRate(double price, double monthlyPayment, int loanTerm)
	{
		double left = 0,right = 100.0,mid = 0;
		while (1e-12 < (right - left)) {
			mid = (left + right)/2.0;
			
			double sub = calcLoan(price, monthlyPayment, loanTerm, mid);
			if (sub > 0) {
				right = mid;
			}
			else {
				left = mid;
			}
		}
		
		return mid*12;
	}
};