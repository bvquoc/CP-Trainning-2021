#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5; 
const int maxLen = 5e5 + 5;
const int base[] = {1000000007, 1000000009};
#define nHash 2
#define cs 31
int POW[nHash][maxLen];
struct THash {
    vector<int> h[2];
    void Init(const string &s) {
        h[0].resize(s.length() + 1);
        h[1].resize(s.length() + 1);
        for (int i = 0; i < s.length(); ++i) {
            h[0][i + 1] = (1ll * h[0][i] * cs + s[i] - 'a' + 1) % base[0];
            h[1][i + 1] = (1ll * h[1][i] * cs + s[i] - 'a' + 1) % base[1];
        }
    }
    int GetHash(int x, int r) {
        return h[x][r];
    }
    int GetHash(int x, int l, int r) {
        long long res = -1ll * h[x][l - 1] * POW[x][r - l + 1] + h[x][r];
        res %= base[x];
        if (res < 0) res += base[x];
        return res;
    }
}hashS, hashDict[maxn];
string s;
pair<string, int> dict[maxn];
int n;
void InitHash() {
    POW[0][0] = POW[1][0] = 1;
    for (int i = 1; i <= 5e5; ++i) {
        POW[0][i] = 1ll * POW[0][i - 1] * cs % base[0];
        POW[1][i] = 1ll * POW[1][i - 1] * cs % base[1];
    }
    for (int i = 1; i <= n; ++i) {
        hashDict[i].Init(dict[i].first);
    }
    hashS.Init(s);
}
bool cmp(int L, int R, int i) { //return true if dict[i].first <= S[L->R]
    int l = 1, r = min(R - L + 1, (int) dict[i].first.length()), res = 0;
    int lim = r;
    while (l <= r) {
        int mid = l + r >> 1;
        int hS0 = hashS.GetHash(0, L, L + mid - 1);
        int hD0 = hashDict[i].GetHash(0, mid);
        if (hS0 != hD0) 
            r = mid - 1;
        else if (hashS.GetHash(1, L, L + mid - 1) != hashDict[i].GetHash(1, mid))
            r = mid - 1;
        else 
            l = mid + 1, res = mid;
    }
    if (res < lim)  {
        return dict[i].first[res] <= s[L + res - 1];
    }
    if (R - L + 1 >= dict[i].first.length()) return true;
    return false;
}
int GetPos(int L, int R) {
    int l = 1, r = n, res = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (cmp(L, R, mid)) 
            res = mid, l = mid + 1;
        else 
            r = mid - 1;
    }
    return res;
}
int main() {
#if ONLINE_JUDGE || THEMIS
    freopen("anctext.inp", "r", stdin);
    freopen("anctext.out", "w", stdout);
#endif

#ifdef LDT
    freopen("input.txt", "r", stdin);
    freopen("sub3.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    
    int q;
    cin >> s;
    cin >> n;  
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x >> dict[i].first;
        dict[i].second = -i;
    }
    sort(dict + 1, dict + 1 + n);
    // for (int i = 1; i <= n; ++i) cerr << dict[i].first << endl;
    InitHash();
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int l, r;
        cin >> l >> r;
        int pos = GetPos(l, r);
        if (pos <= 0)
            cout << -1 << '\n';
        else 
            cout << -dict[pos].second << '\n';
    }
    return 0;
}
