#include<bits/stdc++.h>

using namespace std;

#define task "COOLMAC"
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
const int N=1e5+5;

int m,n,mn=1e9;
int stable[N][25];

void prepare()
{
    for(int i=1;i<=100000;++i)
    {
        stable[i][0]=max(stable[i][0],stable[i-1][0]);
    }

    for(int j=1;j<=24;++j)
    {
        for(int i=0;i<=100000;++i)
        {
            if(stable[i][j-1]!=-1) stable[i][j]=stable[stable[i][j-1]][j-1];
        }
    }
}
bool check(int val)
{
    int l=mn;

    for(int i=24;i>=0;--i)
    {
        if(stable[l][i]==-1) continue;

        if(val-(1<<i)>=0)
        {
            l=stable[l][i];
            val-=(1<<i);
        }
    }

    return (l>=100000);

}
void gogo()
{
    cin>>m;

    for(int i=0;i<=100000;++i)
    {
        for(int j=0;j<=24;++j)
        {
            stable[i][j]=-1;
        }
    }

    for(int i=1;i<=m;++i)
    {
        int l,r;
        cin>>l>>r;
        stable[l][0]=max(stable[l][0],r);
    }

    cin>>n;

    for(int i=1;i<=n;++i)
    {
        int t;
        cin>>t;
        mn=min(mn,t);
    }

    prepare();

    int l=0, r=1e5, ans=-1;

//    cout<<stable[10][0]<<endl;
//    cout<<check(2)<<endl;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            r=mid-1;
            ans=mid;
        }
        else l=mid+1;
    }

    cout<<ans;
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
    return 0;
}






