/*          _
         __(.)< (cocc)
        \____)
    ~~~~~~~~~~~~~~~~
*/

#include <bits/stdc++.h>

#define FASTCIN ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define DEBUG freopen("_inp.inp", "r", stdin);
#define FILE(name) freopen(name".inp","r", stdin); freopen(name".out", "w", stdout);
#define runTime(num) cout << "\nTime: " << fixed << setprecision(num) << (double)(clock() - time)/CLOCKS_PER_SEC << "s\n";

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, b, a) for (int i = b; i >= a; i--)
#define PB push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define BIT(x) (1LL << (x))
#define GET(S, x) ((S >> x) & 1LL)

#define INF (int)(1e9+7)
#define LLINF (ll)(1e18+7)
#define N (ll)(1e6+1)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int n;
int a[N];

// sub1
int p[N];

void sub1() {
    FOR(i, 1, n) p[i] = i;
    int cnt = 0;
    do {
        int sEven = 0;
        int sOdd = 0;
        int pos = 1;
        FORD(i, n, 1) {
            int cur = a[p[i]];
            while (cur > 0) {
                int digit = cur % 10;
                if (pos % 2 == 1) sOdd += digit;
                else sEven += digit;
                cur /= 10;
                pos++;
            }
        }

        if (abs(sOdd - sEven) % 11 == 0) cnt++;
        //cout << pos << "\n";
    } while (next_permutation(p+1, p+1+n));
    cout << cnt << "\n";
}

int main()
{
    auto time = clock();
    FASTCIN
    //DEBUG
    FILE("GIFT11")

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        FOR(i, 1, n) {
            cin >> a[i];
        }
        if (n <= 8) sub1();
        else cout << 0 << "\n";
    }

    //runTime(5);
    return 0;
}


