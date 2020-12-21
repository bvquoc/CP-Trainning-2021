#include<bits/stdc++.h>
#define Task "SOCKS"
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i<=b; i++)
#define FORD(i, a, b) for(int i = a; i>= b; i--)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fifo if(fopen(Task".inp","r")){freopen(Task".inp","r",stdin);freopen(Task".out","w",stdout);}
using namespace std;
const int maxn = 1e5 + 5;
vector<int> a[maxn];
int c[maxn], dda[maxn], ddb[maxn];
//void DFS(int u)
//{
//    for(int i = 0; i < a[u].size(); i++)
//    {
//        int v = a[u][i];
//        if (tr[v] == 0)
//        {
//            tr[v] = u;
//            DFS(v);
//        }
//    }
//}
int main()
{

    faster;
    fifo;
    int n;
    cin >> n;
    FOR(i,1, n) cin >> c[i];
    FOR(i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    int dem1 = 0, dem2 = 0;
    FOR(i, 1, n)
    {
        if (a[i].size() == 1)
            dem1++;
        if ( a[i].size() == 2 )
            dem2++;
    }
    int q;
    cin >> q;
    int dem = 0;
    FOR(i, 1, n)
    if ( c[i] == 1 )
        dem++;
    if ( dem > 2 )
        cout << 1;
    else
        cout << 0;
    cout <<"\n";
    while( q-- )
    {
        int x;
        cin >> x;
        if ( c[x] == 0 )
            c[x] = 1;
        else
            c[x] = 0;
        int dem = 0;
        FOR(i, 1, n)
        if ( c[i] == 1 )
            dem++;
        if ( dem >= 2 )
            cout << 1;
        else
            cout << 0;
        cout <<"\n";
    }
    return 0;

}
