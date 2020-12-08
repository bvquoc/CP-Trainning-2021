#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Ford(i,a,b) for(int i = a; i >= b; --i)
#define maxN 1000001
#define fi first
#define se second
#define Bit(x, i) ((x >> i) & 1)
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
struct pii
{
    int day, clr;
};
int n, k = 0, t, room[maxN];
char x, y;
vector<pii>color[26];
pii a[maxN];
void Sub1()
{
    For(test,1,n)
    {
        cin>>t;
        if(t == 1)
        {
            cin>>x;
            room[++k] = x - 'a';
        }
        else
        {
            cin>>x>>y;
            int u = x - 'a', v = y - 'a';
            For(i,1,k)
                if(room[i] == u)
                    room[i] = v;
        }
    }
    For(i,1,k)
        cout<<char(room[i] + 'a');
}

int dfs(int cur, int u)
{
    if(color[u].size() == 0)return u;
    int l = 0, r = color[u].size() - 1;
    while(r - l > 1)
    {
        int mid = (r + l) / 2;
        int nxt = color[u][mid].day;
        if(nxt < cur)l = mid;
        else
            r = mid;
    }
    if(color[u][l].day > cur)return dfs(color[u][l].day, color[u][l].clr);
    else
    {
        if(color[u][r].day > cur)return dfs(color[u][r].day, color[u][r].clr);
        return u;
    }
}
void Test()
{
    k = 0;
    For(test,1,n)
    {
        cin>>t;
        if(t == 1)
        {
            cin>>x;
            a[++k] = {test, x - 'a'};
        }
        else
        {
            cin>>x>>y;
            int u = x - 'a', v = y - 'a';
            color[u].push_back({test, v});
        }
    }
    For(i,1,k)
        cout<<char(dfs(a[i].day, a[i].clr) + 'a');
}
int main()
{
    freopen("paint.inp", "r", stdin);
    freopen("paint.out", "w", stdout);
    fast_read;
    cin>>n;
    if(n <= 10000)Sub1();
    else
        Test();
}
