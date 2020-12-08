#include<bits/stdc++.h>

const int maxn = 1e5 + 5;
const int INF = 2e9;

using namespace std;

int T, n, m, a[maxn];
int64_t it[4 * maxn], dt[4 * maxn], it1[4 * maxn], dt1[4 * maxn];

void Input()
{
    scanf("%d", &T);
}

void Update(int r, int L, int R, int u, int v, int val)
{
    if(u > R || v < L) return;
    if(u <= L && R <= v)
    {
        dt[r] += val;
        return;
    }
    int mid = (L + R) / 2;
    dt[2 * r] += dt[r], dt[2 * r + 1] += dt[r];
    dt[r] = 0;
    Update(2 * r, L, mid, u, v, val);
    Update(2 * r + 1, mid + 1, R, u, v, val);
    it[r] = min(it[2 * r] + dt[2 * r], it[2 * r + 1] + dt[2 * r + 1]);
}

int Get(int r, int L, int R, int u, int v)
{
    if(u > R || v < L) return INF;
    if(u <= L && R <= v) return it[r] + dt[r];
    int mid = (L + R) / 2;
    dt[2 * r] += dt[r], dt[2 * r + 1] += dt[r];
    dt[r] = 0;
    int t1 = Get(2 * r, L, mid, u, v);
    int t2 = Get(2 * r + 1, mid + 1, R, u, v);
    it[r] = min(it[2 * r] + dt[2 * r], it[2 * r + 1] + dt[2 * r + 1]);
    return min(t1, t2);
}

void Update1(int r, int L, int R, int u, int v, int val)
{
    if(u > R || v < L) return;
    if(u <= L && R <= v)
    {
        dt1[r] += val;
        return;
    }
    int mid = (L + R) / 2;
    dt1[2 * r] += dt1[r], dt1[2 * r + 1] += dt1[r];
    dt1[r] = 0;
    Update1(2 * r, L, mid, u, v, val);
    Update1(2 * r + 1, mid + 1, R, u, v, val);
    it1[r] = min(it1[2 * r] + dt1[2 * r], it1[2 * r + 1] + dt1[2 * r + 1]);
}

int Get1(int r, int L, int R, int u, int v)
{
    if(u > R || v < L) return INF;
    if(u <= L && R <= v) return it1[r] + dt1[r];
    int mid = (L + R) / 2;
    dt1[2 * r] += dt1[r], dt1[2 * r + 1] += dt1[r];
    dt1[r] = 0;
    int t1 = Get1(2 * r, L, mid, u, v);
    int t2 = Get1(2 * r + 1, mid + 1, R, u, v);
    it1[r] = min(it1[2 * r] + dt1[2 * r], it1[2 * r + 1] + dt1[2 * r + 1]);
    return min(t1, t2);
}

void Solve()
{
    while(T--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        int type, u, v, K;
        for(int i = 1; i <= 4 * n + 5; i++) it[i] = dt[i] = 0;
        for(int i = 1; i <= n; i++) Update(1, 1, n, i, i, a[i]);
        while(m--)
        {
            scanf("%d", &type);
            if(type == 1)
            {
                scanf("%d %d %d", &u, &v, &K);
                Update(1, 1, n, u, v, K);
            }
            else
            {
                scanf("%d %d", &u, &v);
                int N = v - u + 1;
                for(int i = 1; i <= 4 * N + 5; i++) it1[i] = dt1[i] = 0;
                for(int i = u; i <= v; i++)
                {
                    int tmp = Get(1, 1, n, i, i);
                    Update1(1, 1, N, i - u + 1, i - u + 1, tmp);
                }
                int64_t dem = 0;
                int Max;
                do
                {
                    int L = 0, R = 0;
                    Max = 0;
                    for(int i = 1; i <= N; i++)
                    {
                        int T = Get1(1, 1, N, i, i);
                        if(T == 0)
                        {
                            if(L != 0)
                            {
                                int tmp = Get1(1, 1, N, L, R);
                                Update1(1, 1, N, L, R, -tmp);
                                L = 0, R = 0;
                                dem += (int64_t)tmp;
                            }
                        }
                        else
                        {
                            Max = max(Max, T);
                            if(L == 0) L = i, R = i;
                            else R = i;
                        }
                    }
                    if(R == N)
                    {
                        int tmp = Get1(1, 1, N, L, R);
                        Update1(1, 1, N, L, R, -tmp);
                        L = 0, R = 0;
                        dem += (int64_t)tmp;
                    }
                }
                while(Max != 0);
                printf("%I64d\n", dem);
            }
        }
    }
}

#define TASK "Construct"
int main()
{
    #ifdef TASK
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    #else
    freopen("1.inp", "r", stdin);
    #endif // TASK
    Input();
    Solve();
}
