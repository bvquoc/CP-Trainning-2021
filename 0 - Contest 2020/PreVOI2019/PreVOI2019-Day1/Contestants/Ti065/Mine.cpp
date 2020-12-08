#include <bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;
int n,m;
int a[N];
int b[N];
int dem=0;
void write()
{
    stack < int > s;
    for(int i=1; i<=n*2; i++)
    {
        if(b[i]==1)
            s.push(a[i]);
        else
        {
            if(s.empty())
                return;
            int u=s.top();
            s.pop();
            if(a[i]-u<=m)
                continue;
            else
                return;
        }
    }
    if(!s.empty())
        return;
    dem=dem+1;
}
void Try(int i)
{
    for(int j=0; j<=1; j++)
    {
        b[i]=j;
        if(i==2*n)
            write();
        else
            Try(i+1);
    }
}
void sub1()
{
    Try(1);
    cout<<dem;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("Mine.inp","r",stdin);
    freopen("Mine.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n*2; i++)
    {
        cin>>a[i];
    }
    sub1();
}
