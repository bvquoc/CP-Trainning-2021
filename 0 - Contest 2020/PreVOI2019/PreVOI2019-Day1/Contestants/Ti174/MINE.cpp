#include<bits/stdc++.h>
#define ll long long
#define db double
#define maxx 200012
#define fi first
#define se second
#define pp pair<int,int>
#define pb push_back
#define mp make_pair
using namespace std;


const int mod=1e6+3;
int n,m;
int d[maxx];
int check[maxx];
ll a[maxx];
ll f[maxx];
int res=0;

void sub2(){
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    f[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            f[i]=(f[i]+f[j]*f[i-j])%mod;
        }
        f[i]=(f[i]+1)%mod;
    }
    cout<<f[n];
}

int solve(){
    int cc[30];
    int spon[30];
    int ok[30];
    spon[0]=1;
    for(int i=1;i<=2*n;i++){
        ok[i]=0;
        cc[i]=0;
        spon[i]=0;
    }
    for(int i=1;i<=2*n;i++){
        if(spon[d[i]-1]==0)return 0;
        spon[d[i]]=1;
        if(cc[d[i]]==0){
            cc[d[i]]=i;
        }
        else{
            if(a[i]-a[cc[d[i]]]>m)return 0;
            for(int j=cc[d[i]]+1;j<i;j++)
                if(ok[j]==0)return 0;
            ok[cc[d[i]]]=1;
            ok[i]=1;
        }
    }
//    for(int i=1;i<=2*n;i++){
//        cout<<d[i]<<" ";
//    }
//    cout<<"\n";
    return 1;
}

void quaylui(int k){
    for(int i=1;i<=n;i++){
        if(check[i]<2){
            check[i]++;
            d[k]=i;
            if(k==2*n)
                res=(res+solve())%mod;
            else
                quaylui(k+1);
            check[i]--;
        }
    }
}

void sub1(){
    for(int i=1;i<=2*n;i++){
        cin>>a[i];
    }
    quaylui(1);
    cout<<res;
}

void kaisa(){
    freopen("MINE.INP","r",stdin);
    freopen("MINE.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    if(n<=10)
        sub1();
    else
        sub2();

}

int main()
{
    kaisa();

    return 0;
}
