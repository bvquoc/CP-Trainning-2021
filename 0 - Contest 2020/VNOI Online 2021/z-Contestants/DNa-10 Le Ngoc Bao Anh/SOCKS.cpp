#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define ins insert
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define unmap unordered_map
#define pq priority_queue
#define minEle min_element
#define maxEle max_element
#define lb lower_bound //first pos >= val
#define ub upper_bound // first pos > val
#define cnt_bit __builtin_popcount
//#pragma GCC optimize("Ofast")  
//#pragma GCC target("avx,avx2,fma")
using namespace std;

int d4x[4] = {1, 0, -1, 0}; int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1}; 

const long long oo = 1e18;
const long long maxN = 1e6;

/* Author : Le Ngoc Bao Anh, 10A5, LQD High School for Gifted Student */

int visited[maxN];
int root[maxN];
int need[maxN];
int special[maxN];
vector<int> a[maxN];
int ans = 0;

void dfs(int node) {
    visited[node] = 1;

    for(int i = 0; i < a[node].size(); i++) {
        if(!visited[a[node][i]]) {
            root[a[node][i]] = node;
            dfs(a[node][i]);
            if(need[a[node][i]] > 0) need[node]++;
        }
    }

    if(need[node] == 0 && special[node] == 1) need[node] = 1;
    ans += need[node] / 2;
}

void Solve()
{
    int n,q,u,v,cnt = 0;
    cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        cin >> u;
        special[i] = u;
        if(u == 1) cnt++;
    }

    for(int i = 1; i < n; i++) {
        cin >> u >> v;
        a[u].pb(v); a[v].pb(u);
    }    

    dfs(1);

    cout << endl;

    int temp = max(ans, 1);
    if(cnt >= 2) cout << max(ans, 1) << endl; else cout << ans << endl;                                                                                                                  
    for(int i = 1; i <= q; i++) {
        cin >> u;
        if(special[u] == 0) {
            //trang sang do
            special[u] = 1;
            cnt++;
            if(need[u] == 0) {
                need[u] = 1;
                need[root[u]]++;
                if(need[root[u]] % 2 == 0) ans++;
            }
        } else {
            //do sang trang
            special[u] = 0;
            cnt--;
            if(need[u] == 1) {
                int ok = 0;
                for(int j = 0; j < a[u].size(); j++) {
                    if(need[a[u][i]] > 0) ok = 1;
                }

                if(!ok) {
                    need[u] = 0;
                    while(root[u] != 0 && need[u] == 0) {
                        u = root[u]; need[u]--;
                    }

                    if(need[u] % 2 == 1) ans--;
                }
            }
        }
        // cout << "With i = " << i << ", so   ";
        // for(int i = 1; i <= n; i++) cout << need[i] << " ";
        // cout << endl; 
        if(cnt >= 2) cout << max(ans, 1) << endl; else cout << ans << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("SOCKS.inp", "r", stdin);
    freopen("SOCKS.out", "w", stdout);

    // long long TestCase;
    // cin >> TestCase;
    // while(TestCase--)
    Solve();
}