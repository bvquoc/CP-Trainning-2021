#include<bits/stdc++.h>
#define fto(i, a, b) for(int i = a; i <= b; i++)
#define fdto(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define maxN 100006
#define ff first
#define ss second
#define vi vector <int>
#define vii vector <ii>
#define ll long long
#define ii pair<int, int>
#define sz(a) (int)a.size()
#define oo 1000000007
#define ooo 10000000000000006
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define bug(a) cout << #a << ": " << a << endl;
#define bug2(a, b) cout << #a << ": " << ", " << #b << ": " << b << endl;
#define pll pair<ll, ll>
using namespace std;
int s[maxN], n, m, k, l, hau[1 << 6];
vi dua[maxN];
vii ke[maxN];
ll d[maxN], d2[maxN], ans;
int f[15], dd[15], yes[15][15];

int onbit(int s, int j){
    return s | (1 << j);
}

bool check(int s, int j){
    return s & (1 << j);
}

void task2(){

    fto(i, 1, n) d[i] = ooo;
    d[1] = 0;
    priority_queue <pair<long long , long long > > pq;

    pq.push(mp(0, 1));

    while(!pq.empty()){
        ll u = pq.top().ss;
        ll w = -pq.top().ff;
        pq.pop();

        if(d[u] < w) continue;
        d[u] = w;

        fto(i, 0, sz(ke[u]) - 1){
            int v = ke[u][i].ss;
            int c = ke[u][i].ff;
            if(d[v] > d[u] + c){
                d[v] = d[u] + c;
                pq.push(mp(-d[v], v));
            }
        }
    }
}

void task3(){

    fto(i, 1, n) d[i] = ooo;
    d[n] = 0;
    priority_queue <pair<long long , long long > > pq;

    pq.push(mp(0, n));

    while(!pq.empty()){
        ll u = pq.top().ss;
        ll w = -pq.top().ff;
        pq.pop();

        if(d[u] < w) continue;
        d[u] = w;

        fto(i, 0, sz(ke[u]) - 1){
            int v = ke[u][i].ss;
            int c = ke[u][i].ff;
            if(d[v] > d[u] + c){
                d[v] = d[u] + c;
                pq.push(mp(-d[v], v));
            }
        }
    }
}

void sinhhv(int i){
    if(i > n){
        int s = hau[1];
        ll res = 0, dem = 0;
        fto(i, 2, n){
            int u = f[i-1];
            int v = f[i];
            if(yes[u][v] != 0){
                s = s | hau[i];
                res += yes[u][v];
            }
            else return;
            if(v == n) break;
        }
        fto(i, 1, k){
            if(check(s, i-1)) dem++;
        }
        if(dem >= l && ans > res) {
            ans = res;
        }
        return;
    }

    fto(j, 2, n){
        if(dd[j] == 0){
            dd[j] = 1;
            f[i] = j;
            sinhhv(i+1);
            dd[j] = 0;
        }
    }
}

int main(){
    freopen("dhaka.inp", "r", stdin);
    freopen("dhaka.out", "w", stdout);
    fast

    cin >> n >> m >> k >> l;

    fto(i, 1, n){
        cin >> s[i];
        hau[i] = 0;
        fto(j, 1, s[i]){
            int x;
            cin >> x;
            hau[i] = onbit(hau[i], x-1);
            dua[i].pb(x);
        }
    }

    fto(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        if(n <= 10){
            yes[u][v] = w;
            yes[v][u] = w;
        }
        ke[u].pb(mp(w, v));
        ke[v].pb(mp(w, u));
    }


    if(l == 0){
        task2();
        if(d[n] == ooo) cout << -1;
        else cout << d[n];
        return 0;
    }
    if(k == 1){
        ans = ooo*100;
        task2();
        fto(i, 1, n) {
            d2[i] = d[i];
        }
        task3();
        fto(i, 1, n){
            if(s[i] > 0){
                ans = min(ans, d[i] + d2[i]);
            }
        }

        if(ans == ooo*100) cout << -1;
        else cout << ans;
        return 0;
    }

    if(n <= 10){
        ans = ooo;
        f[1] = 1;
        sinhhv(2);
        if(ans == ooo) cout << -1;
        else cout << ans;
        return 0;
    }










}
