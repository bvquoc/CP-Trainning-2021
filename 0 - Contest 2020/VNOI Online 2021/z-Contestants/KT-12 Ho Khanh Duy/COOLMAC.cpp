#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const ll N = 1e5+5;
const ll INF = 1e9;

typedef pair <ll, ll> ii;

bool cmp(ii a, ii b){
    return a.fi < b.fi || a.fi == b.fi && a.se > b.se;
}

ll n, m, k;
ii a[N];

void solve(){
    sort(a+1, a+m+1, cmp);

    stack <ii> st;

    ll start = 0, ln = 0;
    for (ll i=1; i<=m; i++){
        if (a[i].fi <= k && a[i].se > ln){
            start = i;
            ln = a[i].se;
        }
    }

    if (start == 0){
        cout << -1;
        exit(0);
    }

    st.push(a[start]);
    for (ll i=start + 1; i<=m; i++){
        ii tmp = st.top();
        if (a[i].se < tmp.se || a[i].fi > tmp.se) continue;

        while (st.size() >= 2){
            ii tmp2 = st.top();
            st.pop();
            ii tmp1 = st.top();

            if (a[i].fi <= tmp1.se){
                continue;
            }
            else{
                st.push(tmp2);
                break;
            }
        }

        st.push(a[i]);
    }

    ii tmp = st.top();
    if (tmp.se >= 1e5)
        cout << st.size();
    else cout << -1;

//    cout << "\n";
//    while (st.size()){
//        ii tmp = st.top();
//        st.pop();
//        cout << tmp.fi << " " << tmp.se << "\n";
//    }
}

int main()
{
    freopen("COOLMAC.inp","r",stdin);
    freopen("COOLMAC.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> m;
    for (ll i=1; i<=m; i++)
        cin >> a[i].fi >> a[i].se;

    cin >> n;
    k = 1e9;
    for (ll i=1; i<=n; i++){
        ll x; cin >> x;
        k = min(k, x);
    }

    solve();

    return 0;
}
