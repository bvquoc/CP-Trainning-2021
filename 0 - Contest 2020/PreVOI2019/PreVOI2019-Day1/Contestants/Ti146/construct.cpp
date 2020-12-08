#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1e6 + 5;
long long a[maxn], b[maxn], d[maxn];
int n, m, id[maxn]; bool check[maxn];

void Input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

void Upd(int L, int R, int k)
{
    d[L] += (long long) k;
    d[R + 1] -= (long long) k;
}

void Ask(int L, int R)
{
    b[0] = 0;
    for (int i = 1; i <= n; i++)
        b[i] = b[i - 1] + d[i];
    for (int i = 1; i <= n; i++)
        b[i] += a[i];

    for (int i = 1; i <= n; i++)
        id[i] = i;
    sort(id + 1, id + 1 + n, [](int i, int j)
    {
        return b[i] < b[j];
    });

    fill(check + 1, check + 1 + n, true);
    int i = 1, cnt = 1; long long pr = 0;
    long long res = 0;
    check[0] = check[n + 1] = false;
    while (i <= n)
    {
        long long s = b[id[i]];
        res += (s - pr) * (long long) cnt;
        pr = s;

        while (i <= n && b[id[i]] == s)
        {
            check[id[i]] = false;
            if (check[id[i] - 1] && check[id[i] + 1])
                cnt++;
            else if (!check[id[i] - 1] && !check[id[i] + 1])
                cnt--;
            i++;
        }
    }
    cout << res << '\n';
}

void Solve()
{
    fill(d, d + 1 + n, 0);
    while (m--)
    {
        int id, L, R, k;
        cin >> id >> L >> R;
        if (id == 1)
            cin >> k, Upd(L, R, k);
        else Ask(L, R);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //freopen("test.inp" , "r" , stdin);
    //freopen("test.out" , "w" , stdout);

    freopen("construct.inp" , "r" , stdin);
    freopen("construct.out" , "w" , stdout);

    int q; cin >> q;
    while (q--)
    {
        Input();
        Solve();
    }
}

