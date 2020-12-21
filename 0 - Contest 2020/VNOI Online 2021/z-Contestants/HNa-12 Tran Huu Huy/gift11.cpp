#include<bits/stdc++.h>
using namespace std;
#define Soloz "gift11"
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
int T;
int n;
const int mod=998244353;
string s[2005];

void add(int &val,int g, int x)
{
    if(x==1)
        val=val+g;
    else
        val=val-g;
}

void sub1()
{
    vector < int > v;
    for(int i=1;i<=n;++i)
        v.push_back(i);
    int num=0;
    int out=0;
    do
    {
        int SUM=0;
        int num=0;
        for(int i=0;i<v.size();++i)
        {
            for(int j=0;j<s[v[i]].size();++j)
            {
                ++num;
                add(SUM,s[v[i]][j]-'0',num%2);
            }
        }
        if(SUM%11==0)
            ++out;
    }while(next_permutation(v.begin(),v.end()));
    cout<<out<<"\n";
}

void sub2()
{
    int SUM=0;
    int num=0;
    FOR(i,1,n)
    {
        for(int j=0;j<s[i].size();++j)
        {
            ++num;
            add(SUM,s[i][j]-'0',num%2);
        }
    }
    if(SUM%11!=0)
        cout<<"0\n";
    else
    {
        int ans=1;
        for(int i=1;i<=n;++i)
            ans=(1ll*ans*i)%mod;
        cout<<ans<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Soloz".inp","r",stdin);
    freopen(Soloz".out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        int CHECK=1;
        for(int i=1;i<=n;++i)
        {
            cin>>s[i];
            if(s[i].size()%2==0)
                CHECK=CHECK&1;
            else
                CHECK=CHECK&0;
        }
        if(CHECK==1)
            sub2();
        else
        if(n<=9)
            sub1();
    }
    return 0;
}
