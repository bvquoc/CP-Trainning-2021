#include <bits/stdc++.h>
#define f first
#define s second
const int maxn = 1000010;
using namespace std;
template <typename T> inline void read (T &x) {
    x = 0; char c; bool p = false;
    while (!isdigit(c = getchar())); if (c == '-') p = true;
    do x = x * 10 + c - 48; while (isdigit(c = getchar()));
}

string s;
string phuchoi[maxn];
int m, n;
void Trau(int pp, int pp1) {
    int ss = 0;
    int res = 0;
    for (int i = pp; i <= pp1; i++) {
        if (s[i] == ')')
            ss--;
        else
            ss++;
        if (ss < 0) {
            res++;
            ss++;
        }
    }
    cout << res + ss << '\n';
}

pair<int, int> it[6 * maxn];

void Make_it(int l, int r, int id) {
    if (l == r) {
        if (s[l] == '(') {
            it[id].s = 1;
            it[id].f = 0;
        }
        else {
            it[id].f = 1;
            it[id].s = 0;
        }
        return;
    }
    int mid = (l + r) / 2;
    Make_it(l, mid, id * 2);
    Make_it(mid + 1, r, id * 2 + 1);
    pair<int, int> le = it[id * 2];
    pair<int, int> ri = it[id * 2 + 1];
    int pp = min(le.s, ri.f);
    le.s -= pp, ri.f -= pp;
    it[id] = {le.f + ri.f, le.s + ri.s};
}

void Update(int l, int r, int id, int pos) {
    if (pos > r || pos < l)
        return;
    if (l == r) {
        if (l == pos) {
            if (s[pos] == '(') {
                it[id].s = 1;
                it[id].f = 0;
            }
            else {
                it[id].f = 1;
                it[id].s = 0;
            }
        }
        return;
    }
    int mid = (l + r) / 2;
    Update(l, mid, id * 2, pos);
    Update(mid + 1, r, id * 2 + 1, pos);
    pair<int, int> le = it[id * 2];
    pair<int, int> ri = it[id * 2 + 1];
    int pp = min(le.s, ri.f);
    le.s -= pp, ri.f -= pp;
    it[id] = {le.f + ri.f, le.s + ri.s};
}

pair<int, int> Get(int l, int r, int u, int v, int id) {
    if (u > r || v < l)
        return {0, 0};
    if (u <= l && r <= v)
        return it[id];
    int mid = (l + r) / 2;
    pair<int, int> le = Get(l, mid, u, v, id * 2);
    pair<int, int> ri = Get(mid + 1, r, u, v, id * 2 + 1);
    int pp = min(le.s, ri.f);
    le.s -= pp, ri.f -= pp;
    return {le.f + ri.f, le.s + ri.s};
}

void tao() {
    freopen ("fixstr.inp", "w", stdout);
    n = 1000000, m = 1000000;
    for (int i = 1; i <= n; i++) {
        int pp = rand() % 2;
        if (pp == 1)
            cout << '(';
        else
            cout << ')';
    }
    for (int i = 1; i <= m; i++) {
        int pp = rand() % 2;
        if (pp == 1) {
            cout << 'C' <<" " << rand() % n + 1 << '\n';
        }
        else {
            int b = rand() % n + 1;
            cout << 'Q' << " " << rand() % b + 1 << " " << b << '\n';
        }
    }
}

int main() {
  //  tao();
    freopen ("fixstr.inp", "r", stdin);
    freopen ("fixstr.out", "w", stdout);
    char ch = getchar();
    while (ch != '\n') {
        s += ch;
        ch = getchar();
    }
    n = s.size();
    s = ' ' + s;
    Make_it(1, n, 1);
    read(m);
    for (int i = 1; i <= m; i++) {
        char ch = getchar();
        if (ch == 'C') {
            int pp;
            read(pp);
            if (s[pp] == '(')
                    s[pp] = ')';
            else
                s[pp] = '(';
            if (s.size() <= 1000 && m <= 1000) {
                phuchoi[i] = s;
                continue;
            }
            else {
                Update(1, n, 1, pp);
            }
        }
        if (ch == 'Q') {
            int pp, pp1;
            read(pp); read(pp1);
            if (s.size() <= 1000 && m <= 1000) {
                phuchoi[i] = s;
                Trau(pp, pp1);
            }
            else {
                pair<int, int> uu = Get(1, n, pp, pp1, 1);
                cout << uu.f + uu.s << '\n';
            }
        }
        if (ch == 'U') {
            int pp;
            read(pp);
            s = phuchoi[pp - 1];
        }
    }
}
