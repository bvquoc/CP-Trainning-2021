#include<bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> ii;

long long test, n;
ii a[100005];
vector<ii> pre[1000005];

vector<ii> get(long long x)
{
    vector<long long> tmp;
    for (long long i = 2; i <= sqrt(x); i++)
    {
        while (x % i == 0) tmp.push_back(i), x /= i;
    }
    if (x > 1) tmp.push_back(x);
    sort(tmp.begin(), tmp.end());
    vector<ii> res;
    res.push_back(ii(tmp[0], 1));
    for (long i = 1; i < tmp.size(); i++)
    {
        if (tmp[i] != tmp[i - 1])
        {
            res.push_back(ii(tmp[i], 1));
        }
        else if (res.size() > 0) res[res.size() - 1].second++;
    }
    return res;
}

void solve()
{
    cin >> n;
    if (n == 1)
    {
        cout << 1 << '\n';
        return;
    }
    for (long i = n; i <= n + 2; i++) if (pre[i].size() == 0) pre[i] = get(i);
    map<long long, long long> d;
    for (ii v: pre[n]) d[v.first] += v.second; for (ii v: pre[n + 1]) d[v.first] += v.second; for (ii v: pre[n + 2]) d[v.first] += v.second;

    long long cntT = 1, cntTT = 1;
    for (ii v: d)
    {
        if (v.first <= 1) continue;
        cntT *= (v.second + 1);
        cntTT *= (v.second * 2 + 1);
    }
    cout << cntTT / 2 - cntT + 1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> test;
    while (test--) solve();
    return 0;
}
