//DinoFromMar
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define fi first
#define se second
#define Task "CONSTRUCT"
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define ll long long

using namespace std;

int T;
int m, n;
int a[maxn];
int h[maxn];
int ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
   cin >> T;
   while(T--)
   {
       cin >> n >> m;
       for(int i = 1; i <= n; i++)
        cin >> a[i];

        while(m--)
        {
            int type, l, r;
            cin >> type >> l >> r;
            if(type == 1)
            {
                int x;
                cin >> x;
                h[l]+=x;
                h[r+1]-=x;
            }
            if(type == 2)
            {
//                cout << 1 <<"\n";
                for(int i = 1; i <= n; i++)
                    h[i] += h[i-1], a[i] += h[i], h[i - 1]= 0;
                h[n] = 0;
                int mi = a[l];
                ans = a[l];
                for(int i = l + 1; i <= r; i++)
                {
                if(a[i] > a[i-1] && a[i] >= a[i+1])
                    ans += a[i] - min(a[i-1], a[i+1]);
//                if(a[i] > a[i-1])
                }

           cout << ans << "\n";
            }
        }
   }

   return 0;
}

