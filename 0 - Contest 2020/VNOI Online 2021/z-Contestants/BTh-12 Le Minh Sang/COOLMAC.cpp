#include <bits/stdc++.h>
#define TASK "COOLMAC"
#define X first
#define Y second
#define ll long long
#define pi pair<int,int>
#define Bit(i) (1<<(i))
#define Get_Bit(i,x) (((x)>>i)&1)

using namespace std;
const int MAXN = 1e5;
const int N = 1e5 + 5;
int n,m,a[N];
pi b[N];

void Sub1()
{
    int res = 1e9;
    sort(b+1,b+m+1);
    sort(a+1,a+n+1);
    for (int S=1; S<Bit(m); ++S) {
        vector<pi> c;
        for (int i=0; i<m; ++i)
            if (Get_Bit(i,S)>0) c.push_back(b[i+1]);

        bool ok = 1;
        for (int i=1; i<c.size(); ++i) {
            if (c[i-1].Y>=c[i].X) continue;
            ok = 0;
            break;
        }
        if (!ok) continue;
        if (c[0].X<=a[1] && c.back().Y>=1e5)
            res = min(res,(int)c.size());
    }
    if (res==(int)1e9) cout << -1; else
    cout << res;
}

int f[N];
void Sub2()
{
    sort(b+1,b+m+1);
    sort(a+1,a+n+1);
    for (int i=1; i<=m; ++i) {
        if (b[i].Y>=1e5) f[i] = 1;
        else f[i] = 1e9;
    }
    for (int i=m; i>=1; --i) {
        for (int j=i+1; j<=m; ++j) {
            if (b[i].Y>=b[j].X)
                f[i] = min(f[i],f[j]+1);
        }
    }
    int res = 1e9;
    for (int i=1; i<=m; ++i) {
        if (b[i].X<=a[1]) res = min(res,f[i]);
    }
    if (res==(int)1e9) cout << -1; else
    cout << res;
}


int st[4*N];
void Update(int id, int l, int r, int u, int val)
{
    if (u<l || u>r) return;
    if (l==r) {
        if (st[id]==0) st[id] = val;
        else st[id] = min(st[id],val);
        return;
    }
    int mid = (l+r) >> 1;
    Update(id*2,l,mid,u,val);
    Update(id*2+1,mid+1,r,u,val);
    st[id] = min(st[id*2],st[id*2+1]);
}

int get(int id, int l, int r, int u, int v)
{
    if (u<=l && v>=r) return st[id];
    if (u>r || v<l) return 1e9;

    int mid =(l+r) >> 1;
    return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}

void Sub3()
{
    sort(b+1,b+m+1);
    sort(a+1,a+n+1);
    for (int i=1; i<=MAXN; ++i) Update(1,1,MAXN,i,1e9);
    for (int i=1; i<=m; ++i) {
        if (b[i].Y>=MAXN) f[i] = 1;
        else f[i] = 1e9;
        Update(1,1,MAXN,b[i].X,f[i]);
    }
    for (int i=m; i>=1; --i) {
        f[i] = min(f[i],get(1,1,MAXN,b[i].X,b[i].Y)+1);
        Update(1,1,MAXN,b[i].X,f[i]);
    }
    int res = 1e9;
    for (int i=1; i<=m; ++i) {
        if (b[i].X<=a[1]) res = min(res,f[i]);
    }
    if (res==(int)1e9) cout << -1; else
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    cin >> m;
    for (int i=1; i<=m; ++i) cin >> b[i].X >> b[i].Y;
    cin >> n;
    for (int i=1; i<=n; ++i) cin >> a[i];
    if (n<=10 && m<=16) Sub1(); else
    if (n<=3000) Sub2(); else
    Sub3();
    return 0;
}
