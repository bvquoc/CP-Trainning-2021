//LAM SAI ROIIIIIIIIII

#include <bits/stdc++.h>
using namespace std;

#define oo 1000000007
#define maxN 200010
#define fto(i,a,b) for (int i=a; i<=b; ++i)
#define fdto(i,a,b) for (int i=a; i>=b; --i)
#define sci(a) scanf("%d", &a)
#define scii(a,b) scanf("%d%d", &a, &b)
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(a) (int)a.size()
#define mod 1000000007

int n, a[maxN], b[maxN], a_tmp[maxN], b_tmp[maxN];

int main() {
    freopen("permeow.inp", "r", stdin);
    freopen("permeow.out", "w", stdout);

    sci(n);
    fto(i, 1, n) {sci(a[i]); a_tmp[i] = a[i];}
    fto(i, 1, n) {sci(b[i]); b_tmp[i] = b[i];}

    sort(a_tmp+1, a_tmp+n+1);
    sort(b_tmp+1, b_tmp+n+1);

    ll ans_a = 0, ans_b = 0;
    fto(i, 1, n) if (a[i] != a_tmp[i]) ++ans_a;
    fto(i, 1, n) if (b[i] != b_tmp[i]) ++ans_b;

    ll ans = abs((ans_a * (ans_a+1)) % mod - (ans_b * (ans_b+1)) % mod);

    if (ans) --ans;
    cout << ans;

    return 0;
}


