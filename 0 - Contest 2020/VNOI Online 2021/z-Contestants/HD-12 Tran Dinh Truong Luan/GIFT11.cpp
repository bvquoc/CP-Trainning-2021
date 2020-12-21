#include <bits/stdc++.h>

using namespace std;

#define bug(x) cerr << #x << " = " << x << '\n'
#define all(c) (c).begin(), (c).end()
#define sz(x)  (int) (x).size()
#define ll     long long
#define x      first
#define y      second
#define eb     emplace_back
#define maxn   2005
#define mod    998244353
#define ii     pair<int, int>

int n;

int d[maxn], b[maxn], len[maxn], a[maxn];

int f[maxn][maxn][15];

int gt[maxn];

void sub1()
{
        for(int i = 1; i <= n; ++ i)
            d[i] = i;

        int ret = 0;
        do {
            int sum = 0, cost = 0;
            for(int i = 1; i <= n; ++ i) {
                if(sum % 2) cost -= b[d[i]];
                else cost += b[d[i]];
                sum += len[d[i]];
            }
            cost = (cost % 11 + 11) % 11;
            if(cost % 11 == 0) ret ++;
        } while(next_permutation(d + 1, d + n + 1));

        printf("%d", ret % mod);
}

void sub2()
{
        int sum = 0;
        for(int i = 1; i <= n; ++ i)
            sum += b[i];
        sum = (sum % 11 + 11) % 11;

        if(sum % 11) {printf("0"); return;}
        int cost = 1;
        for(int i = 1; i <= n; ++ i)
            cost = (ll) cost * i % mod;
        printf("%d", cost);
}

void sub3()
{
        int sum = 0;
        for(int i = 1; i <= n; ++ i)
            sum += b[i];
        sum = (sum % 11 + 11) % 11;

        f[0][0][0] = 1;
        for(int i = 1; i <= n; ++ i) {
            for(int j = 0; j <= i; ++ j)
                for(int k = 0; k < 11; ++ k) {
                    int z = ((k + 2*b[i]) % 11 + 11) % 11;
                    f[i][j][z] = (f[i][j][z] + f[i-1][j-1][k]) % mod;
                    f[i][j][k] = (f[i][j][k] + f[i-1][j][k]) % mod;
            }
        }

        int o = (ll) f[n][n/2][sum] * gt[n/2] % mod;
        o = (ll) o * gt[n-n/2] % mod;
        printf("%d", o);
}

void sub4()
{
        int sum = 0, odd = 0;
        for(int i = 1; i <= n; ++ i) {
            sum += b[i];
            if(len[i] % 2) odd ++;
        }

        sum = (sum % 11 + 11) % 11;

        f[0][0][0] = 1;
        for(int i = 1; i <= n; ++ i) {
            for(int j = 1; j <= i; ++ j)
                for(int k = 0; k < 11; ++ k) {
                    int z = (k + 2*b[i]) % 11;
                    f[i][j][z] = (f[i][j][z] + f[i-1][j-1][k]) % mod;
                    f[i][j][k] = (f[i][j][k] + f[i-1][j][k]) % mod;
            }
        }

        odd /= 2;
        int o = (ll) f[n][odd][sum] * gt[odd] % mod;
        o = (ll) o * gt[n-odd] % mod;
        printf("%d", o);
}

int main() {
        #define task "GIFT11"
            freopen(task".inp","r",stdin);
            freopen(task".out","w",stdout);

//        ios_base::sync_with_stdio(0);
//        cin.tie(0); cout.tie(0);

        int t;
        scanf("%d", &t);

        gt[0] = 1;
        for(int i = 1; i <= 2000; ++ i)
            gt[i] = (ll) gt[i-1] * i % mod;

        while(t --> 0)
        {
            scanf("%d", &n);
            for(int i = 1; i <= n; ++ i)
                scanf("%d", &a[i]);

            int even = 0;
            for(int i = 1; i <= n; ++ i) {
                int x = a[i], o = 1;
                while(x > 0) {
                    if(o) b[i] += x % 10;
                    else b[i] -= x % 10;
                    len[i] ++;
                    o = 1 - o;
                    x /= 10;
                }
                if(len[i] % 2 == 0) b[i] = -b[i];
                even += (len[i] % 2 == 0);
            }

            if(n <= 8) sub1();
            else if(even == n) sub2();
            else if(even == 0) sub3();
            else sub4();
            putchar(10);
        }
}

