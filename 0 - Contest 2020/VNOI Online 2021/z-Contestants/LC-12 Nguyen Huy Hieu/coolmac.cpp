						///*******ZoHuyHieuZo*******///
#include<bits/stdc++.h>
#define F first
#define S second
#define int long long
#define pii pair<int,int>
#define Zo "coolmac"
#define MOD 1000000007
#define maxn 1000111
#define pb push_back
#define mp make_pair
#define mem(i,m) memset(i,m,sizeof(i))
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1) // kiem tra bit i
#define SET_ON(x, i) ((x) | MASK(i)) // bat bit thu i cua x
#define SET_OFF(x, i) ((x) & ~MASK(i)) // tat bit thu i cua x

using namespace std;
int cnt[maxn];
pii a[maxn];
int n,m,mx=-1,ans,mx_all;
bool cmp(pii a,pii b)
{
    if(a.S==b.S)
    {
        return a.F<b.F;
    }
    return a.S>b.S;
}
void nhap()
{
    mem(cnt,64);
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].F>>a[i].S;
        mx_all=max(a[i].S,mx_all);
    }
    if(mx_all!=1e5)
    {
        cout<<-1;
        return ;
    }
    sort(a+1,a+1+m,cmp);
    priority_queue<int,vector<int>,greater<int>> Q;
    for(int i=1;i<=m;i++)
    {
        if(Q.empty())
        {
            cnt[a[i].F]=1;
            Q.push(a[i].F);
            continue;
        }
        int u=Q.top();
        if(a[i].S<u)
            {
                mx=u-1;
                break ;
            }
        if(a[i].F>=u) continue;
        int last;
        while(!Q.empty())
        {
            last=u;
            u=Q.top();
            if(u<=a[i].S)
            {
                Q.pop();
            }
            else break;
        }
        Q.push(last);
        Q.push(a[i].F);
        cnt[a[i].F]=Q.size();
    }
    for(int i=1;i<=1e5;i++)
    {
        cnt[i]=min(cnt[i],cnt[i-1]);
    }
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x<=mx)
        {
            cout<<-1;
            return ;
        }
        else
        {
            ans=max(ans,cnt[x]);
        }
    }
    cout<<ans;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Zo".inp","r",stdin);
    freopen(Zo".out","w",stdout);
    nhap();
}
