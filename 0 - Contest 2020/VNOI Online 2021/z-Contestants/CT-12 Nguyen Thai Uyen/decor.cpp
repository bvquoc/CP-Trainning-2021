#include<bits/stdc++.h>
#define fto(i, a, b) for(int i = a; i <= b; i++)
#define fdto(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define maxN 500006
#define ff first
#define ss second
#define vi vector <int>
#define vii vector <ii>
#define ll long long
#define ii pair<int, int>
#define sz(a) (int)a.size()
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define oo 1000000007
#define ooo 10000000000000006
#define bug(a) cout << #a << ": " << a << endl;
#define bug2(a, b) cout << #a << ": " << ", " << #b << ": " << b << endl;
#define pll pair<ll, ll>
using namespace std;
int n, m, k;
int a[maxN], ans[maxN];

int main(){
    freopen("decor.inp", "r", stdin);
    freopen("decor.out", "w", stdout);
    fast

    cin >> n >> m >> k;

    fto(i, 1, n){
        char x;
        cin >> x;
        a[i] = x-'0';
    }

    fto(i, 1, m){
        int u, v;
        cin >> u >> v;
    }

    if(m == 0 && k == 0){
        int l, r, vs = 0, cnt, luu;
        a[n+1] = 0;
        fto(i, 1, n+1){
            if(a[i] == 1 && a[i-1] == 0){
                cnt = 1;
                luu = i;
            }
            if(a[i] == 0 && a[i-1] == 1){
                if(vs < cnt){
                    vs = cnt;
                    l = luu;
                    r = i-1;
                }
            }
            if(a[i] == 1 && a[i -1] == 1){
                cnt++;
            }
        }

        if(vs == 0) cout << -1;
        else cout << l << " " << r;
        return 0;

    }

    if(m == 0){
        int l, r, vs;
        if(a[1] == 0) a[0] = 0;
        else a[0] = 1;
        if(a[n] == 0) a[n+1] = 1;
        else a[n+1] = 0;

        int cnt = 0, dem = 0;
        fto(i, 1, n+1){
            if(a[i] == a[i-1]){
                cnt++;
            }
            else{
                ans[++dem] = cnt;
                cnt = 1;

            }
        }

        if(a[1] == 1){
            for(int j = 1; j <= dem; j = j+2){


            }

        }

        fto(i, 1, dem){
            cout << ans[i] << " ";
        }


        return 0;
    }





}
