#include<bits/stdc++.h>
#define mino "socks"

#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair

#define INC(i,a,b) for(int i=a; i<=b; i++)
#define DEC(i,a,b) for(int i=a; i>=b; i--)
#define REP(i,a,b) for(int i=a; i<b; i++)

#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oo 1e9

const int N = 1e5 + 5;

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;


int n, q, dem;
int cl[N], D[N];
vi a[N];
set <int> st;

void dfs(int p, int u)
{
    D[u] = cl[u];
    int cnt = 0;
    for(int v : a[u]) if( v != p )
    {
        dfs(u,v);
        if( D[v] > 0 ) cnt++;
        D[u] += D[v];
    }
    if( D[u] == 1 && cl[u] == 1 )
    {
        dem++;
    }
    else if( u == p && cnt <= 1 ) dem++;
}

int main()
{
    freopen(mino".inp","r",stdin);
    freopen(mino".out","w",stdout);

    turbo

    cin >> n >> q;

    INC(i,1,n)
    {
        cin >> cl[i];
        if( cl[i] ) st.insert(i);
    }

    REP(i,1,n)
    {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }

    if( st.size() == 0 ) cout << "0\n";
    else
    {
        dem = 0;
        dfs(*st.begin(), *st.begin());
        cout << (int)ceil((double)dem/2) << '\n';
    }
    while( q-- )
    {
        int x; cin >> x;
        cl[x] = 1 - cl[x];
        if( cl[x] == 0 ) st.erase(x);
        else st.insert(x);

        if( st.size() == 0 ) cout << "0\n";
        else
        {
            dem = 0;
            dfs(*st.begin(), *st.begin());
            cout << (int)ceil((double)dem/2) << '\n';
        }
    }
}
