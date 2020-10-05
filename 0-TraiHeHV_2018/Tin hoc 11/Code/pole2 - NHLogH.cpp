//Dai Ca Di Hoc
// O(N*maxh*log2(maxh))
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

long long F[maxn][maxh], L[13][maxh], R[13][maxn];
int n, c[maxn], h[maxn], delta, st[maxh], hmax = 0;

void Calc(long long a[], int c){
    for (int i = 1; i <= hmax; i ++) L[0][i] = a[i] - i * c;
    for (int i = 1; i <= 12; i++)
        for (int u = 1; u + (1<<i) -1 <= hmax; u++)
            L[i][u] = min(L[i-1][u], L[i-1][u+(1<<(i-1))]);

    for (int i = 1; i <= hmax; i ++) R[0][i] = a[i] + i * c;
    for (int i = 1; i <= 12; i++)
        for (int u = 1; u + (1<<i) -1 <= hmax; u++)
            R[i][u] = min(R[i-1][u], R[i-1][u+(1<<(i-1))]);
}

long long GetL(int u, int v){
    int k = log2(v-u+1);
    return min(L[k][u], L[k][v-(1<<k)+1]);
}

long long GetR(int u, int v){
    int k = log2(v-u+1);
    return min(R[k][u], R[k][v-(1<<k)+1]);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> delta;
    for (int i = 1; i < n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> h[i], hmax = max(hmax, h[i]);
    for (int i = 1; i <= hmax; i++)F[0][i] = 0;
    memset(F, 58, sizeof(F));
    for (int j = h[1]; j <= hmax; j ++) F[1][j] = (j-h[1]) * (j-h[1]);

    for (int i = 2; i <= n; i++) {
        Calc(F[i-1], c[i-1]);
        for (int j = h[i]; j <= hmax; j++){
            int le = max(1, j-delta);
            int ri = min(hmax, j+delta);
            F[i][j] = min(GetL(le,j) + c[i-1] * j, GetR(j,ri) - c[i-1]*j);
            F[i][j] += (j-h[i]) * (j-h[i]);
        }
    }
    cout << *min_element(F[n], F[n] + hmax + 1);
    return 0;
}

