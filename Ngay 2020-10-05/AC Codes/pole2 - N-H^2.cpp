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
#define Task "pole2"
#define maxn 4005
#define maxh 4005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

long long F[maxn][maxh], Low[maxn][maxh], High[maxn][maxh];
int n, c[maxn], h[maxn], delta;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> delta;
    for (int i = 1; i < n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i < maxh; i++)F[0][i] = 0;
    memset(F, 58, sizeof(F));
    for (int j = h[1]; j <= maxh; j ++) F[1][j] = (j-h[1]) * (j-h[1]);
    for (int i = 2; i <= n; i++) {
        for (int j = h[i]; j < maxh; j++){
            for (int k = max(j-delta, h[i-1]); k <= min(j+delta, maxh-1); k++)
                F[i][j] = min(F[i][j], F[i-1][k] + c[i-1] * abs(j-k));
             F[i][j] += (j-h[i]) * (j-h[i]);
        }
    }
    cout << *min_element(F[n], F[n] + 1001);
    return 0;
}

