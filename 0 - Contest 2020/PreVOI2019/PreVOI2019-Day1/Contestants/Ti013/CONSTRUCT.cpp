#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define pll pair<ll, ll>
#define ppii pair<pii, pii>
#define pli pair<ll, int>
using namespace std;
const int N=1e5+2;
int n, m, it[N], L[N], R[N];
ll a[N];
struct query
{
    int t, l, r, k;
};
vector<query> q;
stack<int> st;
void process()
{
    for(int i=1; i<=n; i++) it[i]=n+1;
    while(!st.empty()) st.pop(); st.push(0);
    for(int i=1; i<=n; i++){
        while(a[st.top()]>=a[i]) st.pop();
        L[i]=st.top(); st.push(i);
    }
    while(!st.empty()) st.pop(); st.push(n+1);
    for(int i=n; i>=1; i--){
        while(a[st.top()]>a[i]) st.pop();
        if(a[st.top()]==a[i]){
            it[i]=st.top(); st.pop();
        }
        R[i]=st.top(); st.push(i);
    }
}
void process1(int l, int r)
{
    ll t, t1, res=0;
    for(int i=l; i<=r; i++){
        if(it[i]<=r) continue;
        if(L[i]<l) t=a[i];
        else t=a[i]-a[L[i]];
        if(R[i]>r) t1=a[i];
        else t1=a[i]-a[R[i]];
        res+=min(t, t1);
    }
    cout<<res<<'\n';
}
main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("CONSTRUCT.inp", "r", stdin);
    freopen("CONSTRUCT.out", "w", stdout);
    int test, t;
    cin>>test;
    while(test--){
        cin>>n>>t; q.clear();
        q=vector<query>(t);
        for(int i=1; i<=n; i++) cin>>a[i];
        a[0]=0; a[n+1]=0;
        for(int i=0; i<q.size(); i++){
            cin>>q[i].t>>q[i].l>>q[i].r;
            if(q[i].t==1) cin>>q[i].k;
        }
        process();
        for(int i=0; i<q.size(); i++){
            if(q[i].t==1){
                for(int j=q[i].l; j<=q[i].r; j++) a[j]+=(ll)q[i].k;
                process();
            }
            else process1(q[i].l, q[i].r);
        }
    }
}
