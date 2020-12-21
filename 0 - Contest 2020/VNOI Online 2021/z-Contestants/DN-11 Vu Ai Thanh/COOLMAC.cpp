// i'm wutan
#include <bits/stdc++.h>
#define io_faster ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define EL cout<<'\n'
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fi first
#define se second
#define sz(a) int(a.size())
#define FU(x,a,b) for(int x=int(a);x<=int(b);x++)
#define FD(x,a,b) for(int x=int(a);x>=int(b);x--)
#define PROB "COOLMAC"

using namespace std;
typedef long long ll;
typedef double db;

void file(){
    freopen(PROB".inp","r",stdin);
    freopen(PROB".out","w",stdout);
}

const int N = 1e5 + 2;
int n, m, L;
pii a[N];

void readinp(){
    cin >> n;
    FU(i, 1, n) cin >> a[i].fi >> a[i].se;
    cin >> m; L = 1e9;
    FU(i, 1, m) {
        int t; cin >> t;
        L = min(L, t);
    }
}

void solve(){
    sort(a + 1, a + 1 + n);
    int temp = n; n = 0;
    FU(i, 1, temp) if (a[i].se >= L) a[++n] = a[i];
    int res = 0;
    priority_queue < int > Q;
    FU(i, 1, n){
        if (a[i].fi <= L) Q.push(a[i].se);
        else{
            if (Q.empty()) {
                cout << -1;
                return;
            }
            L = Q.top(); Q.pop();
            res++;
            if (L >= 1e5) break;
            if (a[i].fi <= L) Q.push(a[i].se);
        }
        while (!Q.empty() && Q.top() <= L) Q.pop();
    }
    if (L < 1e5){
        if (Q.empty()){
            cout << -1;
            return;
        }
        if (Q.top() < 1e5){
            cout << -1;
            return;
        }
        res++; L = Q.top(); Q.pop();
    }
    cout << res;
}

int main(){
    io_faster
    file();
    int t = 1;
//    cin >> t;
    while (t--){
        readinp();
        solve();
    }
}


