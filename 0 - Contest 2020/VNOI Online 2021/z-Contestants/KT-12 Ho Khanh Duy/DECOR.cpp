#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const ll N = 5e5+5;

typedef pair <ll, ll> ii;

ll n, m, k;
string S;
ii b[N];

vector <ll> a[N];
ll d[N], par[N], bat[N];
ll soluong[N];
ll Replace[N];

void sub1(){
    cin >> S;
    S = ' ' + S;
    ll ans = 0, ansL = 0, ansR = 0;

    ll cnt = 0, l = 1, r = 0;
    for (ll i=1; i <= n; i++){
        r = i;
        if (S[i] == '1'){
            cnt++;
            if (cnt > ans){
                ans = cnt;
                ansL = l;
                ansR = r;
            }
        }
        else if (S[i] == '0'){
            cnt = 0;
            l = i+1;
        }
    }

    cout << ansL << " " << ansR;
}

void sub2(){
    cin >> S;
    S = ' ' + S;

    ll cnt0 = 0;
    ll ans = 0, ansL = 0, ansR = 0;

    ll l = 1, r = 0;
    for (ll i=1; i<=n; i++){
        r = i;
        if (S[i] == '0'){
            cnt0++;
        }
        while (cnt0 > k){
            if (S[l] == '0')
                cnt0--;
            l++;
        }

        ll dem = r-l+1;
        if (dem > ans){
            ansL = l;
            ansR = r;
            ans = dem;
        }
    }

    cout << ansL << " " << ansR;
}

void dfs(ll u, ll timer){
    d[u] = 1;
    par[u] = timer;
    if (bat[u] == 1){
        soluong[timer]++;
    }

    for (auto v : a[u]){
        if (d[v] == 0){
            dfs(v, timer);
        }
    }
}

void sub3(){
    cin >> S;
    S = ' ' + S;

    for (ll i=1; i<=n; i++){
        if (S[i] == '1') bat[i] = 1;
    }

    for (ll i=1; i<=m; i++){
        ll u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    ll timer = 0;
    for (ll i=1; i<=n; i++){
        if (d[i] == 0){
            timer++;
            dfs(i,timer);
        }
    }

//    for (ll i=1; i<=n; i++)
//        S[i] = '0';

    ll cnt0 = 0;
    ll ans = 0, ansL = 0, ansR = 0;

    ll l = 1, r = 0;
    for (ll i=1; i<=n; i++){
        r = i;
        if (Replace[i] == 0){
            if (soluong[par[i]] != 0){
                soluong[par[i]]--;
                Replace[i] = 1;
            }
            else cnt0++;
        }
        while (cnt0 > k){
            if (Replace[l] == 0){
                cnt0--;
            }
            else if (Replace[l] == 1){
                soluong[par[i]]++;
                Replace[l] = 0;
            }

            l++;
        }

        ll dem = r-l+1;
        if (dem > ans){
            ansL = l;
            ansR = r;
            ans = dem;
        }
    }

    cout << ansL << " " << ansR;
}

int main()
{
    freopen("DECOR.inp","r",stdin);
    freopen("DECOR.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;
    if (m == 0 && k == 0)
        sub1();
    else if (m == 0)
        sub2();
    else
        sub3();

    return 0;
}
