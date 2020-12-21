#include <iostream>
#include <bits/stdc++.h>
#define FORU(i , a , b) for (int i = (a) ; i <= (b) ; i++)
#define FORD(i , a , b) for (int i = (a) ; i >= (b) ; i--)
#define pii pair <int , int>
#define fi first
#define se second
#define task "COOLMAC"
#define oo (int)1e9
using namespace std;
const int maxn = 1e5 + 1;
bool flag = 0;
int n , m , lower = maxn - 1;
pair <int , int> a[maxn];
void input()
{
    cin >> m;
    FORU(i , 1 , m) cin >> a[i].fi >> a[i].se;
    cin >> n;
    FORU(i , 1 , n)
    {
        int x;
        cin >> x;
        lower = min(lower , x);
    }
}
bool cmp(pii a , pii b)
{
    return a.se > b.se;
}
void solve()
{
    sort(a + 1 , a + 1 + m , cmp);
    priority_queue <int , vector <int> , greater<int>> q;
    int i = 1 , current = maxn - 1 , res = 0;
    while (!flag)
    {
        while (a[i].se >= current - 1 && i <= m) {
            q.push(a[i].fi);
            i++;
        }
        if ((!q.empty() && q.top() >= current) || q.empty()){
            cout << -1;
            return;
        }
        else{
            res++;
            current = q.top();
            q.pop();
            if (current <= lower) flag = 1;
        }
    }
    if (flag) cout << res;
    else cout << -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp" , "r" , stdin);
    freopen(task".out" , "w" , stdout);
    input();
    solve();
    return 0;
}
