#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;
const int Mod = 1e9 + 7;

int n;
int64_t a[N], b[N];

int main() {
#ifdef DN
    //freopen("in.txt", "r", stdin);
#endif
    freopen("PERMEOW.inp", "r", stdin);
    freopen("PERMEOW.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    for(int i = 1; i <= n; ++i)
        cin >> b[i];

    int64_t ans = 0;

    for(int i = 1; i < n; ++i) {
        if(a[i] == i) continue;
        int64_t p = -1;

        for(int j = i + 1; j <= n; ++j) {
            if(a[j] == i) {
                p = j;
                break;
            }
        }

        for(int j = p - 1; j >= i; --j) {
            swap(a[j], a[j + 1]);
            ans++;
        }
    }

    cout << ans % Mod;

    return 0;
}
