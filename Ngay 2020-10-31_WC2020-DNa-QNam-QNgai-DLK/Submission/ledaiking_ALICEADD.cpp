#include <assert.h>
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define long long long

typedef vector<int> vi;
const int BASE = 10000;

void fix(vi &a) {
    a.push_back(0);
    for (int i = 0; i < a.size() - 1; ++i) {
        a[i + 1] += a[i] / BASE;
        a[i] %= BASE;
        if (a[i] < 0) {
            a[i] += BASE;
            a[i + 1]--;
        }
    }
    while (a.size() >= 2 && a.back() == 0) a.pop_back();
}

vi operator*(const vi &a, const vi &b) {
    vi c(a.size() + b.size() + 1);
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < b.size(); ++j) {
            c[i + j] += a[i] * b[j];
            c[i + j + 1] += c[i + j] / BASE;
            c[i + j] %= BASE;
        }
    return fix(c), c;
}

vi to_vi(int x) {  // x < Base
    assert(x < BASE);
    return vi(1, x);
}

vi operator+(vi a, const vi &b) {
    a.resize(max(a.size(), b.size()));
    for (int i = 0; i < b.size(); ++i)
        a[i] += b[i];
    return fix(a), a;
}
vi operator-(vi a, const vi &b) {
    for (int i = 0; i < b.size(); ++i)
        a[i] -= b[i];
    return fix(a), a;
}
vi operator*(vi a, int x) {  // x < BASE
    assert(x < BASE);
    for (int i = 0; i < a.size(); ++i)
        a[i] *= x;
    return fix(a), a;
}

bool operator<(const vi &a, const vi &b) {
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i = a.size() - 1; i >= 0; i--)
        if (a[i] != b[i])
            return a[i] < b[i];
    return false;
}

vi operator/(vi a, int x) {  // x < BASE
    assert(x < BASE);
    for (int i = (int)a.size() - 1, r = 0; i >= 0; --i, r %= x) {
        r = r * BASE + a[i];
        a[i] = r / x;
    }
    return fix(a), a;
}
int operator%(const vi &a, int x) {  //x < BASE
    int r = 0;
    for (int i = (int)a.size() - 1; i >= 0; --i)
        r = (r * BASE + a[i]) % x;
    return r;
}

istream &operator>>(istream &cin, vi &a) {
    string s;
    cin >> s;
    a.clear();
    a.resize(s.size() / 4 + 1);
    for (int i = 0; i < s.size(); ++i) {
        int x = (s.size() - 1 - i) / 4;  // <- log10(BASE)=4
        a[x] = a[x] * 10 + (s[i] - '0');
    }
    return fix(a), cin;
}

ostream &operator<<(ostream &cout, const vi &a) {
    printf("%d", a.back());
    for (int i = (int)a.size() - 2; i >= 0; i--)
        printf("%04d", a[i]);
    return cout;
}

void test_fib(int n) {
    vi a = to_vi(1), b = to_vi(1);
    for (int i = 1; i <= n / 2; ++i) {
        a = a + b;
        b = b + a;
        cout << "F[" << i * 2 + 1 << "]=" << a << endl;
        cout << "F[" << i * 2 + 2 << "]=" << b << endl;
    }
}

void test_fact(int n) {
    vi P = to_vi(1);
    for (int i = 1; i <= n; ++i) {
        P = P * i;
        cout << i << "!= " << P << endl;
    }
}

void test_divide() {
    vi a;
    int x;
    for (;;) {
        cout << "Input a big integer and a small integer (<10000)" << endl;
        if (cin >> a >> x)
            ;
        else
            break;
        cout << "a=" << a << " x=" << x << endl;
        vi q = a / x;
        int r = a % x;
        cout << "a/x=" << q << "; a%x=" << r << endl;
        vi a0 = q * to_vi(x) + to_vi(r);
        assert(a0 == a && !(a0 < a) && !(a0 > a));
    }
}

int main() {
    
    vi a, b; int t;
    cin>>t;
    while(t--)
    {
	 
    cin >> a >> b; cout<<a+b<<"\n";
     }
}
