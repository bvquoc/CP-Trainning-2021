#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a),_b=(b);i<_b;++i)

using namespace std;
const int maxn = 5e5 + 5;
int a[maxn];
typedef pair<int,int> pir;
#define fi first
#define se second
pir  b[maxn];
int n,m,k;
template<typename T>
void read(T& u)
{
    u = 0;
    char t;
    do
        t=getchar();
    while(t<'0' || t>'9');
    do
    {
        u = u*10 + (t - '0');
        t=getchar();
    }
    while(t>='0' && t<='9');
}
void enter()
{
    #define fastio
    /**
    cin>>n>>m>>k;
    string A;
    cin>>A;
    _for(i,0,A.size())
        a[i + 1] = A[i] - '0';
    _for(i,1,m+1)
        cin>>b[i].fi>>b[i].se;
    */
    #ifdef fastio
    read(n); read(m); read(k);
    char t;
    _for(i,1,n+1)
    {
        t=getchar();
        a[i] = t - '0';
    }
    _for(i,1,m+1)
    {
        read(b[i].fi);
        read(b[i].se);
    }
    #endif // fastio
}


int rt[maxn], des[maxn], sl[maxn];
int root(int u)
{
    if (rt[u] == 0) return u;
    else return root(rt[u]);
}

void unite(int aa,int bb)
{
    int rt1= root(aa), rt2 = root(bb);
    if (rt1 == rt2) return;
    if (des[rt1] < des[rt2]) swap(rt1, rt2);
    rt[rt2] = rt1;
    des[rt1] += des[rt2];
    sl[rt1] += sl[rt2];
}

void optimize(int &L,int &R,int l ,int r)
{
    if (abs(L - R) < abs(l - r))
    {
        L = l;
        R = r;
    }
}


vector<int> g[maxn];
int nex[maxn];

int mark[maxn];
int bit[maxn];
void update(int i,int val)
{
    for(; i<=n; i+=(i&(-i)))
        bit[i] += val;
}

int _get(int i)
{
    int sum = 0;
    for(; i>0; i-=(i&(-i)))
        sum += bit[i];
    return sum;
}

int las[maxn];

int bs(int l,int r,int L)
{
    if (l==r) return l;
    else
    {
        int mid = ((l+r)>>1) + 1;
        if (_get(mid) - _get(L-1) + k >= (mid - L + 1)) return bs(mid, r, L);
        else return bs(l, mid - 1,L);
    }
}


void sub4()
{
    _for(i,1,n+1)
    {
        des[i] = 1;
        sl[i] = a[i];
    }
    _for(i,1,m+1)
    {
        unite(b[i].fi, b[i].se);
    }
    _for(i,1,n+1)
    {
        g[root(i)].push_back(i);
    }
    _for(i,1,n+1)
    {
        int rot = root(i);
        _for(j,0,g[i].size())
        {
            int I = g[i][j];
            if (j < int(g[i].size()) - 1)
            {

                int J = g[i][j + 1];
                nex[I] = J;
            }
            if (sl[rot] != 0)
            {
                mark[I] = 1;
                sl[rot] --;
                las[g[i][0]] = I;
            }
        }
    }
    _for(i,1,n+1)
    {
        update(i, mark[i]);
    }

    int L = 0,R = -1 ;
    _for(i,1,n+1)
    {
         int pos = bs(i - 1, n, i);
         optimize(L, R, i, pos);

         if (mark[i])
         {
             mark[i] = 0;
             update(i, -1);
             pos = nex[las[i]];
             if (pos != 0)
             {
                 mark[pos] = 1;
                 update(pos, 1);
                 las[nex[i]] = pos;
             }
         }
    }
    if (L == 0) cout<<"-1";
    else cout<<L<<" "<<R;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen("decor.inp","r",stdin);
    freopen("decor.out","w",stdout);
    enter();
    sub4();
    return 0;
}
