#include<bits/stdc++.h>
using namespace std;

typedef pair<long, long> ii;

struct segment
{
    long l, r;
} seg[1000005];

long n, m;
priority_queue<long, vector<long> > pq;

bool cmp(const segment &x, const segment &y)
{
    return x.l < y.l;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("COOLMAC.INP", "r", stdin);
    freopen("COOLMAC.OUT", "w", stdout);
    cin >> n;
    for (long i = 1; i <= n; i++) cin >> seg[i].l >> seg[i].r;
    cin >> m;
    long pos = 1e9;
    for (long i = 1; i <= m; i++)
    {
        long t;
        cin >> t;
        pos = min(pos, t);
    }

    sort(seg + 1, seg + n + 1, cmp);

    pos--;
    long i = 1;
    long res = 0;
    while (pos < 100000)
    {
        while (i <= n && seg[i].l <= pos + 1) pq.push(seg[i].r), i++;
        if (pq.empty())
        {
            cout << -1;
            return 0;
        }
        if (pq.top() <= pos)
        {
            cout << -1;
            return 0;
        }
        pos = pq.top();
        pq.pop();
        res++;
    }
    cout << res;
    return 0;
}
