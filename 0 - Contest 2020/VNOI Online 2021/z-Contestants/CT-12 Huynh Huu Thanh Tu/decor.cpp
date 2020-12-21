#include <bits/stdc++.h>
using namespace std;

#define oo 1000000007
#define maxN 500010
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

int n, m, k, a[maxN];

void solve1() {
    int l = 0, r = 0, ans = 0, l_ans, r_ans;

    a[0] = a[n+1] = 0;
    fto(i, 1, n+1) {
        if (a[i] && a[i-1]) ++r;
        else {
            if (ans < r - l + 1) {
                ans = r - l + 1;
                l_ans = l;
                r_ans = r;
            }
            if (a[i]) l = r = i;
            else l = r = 0;
        }
    }

    cout << l_ans << " " << r_ans;
}

void solve2() {
    int cnt = 0, l=1, ans = 0, l_ans, r_ans;
    fto(i, 1, n) {
        if (a[i] == 0) ++cnt;

        if (cnt > k) {
            while(cnt > k) {
                if (a[l] == 0) --cnt;
                ++l;
            }
        }

        if (ans < i - l + (l > 0)) {
            ans = i - l + 1;
            l_ans = l;
            r_ans = i;
        }
        //cout << i << " " << ans << " " << l_ans << " " << r_ans << endl;
    }

    cout << l_ans << " " << r_ans;
}

int main() {
    freopen("decor.inp", "r", stdin);
    freopen("decor.out", "w", stdout);

    scii(n, m); sci(k);
    fto(i, 1, n) {
        char c; cin >> c;
        a[i] = c - '0';
        //cout << a[i] << " ";
    }

    if (m == 0) {
        if (k == 0) solve1();
        else solve2();
    }
    else cout << -1 << endl;

    return 0;
}


