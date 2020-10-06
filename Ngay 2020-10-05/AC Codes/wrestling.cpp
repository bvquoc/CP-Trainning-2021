//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "wrestling"
#define maxn 500005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

int a[maxn], pos[maxn], n;
int d[maxn];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        pos[x] = i;
    }
    for (int i = 1; i <= n; i++){
        int u = pos[a[i]] - i;
        if (u < 0) u += n; d[u] ++;
    }
    int xmax = 0, pmax;
    for (int i = 0; i < n; i++)
        if (xmax < d[i]) {
            xmax = d[i]; pmax = i;
        }
    cout << pmax << " " << xmax;
    //cerr << xmax << " " << pmax;
    return 0;
}

