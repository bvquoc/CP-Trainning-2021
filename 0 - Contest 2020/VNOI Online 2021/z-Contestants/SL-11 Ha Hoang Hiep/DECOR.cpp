#include <bits/stdc++.h>
using namespace std;
#define job "DECOR"
struct pos{
    int l,r;
}p[500005];
int n,m,k,a[500005];
void enter(){
    cin>>n>>m>>k;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]-'0'==0)
            a[i+1]=0;
        else a[i+1]=1;
    }
    for(int i=1;i<=m;i++)
        cin>>p[i].l>>p[i].r;
}
namespace sub1{
    long long ans=0,flag,ch;
    void solve(){
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i-1] && a[i]==1)
                flag=i;
            if(a[i]!=a[i-1] && a[i]==0)
                ans=max(ans,i-flag),ch=i;
        }
        cout<<flag<<' '<<ch;
    }
}
namespace sub2{
    int num=0,res=0,ans=0;
    void solve(){
        for(int i=1;i<=n;i++)
            num+=a[i];
        if(num+k>=n){
            cout<<1<<' '<<n;
            return;
        }
        int flag,ch;
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i-1] && a[i]==1)
                flag=i;
            if(a[i]!=a[i-1] && a[i]==0)
                if(ans<i-flag)
                    ans=i-flag,
                    ch=flag;
        }
        cout<<1<<' '<<n;
    }
}
void solve(){
    if(m==0){
        if(k==0)
            sub1::solve();
        else
            sub2::solve();
    }
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
