#include <bits/stdc++.h>

using namespace std;
int n,m;
int a[400001];
bool took[20];
int aa[30];
int sve[22];
long long mod=1e6+3;
long long res=0;
bool went[22];
void solve()
{
    stack<int> s;
    int last=1;
    if(aa[1]!=last) return;
    for(int i=1;i<=n;i++)
        sve[i]=0;
    for(int i=1;i<=2*n;i++)
    {
        if(sve[(aa[i]-1)%n+1]==0) sve[(aa[i]-1)%n+1]=aa[i];
        else
        {
            if(sve[(aa[i]-1)%n+1]>aa[i]) return;
        }
    }
    for(int i=1;i<=2*n;i++)
    {
        if(aa[i]<=n&&went[aa[i]-1]==false) return;
        if(aa[i]<=n&&went[aa[i]-1]==true)
        {
            went[aa[i]]=true;
            s.push(aa[i]);
            continue;
        }
        if(aa[i]>n&&s.top()!=(aa[i]-1)%n+1) return;
        if(aa[i]>n&&s.top()==(aa[i]-1)%n+1) s.pop();
    }
    for(int i=1;i<=n;i++)
        sve[i]=0;
    for(int i=1;i<=2*n;i++)
    {
        if(sve[(aa[i]-1)%n+1]==0) sve[(aa[i]-1)%n+1]=a[i];
        else
        {
            if(a[i]-sve[(aa[i]-1)%n+1]>m) return;
        }
    }
    res++;
}
void Try(int i)
{
    for(int j=1;j<=2*n;j++)
    {
        if(!took[j])
        {
            took[j]=true;
            aa[i]=j;
            if(i==2*n) solve();
            else Try(i+1);
            took[j]=false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("MINE.inp","r",stdin);
    freopen("MINE.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=2*n;i++)
        cin>>a[i];
    went[0]=true;
    if(n<=10)
    {
        Try(1);
        cout<<res/2;
    }
    return 0;
}
