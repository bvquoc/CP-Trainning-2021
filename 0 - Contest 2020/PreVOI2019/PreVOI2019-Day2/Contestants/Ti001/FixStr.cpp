#include <bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {
    char c;
    while (!isdigit(c = getchar()));
    x = c - 48;
    while (isdigit(c = getchar()))
        x = (x << 3) + (x << 1) + c - 48;
}
void reads(string &s) {
    char c;
    while ((c = getchar()) != ')' && c != '(');
    s = c;
    while ((c = getchar()) == ')' || c == '(')
        s += c;
}
template <typename T> void wrip(T x) {
    if (x > 9)
        wrip(x / 10);
    putchar(x % 10 + 48);
}
template <typename T> inline void write(T x) {
    wrip(x);
    putchar('\n');
}
string s;
int res, last;
struct node{
    int l, r, m;
    int open, close;
    node *lf, *rt;
    node() {
        l = r = m = open = close = 0;
        lf = rt = NULL;
    }
    inline void pushup() {
        int Min = min(lf->open, rt->close);
        open = rt->open + lf->open - Min;
        close = rt->close + lf->close - Min;
    }
    void build(int u, int v) {
        m = u + v >> 1;
        l = u, r = v;
        if (u == v) {
            if (s[u] == '(')
                open = 1;
            else
                close = 1;
            return;
        }
        lf = new node();
        rt = new node();
        lf->build(l, m);
        rt->build(m + 1, r);
        pushup();
    }
    void update(node *last, int u, int &v, int &pos) {
        l = u,
        r = v;
        m = u + v >> 1;
        lf = last->lf;
        rt = last->rt;
        if (l == r) {
            open = last->close;
            close = last->open;
            return;
        }
        if (pos <= m) {
            lf = new node();
            lf->update(last->lf, l, m, pos);
        }
        else {
            rt = new node();
            rt->update(last->rt, m + 1, r, pos);
        }
        pushup();
    }
    void get(int &u, int &v) {
        if (l > v || r < u)
            return;
        if (u <= l && r <= v) {
            int Min = min(last, close);
            res += close - Min;
            last -= Min;
            last += open;
            return;
        }
        lf->get(u, v);
        rt->get(u, v);
    }
};
const int N = 1e6 + 11;
typedef node* pnode;
pnode cur, root[N];
int n, m;
int main() {
    freopen("FixStr.inp", "r", stdin);
    freopen("FixStr.out", "w", stdout);
    reads(s);
    n = s.size();
    s = '#' + s;
    cur = new node();
    cur->build(1, n);
    read(m);
    for (int i = 1; i <= m; i++) {
        root[i] = cur;
        char c;
        while (!isalpha(c = getchar()));
        if (c == 'C') {
            int pos;
            read(pos);
            cur = new node();
            cur->update(root[i], 1, n, pos);
        }
        if (c == 'Q') {
            int u, v;
            read(u);
            read(v);
            res = last = 0;
            cur->get(u, v);
            write(res + last);
        }
        if (c == 'U') {
            int pos;
            read(pos);
            cur = root[pos];
        }
    }
}
