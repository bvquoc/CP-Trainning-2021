#include <bits/stdc++.h>
#define ft first
#define sc second

using namespace std;
typedef pair <int, int > II;

int const N = 1e5 + 5;
int m, n;
II a[N];
int t[N], p[N];

set <II > s;

#define ha "COOLMAC"
int main()
{
    //freopen("task.inp","r",stdin);
    freopen(ha".INP","r",stdin);
    freopen(ha".OUT","w",stdout);

    scanf("%d", &m);

    int sl = 0;
    for(int i = 1; i <= m; ++i)
    {
        scanf("%d %d", &a[i].ft, &a[i].sc);

        if(a[i].sc + 1 <= 100000)
        {
            ++sl;
            p[sl] = a[i].sc + 1;
        }
    }

    scanf("%d", &n);

    for(int i = 1; i <= n; ++i) scanf("%d", &t[i]);

    for(int i = 1; i <= sl; ++i)
        t[n + i] = p[i];

    n += sl;

    sort(t + 1, t + n + 1);

    int ans = 2e9;

    for(int i = 0; i < (1 << m); ++i)
    {
        int sl = __builtin_popcount(i);
        s.clear();
        for(int j = 1; j <= 17; ++j)
        {
            if(i & (1 << (j - 1)))
            {
                s.insert({a[j].ft, a[j].sc});
            }
        }

        bool ok = true;
        for(int j = 1; j <= n; ++j)
        {
            if(s.empty()){ok = false; break;}

            while(!s.empty())
            {
                II x = (*s.begin());
                if(x.ft <= t[j] && x.sc >= t[j]){break;}
                s.erase(x);
                if(s.empty()){ok = false; break;}
            }
        }

        if(ok == true) ans = min(ans, sl);
    }

    if(ans == 2e9) printf("-1");
    else
    printf("%d", ans);
}
