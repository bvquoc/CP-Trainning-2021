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
int b[N];
int pos[N];
int tmp[N];

int p[N];
void makePermu() {
    FOR(i, 1, n) {
        p[i] = i;
    }
    do {
        FOR(i, 1, n) cout << p[i] << ' ';
        cout << "\n";
    } while (next_permutation(p+1, p+1+n));
}

void sub1() {
    ll res = 0;
    FORD(i, n, 1) {
        //cout << pos[i] << ' ';
        FOR(j, pos[i] + 1, n) {
            //cout << i << ' ' << a[j] << "\n";
            if (a[j] < i) {
                //cout << a[j] << ' ' << i << "\n";
                res++;
            }
        }
        //tmp[pos[i]] = 0;
    }
    cout << res;
}

int main()
{
    auto time = clock();
    FASTCIN
    //DEBUG
    FILE("PERMEOW")

    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i];
        pos[a[i]] = i;
        tmp[i] = 1;
    }
    FOR(i, 1, n) cin >> b[i];
    int ok = 1;
    FOR(i, 1, n) if (a[i] != b[i]) {
        ok = 0;
        break;
    }
    //makePermu();
    if (ok) sub1();
    else cout << ":((\n";

    //runTime(5);
    return 0;
}


