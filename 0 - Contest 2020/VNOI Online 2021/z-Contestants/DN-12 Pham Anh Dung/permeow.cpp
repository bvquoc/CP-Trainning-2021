#include <bits/stdc++.h>

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back

using namespace std;

int main()
{
    IOS;
    freopen("permeow.inp","r",stdin);
    freopen("permeow.out","w",stdout);

    int n;
    cin >> n;

    vector <int> a, b;

    for (int i = 1; i <= n; i++){
        int u; cin >> u;
        a.pb(u);
    }

    for (int i = 1; i <= n; i++){
        int v; cin >> v;
        b.pb(v);
    }

    if (1){
        int ans = 0;
        for (int i = n; i >= 1; i--){
            if (a[i - 1] != i){
                int t;
                for (int j = 1; j <= i; j++){
                    if (a[j - 1] == i){
                        t = j;
                        break;
                    }
                }

                for (int j = t + 1; j <= i; j++){
                    swap(a[t - 1], a[j - 1]);
                    ans++;
                    t++;
                }
            }
        }
        cout << ans;
        return 0;
    }
}
