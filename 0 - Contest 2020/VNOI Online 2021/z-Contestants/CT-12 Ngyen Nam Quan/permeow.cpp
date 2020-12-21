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
#define maxN 200005

using namespace std;

int n, a[maxN], b[maxN];

int main() {
    freopen("permeow.inp", "r", stdin);
    freopen("permeow.out", "w", stdout);

    cin >> n;

    fto(i, 1, n) cin >> a[i];

    fto(i, 1, n) cin >> b[i];
    
    int ans = 0;

    a[n+1] = oo;
    fdto(i, n, 1) {
        if(a[i] > a[i+1]) {
            int j = i;
            while(a[j] > a[j+1]) {
                ans = (ans + 1) % oo;
                swap(a[j], a[j+1]);
                ++j;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}