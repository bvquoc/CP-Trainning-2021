#include<bits/stdc++.h>
#define maxN 100006
#define fto(i, a, b) for(int i = a; i <= b; i++)
#define oo 1000*1000*1000+7
#define ii pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(a) (int)a.size()
#define bug(a) cout << #a << ": " << a << endl;
#define bug2(a, b) cout << #a << ": " << a << ", " << #b <<": " << b << endl;
#define fast ios::sync_with_stdio(false); cin.tie(0);

using namespace std;
int l[maxN], r[maxN], t[maxN], vs[maxN], d[maxN];
bool dich[maxN];
int m, n;
int Mn = oo, Mn_t = oo, Mx = -oo, mx_r, cnt, ans;
ii nhap[maxN], cap[maxN];
int a[maxN];
vector <int> ke[maxN];

void dijkstra(){
    ans = oo;
    queue <int> q;
    fto(i, 1, cnt) d[i] = oo;
    fto(i, 1, cnt) dich[i] = 0;
    fto(i, 1, cnt){
        if(l[i] <= Mn_t){
            d[i] = 1;
            q.push(i);
        }
        if(r[i] == 100000){
            dich[i] = 1;
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        vs[u] = 1;
        if(dich[u] == 1) {

            ans = d[u];
            break;
        }

        fto(i, 0, sz(ke[u]) - 1){
            int v = ke[u][i];
            if(vs[v] == 0){
                d[v] = d[u] + 1;

                q.push(v);
            }
        }
    }


}

int main(){
    freopen("coolmac.inp", "r", stdin);
    freopen("coolmac.out", "w", stdout);
    fast


    cin >> m;

    fto(i, 1, m){
        cin >> l[i] >> r[i];
        Mn = min(Mn, l[i]);
        Mx = max(Mx, r[i]);
        nhap[i] = mp(l[i], r[i]);
    }

    sort(nhap+1, nhap+m+1);

    cin >> n;

    fto(i, 1, n){
        cin >> t[i];
        Mn_t = min(Mn_t, t[i]);
    }

    if(Mx < 1000*100 || Mn > Mn_t) {

        cout << -1;
        return 0;
    }
    cnt = 0;
    fto(i, 1, m){
        if(nhap[i].ss >= Mn_t) cap[++cnt] = nhap[i];
    }

    int left = cap[1].ff, right = cap[1].ss;
    if(left > Mn_t){
        cout << -1;
        return 0;
    }

    fto(i, 1, cnt - 1){
        if(cap[i+1].ff <= right){
            right = max(right, cap[i+1].ss);
        }
        else{
            cout << -1;
            return 0;
        }
    }

    if(n <= 3000 && m <= 3000){

        fto(i, 1, cnt){
            l[i] = cap[i].ff;
            r[i] = cap[i].ss;
            //cout <<l[i] << " " << r[i] << endl;
        }

        fto(i, 1, cnt){
            fto(j, i+1, cnt){
                if(i != j){
                    if(l[j] <= r[i]){
                        ke[i].pb(j);
                        ke[j].pb(i);
                    }
                }
            }
        }

//        fto(i, 1, cnt){
//            fto(j, 0, sz(ke[i]) - 1) cout << ke[i][j] << " ";
//            cout << endl;
//        }


        dijkstra();
        if(ans == oo) cout << -1;
        else cout << ans;

    }










    return 0;

}
