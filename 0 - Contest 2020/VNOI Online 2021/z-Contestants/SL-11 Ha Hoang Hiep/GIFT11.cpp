#include<bits/stdc++.h>
using namespace std;
#define job "GIFT11"
#define mod 998244353
int t,flag=0;
struct pii{
    int f,s;
};
vector<pii> vt[2002];
int lg10(int n){
    int dem=0;
    while(n>=10){
        n/=10;
        dem++;
    }
    return dem;
}
void enter(){
    cin>>t;
    for(int i=1,n,x;i<=t;i++){
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>x;
            vt[i].push_back({x,j});
            if(lg10(x)+1 & 1)
                flag=1;
        }
//        sort(vt[i].begin(),vt[i].end(),[](pii& a,pii& b){return a.s<b.s;});
    }
}
string toString(long long n){
    string a;
    bool ans=0;
    while(n){
        long long t=n%10;
        a+=char(t+'0');
        n/=10;
    }
    reverse(a.begin(),a.end());
    return a;
}
bool Div11(string a){
    int odd=0,even=0;
    for(int i=0;i<a.size();i++){
        if(i&1)
            odd+=a[i]-'0';
        else
            even+=a[i]-'0';
    }
    if(abs(odd-even)%11==0)
        return 1;
    else
        return 0;
}
namespace sub1{
    void add(int &a)
    {
        a++;
        if(a>=mod)
            a-=mod;
    }
    void solve(){
    for(int i=1;i<=t;i++){
        int ans=0;
        do{
            string a;
            for(auto x:vt[i])
                a+=toString(x.f);
            if(Div11(a))
                add(ans);
        }while(next_permutation(vt[i].begin(),vt[i].end(),
                    [](pii& a,pii& b){return a.s<b.s;}
        ));
        cout<<ans<<'\n';
        }
    }
}
namespace sub2{
    long long fra[2002];
    void frac(){
        fra[1]=1;
        for(int i=2;i<=2001;i++)
            fra[i]=(fra[i-1]*i)%mod;
    }
    void solve(){
        frac();
        for(int i=1;i<=t;i++){
            string a;
            int n=vt[i].size();
            for(auto x:vt[i])
                a+=toString(x.f);
            if(Div11(a))
                cout<<fra[n]<<'\n';
            else
                cout<<0<<'\n';
        }

    }
}

void solve(){

    switch(flag){
        case 0:sub2::solve();break;
        default :sub1::solve();break;
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
