#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e6 + 5;

int t, n, m, a[maxn];
vector<int> con[maxn];

int main()
{
    freopen("construct.inp", "r", stdin);
    freopen("construct.out", "w", stdout);
    scanf("%d", &t);
    int type, l, r, k;
    while(t--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        while(m--)
        {
            scanf("%d", &type);
            if(type == 1)
            {
                scanf("%d %d %d", &l, &r, &k);
                for(int i = l; i <= r; ++i) a[i] += k;
            }
            else{
                scanf("%d %d", &l, &r);
                int sl = 1;
                int64_t dem = 0;
                for(int i = l; i <= r; ++i) con[sl].push_back(a[i]);
                for(int i = 1; i <= sl; ++i)
                {
                    int amin = 1000005;
                    for(int u : con[i]) amin = min(amin, u);
                    dem += amin;
                    int sz = con[i].size();
                    for(int j = 0; j < sz; ++j)
                    {
                        if(j == 0 && con[i][j] > amin) con[++sl].push_back(con[i][j] - amin);
                        else if(j > 0 && con[i][j] > amin && con[i][j - 1] == amin) con[++sl].push_back(con[i][j] - amin);
                        else if(j > 0 && con[i][j] > amin) con[sl].push_back(con[i][j] - amin);
                    }
                    con[i].clear();
                }
                printf("%I64d\n", dem);
            }
        }
    }
}
