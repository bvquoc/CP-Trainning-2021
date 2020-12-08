#include <bits/stdc++.h>
typedef int64_t ll;
const int maxn = 500010;
using namespace std;

template <typename T> inline void read (T &x) {
    x = 0; char c; bool p = false;
    while (!isdigit(c = getchar())) if (c == '-') p = true;
    do x = x * 10 + c - 48; while (isdigit(c = getchar()));
    if (p)
        x = -x;
}

vector<int> money;
ll f[maxn], x, t;
int Test;
void Sub2() {
    money.push_back(x);
    for (int i = 1; i <= t; i++)
        f[i] = LLONG_MAX;
    for (int i = 1; i <= t; i++) {
        for (auto v : money)
            if (i - v >= 0)
                f[i] = min(f[i], f[i - v] + 1);
    }
    cout << f[t] << '\n';
    money.pop_back();
}

queue<ll> q;
unordered_map<ll, int> M;
void Sub3() {
    M.clear();
    while (q.empty() == false)
        q.pop();
    money.push_back(x);
    for (auto v : money) {
        q.push(v);
        M[v] = 1;
    }
    while (q.empty() == false) {
        int jjj = q.front();
        if (jjj == t) {
            money.pop_back();
            return;
        }
        q.pop();
        for (auto v : money) {
            int minh = jjj + v;
            if (minh > t)
                continue;
            if (M[minh] == 0) {
                q.push(minh);
                M[minh] = M[jjj] + 1;
            }
        }
    }
}

void Tao() {
    freopen("oddcoin.inp", "w", stdout);
    cout << 50 << '\n';
    for (int i = 1; i <= 50; i++) {
        cout << 2143244 << " " << 2000000000 << endl;
    }
}

int main() {
    freopen ("oddcoin.inp", "r", stdin);
    freopen ("oddcoin.out", "w", stdout);
    money.push_back(1);
    money.push_back(3);
    money.push_back(5);
    money.push_back(10);
    money.push_back(30);
    money.push_back(50);
    money.push_back(100);
    money.push_back(300);
    money.push_back(500);
    money.push_back(1000);
    money.push_back(3000);
    money.push_back(5000);
    money.push_back(10000);
    money.push_back(30000);
    money.push_back(50000);
    read(Test);
    for (int iTest = 1; iTest <= Test; iTest++) {
        read(x); read(t);
        if (t <= 100000)
            Sub2();
        else
            Sub3();
    }
}
