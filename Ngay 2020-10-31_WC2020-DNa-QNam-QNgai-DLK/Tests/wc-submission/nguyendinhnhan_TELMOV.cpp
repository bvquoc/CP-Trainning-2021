#include <bits/stdc++.h>

#define MP make_pair
#define pb push_back
#define INF INT_MAX
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define endl '\n'
#define getBit(A, bit) ((A & 1 << bit) != 0)
#define turnOn(A, bit) (A |= 1 << bit)
#define turnOff(A, bit) (A &= ~(1 << bit))

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pi;
typedef unsigned long long ull;

int n, m, p, l, k;
ll dd[100004];
vector<pi> G[100004];

void dijsktra(int st)
{
    priority_queue<pi, vector<pi>, greater<pi>> pq;

    for(int i = 1; i <= n; i++)
        dd[i] = INF;

    dd[st] = 0;

    pq.push(pi(0, st));

    while(!pq.empty())
    {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();

        if(dd[u] != du) continue;

        for(int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i].second;
            int uv = G[u][i].first;

            if(dd[v] > du + uv)
            {
                dd[v] = du + uv;

                pq.push(pi(dd[v], v));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen("debug.inp","r",stdin);
    freopen("debug.out","w",stdout);
    #endif

    cin >> n >> m >> p >> l >> k;

    while(m--)
    {
        int x, y, w;

        cin >> x >> y >> w;

        G[x].pb(pi(w, y));
        G[y].pb(pi(w, x));
    }

    dijsktra(1);

    cout << dd[n];

    return 0;
}
