#include<bits/stdc++.h>
using namespace std;

ifstream fi("coolmac.inp");
ofstream fo("coolmac.out");

int const N = 1e5 + 5;

int n, m;
int t = N;

struct Data{int lt, rt;} a[N], b[N], ans[N];

int cntAns;

void enter(){
    fi >> m;
    for(int i = 1; i <= m; ++i) fi >> a[i].lt >> a[i].rt;
    fi >> n;
    for(int i = 1; i <= n; ++i){
        int x;
        fi >> x;
        t = min(t, x);
    }
}

bool cmp(Data A, Data B){
    return (A.rt > B.rt) || (A.rt == B.rt && A.lt && A.lt < B.lt);
}

void solve(){
    sort(a + 1, a + m + 1, cmp);
    int cnt = 0;
    for(int i = 1; i <= m; ++i)
        if(a[i].rt != a[i - 1].rt) b[++cnt] = a[i];
    n = cnt;
    if(b[1].rt < 100000){
        fo << -1;
        return;
    }
    ans[1] = b[1];
    cntAns = 1;
    if(ans[1].lt <= t){fo << 1; return;}
    for(int i = 2; i <= m; ++i){
        //cerr << i << " " << b[i].lt <<  " " << b[i].rt << "\n";
        while(cntAns > 1 && b[i].rt >= ans[cntAns - 2].lt) --cntAns;
        //cerr << "cntAns = " << cntAns << "\n";
        if(ans[cntAns].lt > b[i].rt) {fo << -1; return;}
        ans[++cntAns] = b[i];
        if(ans[cntAns].lt <= t) {fo << cntAns; return;}
        //cerr << ans[cntAns].lt << " " << ans[cntAns].rt << "\n";
    }
    if(ans[cntAns].lt > t) {fo << -1; return;}
}

int main(){
    enter();
    solve();
}
