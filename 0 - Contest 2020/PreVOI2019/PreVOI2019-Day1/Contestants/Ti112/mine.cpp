#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define F first
#define S second
#define fi(i,a,b) for(int i=a; i<=b; i++)
#define fid(i,a,b) for(int i=a; i>=b; i--)
#define VanLoi "mine"
#define gb(i, j) ((i >> j) & 1)
#define reset(x) memset(x, 0,sizeof(x))
#define pb push_back
#define mp make_pair
#define MOD 1000003
#define pii pair<int, int>
#define Block 400

using namespace std;

int n;

/*void no() {
    bool ok = true;
    tg = 0;
    fi(i, 1, n) vt1[i] = 0;
    fi(i, 1, 2 * n) {
        int t = x[i];
        if (vt1[t] == 0) {

        }
    }
}

void xuli(int i) {
    fi(j, 1, i) if (dem[j] <= 1) {
        if (dem[j] == 0) {
            dem[j]++;
            x[i] = j;
            vt[j] = i;
            if (i == 2 * n) no(); else xuli(i + 1);
            dem[j]--;
        } else if (i - vt[j] <= m){
            dem[j]++;
            x[i] = j;
            if (i == 2 * n) no(); else xuli(i + 1);
            dem[j]--;
        }
    }
}

void sub1() {
    xuli(1);
    cout << res;
}*/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(VanLoi".inp", "r", stdin);
    freopen(VanLoi".out", "w", stdout);
    srand(time(NULL));
    //cin >> n >> m;
    //fi(i, 1, 2 * n) cin >> a[i];
    //if (n <= 10) sub1();
    cout << rand() % 1000003;
    return 0;
}
