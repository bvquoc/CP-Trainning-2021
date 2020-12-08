#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define F first
#define S second
#define fi(i,a,b) for(int i=a; i<=b; i++)
#define fid(i,a,b) for(int i=a; i>=b; i--)
#define VanLoi "construct"
#define gb(i, j) ((i >> j) & 1)
#define reset(x) memset(x, 0,sizeof(x))
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int, int>
#define Block 400

using namespace std;

ll n, T, m, a[maxn];

ll tinh(int L, int R) {
    ll tong = a[L];
    fi(i, L + 1, R) {
        if (a[i] >= a[i - 1]) tong += a[i] - a[i - 1];
    }
    return tong;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(VanLoi".inp", "r", stdin);
    freopen(VanLoi".out", "w", stdout);
    cin >> T;
    fi(z, 1, T) {
        cin >> n >> m;
        fi(i, 1, n) cin >> a[i];
        fi(y, 1, m) {
            int x, L, R, t;
            cin >> x >> L >> R;
            if (x == 1) {
                cin >> t;
                fi(i, L, R) a[i] += t;
            } else {
                cout << tinh(L, R) << '\n';
            }
        }
    }
    return 0;
}
