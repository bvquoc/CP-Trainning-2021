#include <bits/stdc++.h>

#define elif else if
#define ii pair<int,int>
#define pb push_back
#define int long long
#define FOR(i , a , b , c) for(int i = (a) ; i <= (b) ; i += (c))
#define FORD(i , a , b , c) for(int i = (a) ; i >= (b) ; i -= (c))
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int N = 1e6 + 1;

int n , k , pre[N] , m;
char a[N];

void sub1() {
    int cs = 0 , len = 0;

    FOR(i , 1 , n , 1) {
        if(a[i] == '0') continue;
        int cnt = 0;
        int j = i;
        while(a[i] == a[j]) 
            ++j , ++cnt;
        if(cnt > len) {
            len = cnt;
            cs = i;
        }
        i = j - 1;
    }

    if(cs == 0) 
        cout << -1;
    else cout << cs << " " << cs + len - 1;
}

int check(int mid) {
    int check = 0;
    FOR(i , mid , n , 1) 
        if(pre[i] - pre[i - mid] <= k) 
            check = 1;

    return check; 
}

void sub2() {
    FOR(i , 1 , n , 1) {
        pre[i] = pre[i - 1];
        if(a[i] == '0') pre[i]++;
    }

    int L = 1 , R = n;
    int len = 0;
    while(L <= R) {
        int mid = (L + R) >> 1;
        if(check(mid)) {
            len = mid;
            L = mid + 1;
        }else R = mid - 1;
    }

    FOR(i , len , n , 1) 
        if(pre[i] - pre[i - len] <= k) {
            cout << i - len + 1 << " " << i;
            return ;
        }
}

main() {
    freopen("DECOR.inp" , "r" , stdin);
    freopen("DECOR.out" , "w" , stdout);
    FASTIO;
    cin >> n >> m >> k;

    cin >> a + 1;

    if(m == 0 && k == 0) sub1();

    elif(m == 0) sub2();

    return 0;
}