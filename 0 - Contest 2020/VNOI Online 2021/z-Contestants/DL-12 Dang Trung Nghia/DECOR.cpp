#include<bits/stdc++.h>
using namespace std;

long n, m, K, grsz = 0, cnt[500005], a[5005], team[500005], picked[500005];
string s;
vector<long> g[500005];
vector<long> gr[500005];
bool visit[500005];

void sub1()
{
    long l = 1, now = 0;
    long res = 0, posl;
    for (long r = 1; r <= n; r++)
    {
        now += (s[r] == '0');
        while (now > K) now -= (s[l++] == '0');
        if (r - l + 1 > res)
        {
            res = r - l + 1;
            posl = l;
        }
    }
    if (res == 0) cout << -1;
    else cout << posl << ' ' << posl + res - 1;
}

void bfs(long x)
{
    queue<long> q;
    grsz++;
    q.push(x);
    visit[x] = true;
    while (!q.empty())
    {
        long u = q.front();
        q.pop();
        gr[grsz].push_back(u);
        cnt[grsz] += (s[u] == '1');
        for (long v: g[u])
        {
            if (visit[v]) continue;
            q.push(v);
            visit[v] = true;
        }
    }
    sort(gr[grsz].begin(), gr[grsz].end());
}

void sub2()
{
    fill(visit + 1, visit + n + 1, false);
    for (long i = 1; i <= n; i++) if (!visit[i]) bfs(i);
    fill(a + 1, a + n + 1, 0);
    long res = 0, posl;
    for (long st = 1; st <= n; st++)
    {
        for (long i = 1; i <= grsz; i++)
        {
            long now = 0;
            for (long p: gr[i])
            {
                if (now == cnt[i]) break;
                if (p >= st) a[p] = st, now++;
            }
        }
        long l = 1, now = 0;
        for (long r = 1; r <= n; r++)
        {
            now += (a[r] != st);
            while (now > K) now -= (a[l] != st), l++;
            if (r - l + 1 == res) posl = min(posl, l);
            if (r - l + 1 > res)
            {
                res = r - l + 1;
                posl = l;
            }
        }
    }
    if (res == 0) cout << -1;
    else cout << posl << ' ' << posl + res - 1;
};

bool check(long mid)
{
    for (long i = 1; i <= grsz; i++) picked[i] = 0;
    long now = 0;
    for (long i = 1; i <= mid; i++)
    {
        picked[team[i]]++;
        if (picked[team[i]] > cnt[team[i]]) now++;
    }
    if (now <= K) return true;
    for (long i = 2; i <= n - mid + 1; i++)
    {
        if (picked[team[i - 1]] > cnt[team[i - 1]]) now--;
        picked[team[i - 1]]--;
        picked[team[i + mid - 1]]++;
        if (picked[team[i + mid - 1]] > cnt[team[i + mid - 1]]) now++;
        if (now <= K) return true;
    }
    return false;
}

void sub3()
{
    fill(visit + 1, visit + n + 1, false);
    for (long i = 1; i <= n; i++) if (!visit[i]) bfs(i);
    for (long i = 1; i <= grsz; i++)
    {
        for (long v: gr[i]) team[v] = i;
    }
    long l = 0, r = n;
    long mid = (l + r) / 2;
    while (r - l > 1)
    {
        if (check(mid)) l = mid;
        else r = mid;
        mid = (l + r) / 2;
    }
    long res;
    if (check(r)) res = r;
    else res = l;
    if (res == 0)
    {
        cout << -1;
        return;
    }
    for (long i = 1; i <= grsz; i++) picked[i] = 0;
    long now = 0;
    for (long i = 1; i <= res; i++)
    {
        picked[team[i]]++;
        if (picked[team[i]] > cnt[team[i]]) now++;
    }
    if (now <= K)
    {
        cout << 1 << ' ' << res;
        return;
    }
    for (long i = 2; i <= n - res + 1; i++)
    {
        if (picked[team[i - 1]] > cnt[team[i - 1]]) now--;
        picked[team[i - 1]]--;
        picked[team[i + res - 1]]++;
        if (picked[team[i + res - 1]] > cnt[team[i + res - 1]]) now++;
        if (now <= K)
        {
            cout << i << ' ' << i + res - 1;
            return;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("DECOR.INP", "r", stdin);
    freopen("DECOR.OUT", "w", stdout);
    cin >> n >> m >> K;
    cin >> s;
    s = '@' + s;
    for (long i = 1; i <= m; i++)
    {
        long u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (m == 0)
    {
        sub1();
        return 0;
    }
    if (n <= 4000)
    {
        sub2();
        return 0;
    }
    sub3();
    return 0;
}

