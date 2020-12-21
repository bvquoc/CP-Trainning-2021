#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn=2e5+5;
const int mod=1e9+7;
int bit[maxn];
int ord[maxn]; // this is to calculate the remaining permutation order
int fact[maxn];
int n;
void init() {
    fact[0]=1;
    for(int i=1 ; i<=n ; i++) {
        fact[i]=(fact[i-1]*i)%mod;
    }
}
void upd(int id) {
    for(id ; id<=n ; id+=id&-id) {
        bit[id]++;
    }
}
int sum(int id) {
    int ans=0;
    for(id ; id>0 ; id-=id&-id) {
        ans+=bit[id];
    }
    return ans;
}
int ans1=0;
int ans2=0;
// main
int ans[maxn];
int a[maxn];
signed main() {
    freopen("PERMEOW.inp","r",stdin);
    freopen("PERMEOW.out","w",stdout);
    cin>>n;
    init();
    ans[1]=0;
    for(int i=2 ; i<=n ; i++) {
        int add=(i*(i-1)/2)%mod;
        add=(add*fact[i-1])%mod;
        ans[i]=(ans[i-1]*i+add)%mod;
    }
    for(int i=1 ; i<=n ; i++) {
        cin>>a[i];
    }
    for(int i=n ; i>=1 ; i--) {
        upd(a[i]);
        ord[i]=sum(a[i]);
    }
    // for(int i=1 ; i<=n ; i++) cout<<ord[i]<<" ";
    // cout<<endl;
    int cur_add=0;
    for(int i=1 ; i<=n ; i++) {
        int add=0;
        int ye=0;
        if(ord[i]!=1) {
            add=ans[n-i]*(ord[i]-1);
            //cout<<"current add = "<<cur_add<<endl;
            //cout<<"add = "<<add<<endl;
            int bruh=(ord[i]-2)*(ord[i]-1)/2;
            bruh%=mod;
            ye=fact[n-i]*(ord[i]-1)%mod;
            bruh=(bruh*fact[n-i])%mod;
            add=(add+bruh)%mod;   
        }
        add=(add+cur_add*ye)%mod;
        ans1=(ans1+add)%mod;
        cur_add+=(ord[i]-1);
    }
    //cout<<"ans1 = "<<ans1<<endl;
    for(int i=1 ; i<=n ; i++) bit[i]=0;
    for(int i=1 ; i<=n ; i++) {
        cin>>a[i];
    }
    for(int i=n ; i>=1 ; i--) {
        upd(a[i]);
        ord[i]=sum(a[i]);
        ans2+=(ord[i]-1);
    }
    cur_add=0;
    for(int i=1 ; i<=n ; i++) {
        int add=0;
        int ye=0;
        if(ord[i]!=1) {
            add=ans[n-i]*(ord[i]-1);
            //cout<<"current add = "<<cur_add<<endl;
            //cout<<"add = "<<add<<endl;
            int bruh=(ord[i]-2)*(ord[i]-1)/2;
            bruh%=mod;
            ye=fact[n-i]*(ord[i]-1)%mod;
            bruh=(bruh*fact[n-i])%mod;
            add=(add+bruh)%mod;   
        }
        add=(add+cur_add*ye)%mod;
        ans2=(ans2+add)%mod;
        cur_add+=(ord[i]-1);
        cur_add%=mod;
    }
    int ansss=ans2-ans1;
    if(ansss<0) ansss+=mod;
    cout<<ansss;
}