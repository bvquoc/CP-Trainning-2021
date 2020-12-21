#include <bits/stdc++.h>
using namespace std;

#define oo 1000000007
#define maxN 100010
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

int n, m, val = oo, day[maxN], ans;
ii cool[maxN];
priority_queue<ii, vii> q;

int solve() {
    int mx = 0, mn = 0, mn_tmp;
    while(!q.empty()) {
        int l = -q.top().ss, r = q.top().ff;
        q.pop();

        //cout << l << " "<< r << endl;
        if (mx == 0 && mn == 0) {
            mx = r; mn = mn_tmp = l;
            if (mx < 100000) return 0;

            ++ans;
            continue;
        }
        if (l > mn_tmp) continue;

        //cout << mn_tmp << endl;
        if (r <= mn_tmp) {
            mn = mn_tmp;

            if (r < mn) return 0;

            ++ans;
            mn_tmp = l;
        }
        else mn_tmp = min(mn_tmp, l);

        //cout << mn << " " << mx << " " << mn_tmp << endl;
        if (mn <= val) return 1;
    }

    if (mn != mn_tmp) {
        mn = mn_tmp;
        ++ans;
    }

    if (mn <= val) return 1;
    return 0;
}

int main() {
    freopen("coolmac.inp", "r", stdin);
    freopen("coolmac.out", "w", stdout);

    sci(m);
    fto(i, 1, m) {
        scii(cool[i].ff, cool[i].ss);
        q.push(mp(cool[i].ss, -cool[i].ff));
    }

    sci(n);
    fto(i, 1, n) {
        sci(day[i]);
        val = min(val, day[i]);
    }

    if (solve()) cout << ans;
    else cout << -1;

    return 0;
}


