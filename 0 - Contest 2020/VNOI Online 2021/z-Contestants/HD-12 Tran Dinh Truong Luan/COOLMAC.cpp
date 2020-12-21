#include <bits/stdc++.h>

using namespace std;

#define bug(x) cerr << #x << " = " << x << '\n'
#define all(c) (c).begin(), (c).end()
#define sz(x)  (int) (x).size()
#define ll     long long
#define x      first
#define y      second
#define eb     emplace_back
#define maxn   100005
#define mod    1000000007
#define ii     pair<int, int>

int n, m;

ii a[maxn];

int main() {
        #define task "COOLMAC"
            freopen(task".inp","r",stdin);
            freopen(task".out","w",stdout);

//        ios_base::sync_with_stdio(0);
//        cin.tie(0); cout.tie(0);

        scanf("%d", &m);
        for(int i = 1; i <= m; ++ i)
            scanf("%d %d", &a[i].x, &a[i].y);
        scanf("%d", &n);

        int pos = 100000;
        for(int i = 1; i <= n; ++ i) {
            int x; scanf("%d", &x);
            pos = min(pos, x);
        }

        sort(a + 1, a + m + 1);

        int j = 1, ret = 0;
        while(j <= m) {
            int u = 0;
            if(a[j].x > pos) break;
            while(j <= m && a[j].x <= pos) {
                u = max(u, a[j].y);
                ++ j;
            }
            ret ++;
            pos = u + 1;
        }

        if(pos < 100000) printf("-1");
        else printf("%d", ret);
}

