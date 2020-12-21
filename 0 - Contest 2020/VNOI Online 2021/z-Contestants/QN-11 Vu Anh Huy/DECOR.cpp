#include <bits/stdc++.h>
using namespace std;
int n, m, k;
string s;
pair <int, int> sw[500001];

//sub1
bool checkSub1 () {
    if (m == 0 && k == 0) return true;
    return false;
}
void sub1 () {
    int tmp = 0, ans = 0;
    s = s + "0";
    for (int i = 0; i < s.length(); ++ i) {
        if (s[i] == '0') {
            ans = max(ans, tmp);
            tmp = 0;
        }else {
            ++ tmp;
        }
    }
    cout << ans;
    exit(EXIT_SUCCESS);
}

//sub2
bool checkSub2 () {
    if (m == 0) return true;
    return false;
}
vector <int> d;
void sub2 () {
    int streak1 = 0, streak0 = 0;
    s += '0';
    if (s[0] == '0') d.push_back(0);
    for (int i = 0; i < s.length(); ++ i) {
        if (s[i] == '1') {
            ++ streak1;
            if (streak0 > 1) {
                for (int j = 1; j < streak0; ++ j) d.push_back(0);
            }
            streak0 = 0;
        }else {
            ++ streak0;
            if (streak1 > 0) {
                d.push_back(streak1);
            }
            streak1 = 0;
        }
    }
    int ans = 0, tmp = 0, cnt = 0;
    for (int i = 0; i < d.size(); ++ i) {
        ++ cnt;
        tmp += d[i];
        if (cnt > k) break;
    }

    ans = max(ans, tmp + cnt - 1);
    ++ k;
    for (int i = 1; i < d.size(); ++ i) {
        d[i] += d[i - 1];
    }
    for (int i = k; i < d.size(); ++ i) {
        ans = max(ans, d[i] - d[i - k] + k - 1);
    }
    cout << ans;
}

int main () {
    freopen("DECOR.INP", "r", stdin);
    freopen("DECOR.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    cin >> s;
    for (int i = 1; i <= m; ++ i) {
        cin >> sw[i].first >> sw[i].second;
    }
    if (checkSub1()) sub1();
    if (checkSub2()) sub2();
    return 0;
}
