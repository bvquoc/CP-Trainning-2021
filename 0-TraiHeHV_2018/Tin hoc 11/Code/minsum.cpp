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
#define Task "minsum"
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

int n, k;
long long a[52];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> k;
    while (n--){
        for (int i = 1; i <= k; i++) cin >> a[i];
        sort(a+1, a+k+1);
        if (a[1] * a[k] > a[2] * a[k-1]) cout << a[2] << " " << a[k] << " " << a[1] << " " << a[k-1] << "\n";
        else cout <<  a[1] << " " << a[k-1] << " " << a[2] << " " << a[k] << " " <<"\n";
    }
    return 0;
}

