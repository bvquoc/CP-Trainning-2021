#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
int kt[N + 3];
int n;
int d[N];
void snt() {
    kt[0] = 1;
    kt[1] = 1;
    for (int i = 2; i <= sqrt(N); i++)
        if (!kt[i])
            for (int j = 2; j * i <= N; j++)
                kt[i * j] = i;
    for (int i = 2; i <= N; i++)
        if (!kt[i])
            kt[i] = i;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //    #ifndef ONLINE_JUDGE
    //    freopen("cntdiv.inp","r",stdin);
    //    freopen("cntdiv.out","w",stdout);
    //    #endif // ONLINE_JUDGE
    int TC;
    cin >> TC;
    snt();
    while (TC--) {
        long long kq = 1, ans = 1;
        int M = 0;
        cin >> n;
        int m = n;

        while (m != 1) {
            d[kt[m]]++;
            M = max(M, kt[m]);
            m /= kt[m];
        }

        m = n + 1;
        while (m != 1) {
            d[kt[m]]++;
            M = max(M, kt[m]);
            m /= kt[m];
        }

        m = n + 2;
        while (m != 1) {
            d[kt[m]]++;
            M = max(M, kt[m]);
            m /= kt[m];
        }
        
        for (int i = 2; i <= M; i++) {
            kq *= (d[i] + 1);
            ans *= (2 * d[i] + 1);
            d[i] = 0;
        }
        cout << ans - kq - ans / 2 << "\n";
    }
}