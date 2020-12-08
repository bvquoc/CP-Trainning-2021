#include<bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define pii pair<int,int>
#define st first
#define nd second
#define int long long
#define mid (l+r)/2
using namespace std;
const int N=1e6+4;
int n,m,T,cnt;
int a[N],h[N],c[N];
int t[4*N],b[4*N];
priority_queue<pair<int,pii>> q;
main()
{
    freopen("CONSTRUCT.inp","r",stdin);
    freopen("CONSTRUCT.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();cout.tie();
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        forinc(i,1,n) {cin >> a[i];h[i]=a[i];}
        while(m--)
        {
            int ch,l,r,k,res=0;
            cin >> ch >> l >> r;
            if (ch==1)
            {
                cin >> k;
                forinc(i,l,r) a[i]+=k;
                forinc(i,1,n) h[i]=a[i];
            }
            else
            {
                int dem=0;
                q.push({r-l+1,{l,r}});
                while(!q.empty())
                {
                    cnt=0;
                    int d=q.top().st;
                    int u=q.top().nd.st;
                    int v=q.top().nd.nd;
                    q.pop();
                    dem++;
                    int mi=*min_element(h+u,h+1+v);
                    forinc(i,u,v)
                    {
                        if (mi==h[i]) c[++cnt]=i;
                        h[i]-=mi;
                    }
                    res+=mi;
                    if (c[1]>u && c[1]-u!=0) q.push({abs(c[1]-u),{u,c[1]-1}});
                    else if (c[1]<u && u-c[1]!=0) q.push({abs(c[1]-u),{c[1]+1,u}});
                    if (v-c[cnt]!=0 && v!=c[cnt]) q.push({v-c[cnt],{c[cnt]+1,v}});
                    forinc(i,1,cnt-1)
                    {
                        if (c[i+1]-c[i]-1!=0) q.push({c[i+1]-c[i]-1,{c[i]+1,c[i+1]-1}});
                    }
                }
                cout << res << "\n";
            }
        }
    }
}
