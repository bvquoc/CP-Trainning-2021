#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define taskname "CONSTRUCT"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int maxn = 1e5 + 5;

namespace Sub12{
    const int maxn = 1e3 + 5;
    const int logn = 10;
    int n , m;
    ll a[maxn];
    ll lef[maxn] , rig[maxn];
    void solve(){
        cin >> n >> m;
        for(int i = 1 ; i <= n ; ++i){
            cin >> a[i];
        }
        while(m--){
            int type;cin >> type;
            if(type == 1){
                int l , r , k;cin >> l >> r >> k;
                for(int i = l ; i <= r ; ++i)a[i] += k;
            }else{
                int l , r;cin >> l >> r;
                ll res = 0;
                vector<int> s;
                for(int i = l ; i <= r ; ++i){
                    while(s.size() && a[i] <= a[s.back()])s.pop_back();
                    if(s.size())lef[i] = a[s.back()];
                    else lef[i] = 0;
                    s.pb(i);
                }
                s.clear();
                for(int i = r ; i >= l ; --i){
                    while(s.size() && a[i] < a[s.back()])s.pop_back();
                    if(s.size())rig[i] = a[s.back()];
                    else rig[i] = 0;
                    s.pb(i);
                    res += a[i] - max(lef[i],rig[i]);
                }
                cout << res << '\n';
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP","r")){
		freopen(taskname".INP", "r",stdin);
		freopen(taskname".OUT", "w",stdout);
    }
    int t;cin >> t;
    while(t--){
        Sub12::solve();
    }
}

