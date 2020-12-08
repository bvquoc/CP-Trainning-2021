#define taskname "mine"
#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[2000+100];
int f[2000+100][4000+100];
int mod=1e6+3;

int dq(int i, int sum)
{
    if (sum<0) return 0;
    if (i==2*n+1)
    {
        if (sum==0) return 1;
        else return 0;
    }
    if (f[i][sum]!=-1) return f[i][sum];
    int t=0;
    int _sum;
    _sum=sum+1; t+=dq(i+1,_sum);
    _sum=sum-1; t+=dq(i+1,_sum);
    t=t%mod;
    f[i][sum]=t;
    return t;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(taskname".inp","r",stdin);
    freopen(taskname".out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=2*n; i++)
        cin>>a[i];
    memset(f,-1,sizeof(f));
    cout<<dq(1,0);
}
