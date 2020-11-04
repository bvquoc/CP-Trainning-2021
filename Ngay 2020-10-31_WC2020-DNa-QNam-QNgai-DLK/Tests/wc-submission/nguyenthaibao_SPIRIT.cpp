#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
const int inf = 0x3c3c3c3c;
int a, b, c;
int f[N];

int main() {
    scanf("%d%d%d", &a, &b, &c);
    if (c == 2) {
        printf("%d", (b - a) / 2);
        return 0;
    }
    if (!(a - 1) % c) f[a - 1] = inf;
    if (!(a - 2) % c) f[a - 2] = inf;
    f[a + 1] = min(f[a], f[a - 1]) + 1;
    if (a <= 100000 && b <= 100000 && c <= 100000) {
        for (int i = a + 2; i <= b; i++) {
            if (!(i % c)) f[i] = inf;
            else f[i] = min(f[i - 1], f[i - 2]) + 1;
//            if (!((i - 1) % c)) {f[i] = f[i - 2] + 1; continue; }
//            if (!((i - 2) % c)) {f[i] = f[i - 1] + 1; continue; }
//            if ((i % c)) f[i] = min(f[i - 1], f[i - 2]);
//            else f[i] = min(f[i - 1], f[i - 2]) + 1;
        }
        printf("%d\n", f[b]);
        return 0;
    }
}
