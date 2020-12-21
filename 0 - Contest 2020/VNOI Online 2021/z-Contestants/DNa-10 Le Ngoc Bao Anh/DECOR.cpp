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

char a[maxN];
vector<int> adj[maxN];
int dp[maxN];
int n, m, k;

void solvesub1()
{
    int ans = 0, l = 0, r = 0, cnt = 0, lans = 0, rans = 0;
    if(a[1] == '1') cnt = 1, l = 1, r = 1; else cnt = 0;
    for(int i = 2; i <= n; i++) {
        if(a[i] == '1' && a[i - 1] == '0') {
            cnt = 1; l = i; r = i;
        }
        if(a[i] == '0' && a[i - 1] == '1') {
            if(ans < cnt) {
                lans = l; rans = r;
                ans = cnt;
            } 
            cnt = 0;
        }

        if(a[i] == '1' && a[i - 1] == '1') {
            cnt++;
            r++;
        }

        if(a[i] == '0' && a[i - 1] == '0') {
            cnt = 0; l = 0; r = 0;
        }
    }

    if(ans < cnt) {
        ans = cnt;
        lans = l;
        rans = r;
    }  

    if(lans == 0 && rans == 0) {
        cout << -1;
        return ;
    }
    cout << lans << " " << rans << endl;
}

void solvesub2()
{
    int ans = 0,lans = 0,rans = 0; dp[0] = 0;
    for(int i = 1; i <= n; i++) dp[i] = dp[i - 1] + (a[i] == '1');
    for(int i = 1; i <= n; i++) {
        int l = i, r = n;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(dp[mid] - dp[i - 1] + k >= mid - i + 1) {
                if(ans < mid - i + 1) {
                    ans = mid - i + 1;
                    lans = i; rans = mid;
                }
                l = mid + 1;
            } else r = mid - 1;
        }
    }

    if(lans == 0 && rans == 0) {
        cout << -1;
        return;
    }
    cout << lans << " " << rans;
}

void Solve()
{
    int u,v;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) {
        cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }

    if(m == 0 && k == 0) {
        solvesub1();
        return;
    }

    if(m == 0) {
        solvesub2();
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("DECOR.inp", "r", stdin);
  freopen("DECOR.out", "w", stdout);

    // long long TestCase;
    // cin >> TestCase;
    // while(TestCase--)
    Solve();
}
