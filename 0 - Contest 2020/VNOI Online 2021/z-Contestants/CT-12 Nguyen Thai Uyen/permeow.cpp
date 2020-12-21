#include<bits/stdc++.h>
#define fto(i, a, b) for(int i = a; i <= b; i++)
#define fdto(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define maxN 200005
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
#define mod (1000*1000*1000+7)
#define ull unsigned long long
using namespace std;
int n, m, k;
int a[maxN], b[maxN], f[maxN], dd[maxN];
ll gt[maxN];
ll ans;

void sinhhv(int i){
    if(i > n){
        fto(i, 1, n) cout << f[i] << " ";
        cout << "\n";
        return;
    }

    fto(j, 1, n){
        if(dd[j] == 0){
            dd[j] = 1;
            f[i] = j;
            sinhhv(i+1);
            dd[j] = 0;
        }
    }
}

int main(){
    freopen("permeow.inp", "r", stdin);
    freopen("permeow.out", "w", stdout);
    fast

    cin >> n;
    fto(i, 1, n){
        cin >> a[i];
    }
    fto(i, 1, n) cin >> b[i];
    int dem = 0, dem2 = 0;
    fto(i, 1, n){
        if(a[i] == b[i]) dem++;
        if(a[i] == i && b[i] == n-i+1){
            dem2++;
        }
    }
    //sinhhv(1);

    if(dem == n){
        cout << 0;
        return 0;
    }
    if(dem2 == n){
        if(n == 1) {
            cout << 0;
            return 0;
        }
        if(n == 2){
            cout << 1;
            return 0;
        }
        gt[1] = 1;

        fto(i, 2, n){

            gt[i] = (gt[i-1]*i)%mod;
        }
        //bug(gt[n])
        if(gt[n] % 2 == 0) ans = ((ll)(gt[n]/2)*(gt[n] - 1))%mod;
        else ans = ((ll)(gt[n])*((gt[n] - 1)/2))%mod;
        cout << ans;
        return 0;
    }






}

