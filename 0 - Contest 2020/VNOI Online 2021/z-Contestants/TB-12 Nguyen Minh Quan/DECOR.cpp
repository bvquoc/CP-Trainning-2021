// link:
#include <bits/stdc++.h>

#define task "DECOR"
#define ll long long
#define f0(i, a, b) for(int i = (a); i <= (b); i++)
#define f1(i, a, b) for(int i = (a); i >= (b); i--)
#define pii pair<int, int>
#define fi first
#define se second
#define MASK(i) (1ll << (i))
#define BIT(i, x) (((x) >> (i)) & 1ll)
#define turn_on(i, x) ((1ll << (i)) | (x))
#define turn_off(i, x) ((x) & ~(1ll << (i)))
#define __builtin_popcount __builtin_popcountll

//---------------DO NOT TRY---------------//
using namespace std;

const int mxN = 5e5 + 7;
int n, m, k;
int st[mxN];
string state;
void input(void){
    cin >> n >> m >> k;
    cin >> state;
    f0(i, 0, state.size() - 1){
        st[i + 1] = state[i] - '0';
    }
}
void sub1(void){
    bool ok = false;
    int res = 0, preL, preR, l, r;
    f0(i, 1, n){
        if(st[i] == 1){
            ok = true;
            preL = i;
            while(i <= n && st[i] == 1) i++;
            preR = i - 1;
            if(preR - preL + 1 > res){
                res = preR - preL + 1;
                l = preL, r = preR;
            }
        }
    }
    if(ok ==false) cout << -1;
        else cout << l << " " << r;
}
void solve(void){
    if(m == 0 && k == 0){
        sub1();
        return;
    }
    int cnt0 = 0;
    f0(i, 1, n) if(st[i] == 0) cnt0++;
    if(cnt0 <= k){
        cout << 1 << " " << n;
        return;
    }

}

int main(){
    //
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
    //
    input();
    solve();
}
