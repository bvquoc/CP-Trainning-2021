#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
using namespace std;

using ii = pair <int, int>;
using ld = long double;

int c[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n;

int count(int x) {
    int d[2];
    FOR(i,0,1) {
        d[i] = x%10;
        if (x!=0) x /= 10;
    }
    return c[d[0]] + c[d[1]];
}

signed main(void) {
    FastIO;
    freopen("ALARM.INP","r",stdin);
    freopen("ALARM.OUT","w",stdout);
    cin >> n;
    FOR(h,0,23) {
        FOR(m,0,59) {
            if (count(h)+count(m) == n) {
                if (h<10) cout << '0';
                cout << h << ':';
                if (m<10) cout << '0';
                cout << m;
                return 0;
            }
        }
    }

    cout << "Impossible"; 
    return 0;
}