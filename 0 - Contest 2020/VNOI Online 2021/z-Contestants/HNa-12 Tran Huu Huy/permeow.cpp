#include<bits/stdc++.h>
using namespace std;
#define Soloz "permeow"
#define F first
#define S second
#define pb push_back
typedef long long ll;
#define fore(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();++it)

template<class T> inline void Write(T x){if(x<0){putchar('-');x*=-1;}if(x>9) Write(x/10);putchar(x%10+'0');}
template<class T>inline void Read(T &x){char c;for(c=getchar();(c>'9'||c<'0')&&c!='-';c=getchar());
T y;if(c=='-')x=0,y=-1;else x=c-'0',y=1;for(c=getchar();c>='0'&&c<='9';c=getchar())x=x*10+c-'0';x*=y;}

mt19937 Rand(time(0));
#define endl "\n"
#define al(a) ((a).begin(),(a).end())
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define ep emplace_back
int n;
const int maxn=2e5+5;
const int mod=1e9+7;
int a[maxn],b[maxn];
void sub1()
{
    int out=0;
    for(int i=2;i<=n;++i)
        for(int j=1;j<i;++j)
        if(a[i]<a[j])
        out=(out+1)%mod;
    cout<<out;
    exit(0);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Soloz".inp","r",stdin);
    freopen(Soloz".out","w",stdout);
    cin>>n;
    int checksame=1;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n){
        cin>>b[i];
        checksame=checksame&(a[i]==b[i]);
    }
    if(checksame==1)
        sub1();

    return 0;
}
