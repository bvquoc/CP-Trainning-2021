#include<bits/stdc++.h>
using namespace std;
#define job "COOLMAC"
int n,m,t[100001];
struct pii{
    int l,r;
//    bool operator < (const pii&b)
//    {
//        return l<=b.l;
//    }
}p[100001];
struct cmp{
    bool operator () (pii& a,pii& b){
        return a.l<b.l;
    }
};
void enter(){
    cin>>m;
    for(int i=1;i<=m;i++)
        cin>>p[i].l>>p[i].r;
    sort(p+1,p+m+1,[](pii& a,pii& b){return a.l<b.l;});
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>t[i];
    sort(t+1,t+n+1);
}
void solve(){
    vector<pii> st;
    st.push_back(p[1]);
    for(int i=2;i<=m;i++){
        if(st.back().l <=p[i].l && st.back().r >=p[i].r)
            continue;
        st.push_back(p[i]);
    }
    bool ans=1;
    for(int i=1;i<=n;i++){
        bool flag=1;
        if(st[1].l>t[i] || st.back().r<t[i])
            flag=0;
        ans=flag;
    }
    if(ans){
        for(int i=1;i<st.size();i++)
            if(st[i].l>st[i-1].r){
                cout<<-1;
            }
        else
            cout<<st.size();
        return;
    }
    cout<<-1;
}
int main()
{
    freopen(job".inp","r",stdin);
    freopen(job".out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    enter();
    solve();
}

