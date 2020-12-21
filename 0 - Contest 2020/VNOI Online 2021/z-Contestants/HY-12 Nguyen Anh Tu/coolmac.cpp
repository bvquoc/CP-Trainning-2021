#include <bits/stdc++.h>
#define maxn 100005
#define maxc 1000000007
#define MOD 1000000007
#define task "coolmac"
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define ll long long
#define bit(p,x) ((x>>p) & 1)
using namespace std;

int n, m;
pii a[maxn];
int l = maxc;

int main()
{
    ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; ++ i){
        cin >> a[i].F >> a[i].S;
    }
    cin >> m;
    for(int i = 1; i <= m; ++ i){
            int x;
        cin >> x;
        l = min(l, x);
    }
    sort(a + 1, a + n + 1, [](pii a, pii b){
            return a.S < b.S;
         });
    deque<int> q;
    q.pb(0);
    a[0] = {0, l};
    int ans = maxc;
    for(int i = 1; i <= n; ++ i){
        if(a[i].S < l || (q.size() && a[q.back()].S < a[i].F)) continue;
        while(q.size() && a[q.back()].F >= a[i].F) q.pop_back();
        while(q.size() && l >= a[i].F && l <= a[i].S) q.pop_back();
        q.pb(i);
        if(a[i].S == 100000){
            ans = min(ans, (int)q.size());
        }
    }
    cout << ((ans == maxc) ? - 1: ans);
    return 0;
}
