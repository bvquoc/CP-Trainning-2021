#include <bits/stdc++.h>
#define M 2005
#define Mod 998244353

using namespace std;

void reup(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int n;
stack<int> s;
vector<int> a[M];
bool ok;

void enter(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        a[i].clear();
        int ta;
        cin >> ta;
        while(ta > 0){
            s.push(ta % 10);
            ta /= 10;
        }
        while(!s.empty()){
            a[i].push_back(s.top());
            s.pop();
        }
        if(a[i].size() % 2 == 1)
            ok = 0;
    }
}

bool b[M];
int c[M];
int ans;

void check(){
    int cur = 1;
    int ta = 0;
    int tb = 0;
    for(int i = 1; i <= n; ++i)
        for(int v : a[c[i]]){
            if(cur % 2 == 1)
                ta += v;
            else
                tb += v;
            ++cur;
        }
    if((ta - tb) % 11 == 0)
        ++ans;
}

void trie(int i){
    if(i > n){
        check();
        return;
    }
    for(int j = 1; j <= n; ++j){
        if(b[j])
            continue;
        b[j] = 1;
        c[i] = j;
        trie(i + 1);
        b[j] = 0;
        c[i] = 0;
    }
}

void sub1(){
    trie(1);
    cout << ans << "\n";
}

void sub2(){
    int ta = 0, tb = 0;
    for(int i = 1; i <= n; ++i){
        int cur = 0;
        for(int v : a[i]){
            ++cur;
            if(cur % 2 == 1)
                ta += v;
            else
                tb += v;
        }
    }
    if((ta - tb) % 11 == 0){
        long long res = 1;
        for(int i = 1; i <= n; ++i){
            res *= i;
            if(res >= Mod)
                res %= Mod;
        }
        cout << res << "\n";
    }
    else
        cout << 0 << "\n";
}

void query(){
    int t;
    cin >> t;
    while(t--){
        ans = 0;
        ok = 1;
        enter();
        if(ok)
            sub2();
        else
        if(n <= 9)
            sub1();
    }
}

int main()
{
    freopen("GIFT11.inp", "r", stdin);
    freopen("GIFT11.out", "w", stdout);
    reup();
    query();
    return 0;
}
