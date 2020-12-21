#include <bits/stdc++.h>

using namespace std;
#define task "SOCKS"
const int MAXN = 5e5 + 7;
const int INF = 1e9 + 7;
int N, Q;
bool A[MAXN];
int deg[MAXN];
vector <int> edges[MAXN];
void Input()
{
    cin >> N >> Q;
    for(int i = 1; i <= N; i++)
        cin >> A[i];
    for(int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
}
int numdeg = 0;
int maxx = 0;
int Group[MAXN];
void DFS(int u, int par, const int &p)
{
    Group[u] = p;
    for(auto v : edges[u])
        if(v != par)
            DFS(v, u, p);
}
int cnt = 0;
int num[4];
int root = 0;
void Init()
{
    for(int i = 1; i <= N; i++)
    {
        numdeg += (deg[i] >= 3);
        maxx = max(maxx, deg[i]);
    }
    if(numdeg == 1 && maxx == 3)
    {
        for(int i = 1; i <= N; i++)
            if(deg[i] == 3)
            {
                root = i;
                int k = 0;
                for(auto v : edges[i])
                {
                    ++k;
                    DFS(v, i, k);
                }
                break ;
            }
    }
    for(int i = 1; i <= N; i++)
    {
        cnt += A[i];
        if(Group[i])
            num[Group[i]] += A[i];
    }
}
void calc()
{
    if(cnt < 2)
    {
        cout << 0 << '\n';
        return ;
    }
    if(maxx == 2)
    {
        cout << (cnt >= 2) << '\n';
        return ;
    }
    int coun = 0;
    for(int i = 1; i <= 3; i++)
        coun += (num[i] != 0);
    if(coun == 0)
    {
        cout << 0 << '\n';
        return ;
    }
    if(coun <= 2)
    {
        cout << 1 << '\n';
        return ;
    }
    cout << 2 << '\n';
}
void Output()
{
    calc();
    while(Q--)
    {
        int pos;
        cin >> pos;
        cnt -= A[pos];
        if(Group[pos])
            num[Group[pos]] -= A[pos];
        A[pos] ^= 1;
        cnt += A[pos];
        if(Group[pos])
            num[Group[pos]] += A[pos];
        calc();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    Input();
    Init();
    Output();
    return 0;
}
