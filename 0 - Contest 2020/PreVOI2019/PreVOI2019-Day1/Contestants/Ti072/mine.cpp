#include <bits/stdc++.h>

using namespace std;
const int mod=1e6+3;
const int MAXN=2e5+7;
int t[21];
int a[2*MAXN];
int n,m;
void Input()
{
    cin>>n>>m;
    for(int i=1; i<=2*n; i++)
        cin>>a[i];
}
int ans=0;
int dd[11];
stack <int> tmp;
void sub1(int i,int cnt)
{
    if(i==2*n+1)
    {
        while(!tmp.empty())
            tmp.pop();
        memset(dd,0,sizeof(dd));
        for(int j=1; j<=2*n; j++)
            if(!dd[t[j]])
                tmp.push(t[j]),dd[t[j]]++;
            else
            {
                if(tmp.top()==t[j])
                    tmp.pop();
                else
                    return ;
            }
        ans++;
        if(ans>=mod)
            ans-=mod;
    }
    else
    {
        if(t[i])
            sub1(i+1,cnt);
        else
        {
            t[i]=cnt;
            for(int j=i+1; j<=2*n; j++)
                if(t[j]==0&&(a[j]-a[i])<=m)
                {
                    t[j]=cnt;
                    sub1(i+1,cnt+1);
                    t[j]=0;
                }
        }
        t[i]=0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("mine.inp","r",stdin);
    freopen("mine.out","w",stdout);
    Input();
    if(n<=10)
    {
        sub1(1,1);
        cout<<ans%mod;
    }
    return 0;
}
