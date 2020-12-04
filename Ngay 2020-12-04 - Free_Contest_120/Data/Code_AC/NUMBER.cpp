#include <iostream>
#include <vector>
using namespace std;

const int N = 1010;
vector<int> dp[N][N];
int n, m, k;
string st;

int Calc(int i, int del, int mod) {
    // cerr << i << ' ' << del << ' ' << mod << " calculating\n";
    if (i == n) {
        return (del == k && mod == 0) * 2 - 1;
    }
    if (dp[i][del][mod]) return dp[i][del][mod];
    dp[i][del][mod] = -1;
    // Del pos i
    if (del < k && Calc(i + 1, del + 1, mod) == 1) {
        // cerr << i << ' ' << del << ' ' << mod << " ok\n";
        dp[i][del][mod] = 1;
        return 1;
    }
    // Keep i 
    if (Calc(i + 1, del, (mod * 10 + st[i] - '0') % m) == 1) {
        // cerr << i << ' ' << del << ' ' << mod << " ok\n";
        dp[i][del][mod] = 1;
        return 1;
    }

    //cerr << i << ' ' << del << ' ' << mod << " ok\n";
    return -1;
}

string Largest() {
    int i = 0, del = 0, mod = 0;
    string ret;
    // cerr << "Largest\n";
    while (ret.size() + k < st.size()) {
        int j = i;
        int mx = -1, p = i;
        // cerr << i << ' ' << del << ' ' << mod << ' ' << mx << '\n';
        while (j < n && j - i + del <= k) {
            if (Calc(j + 1, del + j - i, (mod * 10 + st[j] - '0') % m) == 1) {
                //cerr << i  << ' ' << j << ' ' << del + j - i << ' ' << mod << "-> " << st[j] << '\n';
                
                if (st[j] - '0' > mx) p = j, mx = st[j] - '0';
            }
            ++j;
        }
        if (mx == -1 || (mx == 0 && i == 0)) return "-1";
        ret += st[p];
        del += p - i; i = p + 1, mod = (mod * 10 + st[p] - '0') % m;
    }
    if (ret.empty()) return "-1";
    return ret;
}

string Smallest() {
    int i = 0, del = 0, mod = 0;
    string ret;
    while (ret.size() + k < st.size()) {
        //cerr << i << ' ' << del << ' ' << mod << '\n';
        int j = i;
        int mn = 10, p = i;
        while (j < n && j - i + del <= k) {
            if (Calc(j + 1, del + j - i, (mod * 10 + st[j] - '0') % m) == 1) {
            //    cerr << i << ' ' << del << ' ' << mod << "-> " << j << '\n';
                if (st[j] - '0' < mn) {
                    if (st[j] != '0' || i != 0) p = j, mn = st[j] - '0';
                }
            }
            ++j;
        }
        if (mn == 10) {
            return "-1";
        }
        ret += st[p];
        del += p - i; i = p + 1, mod = (mod * 10 + st[p] - '0') % m;
    }

    if (ret.empty()) return "-1";
    return ret;
}
int main() {
    cin >> st;
    n = st.size();
    cin >> k >> m;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) dp[i][j].resize(m);
    }
    cout << Smallest() << '\n';
    cout << Largest() << '\n';
}