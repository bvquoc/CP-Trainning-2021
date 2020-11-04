#include <bits/stdc++.h>
using namespace std;

long long bedTime, delay;
long long timeWatch[2];

void solve(vector<long long> &a, long long &time, bool &channel) {
    int n = a.size() - 1;

    int before = upper_bound(a.begin() + 1, a.end(), time) - a.begin();
    before--;

    // update time khi trùng thời gian giữa quảng cáo
    if (a[before] + delay > time && before >= 1 && before <= n) {
        time = a[before] + delay;
    }
    //cout << time << endl;

    if (time < bedTime) {
        int next = lower_bound(a.begin() + 1, a.end(), time) - a.begin();
        if (next <= n) {
            timeWatch[channel] += min(a[next], bedTime) - time;
            time = min(a[next], bedTime); 
        }
        else {
            timeWatch[channel] += bedTime - time;
            time = bedTime;
        }
    }
}


int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m >> bedTime >> delay;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<long long> b(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    long long time = 0;
    bool channel = 0;
    while (time < bedTime) {
        if (channel == 0) {
            solve(a, time, channel);
        }
        else {
            solve(b, time, channel);
        }
        channel ^= 1;

        //cout << channel << ' ' << time << endl;
    }

    cout << timeWatch[0] << ' ' << timeWatch[1];
    
    return 0;
}