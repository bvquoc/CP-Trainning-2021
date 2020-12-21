#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5;

int m, n;
pair<int, int> jacket[N];
int t[N];

namespace Sub1 {

int64_t dem = 1;
vector<pair<int, int> > tmp, a;
int maxx = -1e9;

void solve() {
    if(t[1] < jacket[1].first) {
        cout << -1;
        return;
    }

    for(int i = 1; i <= m; ++i) {
        if(jacket[i].first <= t[1] && jacket[i].second >= t[1])
            tmp.push_back({jacket[i].second, jacket[i].first});
        else
            if(jacket[i].first > t[1] && jacket[i].second > t[1])
                a.push_back({jacket[i].first, jacket[i].second});

        maxx = max(maxx, jacket[i].second);
    }

    if(maxx < 1e5) {
        cout << -1;
        return;
    }

    sort(tmp.begin(), tmp.end());
    int X = tmp.back().second;
    int Y = tmp.back().first;

    int i = 0;
    while(i < a.size()) {
        if(a[i].first > Y) {
            cout << -1 << '\n';
            return;
        }

        //cout << Y << ' ';
        if(a[i].second < Y) i++;
        else {
            int tmp = Y;
            while(a[i].first <= Y && i < a.size()) {
                tmp = max(tmp, a[i].second);
                ++i;
            }
            Y = tmp;
            dem++;
        }
    }

    cout << dem << '\n';
}

}//namespace Sub1

int main() {
    freopen("COOLMAC.inp", "r", stdin);
    freopen("COOLMAC.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> m;
    for(int i = 1; i <= m; ++i)
        cin >> jacket[i].first >> jacket[i].second;
    sort(jacket + 1, jacket + m + 1);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> t[i];
    sort(t + 1, t + n + 1);

    Sub1::solve();

    return 0;
}
