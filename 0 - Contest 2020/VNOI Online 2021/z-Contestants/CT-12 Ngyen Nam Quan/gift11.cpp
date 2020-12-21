#include<bits/stdc++.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define pri(a) printf("%d ", a)
#define pril(a) printf("%d\n", a)
#define fto(i, a, b) for(int i = a; i <= b; ++i)
#define fdto(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define pb push_back
#define sz(a) (int)a.size()
#define pi pair<int, int>
#define ff first
#define sd second
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define oo 1000000007
#define mod 998244353
#define maxN 2005

using namespace std;

int T, n;
map<int, int> dp[2005][2];
string a[maxN];
ll ans;

void duyet() {
    vi hv;
    fto(i, 1, n) hv.pb(i);
    do {
        string s;
        fto(i, 0, sz(hv)-1) s += a[hv[i]];
        int c = 0, l = 0;
        fto(i, 0, sz(s)-1) {
            if((i+1) & 1) l += s[i] - '0';
            else c += s[i] - '0'; 
        }
        if((l - c) % 11 == 0) ans = (ans + 1) % mod; 
    } while(next_permutation(hv.begin(), hv.end()));
}

void solveS1() {
    duyet();
    cout << ans << "\n";
}

void solveS2() {
    int c = 0, l = 0;
    fto(i, 1, n) {
        fto(j, 0, sz(a[i])-1) {
            if((j+1) & 1) l += a[i][j] - '0';
            else c += a[i][j] - '0';
        }
    }

    if((l - c) % 11 == 0) {
        ans = 1;
        fto(i, 1, n) ans = ans * i % mod;
        cout << ans << "\n";
    } else cout << 0 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("gift11.inp", "r", stdin);
    freopen("gift11.out", "w", stdout);

    cin >> T;
    while(T--) {
        cin >> n;
        bool T2 = 1;
        fto(i, 1, n) {
            cin >> a[i];
            if(sz(a[i]) & 1) T2 = 0;
        }
        
        ans = 0;

        if(n <= 8) {solveS1(); continue;}
        if(T2) {solveS2(); continue;}

        cout << ans << "\n";
        continue;
    }

    return 0;
}