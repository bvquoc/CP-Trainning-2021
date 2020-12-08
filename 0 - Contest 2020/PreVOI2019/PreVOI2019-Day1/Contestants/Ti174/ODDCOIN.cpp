#include<bits/stdc++.h>
#define ll long long
#define db double
#define maxx 100112
#define fi first
#define se second
#define pp pair<ll,ll>
#define pb push_back
#define mp make_pair
using namespace std;

const int oo=1e5;
const int ooo=1e9;
int q;
int a[20]={1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
int b[20];
int f[maxx];


void kaisa(){
    freopen("ODDCOIN.INP","r",stdin);
    freopen("ODDCOIN.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>q;
    while(q--){
        int x,t;cin>>x>>t;
        for(int i=0;i<=14;i++){
            b[i]=a[i];
        }
        b[15]=x;
        sort(b,b+1+15);



        int temp=b[15];
        int dem=0;
        if(t>oo){
            dem=(t-oo)/temp;
            if((t-oo)%temp!=0)dem++;
            t-=dem*temp;
//            cout<<dem<<" "<<t;
        }
        f[0]=0;
        for(int i=1;i<=t;i++){
            f[i]=ooo;
            for(int j=0;j<=15;j++){
                if(i>=b[j]){
                    f[i]=min(f[i],f[i-b[j]]+1);
                }
            }
        }
        cout<<f[t]+dem<<"\n";
    }
}

int main()
{
    kaisa();

    return 0;
}
