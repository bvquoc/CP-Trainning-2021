#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
#define MASK(i) (1LL << (i))
#define BIT(x,i) (((x)>>(i)) & 1)
#define SET_ON(x,i) ((x) | MASK(i))
#define SET_OFF(x,i) ((x) & ~(MASK(i)))
using namespace std;
const int MAXN=5*1e5+1;
int n,m,k;
string s;
int a[MAXN],sum[MAXN];
pii pi[MAXN];
pii res[MAXN];
int cnt[MAXN];
void Get()
{
    int ans=0,tmp=0,l=1,r=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1)
        {
            tmp++;
            r++;
            ans=max(ans,tmp);
            cnt[ans]++;
            if(cnt[ans]==1)
            {
                res[ans]={l,r-1};
            }
        }
        else
        {
            l=i+1;
            r=i+1;
            tmp=0;
        }
    }
    cout<<ans<<endl;
    cout<<res[ans].fi<<" "<<res[ans].se<<endl;
}
void sub1()
{
    Get();
}
void sub2()
{
    int temp=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
        {
            temp++;
        }
    }
    if(temp<=k)
    {
        cout<<1<<" "<<n;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DECOR.INP" , "r" , stdin);
    freopen("DECOR.OUT" , "w" , stdout);
    cin>>n>>m>>k>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1')
        {
            a[i+1]=1;
        }
    }
    if(m==0 && k==0)
    {
        sub1();
        return 0;
    }
    if(m==0)
    {
        sub2();
        return 0;
    }
    cout<<-1;
    return 0;
}
