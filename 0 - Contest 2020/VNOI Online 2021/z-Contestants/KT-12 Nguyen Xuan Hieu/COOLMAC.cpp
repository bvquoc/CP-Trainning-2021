#include <bits/stdc++.h>

#define elif else if
#define ii pair<int,int>
#define pb push_back
#define ll long long
#define FOR(i , a , b , c) for(int i = (a) ; i <= (b) ; i += (c))
#define FORD(i , a , b , c) for(int i = (a) ; i >= (b) ; i -= (c))
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define left first
#define right second

using namespace std;

const int N = 1e5 + 1;

int n , m , st = 1e9 , ed , d[N] , path[N] , s = 1e9;

ii a[N];

main() {
    freopen("COOLMAC.inp" , "r" , stdin);
    freopen("COOLMAC.out" , "w" , stdout);
    FASTIO;

    cin >> n;

    FOR(i , 1 , n , 1) {
        cin >> a[i].left >> a[i].right;
        s = min(s , a[i].left);
    }
    
    cin >> m;
    
    FOR(i , 1 , m , 1) {
        int x ; cin >> x;
        st = min(st , x);
    }

    ed = 1e5;

    sort(a + 1 , a + n + 1);

    FOR(i , 1 , n , 1) 
        path[a[i].left]++ , path[a[i].right]--;
    
    FOR(i , min(s , st) , ed , 1)  {
        path[i] += path[i - 1];
        if(path[i] == 0 && path[i - 1] == 0) {
            cout << -1;
            return 0;
        }
    }

    FOR(i , 1 , n , 1) 
        FOR(j , 1 , n , 1) 
            if( a[j].left <= a[i].left && a[i].right <= a[j].right && i != j && d[j] != -1) 
                d[i] = -1;
    
    d[1] = 1;

    FOR(i , 1 , n - 1 , 1) {
        if(d[i] == -1) continue;
        int Max = 0;
        int cs = i;

        FOR(j , i + 1 , n , 1) {
            if(d[j] == -1 || i == j) continue;
            if(a[j].left > a[i].right) continue;
            if(a[j].right > Max) {
                Max = a[j].right;
                cs = j;
            }
        }

        FOR(j , i + 1 , n , 1) {
            if(d[j] == -1 || i == j) continue;
            if(a[j].left > a[i].right) continue;
            if(a[j].right < Max) 
                d[j] = -1;
        }
        d[cs] = 1;
    }

    int res = 0;    

    memset(path , 0 , sizeof(path));

    FOR(i , 1 , n , 1) 
        if(d[i] == 1) path[a[i].left]++ , path[a[i].right]++;

    FOR(i , 1 , ed , 1)  
        path[i] += path[i - 1];

    FOR(i , 1 , n , 1) 
        if(d[i] == 1) {
            if(a[i].right < st) continue;
            if(a[i].left > ed) continue;
            if(a[i].right == st && path[st] > 1) continue;
            if(a[i].left == ed && path[ed] > 1) continue;
            ++res;
        }

    cout << res;

    return 0;
}