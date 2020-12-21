/*input
4
2
1 1
3
1 31 12
3
12345 67 84
9
1 2 3 4 5 6 7 8 9
*/
#include<bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;
#define cntBit __builtin_popcount

string toStr(int x) {
    string ret; while (x > 0) {
        ret += char(x % 10 + '0');
        x /= 10;
    }
    if (ret.empty()) ret = "0";
    reverse(ret.begin(), ret.end());
    return ret;
}

int a[2005], b[2005];
int id[2005];
long long fact[2005];

void add(long long &a, long long b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int getBit(int bit, int k) {
    return bit & (1 << k);
}

int main() {
    freopen("GIFT11.INP", "r", stdin);
    freopen("GIFT11.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    fact[0] = 1;
    for (int i = 1; i <= 2000; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    int t;
    cin >> t;

    for (int z = 1; z <= t; z++) {
        int n;
        cin >> n;

        bool sub2 = 1;
        bool sub3 = 1;
        vector<string> str_list;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];

            string cur = toStr(a[i]);
            if (cur.size() % 2 != 0) sub2 = 0;
            else sub3 = 0;

            str_list.push_back(cur);
            id[i] = i;
        }

        if (n <= 8) {
            sort(a + 1, a + n + 1);

            long long res = 0;
            do {
                string cur;
                for (int i = 1; i <= n ; i++) {
                    cur += toStr(a[id[i]]);
                }

                int val = 0;
                for (int i = 0; i < cur.size(); i++) {
                    if (i % 2 == 0) val += cur[i] - '0';
                    else val -= cur[i] - '0';
                }

                if (val % 11 == 0) {
                    add(res, 1);
                }
            } while (next_permutation(id + 1, id + n + 1));

            cout << res << "\n";
        }
        else if (sub2) {
            int val = 0;
            string cur;
            for (auto s : str_list) {
                cur += s;
            }

            for (int i = 0; i < cur.size(); i++) {
                if (i % 2 == 0) val += cur[i] - '0';
                else val -= cur[i] - '0';
            }

            if (val % 11 == 0) cout << fact[n] << "\n";
            else cout << 0 << "\n";
        }
        else {
            if (n % 2 == 1) n++;
            for (int i = 1; i <= n; i++) {
                string cur = toStr(a[i]);
                for (int j = 0; j < cur.size(); j++) {
                    if (j % 2 == 0) b[i] += cur[j] - '0';
                    else b[i] -= cur[j] - '0';
                    b[i] %= 11;
                }
            }

            long long res = 0;
            for (int bit = 0; bit < (1 << n); bit++) {
                if (cntBit(bit) != n / 2) continue;

                int sum = 0;
                for (int i = 0; i < n; i++) {
                    if (getBit(bit, i)) sum += b[i + 1];
                    else sum -= b[i + 1];
                    sum = (sum + 11) % 11;
                }

                if (sum == 0) {
                    add(res, 1);
                }
            }

            res *= fact[n / 2];
            res %= MOD;
            cout << res << "\n";
        }

        for (int i = 1; i <= n; i++) {
            a[i] = id[i] = 0;
            b[i] = 0;
        }
    }



    return 0;
}
