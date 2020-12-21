#include<bits/stdc++.h>
using namespace std;
int n,m,k,sl[100005];
int a[100005],b[100005];
string s;
void solve1()
{
    int res=0;
    s=" "+s;
    if(s[1]=='1')
    sl[1]=1;
    else
        s[1]=0;
    for(int i=2;i<=n;i++)
    {
        if(s[i]=='1')
        {
            sl[i]=sl[i-1]+1;
        }
        else
            sl[i]=1;
        res=max(res,sl[i]);
    }
    cout<<res;
}
void solve2()
{
    int res=0;
    s=" "+s;
    int gt=k;
     if(s[1]=='0') gt--;
        s[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(s[i]=='1')
            sl[i]=sl[i-1]+1;
        if(s[i]=='0'&&gt>0)
        {
            gt--;
            sl[i]=sl[i-1]+1;
        }
        if(s[i]=='0'&&gt==0)
        {
            gt=k;
            sl[i]=1;
        }
        res=max(res,sl[i]);
    }
    cout<<res;
}
int main()
{
   freopen("decor.inp","r",stdin);
  freopen("decor.out","w",stdout);
    cin>>n>>m>>k;
    cin>>s;
    for(int i=1;i<=m;i++)
        cin>>a[i]>>b[i];
    if(m==0&&k==0)
        solve1();
    else
        if(m==0) solve2();
}
