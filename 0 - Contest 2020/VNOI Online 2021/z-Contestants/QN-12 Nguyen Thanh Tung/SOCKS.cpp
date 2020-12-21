#include <bits/stdc++.h>
#define fr(i,x,y) for(int i=x;i<=y;i++)
#define frd(i,x,y) for(int i=x;i>=y;i--)
#define ll long long
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second
#define maxn 300100
#define Bit(x,i) ((x>>i)&1)
#define Turnoff(t,k) (t^(1<<(k)))
using namespace std;
int n,q,cnt;
int check1,check2;
int c[maxn],d[maxn],ans = 1e9;
vector<int> e[maxn];
void inp()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("SOCKS.inp","r",stdin);
    freopen("SOCKS.out","w",stdout);
    cin>>n>>q;
    fr(i,1,n) cin>>c[i], cnt += c[i];
    fr(i,1,n-1)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    fr(i,1,n)
    {
        if (e[i].size() == 1) check1++;
        else
            if (e[i].size() == 2) check2++;
    }
}
void sub1()
{
    if (cnt > 1) cout<<"1\n";
    else cout<<"0\n";
    fr(i,1,q)
    {
        int id;
        cin>>id;
        if (c[id] == 0) c[id] = 1, cnt++;
        else c[id] = 0, cnt--;
        if (cnt > 1) cout<<"1\n";
        else cout<<"0\n";
    }
}
void dfs(int u,int parent)
{
    d[u] = 0;
    for (int v : e[u])
        if (v != parent)
        {
            dfs(v,u);
            d[u] += max(d[v],c[v]);
        }
}
void sub2()
{
    fr(i,1,n) dfs(i,i), ans = min(ans,d[i]);
    cout<<ans<<"\n";
    fr(t,1,q)
    {
        ans = 1e9;
        int id;
        cin>>id;
        c[id] = c[id] == 0 ? 1 : 0;
        fr(i,1,n) dfs(i,i), ans = min(ans,(d[i]+c[i]+1)/2);
        cout<<ans<<"\n";
    }
}
int main()
{
    inp();
    if (check1 == 2 && check2 == n-2) sub1();
    else
        sub2();
    return 0;
}
