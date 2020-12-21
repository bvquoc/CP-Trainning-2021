#include <bits/stdc++.h>

using namespace std;
#define task "DECOR"
const int MAXN = 5e5 + 7;
const int INF = 1e9 + 7;
int N, M, K;
string S;
pair <int, int> edges[MAXN];
void Input()
{
    cin >> N >> M >> K >> S;
    for(int i = 1; i <= M; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }
}
void Subtask1()
{
    int ans = -1;
    int l = -1;
    for(int i = 0; i < (int) S.size();)
    {
        if(S[i] == '0')
        {
            i++;
            continue ;
        }
        int j = i;
        while(j < (int) S.size() && S[i] == S[j])
            j++;
        if(ans < j - i)
        {
            ans = j - i;
            l = i;
        }
        i = j;
    }
    if(ans != -1)
        cout << l + 1 << " ";
    cout << ans;
}
void Subtask2()
{
    int ans = -1;
    int l = -1;
    int cntZero = 0;
    int Left = 0;
    for(int i = 0; i < (int) S.size(); i++)
    {
        cntZero += (S[i] == '0');
        while(cntZero > K && Left < i)
        {
            cntZero -= (S[Left] == '0');
            Left++;
        }
        if(ans < i - Left + 1)
        {
            ans = i - Left + 1;
            l = Left;
        }
        else if(ans == i - Left + 1)
            l = min(l, Left);
    }
    if(ans != -1)
        cout << l + 1 << " ";
    cout << ans;
}
int par[MAXN];
int num[MAXN];
int root(int u)
{
    return (par[u] < 0) ? u : par[u] = root(par[u]);
}
void Merge(int u, int v)
{
    if((u = root(u)) == (v = root(v)))
        return ;
    if(par[u] > par[v])
        swap(u, v);
    par[u] += par[v];
    num[u] += num[v];
    par[v] = u;
}
int cnt[MAXN];
int check(const int &mid)
{
    memset(cnt, 0, sizeof cnt);
    int mustBeAdd = 0;
    for(int i = 1; i <= mid; i++)
    {
        int u = root(i);
        cnt[u]++;
        mustBeAdd += (cnt[u] > num[u]);
    }
    if(mustBeAdd <= K)
        return 1;
    int l = 1;
    for(int i = mid + 1; i <= N; i++)
    {
        int u = root(l);
        mustBeAdd -= (cnt[u] > num[u]);
        cnt[u]--;
        l++;
        u = root(i);
        cnt[u]++;
        mustBeAdd += (cnt[u] > num[u]);
        if(mustBeAdd <= K)
            return l;
    }
    return 0;
}
void Subtask3()
{
    S = " " + S;
    memset(par, -1, sizeof par);
    for(int i = 1; i <= N; i++)
        num[i] = (S[i] == '1');
    for(int i = 1; i <= M; i++)
        Merge(edges[i].first, edges[i].second);
//    check(3);
    int l = 1, r = N;
    int ans = -1;
    int Left = -1;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        int temp = check(mid);
        if(temp)
        {
            ans = mid;
            Left = temp;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    if(ans == -1)
        cout << ans;
    else
        cout << Left << " " << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    Input();
    if(M == 0 && K == 0)
        Subtask1();
    else if(M == 0)
        Subtask2();
    else
        Subtask3();
    return 0;
}
