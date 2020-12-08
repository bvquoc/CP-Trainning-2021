#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) ( (int)(x).size() )
#define fi first
#define se second
using LL = long long;

int nTest, m, n, xa, ya, xb, yb, xc, yc, xd, yd;

struct Fraction {
    int a, b;
    Fraction(int _a, int _b) : a(_a), b(_b) {}
    void reduce() {
        int gcd = __gcd(a, b);
        a /= gcd; b /= gcd;
    }
    bool operator < (const Fraction& _) const { return a * _.b < _.a * b; }
    bool operator > (const Fraction& _) const { return _ < *this; }
    Fraction operator - () const { return Fraction(-a, b); }
    Fraction operator + (const Fraction& _) const {
        Fraction ret(a * _.b + _.a * b, b * _.b); ret.reduce();
        return ret;
    }
    Fraction operator - (const Fraction& _) const {
        Fraction ret(a * _.b - _.a * b, b * _.b); ret.reduce();
        return ret;
    }
    Fraction operator * (const Fraction& _) const {
        Fraction ret(a * _.a, b * _.b); ret.reduce();
        return ret;
    }
    Fraction operator / (const Fraction& _) const { *this * Fraction(_.b, _.a); }
};

Fraction get(Fraction s1, Fraction v1, Fraction s2, Fraction v2) {
    if (s1 > s2) {
        swap(s1, s2);
        swap(v1, v2);
    }
    if ( (v1 > Fraction(0, 1)) ^ (v2 > Fraction(0, 1) ) ) {
        if (v1 > Fraction(0, 1) ) {
            return (s2 - s1) / (v1 - v2);
        }
        else {
            Fraction t1 = s1 / -v1, t2 = (Fraction(m, 1) - s2) / v2;
            if (t1 < t2)
        }
    }
    else {

    }
}

void Main() {
    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("MOTION.INP", "r", stdin);
    freopen("MOTION.OUT", "w", stdout);

    cin >> nTest;
    while (nTest--) Main();

    return 0;
}

