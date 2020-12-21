#include <bits/stdc++.h>

using namespace std;

#define bug(x) cerr << #x << " = " << x << '\n'
#define all(c) (c).begin(), (c).end()
#define sz(x)  (int) (x).size()
#define ll     long long
#define x      first
#define y      second
#define eb     emplace_back
#define maxn   505
#define mod    1000000007
#define ii     pair<int, int>

int n, m, p;

char a[maxn], b[maxn], c[maxn];

int f[maxn][maxn][maxn];

char ds[1000005];

void sub1()
{
        if(a[1] == c[1] || b[1] == c[1]) {
            printf("TRETRAU");
            return;
        }

        if(a[1] == b[1]) {
            printf("1\n");
            putchar(a[1]);
            return;
        }

        printf("2\n");
        putchar(a[1]); putchar(b[1]);
}

void sub2()
{
        for(int i = 0; i <= m; ++ i)
            for(int j = 0; j <= n; ++ j)
                for(int z = 0; z <= p; ++ z)
                    f[i][j][z] = mod;

        f[0][0][0] = 0;
        for(int i = 0; i <= m; ++ i)
            for(int j = 0; j <= n; ++ j) {
                for(int z = 0; z <= p; ++ z)
                {
                    if(i < m && j < n && a[i+1] == b[j+1])
                    {
                        int o = (z < p && a[i+1] == c[z+1]);
                        f[i+1][j+1][z+o] = min(f[i+1][j+1][z+o], f[i][j][z] + 1);
                    }
                    else
                    {
                        if(i < m) {
                            int o = (z < p && c[z+1] == a[i+1]);
                            f[i+1][j][z+o] = min(f[i+1][j][z+o], f[i][j][z] + 1);
                        }

                        if(j < n) {
                            int o = (z < p && c[z+1] == b[j+1]);
                            f[i][j+1][z+o] = min(f[i][j+1][z+o], f[i][j][z] + 1);
                        }
                    }
                }
            }

        int ret = mod, pos = 0;
        for(int i = 0; i < p; ++ i) {
            if(ret > f[m][n][i]) {
                ret = f[m][n][i];
                pos = i;
            }
        }
        if(ret == mod) {
            printf("TRETRAU");
            return;
        }

//        printf("%d\n", ret);

        int u = m, v = n, sl = 0;
        while(u > 0 || v > 0)
        {
            if(u == 0) {
                while(v > 0) { ds[++sl] = b[v]; -- v; }
                break;
            }
            if(v == 0) {
                while(u > 0) { ds[++sl] = a[u]; -- u; }
                break;
            }
            if(a[u] == b[v])
            {
                int o = (pos > 0 && c[pos] == a[u]);
                ds[++sl] = a[u];
                -- u; -- v; pos -= o;
            }
            else
            {
                int o = (pos > 0 && c[pos] == a[u]);
                if(f[u][v][pos] == (f[u-1][v][pos-o] + 1)) {
                    ds[++sl] = a[u];
                    pos -= o; -- u;
                } else {
                    int o = (pos > 0 && c[pos] == b[v]);
                    ds[++sl] = b[v];
                    pos -= o; -- v;

                }
            }
        }

        printf("%d\n", ret);
        for(int i = sl; i >= 1; -- i)
            putchar((char) ds[i]);
}

int main() {
        #define task "XCKLT"
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);

//        ios_base::sync_with_stdio(0);
//        cin.tie(0); cout.tie(0);

        scanf("%s %s %s", a + 1, b + 1, c + 1);

        m = strlen(a + 1);
        n = strlen(b + 1);
        p = strlen(c + 1);

        if(m == 1 && n == 1 && p == 1) sub1();
        else sub2();
}

