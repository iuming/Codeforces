#include<iostream>
#define ull unsigned long long
using namespace std;
int main()
{
	ull n,m,a;
	cin>>n>>m>>a;
	ull ans=((n/a)+(n%a>0))*((m/(a))+(m%a>0));
	cout<<ans;
	return 0;
 } 
