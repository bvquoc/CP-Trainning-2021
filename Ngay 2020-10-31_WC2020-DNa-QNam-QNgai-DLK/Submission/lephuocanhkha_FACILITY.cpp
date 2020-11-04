#include <bits/stdc++.h>
using namespace std;

struct People {
    long long start, finish, day, cost;
};

bool cmp(const People &a, const People &b) {
    if (a.finish == b.finish) return a.cost > b.cost;
    return a.finish < b.finish;
}

People a[1000005];
long long d[1000005];

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].start >> a[i].day >> a[i].cost;

        a[i].finish = a[i].start + a[i].day - 1;
    }    

    sort(a + 1, a + n + 1, cmp);

    d[1] = a[1].cost;
    for (int i = 2; i <= n; i++) {
        int lower = 1, upper = i - 1;
        while (lower < upper) {
            int mid = (lower + upper) / 2;
            if (a[i].start > a[mid].finish + k) {
                lower = mid + 1;
            }
            else {
                upper = mid;
            }
        }

        if (a[i].start <= a[lower].finish + k) lower--;

        //cout << lower << ' ';

        d[i] = max(d[i - 1], d[lower] + a[i].cost);
        //cout << d[i] << endl;
    }
    cout << d[n];

    return 0;
}