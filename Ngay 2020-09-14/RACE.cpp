#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
#define int long long
using namespace std;

using ii = pair <int, int>;
using ld = long double;

int T1, V1, T2, V2, x;

int solve(int t1, int v1) {
    int l1 = (x-1)/(v1*t1);
    int cost;
    int x1 = v1*t1*l1;
    l1 = t1*l1*2;
    while (x1<x) {
        if (x1+(v1*t1)<x) {
            x1 += v1*t1;
            l1 += t1*2;
        } else {
            int k = x-x1;
            int m = k%v1;
            if (m!=0) cost = l1+k/v1+1;
            else cost = l1+k/v1;
            break;
        }
    }
    return cost;
}

signed main(void) {
    FastIO;
    freopen("RACE.INP","r",stdin);
    freopen("RACE.OUT","w",stdout);
    cin >> T1 >> V1 >> T2 >> V2 >> x;
    
    int cost1 = solve(T1,V1);
    int cost2 = solve(T2,V2);

    if (cost1 == cost2 && cost1 == 1) {
        if (V1>V2) printf("First");
        else printf("Second");
        return 0;
    }
    if (cost1 == cost2) printf("Draw");
    else if (cost1<cost2) printf("First");
    else printf("Second");
    return 0;
}
