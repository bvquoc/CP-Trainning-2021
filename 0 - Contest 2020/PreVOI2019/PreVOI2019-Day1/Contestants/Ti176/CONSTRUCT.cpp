//Trương Minh Trí
#include <bits/stdc++.h>
#define FOR(i, x, y) for(int i = x; i <= y; ++i)
#define FORN(i, x, y) for(int i = x; i >= y; --i)
#define Task "CONSTRUCT"
#define maxn 100005
#define maxm
#define pii pair <int, int>
#define pll pair <long long, long long>
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
int T;
int n, m, a[maxn], h[maxn];
long long res;
bool ok;
void Solve()
{
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    while(m--)
    {
        int l, r, k, tp;
        cin >> tp;
        if(tp==1)
        {
            cin >> l >> r >> k;
            FOR(i, l, r) a[i] += k;
        }
        else
        {
            res = 0;
            cin >> l >> r;
            FOR(i, l, r+1) h[i] = 0;
            h[r+1] = a[r+1];
            int F = 0, S= 0, cp = INT_MAX;
            ok = 1;
            while(ok)
            {
                ok = 0;
                FOR(i, l, r+1) if(a[i]==h[i])
                {
                    FOR(j, F, S) h[j] += cp;
                    if(F) res += cp;
                    F = 0, S= 0, cp = INT_MAX;
                }
                else
                {
                    if(F==0) F = S = i, cp = min(cp, a[i] - h[i]);
                    else S++, cp = min(cp, a[i] - h[i]);
                }
                FOR(i, l, r) if(a[i] != h[i]) ok = 1;
            }
            cout << res << "\n";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> T;
    while(T--)
        Solve();

}
