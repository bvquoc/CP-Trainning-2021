#include <bits/stdc++.h>
#define maxn 1000005
#define NTLiinhh "construct"
#define fto(i,a,b) for (int i=a;i<=b;i++)
#define fdto(i,a,b) for (int i=a;i>=b;i--)
#define endl '\n'
using namespace std;
int t, n, m;
long long a[maxn];
void input()
{
    ios_base::sync_with_stdio(0);
    cout.tie(NULL);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen (NTLiinhh".inp","r",stdin);
    freopen (NTLiinhh".out","w",stdout);
#endif // ONLINE_JUDGE
    cin >> t;
}

long long b[maxn];
void solve1()
{
    fto (ntl,1 , m) {
        int ip, l, r; long long k;
        cin >> ip >> l >> r;
        if (ip==1) {
            cin >> k;
            fto (j, l, r) a[j]+=k;
        }
        else {
            long long res=0;int sl=1;
            fto (i, l, r) b[i]=a[i];
            while (sl) {
                long long minn=1e9;
                sl=r-l+1;
                fto (i, l, r) if (b[i] && b[i]<minn) minn=b[i];
                    else if (!b[i]) --sl;
                int i=l;
                while (b[i]==0 && i<=r) ++i;
                for (; i<=r; ) {
                    if (b[i]==0) break;
                    b[i]-=minn;
                    if (b[i]==0) --sl;
                    ++i;
                }
                res+=minn;
                if (sl==0) break;
            }
            cout << res << endl;
        }
    }
}

long long s[maxn], it[maxn], it2[maxn], sl[maxn], z[maxn];

void build2(int u, int l, int r)
{
    if (l==r) {it2[u]=a[l]; sl[u]=1; return;}
    int m=(l+r)/2;
    build2(u*2, l, m);
    build2(u*2+1, m+1, r);
    it2[u]=it2[u*2]+it2[u*2+1];
    sl[u]=sl[u*2]+sl[u*2+1];
}

void lazy (int u)
{
        if(z[u]!=0){
            it2[u*2]=it2[u*2]+z[u]*sl[u*2];
            it2[u*2+1]=it2[u*2+1]+z[u]*sl[u*2+1];
            z[u*2]+=z[u];
            z[u*2+1]+=z[u];
            z[u]=0;
    }
}

long long get2(int u, int l, int r, int vt)
{
    if (l>vt || r<vt) return 0;
    lazy(u);
    if (l==r) return it2[u];
    int m=(l+r)/2;
    return get2(u*2, l, m, vt)+get2(u*2+1, m+1, r, vt);
}

void update2 (int u, int l, int r, int d, int c, long long w)
{
    if (l>c|| r<d) return;
    lazy(u);
    if (l>=d && r<=c) {
        it2[u]+=w*(r-l+1);
        z[u]+=w;
        return;
    }
    int g=(l+r)/2;
    update2(u*2, l, g, d, c, w);
    update2(u*2+1, g+1, r, d, c, w);
    it2[u]=it2[u*2] + it2[u*2+1];
}

void build (int u, int l, int r)
{
    if (l==r) {
        if (s[l]>0) it[u]=s[l];
        return;
    }
    int m=(l+r)/2;
    build(u*2, l, m);
    build(u*2+1,m+1, r);
    it[u]=(it[u*2]+it[u*2+1]);
}

long long get(int u, int l, int r, int d, int c)
{
    if (l>c || r<d) return 0;
    if (l>=d && r<=c) return it[u];
    int m=(l+r)/2;
    return get(u*2, l, m, d, c) + get(u*2+1, m+1, r, d, c);
}

void update (int u, int l, int r, int vt, long long w)
{
    if (l>vt || r<vt) return;
    if (l==r) {
        it[u]=w;
        return;
    }
    int m=(l+r)/2;
    update(u*2, l, m, vt, w);
    update(u*2+1, m+1, r, vt, w);
    it[u]=(it[u*2]+it[u*2+1]);
}

void solve2()
{
    s[1]=a[1];
    fto (i, 2, n) s[i]=a[i]-a[i-1];
    build (1, 1, n);
    build2(1, 1, n);
    fto (i, 1, m) {
        int ip, l, r;
        long long  k;
        cin >> ip >> l >> r;
        if (ip==1) {
            cin >> k;
            update2(1, 1, n, l, r, k);
            s[l]+=k;
            s[r+1]-=k;
            if (s[l]>0) update(1, 1, n, l, s[l]);
            if (r<n && s[r+1]>0) update(1, 1, n, r+1, s[r+1]);
            else if (r<n && s[r+1]<=0) update(1, 1, n, r+1, 0);
        }
        else {
            long long res=0;
            res=get2(1, 1, n, l);
            if (l<r) res+=get(1, 1, n, l+1, r);
            cout << res << endl;
        }
    }
}

int main()
{
    input();
    fto (i, 1, t){
        cin >> n >> m;
        fto (i,1 , n) cin >> a[i];
        if (n<=1000 && m<=1000) solve1(); else solve2();
    }
}
