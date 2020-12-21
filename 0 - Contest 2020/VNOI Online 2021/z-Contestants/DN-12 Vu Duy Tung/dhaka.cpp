#include<bits/stdc++.h>
#define mino "dhaka"

#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair

#define INC(i,a,b) for(int i=a; i<=b; i++)
#define DEC(i,a,b) for(int i=a; i>=b; i--)
#define REP(i,a,b) for(int i=a; i<b; i++)

#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oo 1e17

const int N = 1e5 + 5;

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;


int n, m, k, l;
ll F[N][35];
vi a[N], w[N], DH[N];

struct ii
{
    int u;
    ll w;
    int mask;
};
struct ss
{
    bool operator()( ii A, ii B )
    {
        return A.w > B.w;
    }
};
priority_queue <ii, vector<ii>, ss> heap;

void dijkstra()
{
    INC(i,1,n)
        INC(j,0,(1 << k)-1) F[i][j] = oo;

    int tmp = 0;
    for(int x : DH[1]) tmp += int(1 << (x-1));
    F[1][tmp] = 0;
    heap.push({1, 0, tmp});

    while( heap.size() )
    {
        ii x = heap.top();
        heap.pop();
        if( F[x.u][x.mask] < x.w ) continue;

        REP(i,0,(int)a[x.u].size())
        {
            int v = a[x.u][i];
            int New = x.mask;
            for(int cl : DH[v]) New = int(New | int(1 << (cl-1)));
            if( F[v][New] > F[x.u][x.mask] + w[x.u][i] )
            {
                F[v][New] = F[x.u][x.mask] + w[x.u][i];
                heap.push({v, F[v][New], New});
            }
        }
    }
}

int main()
{
    freopen(mino".inp","r",stdin);
    freopen(mino".out","w",stdout);

    turbo

    cin >> n >> m >> k >> l;

    INC(i,1,n)
    {
        int sl; cin >> sl;
        INC(j,1,sl)
        {
            int x; cin >> x;
            DH[i].pb(x);
        }
    }

    INC(i,1,m)
    {
        int u, v, c;
        cin >> u >> v >> c;
        a[u].pb(v);
        a[v].pb(u);
        w[u].pb(c);
        w[v].pb(c);
    }

    dijkstra();

    ll res = oo;
    INC(i,0,(1 << k) - 1)
    {
        int dem = 0;
        INC(j,0,k-1) if( i & (1 << j) ) dem++;

        if( dem >= l ) res = min(res, F[n][i]);
    }
    cout << res;

}
