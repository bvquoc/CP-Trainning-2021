#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
pair<int,int> safe[maxn];
int t[maxn];
int n,m;
int mn;
int ans=0;
signed main() {
    freopen("coolmac.inp","r",stdin);
    freopen("coolmac.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>m;
    for(int i=1 ; i<=m ; i++) {
        cin>>safe[i].second>>safe[i].first;
    }
    sort(safe+1,safe+1+m);
    cin>>n;
    for(int i=1 ; i<=n ; i++) {
        cin>>t[i];
        if(i==1) mn=t[i];
        else mn=min(mn,t[i]);
    }
    int cur_mx=100000;
    int cur_pos=m;
    int cur_mn=100001;
    for(int i=m ; i>=1 ; i--) {
        if(safe[i].first<cur_mx) {
            cur_mx=cur_mn;
            cur_mn=100001;
            ans++;
        }
        if(safe[i].first>=cur_mx) cur_mn=min(cur_mn,safe[i].second);
    }
    if(cur_mn>mn) {
        cout<<-1;
        return 0;
    }
    else if(cur_mx>mn) ans++;
    cout<<ans;
}
/*
3
250 100000
150 200
10 300
2
1000 200

2
250 100000
90 248
1
100
*/
