#include <bits/stdc++.h>
#define int long long
using namespace std;
const string filename="GARDEN";
const int nmax=2e3+5;

template <typename T>
inline void Read(T& x) {
    bool Neg=false;
    char c;
    for (c=getchar();c<'0' || c>'9';c=getchar()) if (c=='-') Neg=!Neg;
    x=c-'0';
    for (c=getchar();c>='0' && c<='9';c=getchar()) x=x*10+c-'0';
    if (Neg) x=-x;
}
template <typename T>
inline void Write(T x) {
    if (x<0) { putchar('-'); x=-x; }
    T p=1;
    for (T temp=x/10;temp>0;temp/=10) p*=10;
    for (;p>0;x%=p,p/=10) putchar(x/p+'0');
}

int n,m,a[nmax][nmax],res=0;

void update(int u, int v, int k1,int k2) {
    for(int i=u; i<u+k1; ++i) {
        for(int j=v; j<v+k2; ++j) {
            ++a[i][j];
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen((filename+".INP").c_str(),"r",stdin);
    freopen((filename+".OUT").c_str(),"w",stdout);
    Read(m); Read(n);
    for(int i=1; i<=m; ++i) {
        for(int j=1; j<=n; ++j) {
            char x;
            // cin>>x;
            do x=getchar();
            while (x==' ' || x=='\n');
            if(x=='.') a[i][j]=1;
            else a[i][j]=0;
            res+=a[i][j];
        }
    }
    for(int i=1; i<=m; ++i) {
        for(int j=1; j<=n; ++j) {
            if(a[i][j]>0) {
                int d=n-j+1;
                for(int k1=1; k1<=m-i+1; ++k1) {
                    for(int k2=1; k2<=d; ++k2) {
                        if(k1==k2 && k1==1) continue;
                        if(a[i+k1-1][j+k2-1]>0) res+=(k1*k2);
                        else {
                            d=k2-1;
                            break;
                        }
                    }
                    if(d==0)    break;
                }
            }
        }
    }
    Write(res);
    return 0;
}
