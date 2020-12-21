#include <bits/stdc++.h>

using namespace std;
#define task "COOLMAC"
const int MAXN = 1e5 + 7;
const int INF = 1e9 + 7;
int M, N;
int L[MAXN], R[MAXN];
int A[MAXN];
void Input()
{
    cin >> M;
    for(int i = 1; i <= M; i++)
        cin >> L[i] >> R[i];
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> A[i];
}
bool cmp(const int &x, const int &y)
{
    if(R[x] == R[y])
        return (L[x] < L[y]);
    return (R[x] < R[y]);
}
int ID[MAXN];
void minimize(int &x, const int &y)
{
    if(x > y)
        x = y;
}
bool maximize(int &x, const int &y)
{
    if(x < y)
    {
        x = y;
        return true;
    }
    return false;
}
int t[MAXN << 2];
void Build(int k, int l, int r)
{
    if(l > r)
        return ;
    if(l == r)
    {
        t[k] = INF;
        return ;
    }
    int mid = (l + r) >> 1;
    Build(k << 1, l, mid);
    Build(k << 1 | 1, mid + 1, r);
    t[k] = min(t[k << 1], t[k << 1 | 1]);
}
void Upd(int k, int l, int r, int pos, int val)
{
    if(l > r || r < pos || l > pos)
        return ;
    if(l == r && r == pos)
    {
        t[k] = min(t[k], val);
        return ;
    }
    int mid = (l + r) >> 1;
    Upd(k << 1, l, mid, pos, val);
    Upd(k << 1 | 1, mid + 1, r, pos, val);
    t[k] = min(t[k << 1], t[k << 1 | 1]);
}
int Get(int k, int l, int r, int i, int j)
{
    if(l > r || r < i || l > j)
        return INF;
    if(i <= l && r <= j)
        return t[k];
    int mid = (l + r) >> 1;
    return min(Get(k << 1, l, mid, i, j), Get(k << 1 | 1, mid + 1, r, i, j));
}
int d[MAXN];
void Output()
{
    for(int i = 1; i <= M; i++)
        ID[i] = i;
    sort(ID + 1, ID + 1 + M, cmp);
    int ans = 0;
    int l = -1, r = -1;
    int val = INF;
    for(int i = 1; i <= N; i++)
        minimize(val, A[i]);
    int pos = 1;
    int lmax = 0;
    for(int i = 1; i <= M; i++)
    {
        int p = ID[i];
        if(L[p] > val || R[p] < val)
            continue ;
        int x = ID[i - 1];
        if(L[p] != L[x])
        {
            pos = i;
            lmax = L[p];
            continue ;
        }
        if(maximize(lmax, L[p]))
            pos = i;
    }
    for(int i = pos; i <= M; i++)
    {
        int x = ID[i];
        if(l == -1)
        {
            ++ans;
            l = L[x];
            r = R[x];
            continue ;
        }
        if(l <= L[x] && R[x] <= r)
            continue ;
        if(L[x] <= r)
        {
            ++ans;
            minimize(l, L[x]);
            r = R[x];
        }
    }
    int rmax = 100000;
    for(int i = 1; i <= N; i++)
        if(!(A[i] >= l && r == rmax))
        {
            ans = INF;
            break ;
        }
    Build(1, 1, rmax);
    for(int i = 1; i <= M; i++)
    {
        int x = ID[i];
        if(R[x] < val)
            continue ;
        int k = Get(1, 1, rmax, L[x], R[x]);
        if(k == INF && L[x] <= val && R[x] <= val)
            d[i] = 1;
        else
            d[i] = k + 1;
        Upd(1, 1, rmax, R[x], d[i]);
    }
    ans = min(ans, Get(1, 1, rmax, rmax, rmax));
    if(ans == INF)
        cout << -1;
    else
        cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    Input();
    Output();
    return 0;
}
