#include <bits/stdc++.h>
using namespace std;

long long calc(long long a, long long b, bool type) {
    return (b - a + type) / 2;
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    long long a, b, c;
    cin >> a >> b >> c;

    long long c1 = (a - 1) / c + 1;
    long long ck = b / c;

    long long c_first = c1 * c;
    long long c_last = ck * c;

    long long cnt = ck - c1 + 1;
    cnt = max(cnt, 0ll);

    long long res = cnt;

    if (cnt >= 1) {
        if (a % 2 == c_first % 2) res += calc(a, c_first - 1, 1);
        else res += calc(a, c_first - 1, 0);    

        if (b % 2 == c_last % 2) res += calc(c_last + 1, b, 1);
        else res += calc(c_last + 1, b, 0);
        
        if (c % 2 == 1) {
            res += (c_last - c_first - (cnt - 1)) / 2;
        }
        else {
            res += (c_last - c_first - 2 * (cnt - 1)) / 2;
        }    
    }
    else {
        if (a % 2 == b % 2) res = calc(a, b, 0);
        else res = calc(a, b, 1);
    }
    
    cout << res;

    return 0;
}