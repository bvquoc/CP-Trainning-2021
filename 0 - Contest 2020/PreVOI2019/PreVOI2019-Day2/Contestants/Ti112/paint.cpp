#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define F first
#define S second
#define fi(i,a,b) for(int i=a; i<=b; i++)
#define fid(i,a,b) for(int i=a; i>=b; i--)
#define VanLoi "paint"
#define gb(i, j) ((i >> j) & 1)
#define reset(x) memset(x, 0,sizeof(x))
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int, int>
#define Block 400

using namespace std;

int n, a[maxn], mi = 0;

void sub1() {
    a[0] = 1;
    fi(j, 1, n) {
        int x;
        char y, z;
        cin >> x;
        if (x == 1) {
            cin >> y;
            while (a[mi] != 0) mi++;
            a[mi] = y - 'a' + 1;
        }
        if (x == 2) {
            cin >> y >> z;
            if (y != z) {
                int tg = y - 'a' + 1, tg1 = z - 'a' + 1;
                fi(i, 1, mi) if (a[i] == tg) a[i] = tg1;
            }
        }
    }
    fi(i, 1, mi) cout << char(a[i] - 1 + 'a');
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(VanLoi".inp", "r", stdin);
    freopen(VanLoi".out", "w", stdout);
    cin >> n;
    sub1();
    return 0;
}
