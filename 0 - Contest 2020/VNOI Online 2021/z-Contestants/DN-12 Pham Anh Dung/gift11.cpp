#include <bits/stdc++.h>

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long

using namespace std;

struct ii{
    int x, y, k;
};

const int N = 2e3 + 5;
const ll MOD = 998244353;

ii a[2005];
ll ans;
int n, s, le, chan;
int used[N];

void quaylui(int pos)
{
    if (pos == n + 1){
        if ((le - chan) % 11 == 0) ans++;
        return;
    }
    for (int i = 1; i <= n; i++){
        if (used[i] != 0) continue;

        s += a[i].k;
        if (s % 2) le += a[i].x, chan += a[i].y;
        else chan += a[i].x, le += a[i].y;

        used[i] = pos;

        quaylui(pos + 1);

        used[i] = 0;
        if (s % 2) le -= a[i].x, chan -= a[i].y;
        else chan -= a[i].x, le -= a[i].y;
        s -= a[i].k;
    }
}

int main()
{
    IOS;
    freopen("gift11.inp","r",stdin);
    freopen("gift11.out","w",stdout);

    int T;
    cin >> T;

    while (T--){
        cin >> n;

        bool sub2 = true;
        for (int i = 1; i <= n; i++){
            int u;
            cin >> u;

            int cnt = 0;
            while (u > 0){
                cnt++;

                if (cnt % 2) a[i].x += u % 10;
                else a[i].y += u % 10;

                u /= 10;
            }

            if (cnt % 2) sub2 = false;
            a[i].k = cnt;
        }

        le = chan = s = ans = 0;
        if (sub2 == true){
            for (int i = 1; i <= n; i++){
                chan += a[i].x;
                le += a[i].y;
            }

            if ((le - chan) % 11 == 0){
                ans = 1;
                for (int i = 1; i <= n; i++){
                    ans *= i;
                    ans %= MOD;
                }
            }

            cout << ans << '\n';
            continue;
        }

        quaylui(1);

        cout << ans << '\n';
    }
}
