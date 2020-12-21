#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define fr first
#define sc second
#define PROBLEMS            "coolmac"
ifstream fi (PROBLEMS".inp");
ofstream fo (PROBLEMS".out");
#define camnguyenmeow ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
bool cmp(const pii &x, const pii &y) {
    return (x.sc < y.sc) || (x.sc == y.sc && x.fr > y.fr);
}
int main()
{
    camnguyenmeow;
    int n, m, x, mintemp;
    fi >> m;
    vector<pii> a(m);
    bool cant = true;
    for (pii &i : a) {
        fi >> i.sc >> i.fr;
        if (i.fr == 100000) cant = false;
    }
    fi >> n >> mintemp;
    for (int i = 1; i < n; ++i) {
        fi >> x;
        mintemp = min(mintemp, x);
    }
    if (cant) {
        fo << -1; return 0;
    }
    sort(a.begin(), a.end(), greater<pii>());
    for (int i = m-1; i >= 0; --i)
        if (a[i].fr < mintemp)
            a.pop_back();
    m = a.size();
    int ans = 0;
    sort(a.begin(), a.end(), cmp);
    int r1 = mintemp, l2 = a[0].sc, savei;
    if (l2 > r1) {
        fo << -1; return 0;
    }
    bool check = false;
    int maxr = 0;
    for (int i = 0; i < m; ++i) {
        if (a[i].sc > r1) {
            if (!check) {
                fo << -1; return 0;
            }
            else {
                ++ans; r1 = maxr; check = false;
            }
        }
        if (a[i].sc <= r1 && maxr < a[i].fr) {
            maxr = a[i].fr;
            if (maxr >= r1) check = true;
            if (maxr == 100000) {
                fo << ans + 1; return 0;
            }
        }
    }
    if (maxr >= 100000 && check) {
        fo << ans + 1; return 0;
    }
    if (maxr < 100000) fo << -1;
    else fo << ans;
    return 0;
}
