#include<bits/stdc++.h>
using namespace std;
#define ft first
#define se second
#define iP pair<int,int>
#define iiP pair<int,pair<int,int> >
#define ll long long
#define lP pair<ll,int>
#define db long double
#define fu(i, a, b) for (int i = a; i <= b; ++i)
const int N=1e6+5;
template <typename T> inline void read(T &x)
{
    x=0;
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c))
    {
        x=x*10+c-48;
        c=getchar();
    }
}
int n,m,q;
int a[N];
int child[4*N];
ll f[4*N], lazy[4*N];

void build(int id, int l, int r)
{
    if (l == r)
    {
        child[id] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    child[id] = child[id << 1] + child[id << 1 | 1];
}
void dolazy(int id, int l, int r)
{
    if (!lazy[id]) return;
    f[id] += lazy[id];
    if (l != r)
    {
        lazy[id << 1] = lazy[id];
        lazy[id << 1 | 1] = lazy[id];
    }
    lazy[id] = 0;
}
void update(int id, int l, int r, int L, int R, ll val)
{
    if (l > r) return;
    dolazy(id, l, r);
    if (R < l || r < L)
        return;
    if (L <= l && r <= R)
    {
        f[id] += val * child[id];
        if (l != r)
        {
            lazy[id << 1] += val;
            lazy[id << 1 | 1] += val;
        }
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, L, R, val);
    update(id << 1 | 1, mid + 1, r, L, R, val);
    f[id] = max(f[id << 1],f[id << 1 | 1]);
}
void inp()
{
    read(n);
    read(m);
    build(1, 1, n);
    fu(i, 1, n)
    {
        int k; read(k);
        update(1, 1, n, i, i, k);
    }
}
ll get(int id, int l, int r, int L, int R)
{
    if (l > r) return LLONG_MIN;
    dolazy(id, l, r);
    if (R < l || r < L) return LLONG_MIN;
    if (L <= l && r <= R)
        return f[id];
    int mid = (l + r) >> 1;
    ll val1 = get(id << 1, l, mid, L, R);
    ll val2 = get(id << 1 | 1, mid + 1, r, L, R);
    return max(val1,val2);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("CONSTRUCT.INP","r",stdin);
    freopen("CONSTRUCT.OUT","w",stdout);
    read(q);
    while(q--)
    {
        inp();
        for(int i=1;i<=m;i++){
            int x;
            read(x);
            if(x==1){
                int y,z,k;
                read(y);
                read(z);
                read(k);
                //cout<<y<<" "<<z<<" "<<k<<endl;
                update(1, 1, n, y, z, k);
            }
            else{
                int y,z;
                read(y);
                read(z);
                cout<<get(1,1,n,y,z)<<endl;
            }
        }
    }
}


