#include<bits/stdc++.h>
using namespace std;

typedef pair<long, long> ii;

struct ore
{
    long long du, u, k, l;
    bool operator < (ore other) const
    {
        return du > other.du;
    }
};

long n, m, P, L, K;
long long f[10005][20][20];
vector<ii> c[10005];
priority_queue<ore, vector<ore> > pq;

void dik()
{
    for (long i = 1; i <= n; i++) for (long k = 0; k <= K; k++) for (long l = 0; l <= L; l++) f[i][k][l] = 1e15;
    f[1][0][0] = 0;
    pq.push({f[1][0][0], 1, 0, 0});
    while (!pq.empty())
    {
        long u = pq.top().u;
        long k = pq.top().k;
        long l = pq.top().l;
        long du = pq.top().du;
        pq.pop();
        if (du != f[u][k][l]) continue;
        if (k < K && f[u][k + 1][L] > f[u][k][l] + P)
        {
            f[u][k + 1][L] = f[u][k][l] + P;
            pq.push({f[u][k + 1][L], u, k + 1, L});
        }
        if (l == 0)
        {
            for (ii v: c[u])
            {
                if (f[v.first][k][0] > f[u][k][l] + v.second)
                {
                    f[v.first][k][0] = f[u][k][l] + v.second;
                    pq.push({f[v.first][k][0], v.first, k, 0});
                }
            }
        }
        else
        {
            for (ii v: c[u])
            {
                if (f[v.first][k][l - 1] > f[u][k][l])
                {
                    f[v.first][k][l - 1] = f[u][k][l];
                    pq.push({f[v.first][k][l - 1], v.first, k, l - 1});
                }
            }
        }
    }
    long long res = 1e15;
    for (long l = 0; l <= L; l++)
    {
        for (long k = 0; k <= K; k++)
        {
            res = min(res, f[n][k][l]);
        }
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("test.inp", "r", stdin);
    cin >> n >> m >> P >> L >> K;
    for (long i = 1; i <= m; i++)
    {
        long u, v, w;
        cin >> u >> v >> w;
        c[u].push_back(ii(v, w));
        c[v].push_back(ii(u, w));
    }
    dik();
    return 0;
}
