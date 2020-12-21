#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fr(i,a,b) for(int i = a; i <= b; i++)
#define ll long long
#define pb push_back
typedef struct pair<int, int> ii;
void io () {
    freopen ("socks.inp", "r", stdin);
    freopen ("socks.out", "w", stdout);
}

bool check3 = false;
vector<int> a[100010];
int n, q;
int col[100010];
int type[100010];
int tatdo = 0;
int dinh = 0;
int res[5];

void inp () {
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> col[i];
        if(col[i] == 1)
            tatdo++;
    }
    int u, v;
    for(int i = 1; i <= n - 1; i++)
    {
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    int cnt = 0;
//    bool check = true;
    for(int i = 1; i <= n; i++)
    {
        if(a[i].size() == 3) {dinh = i; cnt++;}
        if(cnt == 2) {check3 = false;break;}
    }
//    cout << cnt << "\n";
    if(cnt == 1) check3 = true;
}
int cnt = 0;
void DFS(int par, int u)
{
    for(int i = 0; i < a[u].size(); i++)
    {
        int v = a[u][i];
        if(v == par) continue;
        if(par == 0) type[v] = ++cnt;
        else type[v] = type[u];
        DFS(u, v);
    }
}

void sub () {
    if(check3 == true)
    {
        DFS(0, dinh);
        type[dinh] = 1;
        for(int i = 1; i <= n; i++)
        {
            if(col[i] == 1 and i != dinh) res[type[i]]++;
        }
        int t;
        if(tatdo < 2) {cout << "0\n";}
        else
        {
            cnt = 0;
            for(int j = 1; j <= 3; j++)
            {
                if(res[j] != 0) cnt ++;
            }
            if(cnt <= 2)
            {
                cout << "1\n";
            }
            else
            {
                cout << "2\n";
            }
        }
        for(int i = 1; i <= q; i ++)
        {
            cin >> t;
            if(col[t] == 0)
            {
                col[t] = 1;
                if(t != dinh) res[type[t]] ++;
                tatdo++;
            }
            else
            {
                col[t] = 0;
                if(t != dinh) res[type[t]] --;
                tatdo--;
            }
            if(tatdo < 2) {cout << "0\n"; continue;}
            cnt = 0;
            for(int j = 1; j <= 3; j++)
            {
                if(res[j] != 0) cnt ++;
            }
            if(cnt <= 2)
            {
                cout << "1\n";
            }
            else
            {
                cout << "2\n";
            }
        }
    }
    else
    {
        int t;
        if(tatdo < 2) {cout << "0\n";}
        else cout << "1\n";
        for(int i = 1; i <= q; i++)
        {
            cin >> t;
            if(col[t] == 0)
            {
                col[t] = 1;
                tatdo++;
            }
            else
            {
                col[t] = 0;
                tatdo--;
            }
            if(tatdo < 2) {cout << "0\n";}
            else cout << "1\n";
        }
    }
}
int main () {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    io ();
    inp ();
    sub ();
    return 0;
}

