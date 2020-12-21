#include <bits/stdc++.h>

// ====================================================================
template<const int &MOD>
struct _m_int {
    int val;
    _m_int(int64_t v = 0) { if (v < 0) v = v % MOD + MOD; if (v >= MOD) v %= MOD; val = int(v); }
    _m_int(uint64_t v) { if (v >= MOD) v %= MOD; val = int(v); }
    _m_int(int v) : _m_int(int64_t(v)) {}
    _m_int(unsigned v) : _m_int(uint64_t(v)) {}
    static int inv_mod(int a, int m = MOD) { int g = m, r = a, x = 0, y = 1; while (r) { int q = g / r; g %= r; std::swap(g, r); x -= q * y; std::swap(x, y); } return x < 0 ? x + m : x; }
    explicit operator int() const { return val; }
    explicit operator uint32_t() const { return val; }
    explicit operator int64_t() const { return val; }
    explicit operator uint64_t() const { return val; }
    explicit operator double() const { return val; }
    explicit operator long double() const { return val; }
    _m_int& operator+=(const _m_int &other) { val -= MOD - other.val; if (val < 0) val += MOD; return *this; }
    _m_int& operator-=(const _m_int &other) { val -= other.val; if (val < 0) val += MOD; return *this; }
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) { return unsigned(x % m); }
    _m_int& operator*=(const _m_int &other) { val = fast_mod(uint64_t(val) * other.val); return *this; }
    _m_int& operator/=(const _m_int &other) { return *this *= other.inv(); }
    friend _m_int operator+(const _m_int &a, const _m_int &b) { return _m_int(a) += b; }
    friend _m_int operator-(const _m_int &a, const _m_int &b) { return _m_int(a) -= b; }
    friend _m_int operator*(const _m_int &a, const _m_int &b) { return _m_int(a) *= b; }
    friend _m_int operator/(const _m_int &a, const _m_int &b) { return _m_int(a) /= b; }
    _m_int& operator++() { val = val == MOD - 1 ? 0 : val + 1; return *this; }
    _m_int& operator--() { val = val == 0 ? MOD - 1 : val - 1; return *this; }
    _m_int operator++(int) { _m_int before = *this; ++*this; return before; }
    _m_int operator--(int) { _m_int before = *this; --*this; return before; }
    _m_int operator-() const { return val == 0 ? 0 : MOD - val; }
    friend bool operator==(const _m_int &a, const _m_int &b) { return a.val == b.val; }
    friend bool operator!=(const _m_int &a, const _m_int &b) { return a.val != b.val; }
    friend bool operator<(const _m_int &a, const _m_int &b) { return a.val < b.val; }
    friend bool operator>(const _m_int &a, const _m_int &b) { return a.val > b.val; }
    friend bool operator<=(const _m_int &a, const _m_int &b) { return a.val <= b.val; }
    friend bool operator>=(const _m_int &a, const _m_int &b) { return a.val >= b.val; }
    _m_int inv() const { return inv_mod(val); }
    _m_int pow(int64_t p) const { if (p < 0) return inv().pow(-p); _m_int a = *this, result = 1; while (p > 0) { if (p & 1) result *= a; p >>= 1; if (p > 0) a *= a; } return result; }
    friend std::ostream& operator<<(std::ostream &os, const _m_int &m) { return os << m.val; }
    friend void __print(const _m_int &m) { std::cerr << m; }
};

extern const int MOD = 1e9 + 7;
using Mint = _m_int<MOD>;
// ====================================================================

const int N = 2e5 + 5;

int n;
int a[N], b[N];

signed main() {
#ifndef LOCAL
    freopen("PERMEOW.inp", "r", stdin);
    freopen("PERMEOW.out", "w", stdout);
#endif
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;

    for (int i = 1; i <= n; i++) std::cin >> a[i];
    for (int i = 1; i <= n; i++) std::cin >> b[i];

    Mint ans = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i] == i) continue;

        int p = -1;

        for (int j = i + 1; j <= n; j++) {
            if (a[j] == i) {
                p = j;
                break;
            }
        }

        for (int j = p - 1; j >= i; j--) {
            std::swap(a[j], a[j + 1]);
            ++ans;
        }
    }

    std::cout << ans;

    return 0;
}
