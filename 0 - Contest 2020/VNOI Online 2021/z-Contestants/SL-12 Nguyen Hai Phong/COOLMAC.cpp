///COOLMAC
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stack>

#define R second
#define L first

const int M = 100005;
const int N = 100005;
typedef std::pair<int, int> ii;
int NumM, NumN, MaxT = M, MinT = M, MaxR = 0, MinL = M;
ii e[M];
int Cnt = N;
bool ok = 0;

void solve()
{
    if(e[1].L > MinT || MaxR < 100000)
    {
        printf("-1");
        return;
    }
    for(int j = 1; j <= NumN; ++j)
    {
        MaxR = 0, MinL = M;
        if(e[j].L > MinT) break;
        std::stack<ii> St;
        St.push(e[j]);
        for(int i = j + 1; i <= NumM; ++i)
        {
            ii p = St.top();
            if(e[i].L >= p.L && p.R >= e[i].R) continue;
            while(St.size() > 1 && St.top().L >= e[i].L && e[i].R >= St.top().R) St.pop();
            if(St.size() == 1 && St.top().L >= e[i].L && e[i].R >= St.top().R && e[i].L > MinT) continue;
            if(St.size() == 1 && St.top().L >= e[i].L && e[i].R >= St.top().R && e[i].L <= MinT) St.pop();
            while(St.size() >= 2)
            {
                p = St.top();
                St.pop();
                if(St.top().R > e[i].L)
                {
                    St.push(p);
                    break;
                }
            }
            if(!St.empty() && St.top().R < e[i].L) continue;
            St.push(e[i]);
            if(e[i].R == 100000) break;
        }
        int ans = St.size();
        while(!St.empty()) MaxR = std::max(MaxR, St.top().R), MinL = std::min(MinL, St.top().L), St.pop();
        if(MaxR < 100000 || MinL > MinT)
            continue;
        ok = 1;
        Cnt = std::min(Cnt, ans);
    }
    if(ok == 1)
        printf("%d",Cnt);
    else printf("-1");
    return;
}

int main()
{
    freopen("COOLMAC.inp", "r", stdin);
    freopen("COOLMAC.out", "w", stdout);
    scanf("%d",&NumM);
    for(int i = 1; i <= NumM; ++i) scanf("%d%d",&e[i].L,&e[i].R), MaxR = std::max(MaxR, e[i].R);
    std::sort(e + 1, e + 1 + NumM);
    scanf("%d",&NumN);
    for(int i = 1; i <= NumN; ++i)
    {
        int t; scanf("%d",&t);
        MinT = std::min(MinT, t);
    }
    solve();
    return 0;
}
