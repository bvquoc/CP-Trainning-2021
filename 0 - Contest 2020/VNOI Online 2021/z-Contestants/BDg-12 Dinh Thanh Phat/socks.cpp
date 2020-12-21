#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a),_b=(b);i<_b;++i)

using namespace std;
const int maxn = 5e5  +5;
int n,q;
vector<int> g[maxn];
int a[maxn];
int tv[maxn];

void enter()
{
    cin>>n>>q;
    _for(i,1,n+1)
        cin>>a[i];
    _for(i,1,n)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    _for(i,1,q+1)
    {
        cin>>tv[i];
    }
}
int h[maxn];

void dfs(int u,int _anc,int hh)
{
    h[u] = hh;
    for(auto i:g[u])
    {
        if (i!=_anc)
        {
            dfs(i, u, hh + 1);
        }
    }
}


bool issegment()
{
    dfs(1, 0, 1);
    int x = 0;
    _for(i,1,n+1)
        if (h[x] < h[i]) x = i;
    dfs(x, 0, 1);
    x = 0;
    _for(i,1,n+1)
        if (h[x] < h[i]) x=  i;
    if (h[x] == n) return true;
    else return false;
}

void sub1()
{
    int  cnt =0 ;
    _for(i,1,n+1)
        if (a[i] == 1) ++cnt;
    if (cnt>=2) cout<<"1\n";
    _for(i,1,q+1)
    {
        if (a[tv[i]] == 1)
            --cnt;
        else ++cnt;
        a[tv[i]] ^= 1;
        if (cnt>=2) cout<<"1\n";
        else cout<<"0\n";
    }
}
bool issub2()
{
    int deg3 = 0;
    _for(i,1,n+1)
    {
        if (g[i].size() == 3) deg3++;
        else if (g[i].size() > 2) return false;
    }
    if(deg3 == 1) return true;
    else return false;

}

int Group[maxn];

void rdfs(int u,int _anc,int gr)
{
    if (_anc == 0)
    {
        _for(i,0,g[u].size())
            rdfs(g[u][i], u, i);
    }
    else

    {
        Group[u] = gr;
        for(auto i:g[u])
            if (i!=_anc)
                rdfs(i, u, gr);
    }
}

int calc(int cnt[],bool p)
{
    int dem = 0;
    if (cnt[0] != 0) ++dem;
    if (cnt[1] != 0) ++dem;
    if (cnt[2] != 0) ++dem;
    if (dem >=2) return dem - 1;
    else
    {
        if (p ) return 1;
        else return 0;
    }
}
void sub2()
{
    int root = 0;
    _for(i,1,n+1)
        if (g[i].size() == 3) root = i;
    rdfs(root, 0, -1);
    int cnt[3] = {0,0,0};
    int dem = 0;
    _for(i,1,n+1)
    {
        if (i != root)
        {
            cnt[Group[i]] += a[i];
        }
        else dem += a[i];
    }
    cout<<calc(cnt, dem)<<"\n";
    _for(i,1,q+1)
    {
        if (tv[i] == root)
        {
            a[tv[i]] ^= 1;
            dem = a[root];
        }
        else
        {
             cnt[Group[tv[i]]] -= a[tv[i]];
             a[tv[i]] ^= 1;
             cnt[Group[tv[i]]] += a[tv[i]];
        }
        cout<<calc(cnt, dem)<<"\n";
    }
}




/// sub3
int leaf[maxn];
int onfire[maxn];

int look_for(int u,int _anc)
{
    if (onfire[u]) return u;
    for(auto i:g[u])
    {
        if (i!= _anc)
        {
            int ans = look_for(i, u);
            if (ans != 0)
                return ans;
        }
    }
    return 0;
}


bool found = false;
void color(int u,int _anc,int goal,int val)
{
    if (u == goal)
    {
        found = true;
        onfire[u] += val;
        return;
    }
    for(auto i:g[u])
    {
        if (i != _anc)
        {
            color(i, u, goal,val);
            if (found)
            {
                onfire[u] += val;
                return;
            }
        }
    }
}

int stop[maxn];


void sub3()
{
    int dem = 1;
    _for(i,1,n+1)
    {
        if (a[i] == 1)
        {
            stop[i] = look_for(i, 0);
            if (stop[i] == 0)
            {
                onfire[i] = 1;
                leaf[i] = 0;
            }
            else
            {
                found = false;
                color(i, 0, stop[i], 1);
                if (leaf[stop[i]] > 1)
                    dem ++ ;
                leaf[stop[i]] ++ ;
                leaf[i] = 1;
            }
        }
    }

    cout<<(dem + 1)/2<<"\n";
    _for(i,1,q+1)
    {
        a[tv[i]] ^= 1;
        int v = tv[i];
        if (a[v] ==1)
        {
            stop[v] = look_for(v, 0);
            found = false;
            color(v, 0, stop[v], 1);
            if (leaf[stop[v]] != 1)
            {
                dem++;
            }
            leaf[stop[v]]++;
            leaf[v] = 1;
        }
        else
        {
            found = false;
            color(v, 0, stop[v], -1);
            leaf[stop[v]]--;
            if (leaf[stop[v]] >1)
            {
                dem -- ;
            }
        }
        cout<<(dem + 1)/2<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen("socks.inp","r",stdin);
    freopen("socks.out","w",stdout);
    enter();
    if (issegment()) sub1();
    else if (issub2()) sub2();
    else
    {
        sub3();
    }
    return 0;
}
