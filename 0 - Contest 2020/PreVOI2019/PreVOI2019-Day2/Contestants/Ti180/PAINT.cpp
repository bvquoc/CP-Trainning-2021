// Nguyen Anh Tu
#include <bits/stdc++.h>
#define FOR(x,a,b) for(int x=a;x<=b;x++)
#define FORD(x,a,b) for(int x=a;x>=b;x--)
#define maxn 1000005
#define maxc 1000000007
#define MOD 1000000007
#define reset(x,y) memset(x,y,sizeof(x))
#define task "PAINT"
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pii pair<char,char>
#define ll long long
#define bit(p,x) ((x>>p) & 1)
#define remain(a,b) (a+b >= MOD) ? (a+b - MOD) : (a+b)

using namespace std;
int n, type[maxn];
int a[maxn];
pii c[maxn];
int val[27][maxn];
vector<int> v[maxn];
void sub1()
{
    int cnt = 0;
    int type;
    char x,y;
    for(int i=1; i<=n; ++i)
    {
        cin >> type;
        if(type == 1)
        {
            cin >> x;
            a[++cnt] = x;
            v[x].pb(cnt);
        }
        else
        {
            cin >> x >> y;
            while(v[x].size())
            {
                int u = v[x].back();
                v[x].pop_back();
                v[y].pb(u);
                a[u] = y;
            }
        }
    }
    for(int i=1; i<=cnt; ++i) cout << (char)a[i];
}
void sub2()
{
    int cnt = 0;
    char x,y;
    for(int i=1; i<=n; ++i)
    {
        cin >> type[i];
        if(type[i] == 1)
        {
            cin >> x;
            a[++cnt] = x;
        }
        else
        {
            cin >> x >> y;
            c[i] = {x,y};
            val[x-'a'+1][i] = y;
        }
    }
    int res = cnt;
    for(int i=n; i>=1; --i)
    {
        for(int j=1; j<=26; ++j)
        {
            val[j][i] = val[j][i+1];
        }
        if(type[i] == 2)
        {
            x = c[i].F;
            y = c[i].S;
            if(val[y-'a'+1][i] != 0)
                val[x-'a'+1][i] = val[y-'a'+1][i];
            else val[x-'a'+1][i] = y;
        }
        if(type[i] == 1)
        {
            if(val[a[res]-'a'+1][i])
            a[res] = val[a[res]-'a'+1][i];
            --res;
        }
    }
    for(int i=1; i<=cnt; ++i)
        cout << (char)a[i];
}
int main()
{
    #ifndef ONLINE_JUDGE
    ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    #endif
    cin >> n;
    if(n <= 10000)
    {
        sub1();
        return 0;
    }
    sub2();

}
