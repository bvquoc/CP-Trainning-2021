#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;

string s, nt[1005];
int mt[1005];
int res = 0;
struct data {
    int l, r, k;
} A[1005];

int t = 0;
void Nguyen_to() {
    int N = 1000;
    bool check[N + 1];
    for (int i = 2; i <= N; i++) {
        check[i] = true;
    }

    for (int i = 2; i <= N; i++) {
        if (check[i]) {
            for (int j = 2 * i; j <= N; j += i) {
                check[j] = false;
            }
        }
    }

    check[601] = false;
    for (int i = 2; i <= N; i++) {
        if (check[i] == true) {
            t++;
            int k = i;
            while (k != 0) {
                int m = k % 10;
                nt[t] = char(m + '0') + nt[t];
                mt[t]++;
                k /= 10;
            }
        }
    }
}


signed main() {
    FastIO;
    freopen("NGUYENTO.INP", "r", stdin);
    freopen("NGUYENTO.OUT", "w", stdout);
    cin >> s;
    Nguyen_to();
    for (int i = 1; i <= t; i++) {
        int k = s.find(nt[i]);
        if (k != -1) {
            res++;
            A[res].r = i;
            A[res].l = k;
            A[res].k = mt[i];
        }
    }
    cout << res << '\n';
    sort(A + 1, A + res + 1, [](const data &x, const data &y) {
        return (x.l < y.l) || (x.k < y.k && x.l == y.l);
    });
    
    for (int i = 1; i <= res; i++) {
        int k = A[i].r;
        cout << nt[k] << ' ';
    }
    return 0;
}
