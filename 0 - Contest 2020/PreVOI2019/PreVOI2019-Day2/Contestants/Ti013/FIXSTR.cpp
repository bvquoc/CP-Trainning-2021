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
const int N=1e6+1;
int n, m;
string S;
vector<pii> it;
struct query
{
    int t, x, y;
};
vector<query> q;
vector<int> v, v1;
void process(int l, int r)
{
    int cnt=0, res=0;
    for(int i=l; i<=r; i++){
        cnt+=v1[i];
        if(cnt<0){
            cnt=0; res++;
        }
    }
    cout<<res+cnt<<'\n';
}
void process1(int x)
{
    v1=v;
    for(int i=0; i<x; i++){
        if(q[i].t==0) v1[q[i].x-1]*=-1;
    }
}
bool chksub2()
{
    for(int i=0; i<q.size(); i++){
        if(q[i].t==1) return 0;
    }
    return 1;
}
struct segment_tree
{
    void upd(int id)
    {
        int t=min(it[2*id].se, it[2*id+1].fi);
        it[id].fi=it[2*id].fi+it[2*id+1].fi-t;
        it[id].se=it[2*id].se+it[2*id+1].se-t;
    }
    void init(int id, int l, int r)
    {
        if(l==r){
            it[id]={0, 0};
            if(v[l-1]==1) it[id].se++;
            else it[id].fi++; return;
        }
        int mid=(l+r)/2;
        init(2*id, l, mid);
        init(2*id+1, mid+1, r);
        upd(id);
    }
    void upd1(int id, int l, int r, int pos)
    {
        if(pos<l||r<pos) return;
        if(l==r){
            it[id]={0, 0};
            if(v[l-1]==1) it[id].se++;
            else it[id].fi++; return;
        }
        int mid=(l+r)/2;
        upd1(2*id, l, mid, pos);
        upd1(2*id+1, mid+1, r, pos);
        upd(id);
    }
    pii get(int id, int l, int r, int l1, int r1)
    {
        if(r1<l||r<l1) return {0, 0};
        if(l1<=l&&r<=r1) return it[id];
        int mid=(l+r)/2;
        pii ret1=get(2*id, l, mid, l1, r1);
        pii ret2=get(2*id+1, mid+1, r, l1, r1);
        int t=min(ret1.se, ret2.fi);
        return {ret1.fi+ret2.fi-t, ret1.se+ret2.se-t};
    }
} IT;
main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("FIXSTR.inp", "r", stdin);
    freopen("FIXSTR.out", "w", stdout);
    cin>>S; n=S.size();
    cin>>m; q=vector<query>(m);
    char c;
    for(int i=0; i<q.size(); i++){
        cin>>c>>q[i].x;
        if(c=='C') q[i].t=0;
        else if(c=='U') q[i].t=1;
        else{
            q[i].t=2; cin>>q[i].y;
        }
    }
    for(int i=1; i<=n; i++){
        if(S[i-1]=='(') v.pb(1);
        else v.pb(-1);
    }
    v1=v;
    if(n<=1000&&m<=1000){
        for(int i=0; i<q.size(); i++){
            if(q[i].t==0) v1[q[i].x-1]*=-1;
            else if(q[i].t==1) process1(q[i].x-1);
            else process(q[i].x-1, q[i].y-1);
        }
    }
    else if(chksub2()){
        it=vector<pii>(4*(n+1));
        IT.init(1, 1, n);
        pii x;
        for(int i=0; i<q.size(); i++){
            if(q[i].t==0){
                v[q[i].x-1]*=-1;
                IT.upd1(1, 1, n, q[i].x);
            }
            else if(q[i].t==2){
                x=IT.get(1, 1, n, q[i].x, q[i].y);
                cout<<x.fi+x.se<<'\n';
            }
        }
    }
}
