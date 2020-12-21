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
int n, q;
int a[maxN], deg[maxN], cnt2[maxN], dem, luu, par[maxN], mau[maxN], yes[3];
vector<int> ke[maxN];

void task1(){
    if(dem > 0) cout << 1 << "\n";
    else cout <<0 << "\n";

    fto(i, 1, q){
        int x;
        cin >> x;
        if(a[x] == 0){
            a[x] = 1;
            dem++;
            cout << 1 << "\n";
        }
        else if(a[x] == 1){
            a[x] = 0;
            dem--;
            if(dem == 0) cout << 0 << "\n";
            else cout << 1 << "\n";
        }
    }
}

void dfs(int u, int col){
    mau[u] = col;

    fto(i, 0, sz(ke[u]) - 1){
        int v = ke[u][i];
        if(v != par[u]){
            par[v] = u;
            dfs(v, col);
        }
    }
}

void task2(){

    fto(i, 0, 2){
        if(cnt2[i] > 0) yes[i] = 1;
        else yes[i] = 0;
    }
    int tmp;
    tmp = 0;
    fto(i, 0, 2){
        tmp += yes[i];
    }
    if(tmp == 3) cout << "2\n";
    else if(tmp == 2 || tmp == 1) cout << "1\n";
    else if(tmp == 0 && a[luu] == 1) cout << "1\n";
    else cout << "0\n";

    fto(i, 1, q){
        int x;
        cin >> x;

        if(mau[x] == -1){
            if(a[x] == 1) a[x] = 0;
            else a[x] = 1;

            tmp = 0;
            fto(i, 0, 2){
                tmp += yes[i];
            }
            if(tmp == 3) cout << "2\n";
            else if(tmp == 2 || tmp == 1) cout << "1\n";
            else if(tmp == 0 && a[luu] == 1) cout << "1\n";
            else cout << "0\n";

        }
        else{
            if(a[x] == 0){

                a[x] = 1;
                cnt2[mau[x]]++;
                yes[mau[x]] = 1;
            }
            else if(a[x] == 1){
                a[x] = 0;
                cnt2[mau[x]]--;
                if(cnt2[mau[x]] == 0) yes[mau[x]] = 0;

            }
            tmp = 0;
            fto(i, 0, 2){
                tmp += yes[i];
            }


            if(tmp == 3) cout << "2\n";
            else if(tmp == 2 || tmp == 1) cout << "1\n";
            else if(tmp == 0 && a[luu] == 1) cout << "1\n";
            else cout << "0\n";

        }

    }

}

int main(){
    freopen("socks.inp", "r", stdin);
    freopen("socks.out", "w", stdout);
    fast
    cin >> n >> q;
    dem = 0;
    fto(i, 1, n) {
        cin >> a[i];
        if(a[i] == 1)dem++;
    }

    fto(i, 1, n-1){
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
        ke[u].pb(v);
        ke[v].pb(u);
    }

    int dem2 = 0, dem3 = 0;
    fto(i, 1, n){
        if(deg[i] <= 2) dem2++;
        if(deg[i] == 3) {
            dem3++;
            luu = i;
        }
    }

    if(dem2 == n){
        task1();
        return 0;
    }
    if(dem2 == n-1 && dem3 == 1){
        fto(i, 0, sz(ke[luu]) - 1){
            int u = ke[luu][i];
            par[u] = luu;
            dfs(u, i);
        }


        mau[luu] = -1;
        fto(i, 1, n){
            if(a[i] == 1) cnt2[mau[i]]++;
        }
        task2();

        return 0;
    }














    return 0;

}

