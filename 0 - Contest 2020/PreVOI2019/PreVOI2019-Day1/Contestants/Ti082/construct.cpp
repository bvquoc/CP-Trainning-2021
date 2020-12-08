#include <bits/stdc++.h>
#define forinc(i,a,b) for(int i = a; i <= b; ++i)
#define fordec(i,a,b) for(int i = a; i >= b; --i)
#define ll long long
#define f first
#define s second
#define pii pair<int,int>
#define nmax 1000005
#define pb push_back
#define task "construct"
#define endl '\n'
#define reset(x) memset(x,0,sizeof(x))
#define MOD 1000000007
#define mp make_pair
using namespace std;
int n, m,a[100005],kq,t[100001*4],id[100005],del[400004], testcase;
void cnp(int node,int l ,int r)
{
    if (l==r)
    {
        t[node]=a[l];
        id[l]=node;
        return ;
    }
    int g=(l+r)/2;
    cnp(node*2,l,g);
    cnp(node*2+1,g+1,r);
    t[node]=min(t[node*2],t[node*2+1]);
}
void upd(int node, int l, int r, int u, int v, int w)
{
    if(l>v||r<u) return ;
    if (l>=u&&r<=v)
    {
        t[node]+=w;
        del[node]+=w;
        return;
    }
    int g=(l+r)/2;
    upd(node*2,l,g,u,v,w);
    upd(node*2+1,g+1,r,u,v,w);
    t[node]=min(t[node*2], t[node*2+1])+del[node];
}
int getmin(int node, int l ,int r, int u ,int v)
{
    if(l>v||r<u) return INT_MAX;
    if (l>=u&&r<=v) return t[node];
    int g=(l+r)/2;
    int trai=getmin(node*2,l,g,u,v);
    int phai=getmin(node*2+1,g+1,r,u,v);
    return min(trai, phai)+del[node];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>testcase;
    for(int i=1;i<=testcase;i++){
       int type, u, v, w;
       cin>>n>>m;
       for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=m;i++){
            cin>>type;
            if(type==1){
                cin>>u>>v>>w;
                for(int j=u;j<=v;j++) a[j]=a[j]+w;
            }
            else{
                ll res=0; int minn=INT_MAX, cnt=0, cnt2=0;
                cin>>u>>v;
                for(int j=u;j<=v;j++){ minn=min(minn,a[j]);}
                if(a[u]!=minn) cnt=a[u];
                for(int j=u+1;j<=v;j++){if(a[j]==minn){if(cnt!=0||cnt2!=0) res+=(cnt+cnt2-minn); } if(a[j]>=a[j-1]){ cnt=a[j]; cnt2=0;} if(a[j]<=a[j-1]){ cnt2=a[j-1]; cnt=0;}}
                res+=(cnt+cnt2-minn);
                cout<<res+minn<<'\n';
            }
        }
    }
    return 0;
}
