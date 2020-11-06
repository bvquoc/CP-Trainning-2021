#include <bits/stdc++.h>
using namespace std;

int n, delay, sum, lim;
long long a[1005];
long long d[1005][1005];
bool vs[1005][1005];

long long dp(int day, int numSeed) {
    if (day > n) return 0;
    if (vs[day][numSeed]) return d[day][numSeed];
    vs[day][numSeed] = 1;

    long long ans = 0;

    ans = max(ans, dp(day + 1, numSeed));
    for (int i = 1; i <= min(lim, sum - numSeed); i++) {
        ans = max(ans, dp(day + delay, i + numSeed) + a[day] * i);
    } 

    //cout << day << ' ' << numSeed << ' ' << ans << endl;
    return d[day][numSeed] = ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> delay >> sum >> lim;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cout << dp(0, 0);

    return 0;
}