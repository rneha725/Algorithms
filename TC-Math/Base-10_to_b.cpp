//Number is given in decimal

#include<iostream>

using namespace std;

int convertToBase(int n, int b)
{
	int result = 0, multiplier = 1;
	while(n)
	{
		result = result + (n%b)*multiplier;
		multiplier = multiplier*10;
		n = n/b;
	}
	return result;
}


int main()
{
	int num, base;
	cin>>num>>base;
	cout<<convertToBase(num, base);
	return 0;
}

