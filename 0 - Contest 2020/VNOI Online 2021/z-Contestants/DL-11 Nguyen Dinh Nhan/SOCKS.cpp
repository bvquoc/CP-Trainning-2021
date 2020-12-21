#include <bits/stdc++.h>

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define PI 3.1415926535897932384626433832795
#define MOD 998244353
#define endl '\n'
#define getBit(A, bit) ((A & 1LL << bit) != 0)
#define turnOn(A, bit) (A |= 1LL << bit)
#define turnOff(A, bit) (A &= ~(1LL << bit))
#define filename "SOCKS"

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;

int n, a[10000], q, col[10000], dd[100000], cnt = 0;
vector<int> G[10000];

void bfs(int st,int found)
{
    queue<int> pq;

    while(!pq.empty())
    {
        int v = pq.front();
        if(!dd[v])
        {
            dd[v] = st;
            if(v == found) return;
            pq.push(v);
        }
    }
}

void query()
{
    int change;

    cin >> change;

    a[change] = !a[change];

    cnt += a[change];

    if(!a[change])
    {
        cout << cnt * (cnt + 1) / 2 << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if(fopen("debug.inp", "r"))
    {
        freopen("debug.inp", "r", stdin);
        freopen("debug.out", "w", stdout);
    }
    else
    {
        freopen(filename".inp", "r", stdin);
        freopen(filename".out", "w", stdout);
    }

    cin >> n >> q;

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i < n; i++)
    {
        int u, v;

        cin >> u >> v;

        G[u].pb(v);
        G[v].pb(u);
    }

    for(int i = 1; i < n; i++)
    {
        cnt += a[i];
    }

    cout << n * (n - 1) / 2 << "\n";

    while(q--)
    {
        query();
    }

    return 0;
}
