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
const ll maxn=2000;

//ll fact[4009],c[4009][4009],f1[2009][2009][13],f2[2009][2009][13],n,i,j,i2,t,it,m1,m2,k,x,res;
//pll a[4009],l[4009],r[4009];

ll fact[4009],t,it,n,i,res,cnt,a[5009],b[5009];
bool ok[5009];

bool check() {
    //cout<<it<<' '<<n<<'\n';
    int k=0;
    int kq=0;
    vector<int> d;
    for (int ii=1;ii<=n;ii++) {
        int tmp=a[ii];
        d.clear();
        while (tmp>0) {
            d.push_back(tmp%10);
            tmp/=10;
        }
        for (int ij=d.size()-1;ij>=0;ij--) {
            k++;
            if (k%2==0) {
                kq-=d[ij];
            }
            else {
                kq+=d[ij];
            }
        }
    }
    //cout<<kq<<'\n';
    if (kq%11==0) {
        return true;
    }
    else {
        return false;
    }
}

void tryt(int x,int y) {
    if (x==n) {
        if (check()) {
            res++;
        }
    }
    else {
        for (int ii=1;ii<=n;ii++) {
            if (!ok[ii]) {
                ok[ii]=true;
                b[x+1]=a[ii];
                tryt(x+1,ii);
                ok[ii]=false;
            }
        }
    }
}

void solvesub1() {
    res=0;
    tryt(0,0);
    cout<<res<<'\n';
}

int main(){
    IO;
    freopen("gift11.inp", "r", stdin);
    freopen("gift11.out", "w", stdout);
    return 0;
    cin>>t;
    fact[0]=1;
    for (i=1;i<=2*maxn;i++) {
        fact[i]=(fact[i-1]*i)%mod;
    }
    for (it=1;it<=t;it++) {
        res=0;
        //cnt=0;
        cin>>n;
        for (i=1;i<=n;i++) {
            cin>>a[i];
        }
        if (n<=9) {
            solvesub1();
        }
        //else if (checksub2()) {
        //    solvesub2();
        //}
        //else {
        //    solvesub3();
        //}
    }
    /*
    for (i=0;i<=2*maxn;i++) {
        c[i][0]=1;
    }
    for (i=1;i<=2*maxn;i++) {
        //c[i][1]=i;
        for (j=1;j<=i;j++) {
            //if (i==j) {
            //    c[i][j]=1;
            //}
            //else {
                c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
            //}
        }
    }
    //return 0;
    cin>>t;
    for (it=1;it<=t;it++) {
        cin>>n;
        m1=0;
        m2=0;
        res=0;
        for (i=1;i<=n;i++) {
            a[i]={0,0};
            cin>>x;
            k=0;
            while (x>0) {
                if (k%2==0) {
                    a[i].fi+=x%10;
                }
                else {
                    a[i].se+=x%10;
                }
                x/=10;
                k++;
            }
            if (k%2!=0) {
                m1++;
                l[m1]=a[i];
            }
            else {
                m2++;
                r[m2]=a[i];
            }
        }
        f1[0][0][0]=1;
        f2[0][0][0]=1;
        for (i=1;i<=m1;i++) {
            for (i2=0;i2<11;i2++) {
                f1[i][0][i2]=(f1[i][0][i2]+f1[i-1][0][(i2+l[i].se-l[i].fi+11*10000000)%11])%mod;
            }
        }
        for (i=1;i<=m2;i++) {
            for (i2=0;i2<11;i2++) {
                f2[i][0][i2]=(f2[i][0][i2]+f2[i-1][0][(i2+r[i].se-r[i].fi+11*10000000)%11])%mod;
            }
        }
        for (i=1;i<=m1;i++) {
            for (j=1;j<=(m1+1)/2;j++) {
                for (i2=0;i2<11;i2++) {
                    f1[i][j][i2]=(f1[i][j][i2]+f1[i-1][j-1][(i2+l[i].se-l[i].fi+11*10000000)%11]+f1[i-1][j][(i2-l[i].se+l[i].fi+11*10000000)%11])%mod;
                }
            }
        }
        for (i=1;i<=m2;i++) {
            for (j=1;j<=m2;j++) {
                for (i2=0;i2<11;i2++) {
                    f2[i][j][i2]=(f2[i][j][i2]+f2[i-1][j-1][(i2+r[i].se-r[i].fi+11*1000000)%11]+f2[i-1][j][(i2-r[i].se+r[i].fi+11*10000000)%11])%mod;
                }
            }
        }
        for (i=0;i<=m2;i++) {
            for (i2=0;i2<11;i2++) {
                res=(res+((((f1[m1][(m1+1)/2][(11-i2)%11]*fact[(m1+1)/2])%mod)*fact[m1/2])%mod)*(((((f2[m2][i][i2]*c[i+(m1+1)/2][i])%mod)*c[m2-i+m1/2][m2-i])%mod)*(fact[m2/2]*fact[(m2+1)/2]))%mod)%mod;
            }
        }
        i=0;
        i2=10;
        cout<<f1[m1][(m1+1)/2][(11-i2)%11]<<' '<<fact[(m1+1)/2]<<' '<<fact[m1/2]<<' '<<f2[m2][i][i2]<<' '<<c[i+(m1+1)/2][i]<<' '<<c[m2-i+m1/2][m2-i]<<' '<<fact[m2/2]<<' '<<fact[(m2+1)/2]<<'\n';
        cout<<res<<'\n';

        //for (i=1;i<=m1;i++) {
        //    cout<<l[i].fi<<' '<<l[i].se<<'\n';
        //}
        //for (i=1;i<=m2;i++) {
        //    cout<<r[i].fi<<' '<<r[i].se<<'\n';
        //}
        cout<<m1<<'\n';
        for (i=1;i<=m1;i++) {
            for (j=0;j<=m1;j++) {
                cout<<f1[i][j][1]<<' ';
            }
            cout<<'\n';
        }
        cout<<m2<<'\n';
        for (i=1;i<=m2;i++) {
            for (j=0;j<=m2;j++) {
                cout<<f2[i][j][10]<<' ';
            }
            cout<<'\n';
        }
    cout<<'\n';
    }
    */
}
