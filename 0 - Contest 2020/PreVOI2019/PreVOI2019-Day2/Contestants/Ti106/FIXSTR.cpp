#include<bits/stdc++.h>
#define mx 1000005
using namespace std;
string s;
map<int,string> tr;
int m;
struct data
{
    int id, u,v;
} q[mx];
void rev(int u)
{
    if(s[u] == '(')
        s[u] = ')';
    else
        s[u] = '(';
}
void solve1(int u,int v)
{
    int res = 0;
    int ans = 0;
    for(int i = u; i <= v; i++)
    {
        if(s[i] == ')')
            res--;
        else
            res++;
        if(res < 0)
        {
            res = 0;
            ans++;
        }
    }
    cout << ans + res << '\n';
}
void par(int u)
{
    s = tr[u-1];
}
void nhap()
{
    cin >> s;
    s="." + s;
    cin >> m;
}
void sub2()
{
    bool abc = 0;
    for(int i = 1; i <= m; i++)
    {
        char id;
        int u, v;
        cin >> id >> u;
        if(id == 'Q')
        {
            cin >> v;
            q[i] = {id,u,v},abc = 1;
        }
        else
            q[i] = {id,u};
    }
    if(!abc)
    {
        for(int i = 1; i <= m; i++)
        {
            char id = q[i].id;
            int u = q[i].u;
            if(id == 'C')
                rev(u);
            if(id == 'Q')
            {
                int v = q[i].v;
                solve1(u,v);
            }
        }
    }
    else
    {
        for(int i = 1; i <= m; i++)
        {
            char id = q[i].id;
            int u = q[i].u;
            if(id == 'C')
                rev(u);
            if(id == 'Q')
            {
                int v = q[i].v;
                solve1(u,v);
            }
            if(id == 'U')
                par(u);
            tr[i + 1] = s;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("FIXSTR.inp","r",stdin);
    freopen("FIXSTR.out","w",stdout);
    nhap();
    sub2();
}
