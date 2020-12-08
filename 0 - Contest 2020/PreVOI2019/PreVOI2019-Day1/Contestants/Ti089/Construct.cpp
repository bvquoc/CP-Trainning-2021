#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define nmax 500005
#define MOD 1000000007
#define pii pair<long long, long long>
#define ll long long
#define Task "Construct"
#define sqr(x) (x) * (x)
#define For(i,x,y) for(int i=x; i <= y ; i++)
#define oo
using namespace std;
int n , m  , u , v , k , t;
ll a[nmax];
void build()
{
    cin >> u >> v >> k;
    For(i , u , v)
        a[i] += 1ll*k ;
}
void querry()
{
    cin >> u >> v;
    int res = 0;
    For( i , u + 1 , v)
        res += max(1ll*0, a[i] - a[i-1]);
    res += a[u];
        cout << res << endl;
}
void enter()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        a[0]=0;
        For(i , 1 , n)
            cin >> a[i];
        int d;
        For(i , 1 , m)
        {
            cin >>d;
            if(d==1)
                build();
            if(d == 2)
                querry();
        }
    }

}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    enter();
    }
