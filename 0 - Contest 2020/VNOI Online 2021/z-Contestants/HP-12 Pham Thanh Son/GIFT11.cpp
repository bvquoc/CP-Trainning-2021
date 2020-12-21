#include<bits/stdc++.h>
using namespace std;
#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){ return rng()%(r-l+1)+l;}
#define pii pair<int,int>
#define fi first
#define se second
#define getbit(i,x) ((x>>i)&1ll)
#define tatbit(i,x) (x&~(1ll<<i))
#define batbit(i,x) (x|(1ll<<i))

const int maxn=2010,mod=998244353;

int T;
int n;
int a[maxn],ret;
int A[2][maxn];
int pw[maxn];
int b[maxn],p[maxn],x[maxn];
int dd[20],pos[10];

int get_len(int val){
    int dem=0;
    while(val) val/=10,dem++;
    return dem;
}

int process(int val){
    vector<int> num;
    int ODD=0,EV=0;
    while(val){
        num.push_back(val%10);
        val/=10;
    }
    int sz=num.size()-1;
    reverse(num.begin(),num.end());
    for(int i=0;i<=sz;i++){
        if(i%2==0) ODD+=num[i];
        else EV+=num[i];
    }
    return ODD-EV;
}

int get_mod(int val){
    if(val>0) return val%11;
    else{
        int X=val%11;
        return 11+X;
    }
}

int f[maxn][maxn][12];
int gt[maxn];

main(){
    freopen("GIFT11.inp","r",stdin);
    freopen("GIFT11.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    pw[0]=1;
    forinc(i,1,9) pw[i]=pw[i-1]*10%11;
    cin>>T;
    while(T--){
        cin>>n;
        int SUB2=1;
        forinc(i,1,n){
            cin>>a[i],p[i]=i;
            int z=get_len(a[i]);
            if(z%2==1) SUB2=0;
        }
        if(n<=9){
        ret=0;
        do{
            int z=0;
            forinc(i,1,n) b[i]=a[p[i]];
          //  if(n==9)forinc(i,1,n) cout<<b[i]<<" ";
            forinc(i,1,n){
                int LL=get_len(b[i]);
                z=z*pw[LL]%11;
                z=(z+b[i])%11;
            }
            if(z==0) ret=(ret+1)%mod;

        }while(next_permutation(p+1,p+n+1));
        cout<<ret<<"\n";
        }else if(SUB2){
            int tmp=0;
            forinc(i,1,n){
                A[0][i]=process(a[i]);
                A[1][i]=-process(a[i]);
                tmp+=A[0][i];
            }
            if(tmp%11==0){
                int kq=1;
                forinc(i,2,n) kq=kq*i%mod;
                cout<<kq<<"\n";
            }else cout<<0<<"\n";
        }else{
            gt[0]=1;
            forinc(i,1,n) gt[i]=gt[i-1]*i%mod;
            int sum_mod=0;
            forinc(i,1,n){
                int tmp=get_mod(A[0][i]);
                sum_mod=(sum_mod+tmp)%11;
            }
            int need_even=n/2;
            int expected_mod=(11-sum_mod)%11;

            f[0][0][0]=1;
            /// (need_even)! *((n+1)/2)!
            int ret=gt[need_even] * gt[(n+1)/2]%mod;

            forinc(i,1,n) forinc(j,1,need_even) forinc(t,0,10){
                f[i][j][t]=(f[i][j][t]+f[i-1][j][t])%mod;
                int tmp=get_mod(A[1][i]);
                int pre_mod=(t>=tmp?t-tmp:11+t-tmp);
                f[i][j][t]=(f[i-1][j-1][pre_mod]+f[i][j][t])%mod;
            }
            cout<<f[n][need_even][0]*ret%mod;
        }
    }

}

