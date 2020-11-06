#define X first
#define Y second

#include <bits/stdc++.h>
using namespace std;
const int N = 10001;

int n, m, p, l, k, x, y, z, v;
int d[N];
vector < pair <int, int> > s[N];
queue < pair <int, int> > Q;

int main() {
    scanf("%d%d%d%d%d", &n, &m, &p, &l, &k);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        s[x].push_back({y, z});
        s[y].push_back({x, z});
    }
    for (int i = 2; i <= n; i++) d[i] = 0x3c3c3c3c;
    Q.push({0, 1});
    while(!Q.empty()) {
        x = Q.front().Y, y = Q.front().X;
        Q.pop();
        if (d[x] != y) continue;
        for (int i = 0; i < s[x].size(); i++) {
            z = s[x][i].X, v = s[x][i].Y;
            if (d[z] > y + v) {
                d[z] = y + v;
                Q.push({d[z], z});
            }
        }
    }
    printf("%d", d[n]);
    return 0;
}
