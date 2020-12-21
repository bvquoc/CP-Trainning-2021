#include <bits/stdc++.h>

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define sz(x) (int)x.size()

using namespace std;

const int N = 5e5 + 5;

int part[N], d[5], a[N], dem, ans;
vector <int> ke[N];

void DFS_vet(int u, int w)
{
    part[u] = w;
    for (int v : ke[u]){
        if (part[v] != 0) continue;

        DFS_vet(v, w);
    }
}

bool DFS(int u, int p)
{
    if (a[u] == 1) dem++;

    int tam = sz(ke[u]);
    for (int i = 0; i < sz(ke[u]); i++){
        int v = ke[u][i];
        if (v == p) continue;

        if (DFS(v, u) == true){
            tam = i;
            break;
        }
    }

    for (int i = tam + 1; i < sz(ke[u]); i++){
        int v = ke[u][i];
        if (v == p) continue;

        if (DFS(v, u) == true){
            if (dem > 0) ans++;
        }
    }

    if (a[u] == 1) dem--;

    if (a[u] == 1 || tam != sz(ke[u])) return true;
    return false;
}

int main()
{
    IOS;
    freopen("socks.inp","r",stdin);
    freopen("socks.out","w",stdout);

    int cnt = 0, n, nq;

    cin >> n >> nq;
    for (int i = 1; i <= n; i++){
        cin >> a[i];

        if (a[i]) cnt++;
    }

    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;

        ke[u].pb(v);
        ke[v].pb(u);
    }

    bool sub1 = true, sub2 = true;
    for (int i = 1; i <= n; i++){
        if (sz(ke[i]) > 2){
            if (sz(ke[i]) == 3 && sub1 == false || (sz(ke[i]) > 3)) sub2 = false;
            sub1 = false;
        }
    }

    int t;
    if (sub2 == true && sub1 == false){
        for (int i = 1; i <= n; i++){
            if (sz(ke[i]) == 3){
                t = i;
                break;
            }
        }

        part[t] = 1;
        for (int i = 0; i < sz(ke[t]); i++){
            DFS_vet(ke[t][i], i + 1);
        }

        for (int i = 1; i <= n; i++){
            if (a[i]) d[part[i]]++;
        }
    }

    for (int i = 0; i <= nq; i++){
        int u;
        if (i != 0){
            cin >> u;
            a[u] ^= 1;

            if (a[u]) d[part[u]]++, cnt++;
            else d[part[u]]--, cnt--;
        }

        if (sub1 == true){
            if (cnt > 0) cout << 1 << '\n';
            else cout << 0 << '\n';
            continue;
        }

        if (sub2 == true){
            if (a[t] == 1) d[1]--;
            int s1 = d[1] > 0, s2 = d[2] > 0, s3 = d[3] > 0;

            if (s1 + s2 + s3 == 0) cout << 0 << '\n';
            else if (s1 + s2 + s3 < 3) cout << 1 << '\n';
            else cout << 2 << '\n';
            continue;
        }

        ans = 0;
        dem = 0;
        DFS(1, 1);

        if (cnt > 0) ans++;
        cout << ans << '\n';
    }
}
