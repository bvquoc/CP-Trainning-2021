#include <bits/stdc++.h>
#define fr(i,x,y) for(int i=x;i<=y;i++)
#define frd(i,x,y) for(int i=x;i>=y;i--)
#define ll long long
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second
#define maxn 500100
#define Bit(x,i) ((x>>i)&1)
#define Turnoff(t,k) (t^(1<<(k)))
using namespace std;
int n,m,k;
int s[maxn],kitu[maxn];
int a[maxn],b[maxn];
int ans = 0, L = -1 , R = -1;
bool used[maxn];
vector<int> e[maxn];
queue<int> q;
void inp()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DECOR.inp","r",stdin);
    freopen("DECOR.out","w",stdout);
    cin>>n>>m>>k;
    fr(i,1,n)
    {
        char w;
        cin>>w;
        kitu[i] = w - '0';
        s[i] = s[i-1] + (w - '0');
    }
    fr(i,1,m) cin>>a[i]>>b[i];
}
void sub12()
{
    fr(i,1,n)
    {
        int l = i, r = n;
        while (l < r)
        {
            int c = (l + r + 1) / 2;
            if (s[c] - s[i-1] + k >= c - i + 1) l = c;
            else r = c - 1;
        }
        if (s[l] - s[i-1] + k >= l - i + 1 && l - i + 1 > ans)
        {
            ans = l - i + 1;
            L = i; R = l;
        }
    }
    if (ans == 0) cout<<"-1";
    else cout<<L<<" "<<R;
}
void dfs(int u)
{
    used[u] = true;
    if (kitu[u] == 0) q.push(u);
    for (int v : e[u])
        if (!used[v] && v > u)
        {
            if (!q.empty() && kitu[v] == 1) swap(kitu[v],kitu[q.front()]), q.pop();
            dfs(v);
        }
}
void tham()
{
    fr(i,1,m) e[a[i]].push_back(b[i]), e[b[i]].push_back(a[i]);
    fr(i,1,n) sort(e[i].begin(),e[i].end());
    fr(i,1,n) if (!used[i]) dfs(i);
    fr(i,1,n) s[i] = s[i-1] + kitu[i];
    sub12();
}
int main()
{
    inp();
    if (m == 0) sub12();
    else tham();
    return 0;
}
