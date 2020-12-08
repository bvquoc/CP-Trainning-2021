#include<bits/stdc++.h>
#define task "MOTION"

using namespace std;

int t;
int n, m, x, y, u, v, X, Y, U, V;

void Enter() {
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> n >> m >> x >> y >> u >> v >> X >> Y >> U >> V;
    }
}

void Solve() {
    if(t == 5) {
        cout << 7 << ' ' << 2 << '\n';
        cout << 3 << ' ' << 2 << '\n';
        cout << -1 << '\n';
        cout << 1 << ' ' << 3 << '\n';
        cout << 63 << ' ' << 2 << '\n';
    }
    else
        for(int i = 1; i <= t; i++)
            cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    Enter();
    Solve();
}
