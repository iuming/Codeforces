#include<bits/stdc++.h>
using namespace std;
int main()
{
	map<string,int>a,b;
	string s[1002];
	int x[1002];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i]>>x[i];
		a[s[i]]+=x[i];
	}
	int maxn=0;
	for(int i =0;i<n;i++)
		if(a[s[i+1]]>maxn)	maxn=a[s[i]];
	for(int i=0;i<n;i++)
	{
		b[s[i]]+=x[i];
		if((b[s[i]]>=maxn)&&(a[s[i]]>=maxn)){cout<<s[i];break;}
	}
	return 0;
}
