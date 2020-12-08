// He always smiles :)
#include <bits/stdc++.h>
#define maxn 100005
#define mod 1000000007
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define task "CONSTRUCT"
#define ll long long
#define reset(x, a) memset(x, a, sizeof(x))
#define endl "\n"

using namespace std;

int t, n, m;
ll a[maxn], ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for (int i = 1 ; i <= n ; i ++)
            cin >> a[i];
        while(m --)
        {
            int type, l, r;
            ll k;
            cin >> type;
            if(type == 1)
            {
                cin >> l >> r >> k;
                for (int i = l ; i <= r ; i ++) a[i] +=k;
            }
            else
            {
                cin >> l >> r;
                int L = l, R = l;
                ans = a[l];
                for (int i = l + 1 ; i <= r ; i ++)
                    if(a[i] >= a[i - 1]) R = i;
                    else ans += a[R] - a[L], L = i, R = i;
                ans += a[R] - a[L];
                cout << ans << endl;
            }
        }
    }
    return 0;
}
