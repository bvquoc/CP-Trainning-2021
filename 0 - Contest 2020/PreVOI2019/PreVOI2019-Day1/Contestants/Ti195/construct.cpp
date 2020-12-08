#include <bits/stdc++.h>
#define fo(i, a, b) for(int i=a;i<=b;i++)
#define rep(i, a, b) for(int i=a;i>=b;i--)
#define Reset(c) memset(c,0,sizeof(c))
#define ll long long
#define ii pair<int, int>
#define gt first
#define cs second
#define vi vector<int>
#define pb push_back
#define maxn 100001
#define inf 1000000001
#define name "construct"
#define INPUT  freopen(name".inp","r",stdin)
#define OUTPUT freopen(name".out","w",stdout)
#define el '\n'
//-------------------------------------------------------------------------------
using namespace std;

ii it[maxn];
int a[maxn], lazy[maxn], n, m;
void down(int id)
{
    int val=lazy[id], k=id*2;
    lazy[id]=0;
    lazy[k]+=val; it[k].gt+=val;
    lazy[k+1]+=val; it[k+1].gt+=val;
}
void update(int id, int l, int r, int u, int v,int val)
{
    if(l>v || r<u) return;
    if(u<=l && v>=r){
        if(l==r) {
                it[id].cs+=u;
                it[id].gt=val;
                lazy[id]+=val;
        } else {
            it[id].gt+=val;
            lazy[id]+=val;
        }
        return;
    }
    down(id);
    int mid=(l+r)/2, k=id*2;
    update(k, l, mid, u, v, val);
    update(k+1, mid+1, r, u, v, val);
    it[id]=min(it[k], it[k+1]);
}
ii get(int id, int l, int r, int u, int v)
{
    if(l>v || r<u) return {inf, inf};
    if(u<=l && v>=r)return it[id];
    down(id);
    int mid=(l+r)/2, k=id*2;
    return min(get(k, l, mid, u, v), get(k+1, mid+1, r, u, v));
}
int cal(int u, int v, int tg)
{

    if(u>v) return 0;
    if(u==v) return get(1, 1, n, u, v).gt-tg;
    ii tmp=get(1, 1, n, u, v);
    return cal(u, tmp.cs-1, tmp.gt)+cal(tmp.cs+1, v, tmp.gt)+ (tmp.gt-tg);
}
void xl1()
{
    int u, v;
    cin >> u >> v;
    cout << cal(u, v, 0) << endl;
}
void xl2()
{
    int u, v, c; cin >> u >> v >>c;
    update(1, 1, n, u, v, c);
}
//-------------------------------------------------------------------------------
int main()
{
    INPUT; OUTPUT;
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=1; i<=n; i++)
        {
            int x; cin >> x;
            update(1, 1, n, i, i, x);
        }
        for(int i=1; i<=m; i++){
            int k;cin >> k;
            if(k-1) xl1();
            else xl2();
        }
    }
}
