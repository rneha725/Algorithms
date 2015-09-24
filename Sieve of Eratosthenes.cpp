#include <iostream>
#include <cmath>

using namespace std;

bool isprime(int n)
{
	if(n==2) return 1;
	else if(n%2 == 0) return 0;
	else
	{
		for(int i = 3; i<=sqrt(n); i = i+2)
		{
			if(n%i == 0) return 0;
		}
	}
	return 1;
}

int main()
{
	int n;
	cin>>n; //Enter the upper limit
	cout<<endl;
	int prime[n+1];
	prime[0] = prime[1] = 0;
	prime[2] = 1;
	for(int i = 2; i<n+1; i++)
	{
		if(isprime(i))
		{
			for(int k = 2; k*i<n+1;k++)
			prime[k*i] = 0;
		}
	}
	//output
	for(int i = 0;i<n+1;i++)
	if(prime[i]) cout<<i<<endl;
	return 0;
}
