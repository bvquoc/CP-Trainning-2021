#include <bits/stdc++.h>
#define ll long long 
using namespace std;
struct bg{
    int st,en,cp;
};

const int N=1000000+10;
int n,k;
ll f[N];
bg a[N];

bool cmp(bg a,bg b){
        if (a.en == b.en)
            if (a.st != b.st) return a.st < b.st;
            else return a.cp > b.cp;
        return a.en < b.en;
}
int tknp(int l,int r,int x){
        int d, c, mid;
        d = l; c = r;
        while (d + 1 < c){
            mid = (d + c) / 2;
            if (a[mid].en + k <= x) d = mid;
            else c = mid - 1;
        }
        if (a[c].en + k <= x) return c;
        if (a[d].en + k <= x) return d;
        return 0;
}
void solve(){
        sort(a + 1, a + 1 + n, cmp);
        f[0] = 0;
        for(int i = 1; i <= n; i++){
            int j = tknp(1, i - 1, a[i].st);
            f[i] = f[j] + a[i].cp;
            f[i] = max(f[i],f[i-1]);
        }

        cout<<f[n]<<'\n';
}
int main(){
        ios_base :: sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
//        freopen("facility.inp", "r", stdin);
//        freopen("facility.out", "w", stdout);
        
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
                cin >> a[i].st >> a[i].en >> a[i].cp;
            	a[i].en += a[i].st;
        }
        solve();
}

