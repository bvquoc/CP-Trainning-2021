//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
//#define F first
#define S second
#define Task "pole"
#define maxn 10005
#define maxh 1005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

long long F[maxn][maxh], Low[maxn][maxh], High[maxn][maxh];
int n, c, h[maxn], hmax = 0;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> c;
    memset(F, 58, sizeof(F));
    for (int i = 1; i <= n; i++) cin >> h[i], hmax = max(hmax, h[i]);
    for (int j = h[1]; j <= hmax; j ++) F[1][j] = (j-h[1]) * (j-h[1]);
    for (int i = 2; i <= n; i++) {
        Low[i-1][0] = High[i-1][hmax+1] = 1e18;
        for (int j = 1; j <= hmax; j++) Low[i-1][j] = min(Low[i-1][j-1], F[i-1][j] - j*c);
        for (int j = hmax; j; j--) High[i-1][j] = min(High[i-1][j+1], F[i-1][j] + j*c);

        for (int j = h[i]; j <= hmax; j++)
            F[i][j] =  min(Low[i-1][j] + j * c, High[i-1][j] - j*c) + (h[i] - j) * (h[i] - j);
    }
    cout << *min_element(F[n], F[n] + hmax + 1);
    return 0;
}

