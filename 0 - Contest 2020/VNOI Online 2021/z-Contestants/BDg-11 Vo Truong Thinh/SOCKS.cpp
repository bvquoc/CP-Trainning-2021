#include <bits/stdc++.h>
#define M 100005

using namespace std;

void reup(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int n;
int b[M];
vector<int> a[M];
int maxi;
int q;
int cnt;

void enter(){
    reup();
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> b[i];
        cnt += b[i];
    }
    for(int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i){
        int ta = a[i].size();
        maxi = max(maxi, ta);
    }
}

void sub1(){
    if(cnt > 1)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";
    for(int i = 1; i <= q; ++i){
        int ta;
        cin >> ta;
        ++b[i];
        b[i] %= 2;
        if(b[i] == 0)
            --cnt;
        else
            ++cnt;
        if(cnt > 1)
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
}

int main()
{
    freopen("SOCKS.inp", "r", stdin);
    freopen("SOCKS.out", "w", stdout);
    enter();
    if(maxi <= 2)
        sub1();
    return 0;
}
