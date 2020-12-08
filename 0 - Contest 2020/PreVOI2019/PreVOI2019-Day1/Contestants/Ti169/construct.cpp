#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 1e5 + 7;
int n, m, a[maxn], Left[maxn], Right[maxn];
int IT[4 * maxn], b[maxn];
vector<int> vt = {};
void Solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int l, r, k;
            cin >> l >> r >> k;
            for(int i = l; i <= r; i++)
            {
                a[i] += k;
            }
        }
        else
        {
            int l, r, ans = 0;
            cin >> l >> r;
            bool ok = false;
            for(int i = l; i <= r; i++) b[i] = a[i];
            b[r + 1] = 0;
            while(!ok)
            {
                ok = true;
                for(int i = l; i <= r; i++)
                {
                    if(b[i] > 0)
                    {
                        ok = false;
                        int Min = b[i];
                        for(int j = i + 1; j <= r + 1; j++)
                        {
                            if(b[j] > 0) Min = min(Min, b[j]);
                            else
                            {
                                ans += Min;
                                for(int k = i; k < j; k++)
                                {
                                    b[k] -= Min;
                                }
                                break;
                            }
                        }
                        break;
                    }
                }
            }
            cout << ans << '\n';
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen("construct.inp", "r")) freopen("construct.inp", "r", stdin), freopen("construct.out", "w", stdout);
    int sotest;
    cin >> sotest;
    while(sotest--)
    {
        Solve();
    }
}
