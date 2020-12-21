#include <bits/stdc++.h>

using namespace std;

#define bug(x) cerr << #x << " = " << x << '\n'
#define all(c) (c).begin(), (c).end()
#define sz(x)  (int) (x).size()
#define ll     unsigned long long
#define x      first
#define y      second
#define eb     emplace_back
#define maxn   10005
#define mod    1000000007
#define ii     pair<int, int>
#define ar4    array<ll, 4>

int n, m;

char s[10];

ar4 e[maxn];

ll a[maxn];

void sub1()
{
        for(int i = 1; i < m; ++ i) {
            if(e[i][0] == e[i+1][0] && e[i][1] == e[i+1][1] && e[i][2] == e[i+1][2]) {
                putchar('N'); return;
            }
        }

        for(int i = 1; i <= n; ++ i)
            a[i] = 1;

        for(int i = 1; i <= m; ++ i) {
            int id = e[i][0];
            ll x = e[i][3];
            int u = e[i][1];
            int v = e[i][2];

            if(id == 1)
            {
                ll o = a[u];
                a[u] = o * x / __gcd(o, x);

                o = a[v];
                a[v] = o * x / __gcd(o, x);
            }
            else
            {
                ll o = a[u] * a[v] / __gcd(a[u], a[v]);

                if(x % o) { putchar('N'); return; }

                a[u] *= x / o;
            }
        }

        for(int i = 1; i <= m; ++ i)
        {
            int id = e[i][0];
            ll x = e[i][3];
            int u = e[i][1];
            int v = e[i][2];

            if(id == 1) {
                if(__gcd(a[u], a[v]) != x) {
                    putchar('N'); return;
                }
            } else {
                if((a[u] * a[v] / __gcd(a[u], a[v])) != x) {
                    putchar('N'); return;
                }
            }
        }

        putchar('Y');
}

int main() {
        #define task "GCDLCM"
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);

//        ios_base::sync_with_stdio(0);
//        cin.tie(0); cout.tie(0);

        int t, test;
        scanf("%d %d", &t, &test);

        while(test --> 0) {
            scanf("%d %d", &n, &m);
            for(int i = 1; i <= m; ++ i) {
                int u, v; ll x;
                scanf(" %s %d %d %lld ", s + 1, &u, &v, &x);
                if(u > v) swap(u, v);
                if(s[1] == 'G')
                    e[i] = {1, (ll) u, (ll) v, x};
                else
                    e[i] = {2, (ll) u, (ll) v, x};
            }

            sort(e + 1, e + m + 1);
            m = unique(e + 1, e + m + 1) - e - 1;

            sub1();
        }
}

