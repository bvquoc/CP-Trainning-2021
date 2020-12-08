// @___justkiddin
#include <bits/stdc++.h>
#define ll long long
#define Pii pair<int, int>
#define Piii pair<int, Pii>
#define _mp make_pair
#define _pb push_back
#define st first
#define nd second
#define whole(x) x.begin(), x.end()
#define Reset(x) memset(x, 0, sizeof(x))
#define PI acos(-1)
#define TASK "CONSTRUCT"
const int M = 1e5+8;
const int oo = 1e9+7;
using namespace std;

// mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int n, m, t, Query, a[M], l, r, w;
int State[M];
long long Res = 0;

int main(int argc, char const *argv[]){
	// freopen("test.txt", "r", stdin);
	freopen(TASK".inp", "r", stdin);
	freopen(TASK".out", "w", stdout);
	ios_base::sync_with_stdio(false);   cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++) cin >> a[i];
        a[0] = 0;
        while(m--){
            cin >> Query;
            if(Query == 1){
                cin >> l >> r >> w;   

                for(int i = l; i <= r; i++) a[i] += w;
                
            }
            else{
                Res = 0;
                cin >> l >> r;

                int Minn = oo;
                for(int i = l; i <= r; i++) Minn = min(Minn, a[i]);
                // for(int i = l; i <= r; i++) cout << a[i] << ' '; cout << '|'; cout << Minn << '\n';

                Res = Minn;

                for(int i = l; i <= r; i++)
                    if((a[i-1] <= a[i] || i == l) && (a[i] >= a[i+1] || i == r)){
                        Res += (a[i] - Minn);
                        Minn = oo;
                    }
                    else
                        Minn = min(Minn, a[i]);
                cout << Res << '\n';
            }   
        }
    }
	return 0; 
}
