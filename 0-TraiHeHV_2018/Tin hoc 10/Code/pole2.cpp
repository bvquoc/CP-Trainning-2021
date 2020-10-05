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

long long F[maxn][maxh], L[maxh], R[maxn];
int n, c[maxn], h[maxn], delta, st[maxh], hmax = 0;

void Calc(long long a[], int c){
    int top = 0, bot = 1;
    for (int i = 1; i <= hmax; i++){
        long long cur = a[i] - c * i;
        while (top >= bot && cur <= a[st[top]] - st[top] * c) top --;
        st[++top] = i;
        if (i-st[bot] > delta) bot++;
        L[i] = a[st[bot]] - st[bot] * c;
    }

    top = 0, bot = 1;
    for (int i = hmax; i ; i--){
        long long cur= a[i] + c * i;
        while (top >= bot && cur <= a[st[top]] + st[top] * c) top --;
        st[++top] = i;
        if (st[bot] - i > delta) bot++;
        R[i] = a[st[bot]] + st[bot] * c;
    }
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
    memset(F, 60, sizeof(F));
    for (int j = h[1]; j <= hmax; j ++) F[1][j] = (j-h[1]) * (j-h[1]);
    for (int i = 2; i <= n; i++) {
        Calc(F[i-1], c[i-1]);
        for (int j = h[i]; j <= hmax; j++)
            F[i][j] = min(L[j] + c[i-1] * j, R[j] - c[i-1]*j) + (j-h[i]) * (j-h[i]);
    }
    cout << *min_element(F[n], F[n] + hmax + 1);
    cerr << *min_element(F[n], F[n] + hmax + 1) << " -------- ";
    return 0;
}

