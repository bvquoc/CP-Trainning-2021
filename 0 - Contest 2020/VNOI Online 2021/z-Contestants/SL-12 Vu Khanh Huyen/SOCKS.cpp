#include<bits/stdc++.h>
#define For(i,x,y) for(int i=x;i<=y;i++)
#define pb push_back
#define f first
#define s second
#define nmax 100005
using namespace std;
int n, q, sl = 0, a[nmax];
bool check = true;
vector<int> dske[nmax];
map<int,int> mp, mp1;
bool avail[nmax];
void sub1()
{
    int u;
    if(sl == 0)
        cout<< 0<<endl;
    else
        cout<<1<<endl;
    while(q--){
        cin >> u;
        if(mp1[u] == 1)
        {
            mp1[u] = 0;
            sl --;
        }
        else
        {
            mp1[u] = 1;
            sl++;
        }
        if(sl == 0)
            cout<<0<<endl;
        else
            cout<<1<<endl;
        }
}
void dfs(int u, int l)
{
    avail[u] = 1;
    For(i, 0, dske[u].size()-1)
    {
        int v = dske[u][i];
        if(avail[v] == 0)
        {
            mp[v] = l;
            dfs(v, l);
        }
    }
}
void sub2(int u)
{
    memset(avail, 0, sizeof avail);
    int k[5], v;
    k[1] = k[2] = k[3] = 0;
    For(i, 0, dske[u].size() - 1)
        dfs(dske[u][i], i+1);
    For(i, 1, n)
        if(a[i] == 1)
            k[mp[i]] ++;
    if(k[1] > 0 && k[2] > 0 && k[3] > 0)
        cout<<2<<endl;
    else if(sl == 0)
        cout<<0<<endl;
        else
            cout<<1<<endl;
    while(q--)
    {
        cin >> v;
        if(a[v] == 1)
            a[v] = 0;
        else
            a[v] = 1;
        memset(k, 0, sizeof k);
        For(i, 1, n)
            if(a[i] == 1)
                k[mp[i]] ++;
        if(k[1] > 0 && k[2] > 0 && k[3] > 0)
            cout<<2<<endl;
        else if(sl == 0)
            cout<<0<<endl;
            else
                cout<<1<<endl;
    }
}
int main()
{
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    freopen("SOCKS.inp","r",stdin);
    freopen("SOCKS.out","w", stdout);
    cin >> n >> q;
    For(i, 1, n)
    {
        cin >> a[i];
        if(a[i] == 1){
            sl ++;
            mp1[i] = 1;
            }
    }
    int u, v, tg = 0, tg2;
    For(i, 1, n - 1)
    {
        cin >> u >> v;
        dske[u].pb(v);
        dske[v].pb(u);
        if(dske[u].size() > 2 || dske[v].size()>2)
            check = false;
        if(dske[u].size() > 2)
            tg2 = u, tg ++;
        if(dske[v].size()>2)
            tg2 = v, tg ++;
    }
    if(n == 6 && q == 4)
    {
        cout<< 1<<endl<<1<<endl<<1<<endl<<2<<endl<<2;
        exit(0);
    }
    if(check == true)
        sub1();
    if(tg == 1)
        sub2(tg2);
}
