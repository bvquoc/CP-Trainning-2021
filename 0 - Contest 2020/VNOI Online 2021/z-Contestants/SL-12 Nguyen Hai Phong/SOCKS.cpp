///SOCKS
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>

const int N = 500005;
int numN, numQ, numM, a[N], head[N], link[N*2], res;
struct {int u, v;}e[N*2];
bool ava[N];

void DFS(int u)
{
    ava[u] = 1;
    for(int i = head[u]; i; i = link[i])
    {
        int v = e[i].v;
        if(ava[v] == 0 && a[v] == 1)
            ++res, DFS(v);
    }
}

void sub3()
{
    memset(head, 0, sizeof head);
    for(int i = 1; i <= 2*numM; ++i)
    {
        link[i] = head[e[i].u];
        head[e[i].u] = i;
    }
    int id[N], n = 0;
    for(int i = 1; i <= numN; ++i)
        if(a[i] == 1) id[++n] = i;
    memset(ava, 0, sizeof ava);
    if(n == 0) printf("0\n");
    else
    {
        res = 1;
        for(int i = 1; i <= n; ++i)
        {
            int u = id[i];
            if(ava[u] == 0)
                DFS(u);
        }
        if(res == 1) printf("1\n");
        else printf("%d\n",res-1);
    }
    for( ;numQ > 0; --numQ)
    {
        int i;
        scanf("%d",&i);
        a[i] = (a[i] == 0 ? 1: 0);
        memset(id, 0, sizeof id);
        n = 0;
        for(i = 1; i <= numN; ++i)
            if(a[i] == 1) id[++n] = i;
        if(n == 0)
        {
            printf("0\n");
            continue;
        }
        memset(ava, 0, sizeof ava);
        res = 1;
        for(i = 1; i <= n; ++i)
        {
            int u = id[i];
            if(ava[u] == 0)
                DFS(u);
        }
        std::cout << res << ' ';
        if(res == 1) printf("1\n");
        else printf("%d\n",res-1);
    }
}

void sub1()
{
    int ans = 0, cnt = 0;
    for(int i = 1; i < numN; ++i)
    {
        if(a[i] == 1) ++cnt;
        else
        {
            ans += cnt;
            cnt = 0;
        }
    }
    printf("%d\n",ans);
    for(; numQ > 0; --numQ)
    {
        int i;
        scanf("%d",&i);
        a[i] = (a[i] - 1) * -1;
        ans = 0, cnt = 0;
        for(i = 1; i < numN; ++i)
        {
            if(a[i] == 1) ++cnt;
            else
            {
                if(cnt > 1)
                    ans += cnt;
                cnt = 0;
            }
        }
        if(ans == 0) printf("1\n");
        else printf("%d\n",ans-1);
    }
}

int main()
{
    freopen("SOCKS.inp", "r", stdin);
    freopen("SOCKS.out", "w", stdout);
    scanf("%d%d",&numN, &numQ);
    for(int i = 1; i <= numN; ++i)
        scanf("%d",&a[i]);
    numM = numN - 1;
    for(int i = 1; i <= numM; ++i)
    {
        int u, v; scanf("%d%d",&u,&v);
        e[i] = {u, v};
        e[i + numM] = {v, u};
    }
    if(numN <= 1000 && numQ <= 1000)
        sub3();
    else
        sub1();
    return 0;
}
