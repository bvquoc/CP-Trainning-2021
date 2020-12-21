#include<bits/stdc++.h>

using namespace std;

#define task "DECOR"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define CNTBIT __builtin_popcountll
#define ALL(v) (v).begin(),(v).end()
#define endl '\n'

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;

const int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
const int dxx[8]={-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};

const ll mod=1000000007; /// 998244353
const int base=311;
const int N=5e5+5;

struct DSU
{
    vector<int> par;

    void kc(int n)
    {
        par.assign(n+5,-1);
    }
    int root(int u)
    {
        if(par[u]<0) return u;
        return par[u]=root(par[u]);
    }
    void dsu(int u, int v)
    {
        u=root(u); v=root(v);
        if(u==v) return;
        if(par[u]>par[v]) swap(u,v);
        par[u]+=par[v];
        par[v]=u;
    }
};

int n,m,k,origin[N],tmp[N];
string s;
DSU dset;

void sub12()
{
    int ans=0, l=0, r=0;
    for(int cnt=0,j=1,i=1;i<=n;++i)
    {
        cnt+=(s[i]=='1');

        while(j<i&&i-j+1>cnt+k)
        {
            cnt-=(s[j]=='1');
            ++j;
        }

        if(ans<i-j+1)
        {
            ans=i-j+1;
            l=j;
            r=i;
        }

//        cout<<j<<' '<<i<<endl;
    }

    if(ans==0) cout<<-1;
    else cout<<l<<' '<<r;
}
void sub3()
{
    for(int i=1;i<=n;++i)
    {
        if(s[i]=='1') origin[dset.root(i)]++;
    }

    int ans=0,L=0,R=0;

    for(int l=1;l<=n;++l)
    {
        int used=k;
        for(int i=1;i<=n;++i) tmp[i]=origin[i];

        for(int r=l;r<=n;++r)
        {
            int root=dset.root(r);
            if(tmp[root]==0)
            {
                if(used) --used;
                else break;
            }
            else --tmp[root];

            if(r-l+1>ans)
            {
                L=l;
                R=r;
                ans=r-l+1;
            }
        }
    }
    if(ans==0) cout<<-1;
    else cout<<L<<' '<<R;
}

//int used[N];
//
//void full()
//{
//    for(int i=1;i<=n;++i)
//    {
//        if(s[i]=='1') origin[dset.root(i)]++;
//    }
//
//    int cnt=0, ans=0, l, r;
//
//    for(int i=1,j=1;i<=n;++i)
//    {
//        while(j<i&&origin[dset.root(i)]==0&&cnt==k)
//        {
//            if(used[j])
//            {
//                --cnt;
//                used[j]=0;
//            }
//            else
//            {
//                ++origin[dset.root(j)];
//            }
//            ++j;
//        }
//
//
//        if(origin[dset.root(i)])
//        {
//            --origin[dset.root(i)];
//            if(ans<i-j+1)
//            {
//                l=j;
//                r=i;
//                ans=i-j+1;
//            }
//        }
//        else
//        {
//            if(cnt<k)
//            {
//                ++cnt;
//                used[i]=1;
//                if(ans<i-j+1)
//                {
//                    l=j;
//                    r=i;
//                    ans=i-j+1;
//                }
//            }
//        }
//
//        cout<<j<<' '<<i<<endl;
//    }
//
//    if(ans==0) cout<<-1;
//    else cout<<l<<' '<<r;
//}
void gogo()
{
    cin>>n>>m>>k>>s;
    s=' '+s;

    dset.kc(n);

    for(int i=1;i<=m;++i)
    {
        int u,v;
        cin>>u>>v;
        dset.dsu(u,v);
    }

    if(m==0) sub12();
    else if(n<=2000) sub3();
    else cout<<-1;

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    gogo();
}







