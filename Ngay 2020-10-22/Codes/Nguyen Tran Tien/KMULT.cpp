#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const int NMAX = 10005;

int a[NMAX], x[NMAX], n, k, ok = 0;

void check(){
    int ans = a[1];
    FOR(i, 1, n - 1){
        if (x[i]){
            ans += a[i + 1];
        }
        else {
            ans -= a[i + 1];
        }
    }
    if (ans % k == 0){
        ok = 1;
        printf("1\n");
        FOR(i, 1, n - 1){
            if (x[i]){
                printf("+");
            }
            else{
                printf("-");
            }
        }
    }
}
void backtrack(int i){
    FOR(j, 0, 1){
        if (ok){
            return;
        }
        x[i] = j;
        if (i == n - 1){
            check();
        }
        else {
            backtrack(i + 1);
        }
    }
}

int main(){
    freopen("KMULT.INP", "r", stdin);
    freopen("KMULT.OUT", "w", stdout);

    scanf("%d%d", &n, &k);
    FOR(i, 1, n){
        scanf("%d", &a[i]);
    }
    backtrack(1);
    if (!ok){
        printf("0\n");
    }
    return 0;
}
