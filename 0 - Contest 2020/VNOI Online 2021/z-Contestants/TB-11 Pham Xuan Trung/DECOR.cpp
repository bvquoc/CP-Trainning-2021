#include <bits/stdc++.h>
#define pii pair<int , int>
#define fi first
#define se second
using namespace std;
const int N = (int)5e5+1;
int n , m , k , a[N];
pii way[N];
char s;
void inp()
{
    cin >> n >> m >> k;
    for(int i=1 ; i<=n ; ++i)
    {
        cin >> s;
        a[i] = (int)s-48;
    }
    for(int i=1 ; i<=m ; ++i) cin >> way[i].fi >> way[i].se;
}
void subtask1_2()
{
    int p1 , p2 , best = 0;
    for(int i=1 ; i<=n ; ++i) a[i]+=a[i-1];
    for(int i=1 ; i<=n ; ++i)
    {
        int L = 0 , R = n-i+1 , l = 0;
        while(L <= R)
        {
            int mid = (L+R)/2;
            if(mid - (a[i+mid-1] - a[i-1]) <= k)
            {
                l = mid;
                L = mid+1;
            }
            else R = mid-1;
        }
        if(l > best)
        {
            best = l;
            p1 = i , p2 = i+l-1;
        }
    }
    if(best == 0) cout << -1;
    else cout << p1 << " " << p2;
}
int pa[N] , cnt[N] , Save[N];
int getpa(int u)
{
    if(pa[u] != u) pa[u] = getpa(pa[u]);
    return pa[u];
}
void join(int x , int y)
{
    int u = getpa(x);
    int v = getpa(y);
    if(u == v) return;
    pa[u] = v , Save[v]+=Save[u];
}
int Last[N] , used[N];
void subtask4()
{
    for(int i=1 ; i<=n ; ++i) pa[i] = i , Save[i] = a[i];
    for(int i=1 ; i<=m ; ++i) join(way[i].fi , way[i].se);
    for(int i=1 ; i<=n ; ++i) pa[i] = getpa(i) , cnt[i] = Save[i];
    int best = 0 , p1 , p2;
    for(int i=1 ; i<=n ; ++i)
    {
        Last[i] = Last[i-1];
        for(int j=max(Last[i-1]+1 , i) ; j<=n ; ++j)
        {
            if(cnt[pa[j]]) cnt[pa[j]]--;
            else
            {
                if(k)
                {
                    --k;
                    used[pa[j]]++;
                }
                else break;
            }
            Last[i] = j;
        }
        if(Last[i] - i + 1 > best)
        {
            best = Last[i]-i+1;
            p1 = i , p2 = Last[i];
        }
        if(used[pa[i]]) ++k , used[pa[i]]--;
        else cnt[pa[i]]++;
    }
    if(best == 0) cout << -1;
    else cout << p1 << " " << p2;
}
int getSubtask()
{
    if(m == 0) return 1;
    return 4;
}
void solve()
{
    int st = getSubtask();
    if(st == 1) subtask1_2();
    else subtask4();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DECOR.INP" , "r" , stdin);
    freopen("DECOR.OUT" , "w" , stdout);
    inp();
    solve();
    return 0;
}
