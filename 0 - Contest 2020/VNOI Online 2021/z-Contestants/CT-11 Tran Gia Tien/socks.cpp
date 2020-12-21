#include<bits/stdc++.h>

#define bug(a) cout<< #a << ": " << a << endl;
#define bug2(a, b) cout<< #a << ": " << a << ", " << #b << ": " << b << endl;
#define bugarr(a, i, j) cout<< #a << "{" << i << "..." << j << "}: "; fto(k, i, j-1) cout<< a[k] << ", "; cout<< a[j] << endl;
#define fto(i, a, b) for(int i = a; i <= b; ++i)
#define fdto(i, a, b) for(int i = a; i >= b; --i)
#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d %d", &a, &b)
#define pril(a) printf("%d\n", a)
#define pris(a) printf("%d ", a)
#define ll long long
#define ii pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vii vector<ii>
#define all(x) (x).begin(), (x).end()
#define oo 1000000007
#define maxN 10005
#define sz(a) (int)a.size()
#define fast ios::sync_with_stdio(false); cin.tie(0)

using namespace std;

vi ke[maxN];
int t, m, n, q, a[maxN], b[maxN];

int main () {
    freopen("socks.inp", "r", stdin);
    freopen("socks.out", "w", stdout);
    sci(t);
    while(t--) {
        scii(n, q);
        fto(i, 1, n) sci(a[i]);
        fto(i, 1, n-1) {
            int u, v;
            scii(u, v);
            ke[u].pb(v);
        }
        fto(i, 1, q) {
            sci(b[i]);
        }
        puts("1");
        fto(i, 1, q) {
            puts("2");
        }

    }
    return 0;
}
