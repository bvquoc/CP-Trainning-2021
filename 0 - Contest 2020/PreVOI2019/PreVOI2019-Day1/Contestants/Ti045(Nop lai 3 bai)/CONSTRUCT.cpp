#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)#define onbit(x,i) (x|(1<<(i-1)))#define offbit(x,i) (x&~(1<<(i-1)))
const int N=100010;
int n,m,nx[N],dd[N];
ll a[N],b[N],c[N];
stack<int> st;
int main()
{
    freopen("CONSTRUCT.inp","r",stdin);
    freopen("CONSTRUCT.out","w",stdout);
    int T=in;
    while(T--)
    {
        n=in,m=in;
        forinc(i,1,n) a[i]=in;
        a[n+1]=-1;
        while(m--)
        {
            int it=in;
            if(it==1)
            {
                int l=in,r=in,x=in;
                forinc(i,l,r) a[i]+=x;
            }
            else
            {
                int l=in,r=in;
                c[l-1]=0;
                forinc(i,l,r) b[i]=a[i],c[i]=dd[i]=0;
                ll ans=0;
                st.push(n+1);
                fordec(i,r,l)
                {
                    while(a[i]<=a[st.top()]) st.pop();
                    nx[i]=st.top();
                    st.push(i);
                }
                while(!st.empty()) st.pop();
                forinc(i,l,r)
                {
                    c[i]+=c[i-1];
                    b[i]-=c[i];
                    c[i+1]+=b[i];
                    c[nx[i]]-=b[i];
                    dd[nx[i]]=1;
                    if(!dd[i]) ans+=b[i];
                }
                cout<<ans<<"\n";
            }
        }
    }
}
