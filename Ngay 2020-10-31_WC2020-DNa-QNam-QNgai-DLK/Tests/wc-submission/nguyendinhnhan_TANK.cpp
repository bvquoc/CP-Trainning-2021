/// Author: djxone123456(Mong u)

#include<bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi pair<int, int>
#define pii pair<pi, int>
#define Task "debug"
#define MOD 1000000007
#define INF INT_MAX
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double db;

ll n, m;
ll a[100006];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    #endif // djxone123456

    cin >> m >> n;

    a[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = a[i - 1] + a[i];
    }

    for(int i = 1; i <= n; i++)
    {
        int ok = 1;
        for(int j = 1; j <= n - i + 1; j++)
        {
            if(a[j + i - 1] - a[j - 1] < m)
            {
                ok = 0;
                break;
            }
        }

        if(ok)
        {
            cout << i;
            return 0;
        }
    }

    return 0;
}
