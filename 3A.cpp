#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s(""),d("");
    cin>>s>>d;
    int h,v; 
	char hL,vL;
    if(s[0]<d[0])
	{
		h=d[0]-s[0];
		hL='R';
	}
    else
	{
		h=s[0]-d[0]; 
		hL='L';
	} 
    if(s[1]<d[1])
	{
		v=d[1]-s[1]; 
		vL='U';
	}
    else
	{
		v=s[1]-d[1];
		vL='D';
	}
    int num=max(h,v);
	cout<<num<<endl;
    while(num--)
	{
        if(--h >= 0)cout<<hL;
        if(--v >= 0)cout<<vL;
        cout<<endl;
    }
    return 0;
}
