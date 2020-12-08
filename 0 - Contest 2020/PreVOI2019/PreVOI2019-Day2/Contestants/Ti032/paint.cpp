#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define lam_tron cout<<fixed <<setprecision(2);
/*----------------------------------------------*/
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
/*----------------------------------------------*/
const int M=1e6+5;
const int mod=1e9+7;
const double esp=1e-1;
const long double pi=4*atan((long double)1);
/*----------------------------------------------*/
char a[M];
int n;
vector< ii > dad[30];
vector< int > b[30],d[30];
int main()
{
    freopen("paint.inp","r",stdin);
    freopen("paint.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n;
    if(n<=10000)
    {
        int dem=0;
        while(n--)
        {
            int x;
            cin>>x;
            if(x==1)
            {
                char c;
                cin>>c;
                a[++dem]=c;
            }
            else
            {
                char u,v;
                cin>>u>>v;
                for(int i=1;i<=dem;i++) if(a[i]==u) a[i]=v;
            }
        }
        for(int i=1;i<=dem;i++) cout<<a[i];
    }
    else
    {
        int dem=0,dem1=0;
        for(int i=1; i<=n; i++)
        {
            int x;
            cin>>x;
            if(x==1)
            {
                char c;
                cin>>c;
                a[++dem]=c;
            }
            else
            {
                dem1++;
                char u,v;
                cin>>u>>v;
                int uu=u-'a';
                int vv=v-'a';
                dad[uu].pb(ii(dem,vv));
                b[uu].pb(dem);
                d[uu].pb(dem1);
            }
        }
        for(int i=1;i<=dem;i++)
        {
            int k=a[i]-'a';
            int vt=lower_bound(b[k].begin(),b[k].end(),i)-b[k].begin();
            //if(i==1) cout<<vt<<endl;
            int j;
            while(vt<b[k].size())
            {
                j=b[k][vt];
                int bien=d[k][vt];
                k=dad[k][vt].Y;
                int vt1=upper_bound(d[k].begin(),d[k].end(),bien)-d[k].begin();
                vt=lower_bound(b[k].begin()+vt1,b[k].end(),j)-b[k].begin();
            }
            char c=k+'a';
            cout<<c;
        }
    }
    return 0;
}
