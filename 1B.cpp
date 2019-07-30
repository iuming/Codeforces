#include<bits/stdc++.h>
using namespace std;
long ctn(string i)
{
	long o(0);
	const al(26);
	for(int k =0;k<i.size();++k)
		o=al*o+(i[k]-'A'+1);
	return o;
}
string cta(long i)
{
	const al(26);
	string o("");
	while(i>0)
	{
		char ch='Z';
		long m=i%al;
        if(m>0)ch='A'+m-1;
        else i-=al;
        i= i/al;
        o=ch+o;
	}
	return o;
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string line;
		cin>>line;
		bool b(0);
		if(line[0]=='R'&&('0'<=line[1]&&line[1]<='9')&&1<line.find('C') &&line.find('C')<line.size()-1)
			b=1;
		if(b)
		{
			int c=line.find('C');
			string r=line.substr(1,c-1);
			string co=line.substr(c+1);
			long col=atol(co.c_str());
			cout<<cta(col)<<r<<endl;
		}
		else
		{
			string r="";
			string c="";
			for(int k=0;k<line.size();++k)
			{
				if('0'<=line[k]&&line[k]<='9')
				{
					c=line.substr(k);
					break;
				}
				else r+=line[k];
			}
			cout<<"R"<<c<<"C"<<ctn(r)<<endl;
		}
	}
	return 0;
}
