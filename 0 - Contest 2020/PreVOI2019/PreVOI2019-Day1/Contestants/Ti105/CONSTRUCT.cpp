#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 4004
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x>>i)&1)
#define debug4(i,j,k,l) cerr << i << ' ' << j << ' ' << k << ' ' << l << '\n';
#define debug3(i,j,k) cerr << i << ' ' << j << ' ' << k << '\n';
#define debug2(i,j) cerr << i << ' ' << j<< '\n';
#define debug1(i) cerr << i << '\n';
using namespace std;

int t,n,m;
ll a[maxn];

int main()
{
    fast_read;
    freopen("CONSTRUCT.inp","r",stdin);
    freopen("CONSTRUCT.out","w",stdout);
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        For(i,1,n)
            cin >> a[i];
        For(i,1,m)
        {
            int type,l,r,k;
            cin >> type >> l >> r;
            if(type == 1)
            {
                cin >> k;
                For(j,l,r) a[j] += k;
            }
            else
            {
                ll ans = 0,cur = 0;
                For(i,l,r)
                {
                    if(a[i] > cur)
                        ans = ans + (a[i] - cur);
                    cur = a[i];
                }
                cout << ans << endl;
            }
        }
    }
}
