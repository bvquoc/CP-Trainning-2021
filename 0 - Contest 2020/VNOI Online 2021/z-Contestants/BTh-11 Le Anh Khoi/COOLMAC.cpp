#include <bits/stdc++.h>

using namespace std;

int m, res = 1e5, L = 1e5, n;

struct cool
{
    int l, r, cnt = 0;
};

vector<cool> a;

bool cmp(cool a, cool b)
{
    return a.cnt < b.cnt;
}

int main()
{
    freopen("COOLMAC.INP", "r", stdin);
    freopen("COOLMAC.OUT", "w", stdout);
    cin >> m;
    for(int i = 1; i <= m; i++){
        int l, r; cin >> l >> r;
        int cnt = 1;
        cool tmp;
        tmp.l = l; tmp.r = r; tmp.cnt = cnt;
        a.push_back(tmp);
        int k = (int)a.size();
        for(int j = 0; j < k; j++){
            if(a[j].l == l && a[j].r == r) continue;
            if(max(l, a[j].l) <= min(r, a[j].r)){
                cool tmp;
                tmp.cnt = 1 + a[j].cnt;
                tmp.l = min(l, a[j].l);
                tmp.r = max(r, a[j].r);
                a.push_back(tmp);
            }
        }
    }
    sort(a.begin(), a.end(), cmp);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(x >= L) continue;
        bool ok = true;
        for(cool i: a){
            if(i.l <= x && i.r == (int)1e5 && i.l < L){
                L = i.l;
                res = i.cnt;
                ok = false;
                break;
            }
        }
        if(!ok) continue;
    }
    cout << (res == 100000? -1: res);
    return 0;

}
