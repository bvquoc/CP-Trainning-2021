#include <bits/stdc++.h>
#define Task "COOLMAC"
#define F first
#define S second

using namespace std;

const int maxn = 100005;

int m, n;
pair<int, int> a[maxn];
int t[maxn], ans = 2e9, L, R;
int Q[maxn], bot = 1, top = 0;

bool comp(pair<int, int> a, pair<int, int> b) {
    if(a.S != b.S) return a.S < b.S;
    return a.F > b.F;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> m;
    for(int i = 1; i <= m; ++ i) cin >> a[i].F >> a[i].S;
    sort(a + 1, a + m + 1, comp);
    cin >> n;
    for(int i = 1; i <= n; ++ i) cin >> t[i];
    sort(t + 1, t + n + 1);
    L = t[1], R = 100000;
    for(int i = 1; i <= m; ++ i) {
        if(a[i].S < L || a[i].S == a[i - 1].S) continue;
        while(top > bot && a[Q[top - 1]].S >= a[i].F) top --;
        if(top && a[i].F <= a[Q[top]].S) Q[++ top] = i;
        else if(!top) Q[++top] = i;
        while(top > bot && a[Q[bot + 1]].F <= L) ++ bot;
    }
    if(a[Q[bot]].F <= L && R <= a[Q[top]].S) ans = top - bot + 1;
    else ans = -1;
    cout << ans;
}
