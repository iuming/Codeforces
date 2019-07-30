#include<bits/stdc++.h>
using namespace std;
long long n,m,a;
void rot(double &a,double &b,double cs,double sn)
{
	double t;
	t=a*cs-b*sn;
	b=b*cs+a*sn;
	a=t;
}
int main()
{
	double x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	double ma,mb,p1,p2;
	do
	{	
		double f=rand()%311/100;
		double c=cos(f),s=sin(f);
		rot(x1,y1,c,s);
		rot(x2,y2,c,s);
		rot(x3,y3,c,s);
		if(y1==y2||y2==y3)continue;
		ma=-(x2-x1)/(y2-y1);
		mb=-(x3-x2)/(y3-y2);
		if(ma==mb)continue;
		p1 = (x1+x2)/2;
		p2 = (x3+x2)/2;
		double q1 = (y1+y2)/2, q2 = (y3+y2)/2;
		double xc = (-q1+q2 + p1*ma - p2*mb)/(ma-mb);
		double yc = ma*(xc-p1) + q1;
		double s1 = hypot(x1-x2,y1-y2);
		double s2 = hypot(x2-x3,y2-y3);
		double s3 = hypot(x3-x1,y3-y1);
		double r1 = hypot(x1-xc,y1-yc);
		double r2 = hypot(x2-xc,y2-yc);
		double r3 = hypot(x3-xc,y3-yc);
		double f1 = atan2(x1-xc,y1-yc);
		double f2 = atan2(x2-xc,y2-yc);
		double f3 = atan2(x3-xc,y3-yc);
		double q = 180/(acos(-1.0));
		for(int vv=3;vv<=100;vv++)
		{
			if(abs(sin( (f1-f3)*vv/2.0 ))>1e-4) continue;
			if(abs(sin( (f1-f2)*vv/2.0 ))>1e-4) continue;
			if(abs(sin( (f2-f3)*vv/2.0 ))>1e-4) continue;
			printf("%.8lf\n",vv * r1*r1 * 0.5 * sin(2*(acos(-1.0)) / vv));
			return 0;	
		}
	}while(1);
	return 1;
}
