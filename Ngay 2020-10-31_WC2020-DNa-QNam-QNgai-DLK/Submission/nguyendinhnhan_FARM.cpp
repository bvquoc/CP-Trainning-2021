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

int n, k, q, p, a[20000], f[2000][2000];

int trau(int pos, int cnt_hat)
{
    if(pos > n) return 0;

    int &res = f[pos][cnt_hat];
    if(res != -1) return res;
    res = -INF;

    res = max(res, trau(pos + 1, cnt_hat));

    for(int i = 1; i <= min(p, cnt_hat); i++)
    {
        res = max(res, trau(pos + k, cnt_hat - i) + i * a[pos]);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    #endif // djxone123456

    cin >> n >> k >> q >> p;

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    memset(f, 255, sizeof(f));

    cout << trau(1, q);

    return 0;
}
