#include<bits/stdc++.h>
using namespace std;

long n, c[1005][1005], match[1005], visit[1005], timed = 0;
vector<long> g[1005];

bool dfs(long u)
{
    if (visit[u] == timed) return false;
    visit[u] = timed;
    for (long v: g[u])
    {
        if (!match[v] || dfs(match[v]))
        {
            match[v] = u;
            return true;
        }
    }
    return false;
}

bool check(long mid)
{
    for (long i = 1; i <= n; i++) g[i].clear();
    for (long i = 1; i <= n; i++)
    {
        match[i] = 0;
        for (long j = 1; j <= n; j++)
        {
            if (c[i][j] >= mid) g[i].push_back(j);
        }
    }
    long cnt = 0;
    for (long i = 1; i <= n; i++)
    {
        timed++;
        cnt += dfs(i);
    }
    return cnt == n;

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (long i = 1; i <= n; i++)
    {
        for (long j = 1; j <= n; j++)
        {
            cin >> c[i][j];
        }
    }
    long l = 1, r = 1e9;
    long mid = (l + r) / 2;
    while (r - l > 1)
    {
        if (check(mid)) l = mid;
        else r = mid;
        mid = (l + r) / 2;
    }
    if (check(r)) cout << r;
    else cout << l;
    return 0;
}
