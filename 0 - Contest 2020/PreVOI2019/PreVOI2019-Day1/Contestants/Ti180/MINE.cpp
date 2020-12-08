// Nguyen Anh Tu
#include <bits/stdc++.h>
#define FOR(x,a,b) for(int x=a;x<=b;x++)
#define FORD(x,a,b) for(int x=a;x>=b;x--)
#define maxn 100005
#define maxc 1000000007
#define MOD 1000000007
#define reset(x,y) memset(x,y,sizeof(x))
#define task "MINE"
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define ll long long
#define bit(p,x) ((x>>p) & 1)
#define remain(a,b) (a+b >= MOD) ? (a+b - MOD) : (a+b)

using namespace std;
int n,m,a[maxn],L[maxn],R[maxn],dd[maxn];
int ans = 0;
bool check()
{
    for(int i=1; i<=n; ++i)
    {
        if(L[i] < L[i-1]) return false;
        if(R[i-1] > L[i] && R[i] > R[i-1]) return false;
        if(a[R[i]] - a[L[i]] > m) return false;
    }
    return true;
}
void Solve(int x)
{
    L[x] = maxc;
    R[x] = 0;
    if(x == n)
    {
        for(int i=1; i<=2*n; ++i)
        {
            if(!dd[i])
            {
                L[x] = min(L[x],i);
                R[x] = max(R[x],i);
            }
        }
            if(check()) ans ++;
            return;
    }
    int k;
    for(int i=x; i<=x+x-1; ++i)
    {
        if(!dd[i])
        {
            k = i;
            break;
        }
    }
    dd[k] = 1;
    L[x] = k;
    for(int i=k+1; i<=2*n; i+=2)
    {
        if(!dd[i])
        {
            R[x] = i;
            dd[i] = x + 1;
            Solve(x+1);
            dd[i] = 0;
        }
    }
    dd[k] = 0;
}
int main()
{
    #ifndef ONLINE_JUDGE
    ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    #endif
    cin >> n >> m;
    for(int i=1; i<=2*n; ++i) cin >> a[i];
    dd[1] = 1;
    L[1] = 1;
    for(int i=2; i<=2*n; i+=2)
    {
        if(a[i] - a[1] > m) break;
        dd[i] = 1;
        R[1] = i;
        Solve(2);
        dd[i] = 0;
    }
    cout << ans;
}
