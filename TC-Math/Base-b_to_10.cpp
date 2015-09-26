#include <iostream>

int convertInDec(int n, int b)
{
	int result = 0, multiplier = 1;
	while(n)
	{
		result = result + n%10*multiplier;
		multiplier = multiplier*b;
		n=n/10;
	}
	return result;
}

using namespace std;

int main()
{
	int num, base;
	cin>>num>>base;
	cout<<convertInDec(num, base);
}
