///----------/// dylanrhodes ///----------///
#include <bits/stdc++.h>
#define f first
#define s second
#define reset(x,a) memset (x,a,sizeof(x))
#define task "CONSTRUCT"

using namespace std;

const long long MOD = 1e18;
const int N = 100005;
int n,m,t;
long long A[N];
struct tree
{
    long long lt,rt,lz,t;
} st[4*N],joke;

void make (int id,int l,int r)
{
    if (l == r)
    {
        st[id].lt = A[l];
        st[id].rt = A[l];
        st[id].t = A[l];
        return;
    }
    int  mid = (l+r)/2;
    make (id*2,l,mid);
    make (id*2+1,mid+1,r);
    st[id].lt = st[id*2].lt;
    st[id].rt = st[id*2+1].rt;
    st[id].t = st[id*2].t + st[id*2+1].t - min(st[id*2].rt,st[id*2+1].lt);
}

void down (int  id)
{
    long long zz = st[id].lz;
    st[id].lz = 0;
    st[id*2].lz += zz;
    st[id*2+1].lz += zz;
    st[id*2].lt += zz;
    st[id*2].rt += zz;
    st[id*2+1].lt += zz;
    st[id*2+1].rt += zz;
    st[id*2].t += zz;
    st[id*2+1].t += zz;
}

void up (int id,int l,int r,int L,int R,long long k)
{
    if (R < l || r < L)
        return;
    if (L <= l && r <= R)
    {
        st[id].lt += k;
        st[id].rt += k;
        st[id].lz += k;
        st[id].t += k;
        return;
    }
    down(id);
    int  mid = (l+r)/2;
    up (id*2,l,mid,L,R,k);
    up (id*2+1,mid+1,r,L,R,k);
    st[id].lt = st[id*2].lt;
    st[id].rt = st[id*2+1].rt;
    st[id].t = st[id*2].t + st[id*2+1].t - min(st[id*2].rt,st[id*2+1].lt);
}

tree get (int id,int l,int r,int L,int R)
{
    if (R < l || r < L)
        return joke;
    if (L <= l && r <= R)
        return st[id];
    down(id);
    int  mid = (l+r)/2;
    tree x = get(id*2,l,mid,L,R);
    tree y = get(id*2+1,mid+1,r,L,R);
    if (y.lt == MOD)
        return x;
    else if (x.rt == MOD)
        return y;
    x.t = x.t + y.t - min(x.rt,y.lt);
    x.rt = y.rt;
    return x;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen (task".inp","r",stdin);
    freopen (task".out","w",stdout);

    cin >> t;
    joke.lt = MOD;
    joke.rt = MOD;

    while(t--)
    {
        cin >> n >> m;
        for (int  i = 1; i <= n; i++)
            cin >> A[i];

        make(1,1,n);
        for (int  i = 1; i <= m; i++)
        {
            int k;
            cin >> k;
            if (k == 1)
            {
                int l,r;
                long long val;
                cin >> l >> r >> val;
                up(1,1,n,l,r,val);
            }
            else
            {
                int l,r;
                cin >> l >> r;
                cout << get(1,1,n,l,r).t << "\n";
            }
        }

        for (int  i = 1; i <= 4*n; i++)
            st[i] = {0,0,0,0};
    }
    return 0;
}
