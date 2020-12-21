#include <bits/stdc++.h>
#define pii pair<int,int>
#define vi vector<int>
#define F first
#define S second
#define PB(x) push_back(x)
#define ll long long
#define maxn 100005

using namespace std;

const ll MOD = 1e9 + 7;
vector<vi> ke;
int n,q,cnt;
queue<int> Q;
int light[maxn],r[maxn];

int main()
{
    ifstream cin("SOCKS.inp");
    ofstream cout("SOCKS.out");
    cin >> n >> q;
    ke.assign(n+1,vi());
    for (int i = 1 ; i <= n ; i++){
        cin >> light[i];
        if (light[i] == 1) Q.push(i), r[i] = i, cnt++;
    }
    for (int i = 1 ; i < n ; i++){
        int u,v;
        cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }

    for (int i = 0 ; i < q ; i++){
        int u;
        cin >> u;
        if (light[u]) light[u] = 0,cnt--;
         else light[u] = 1,cnt++;
         if (cnt) cout << 1 << '\n';
          else cout << 0 << '\n';
    }

    return 0;
}
