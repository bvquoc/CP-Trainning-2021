#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int a[200005], b[200005];
int id[200005];

void add(long long &a, long long b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int main() {
    freopen("PERMEOW.INP", "r", stdin);
    freopen("PERMEOW.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        id[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    bool sub1 = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) sub1 = 0;
    }

    if (sub1 == 1) {
        long long cnt = 0;
        for (int i = 1; i <= n; i++) {
            while (id[i] > i) {
                int idx = id[i];
                swap(id[i], id[a[idx - 1]]);
                add(cnt, 1);
            }

            while (id[i] < i) {
                int idx = id[i];
                swap(id[i], id[a[idx + 1]]);
                add(cnt, 1);
            }

            for (int j = 1; j <= n; j++) {
                a[id[j]] = j;
            }
        }
        cout << cnt % MOD;
    }
    else cout << 0;

    return 0;
}

