///DECOR
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
#include<string.h>

const int N = 500005;
typedef std::pair<int, int> ii;
int n, m, k, b[N];
int par[N], cntb[N];
bool ava[N], Ns[N];
std::vector<int> vt[N];
ii e = {0, 0};
std::string s;

///sub1()

void sub1()
{
    int ans = 0;
    int cnt = 0;
    int id = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(s[i-1] == '0')
        {
            if(ans < cnt)
            {
                ans = cnt;
                e = {id, i-1};
            }
            cnt = 0;
            id = 0;
        }
        else
        {
            ++cnt;
            if(id == 0) id = i;
        }
    }
    if(ans == 0) printf("-1");
    else printf("%d %d",e.first,e.second);
}

///

///sub2

void sub2()
{
    int ans = 0;
    int cnt = 0;
    int id = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(s[i-1] == '0')
        {
            if(ans < cnt)
            {
                ans = cnt;
                e = {id, i-1};
            }
            cnt = 0;
            id = 0;
        }
        else
        {
            ++cnt;
            if(id == 0) id = i;
        }
    }
    if(ans == 0) printf("-1");
    else
    {
        for(int i = e.second; i <= n; ++i)
        {
            if(k == 0 && s[i-1] == '0') break;
            if(s[i-1] == '0') --k;
            id = i;
        }
        e.second = id;
        printf("%d %d",e.first,e.second);
    }
}

///

///sub34

int root(int u)
{
    if(par[u] < 0) return u;
    return par[u] = root(par[u]);
}

bool unco(int u, int v)
{
    int pu = root(u), pv = root(v);
    if(pu == pv) return 0;
    if(par[pu] > par[pv]) std::swap(pu, pv);
    par[pu] += par[pv];
    par[pv] = pu;
    return 1;
}

bool ok(int mid)
{
    for(int i = 1; i <= n; ++i){
        ava[i] = 0;
        vt[i].clear();
        cntb[root(i)] = 0;
        Ns[i] = 0;
    }
    for(int i = 1; i <= n; ++i) cntb[root(i)] += b[i];
    int cntb1 = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(cntb[root(i)] > 0)
        {
            --cntb[root(i)];
            ava[i] = 1;
            ++cntb1;
        }
        else
        {
            ava[i] = 0;
            vt[root(i)].push_back(i);
        }
        if(i >= mid)
            if(mid - cntb1 <= k)
            {
                e = {i - mid + 1, i};
                return 1;
            }
        if(i > mid)
        {
            int v = i - mid;
            if(ava[v])
            {
                cntb1--;
                ava[v] = 0;
                cntb[root(v)]++;
                while(vt[root(v)].size() > 0)
                {
                    if(Ns[vt[root(v)].back()])
                    {
                        vt[root(v)].pop_back();
                        continue;
                    }
                    cntb[root(v)]--;
                    ++cntb1;
                    ava[vt[root(v)].back()] = 1;
                    vt[root(v)].pop_back();
                    break;
                }
            }
            else Ns[v] = 1;
        }
    }
    return 0;
}

void sub34()
{
    int l = 1, r = n, ans = 0;
    while(l <= r)
    {
        int mid = l + r >> 1;
        if(ok(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    if(ans == 0) printf("-1");
    else printf("%d %d",e.first,e.second);
}

///

int main()
{
    freopen("DECOR.inp", "r", stdin);
    freopen("DECOR.out", "w", stdout);
    scanf("%d%d%d",&n,&m,&k);
    std::cin >> s;
    for(int i = 1; i <= n; ++i) b[i] = (s[i - 1] - '0');
    for(int i = 1; i <= n; ++i) par[i] = -1;
    for(int i = 1; i <= m; ++i)
    {
        int u, v; scanf("%d%d",&u,&v);
        unco(u, v);
    }
    if(m == 0 && k == 0) sub1();
    else if(m == 0) sub2();
    else sub34();
    return 0;
}
