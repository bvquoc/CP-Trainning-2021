#include <bits/stdc++.h>
using namespace std;

#define oo 1e9
#define fi first
#define se second
#define sp(iiii) setprecision(iiii)
#define IO ios_base::sync_with_stdio(false); cin.tie(0)
#define ms(aaaa,xxxx) memset(aaaa,xxxx,sizeof(aaaa))
#define cntbit(xxxx) __builtin_popcount(xxxx)
#define getbit(xxxx,aaaa) ((xxxx>>(aaaa-1))&1)


typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
typedef pair<long long,long long> pll;
typedef pair<pair<long long,long long>,long long> plll;

const ll mod=1e9+7;

bool comp(pll x,pll y) {
    return x.fi>y.fi;
}

vector<pll> st;
pll a[500009];
ll n,i,t,it,k,ans,res;

int main(){
    IO;
    freopen("coolmac.inp", "r", stdin);
    freopen("coolmac.out", "w", stdout);
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>a[i].se>>a[i].fi;
    }
    sort(a+1,a+n+1,comp);
    st.push_back({100001,100001});
    for (i=1;i<=n;i++) {
        while (a[i].fi>=st.back().fi&&a[i].se<=st.back().se) {
            st.pop_back();
        }
        if (a[i].fi>=st.back().se-1&&a[i].se<=st.back().se) {
            st.push_back({min(st.back().se-1,a[i].fi),a[i].se});
        }
    }
    //for (i=0;i<st.size();i++) {
    //    cout<<st[i].fi<<' '<<st[i].se<<'\n';
    //}
    cin>>t;
    for (it=1;it<=t;it++) {
        cin>>k;
        ans=st.size();
        for (i=st.size();i>0;i/=2) {
            while (ans-i>=0&&st[ans-i].se<=k) {
                ans-=i;
            }
        }
        if (ans==st.size()) {
            cout<<-1<<'\n';
            return 0;
        }
        else {
            res=max(res,ans);
        }
    }
    cout<<res<<'\n';
}
