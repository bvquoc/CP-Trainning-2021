#include<bits/stdc++.h>
using namespace std;
int a, b, c;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> a >> b >> c;
    int u = -a / c;
    u += b / c;
    if(u == 0) {
        int res = b - a;
        res = res / 2 + (res % 2);
        cout << res;
        return 0;
    }
    if(c % 2 != 0) {
        int x = c - 1 - (a % c);
        int y = (b % c) - 1;
        int w = c - 2;
        x = x / 2 + x % 2;
        y = y / 2 + y % 2;
        w = w / 2 + w % 2;
        cout << x + y + u + w * (u - 1);
        return 0;
    }
    int res = 0;
    if(a % 2 == 0) {
        ++ a;
        ++ res;
    }
    cout << (b - a) / 2 + (b - a) % 2 + res;
    return 0;
}
