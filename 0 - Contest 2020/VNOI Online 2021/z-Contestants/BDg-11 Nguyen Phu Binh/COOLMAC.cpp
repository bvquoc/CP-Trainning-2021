#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int oo = (int) 1e9;
const int N = 1e5 + 5;

int minl[N];
int n,m,mindeg = oo;

void proc()
{
    int ans = 0;
    for (int i = N - 5, j = N - 5; i >= 0;)
    {
        int minres = oo;
        while (j >= i)
        {
            minres = min(minres, minl[j]);
            j--;
        }
        ans++;

        if (minres == oo)
        {
            cout << -1;
            return;
        }

        if (minres <= mindeg)
        {
            cout << ans;
            break;
        } else {
            i = minres;
        }
    }
}

void enter()
{
    cin >> n;
    for (int i = 0; i <= N - 4; i++)
    {
        minl[i] = (int) 1e9;
    }
    for (int i = 1; i <= n; i++)
    {
        int l,r;
        cin >> l >> r;
        minl[r] = min(minl[r], l);
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        mindeg = min(mindeg, x);
    }
}

void preproc()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("COOLMAC.inp","r",stdin);
    freopen("COOLMAC.out","w",stdout);
}

int main()
{
    preproc();
    enter();
    proc();
    return 0;
}
