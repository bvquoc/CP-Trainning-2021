#include <bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define pii pair<int,int>
using namespace std;
const int N=1e6+1;
int a[N],h[N],n,m,b[N];
int main()
{
    freopen("construct.inp","r",stdin);
    freopen("construct.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int test; cin>>test;
    while(test--)
    {
        cin>>n>>m;
        forinc(i,1,n) cin>>a[i];
        while(m--)
        {
            int tp; cin>>tp;
            if(tp==1)
            {
                int l,r,k;
                cin>>l>>r>>k;
                forinc(i,l,r) a[i]+=k;
            }
            if(tp==2)
            {
                int l,r;
                cin>>l>>r;
                priority_queue<pii,vector<pii>,greater<pii> > heap;
                forinc(i,l,r)
                {
                    h[i]=0;
                    b[i]=a[i];
                    heap.push({a[i],i});
                }
                int res=0;
                while(!heap.empty())
                {
                    int cao=heap.top().first; // do cao can xay them
                    int id=heap.top().second;
                    heap.pop();
                    if(cao!=b[id]) continue;
                    res+=cao;
                    //cout<<cao<<' '<<id<<endl;
                    b[id]=0;
                    h[id]=a[id];
                    fordec(i,id-1,l)
                    {
                        if(h[i]>=a[i]) break;
                        h[i]+=cao;
                        b[i]-=cao;
                        if(h[i]<a[i])
                        heap.push({b[i],i});
                    }
                    forinc(i,id+1,r)
                    {
                        if(h[i]>=a[i]) break;
                        h[i]+=cao;
                        b[i]-=cao;
                        if(b[i]>0)
                        heap.push({b[i],i});
                    }
                    //forinc(i,l,r) cout<<b[i]<<' ';
                }
                cout<<res<<'\n';
            }

        }
    }
}
