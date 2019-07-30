#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ls rt<<1
#define rs ls1
#define lson l,mid,ls
#define rson mid+1,r,rs
#define middle (l+r)>>1
#define eps (1e-9)
#define p2(a) ((a)*(a))
#define clr_all(x,c) memset(x,c,sizeof(x))
#define clr(x,c,n) memset(x,c,sizeof(x[0])*(n+1))
#define MOD 1000000007
#define inf 100000007
#define pi acos(-1.0)
#define M 200000+5
struct point
{
	double x,y;
}p[5];
double r[5],t[5],s,temp;
double check(double dx,double dy)
{
	double ret=0;
	int i;
	for(i=0;i<3;i++)
		t[i]=sqrt(p2(dx-p[i].x)+p2(dy-p[i].y))/r[i];
	for(i=0;i<3;i++)
		ret+=p2(t[i]-t[(i+1)%3]);
	return ret;
}
int main()
{
    int i,j,f;p[4].x=0;p[4].y=0;
    for(i=0;i<3;i++)
	{
		cin>>p[i].x>>p[i].y>>r[i];
		p[4].x+=p[i].x/3; 
		p[4].y+=p[i].y/3;
	}
	for(s=1;s>1e-6;f=0)
	{
		temp=check(p[4].x,p[4].y);
		if(temp>check(p[4].x+s,p[4].y))
			p[4].x+=s,f=1;
		else if(temp>check(p[4].x-s,p[4].y))
			p[4].x-=s,f=1;
		else if(temp>check(p[4].x,p[4].y+s))
			p[4].y+=s,f=1;
		else if(temp>check(p[4].x,p[4].y-s))
			p[4].y-=s,f=1;
		if(!f)s*=0.7;
	}
	if(check(p[4].x,p[4].y)<1e-5)
		cout<<fixed<<setprecision(5)<<p[4].x<<' '<<p[4].y<<endl;
    return 0;
}
