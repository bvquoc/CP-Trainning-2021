#include <bits/stdc++.h>

using namespace std;

int n[15];
int a[15][2005];
int s;
string b[2005];
string S;
bool cx[123];
int res;
long long F[2005];
void Check(string L) {
    int c = 0, l = 0;
    for (int i = 0; i < L.size(); i++) {
        if (i % 2 == 0) l = l + int(L[i] - '0');
        else c = c + int(L[i] - '0');
    }
    if ((l - c) % 11 == 0) res++;
}

void Try(int i, int l, string X) {
    for (int j = 1; j <= n[l]; j++) {
        if (cx[j]) continue;
        S = X + b[j];
        cx[j] = true;
        if (i == n[l]) Check(S);
        else Try(i + 1, l, S);
        cx[j] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("GIFT11.INP","r",stdin);
    freopen("GIFT11.OUT","w",stdout);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n[t];
        s += n[t];
        for (int i = 1; i <= n[t]; i++) cin >> a[t][i];
    }
    if (s <= 8) {
        for (int t = 1; t <= T; t++) {
            for (int i = 1; i <= n[t]; i++) {
                b[i] = "";
                while (a[t][i] != 0) {
                    b[i] = char(a[t][i] % 10 + '0') + b[i];
                    a[t][i] /= 10;
                }
            }
            res = 0;
            Try(1, t, "");
            cout << res << endl;
        }
        return 0;
    }
    F[0] = 1;
    for (int i = 1; i <= 2000; i++) F[i] = F[i - 1] * i;
    for (int t = 1; t <= T; t++) {
        string KQ = "";
        for (int i = 1; i <= n[t]; i++) {
            b[i] = "";
            while (a[t][i] != 0) {
                b[i] = char(a[t][i] % 10 + '0') + b[i];
                a[t][i] /= 10;
            }
            KQ = KQ + b[i];
        }
        res = 0;
        Check(KQ);
        if (res == 1) {
            cout << F[n[t]] << endl;
        } else cout << -1 << endl;
    }
    return 0;
}
