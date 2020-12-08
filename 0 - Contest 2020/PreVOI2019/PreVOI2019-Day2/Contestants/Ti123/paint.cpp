#include <bits/stdc++.h>
const int maxn = 1000010;
using namespace std;

template <typename T> inline void read (T &x) {
    x = 0; char c; bool p = false;
    while (!isdigit(c = getchar())); if (c == '-') p = true;
    do x = x * 10 + c - 48; while (isdigit(c = getchar()));
}

int n;
char room[maxn];
void Trau() {
    int cs = 1;
    for (int i = 1; i <= n; i++) {
        int pp;
        read(pp);
        if (pp == 1) {
            char ch = getchar();
            room[cs] = ch;
            cs++;
        }
        else {
            char ch = getchar();
            getchar();
            char ch1 = getchar();
            for (int j = 1; j < cs; j++)
                if (room[j] == ch)
                    room[j] = ch1;
        }
    }
    for (int i = 1; i <= cs - 1; i++)
        cout << room[i];
}

int parent[maxn], height[maxn], root[maxn];
char color[maxn];
int Goc(int a) {
    if (parent[a] == -1)
        return a;
    return parent[a] = Goc(parent[a]);
}

void Gop(int a, int b, char ch) {
    a = Goc(a), b = Goc(b);
    if (a == b)
        return;
    if (height[a] > height[b]) {
        parent[b] = a;
        color[a] = ch;
        root[ch] = a;
    }
    else {
        if (height[a] == height[b]) {
            parent[b] = a;
            color[a] = ch;
            root[ch] = a;
            height[a]++;
        }
        else {
            parent[a] = b;
            color[b] = ch;
            root[ch] = b;
        }
    }
}

void Ac() {
    for (int i = 1; i <= n; i++) {
        parent[i] = -1;
        height[i] = 1;
    }
    int cs = 1;
    for (int i = 1; i <= n; i++) {
        int pp;
        read(pp);
        if (pp == 1) {
            char ch = getchar();
            color[cs] = ch;
            if (root[ch] == 0) {
                root[ch] = cs;
            }
            else
                Gop(cs, root[ch], ch);
             cs++;
        }
        if (pp == 2) {
            char ch = getchar();
            getchar();
            char ch1 = getchar();
            if (ch == ch1)
                continue;
            if (root[ch] == 0)
                continue;
            if (root[ch1] == 0) {
                root[ch1] = root[ch];
                color[root[ch1]] = ch1;
                root[ch] = 0;
            }
            else {
                Gop(root[ch], root[ch1], ch1);
                root[ch] = 0;
            }
        }
    }
    cs--;
    for (int i = 1; i <= cs; i++)
        cout << color[Goc(i)];
}

int main() {
    freopen ("paint.inp", "r", stdin);
    freopen ("paint.out", "w", stdout);
    read(n);
    if (n <= 10000)
        Trau();
    else
        Ac();
}
