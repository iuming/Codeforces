#include <bits/stdc++.h>
#define MAXN 1001
#define INF 1<<30
using namespace std;
char pa[MAXN][MAXN][2];
int ma[1001][1001][2];
int po=0;
void PP(int x,int y,int l)
{
    if(x==1&&y==1)return;
    if(pa[x][y][l])
    {
        PP(x-1,y,l);
        cout<<'D';
    }
    else
    {
        PP(x,y-1,l);
        cout<<'R';
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
        ma[0][i][0]=ma[0][i][1]=ma[i][0][0]=ma[i][0][1]=INF;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int k;
            cin>>k;
            if(k==0)
                po=i;
            else
            {
                while(k%2==0)
                {
                    ma[i][j][0]++;
                    k/=2;
                }
                while(k%5==0)
                {
                    ma[i][j][1]++;
                    k/=5;
                }
            }
            for(int k=0;k<2;k++)
            {
                pa[i][j][k]=ma[i-1][j][k]<ma[i][j-1][k]?1:0; 
                ma[i][j][k]+=min(ma[i-1][j][k],ma[i][j-1][k]);
            }
        }
    }
    int l=ma[n][n][0]<ma[n][n][1]?0:1; 
    if(po&&ma[n][n][l]>1)
    {
        cout<<1<<endl;
        for(int i=2;i<=po;i++)cout<<'D';
        for(int i=2;i<=n;i++)cout<<'R';
        for(int i=po+1;i<=n;i++)cout<<'D';
    }
    else
    {
        cout<<ma[n][n][l]<<endl;
        PP(n,n,l);
    }
    return 0;
}
