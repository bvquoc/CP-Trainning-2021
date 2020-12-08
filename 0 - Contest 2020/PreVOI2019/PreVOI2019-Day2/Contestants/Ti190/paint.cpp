// KHAz
#include <bits/stdc++.h>
#define maxn 1000005
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007
#define Task "paint"
#define pii pair < int,int >
#define pil pair < int,pii >
using namespace std;
int n;
char ch[10005];
int r[28] , ans[maxn], b[maxn] , dd[28] ,cnt, e[maxn];
pii ne[27][maxn];
vector<pii> g[maxn];
struct dt
{
    int id ,u,v;
};
void sub1()
{
    int cnt=1;
    for(int i=1;i<=n;i++)
    {
        int ty ;char u ,v;
        cin>>ty>>u;
        if(ty==1) ch[cnt++]=u;
        else
        {
            cin>>v;
            for(int j=1;j<cnt;j++)
            {
                if(ch[j]==u) ch[j]=v;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
       cout << ch[i];
    }
}
int res;
void dq(int cur , int pos)
{
  //  cout << cur << ' '<< pos << endl;
    if(pos==cnt+1) {res=cur;b[pos]=res;return ;}
    pii k=ne[cur][pos];
    dq(k.F,k.S);
    b[pos]=res;
}
void sub2()
{
    for(int i=1;i<=n;i++)
    {
        int ty;char u,v;
        cin>>ty>>u;
        if(ty==1) b[++cnt]=u-'a';
        else
        {
            cin>>v;
            int k=u-'a', k1=v-'a';
            if(k==k1) continue;
            g[cnt].PB({k,k1});
            dd[cnt]=1;
        }
    }
 //   cout <<dd[5];
    for(int i=0;i<26;i++) ne[i][cnt+1]={i , cnt+1};
    for(int i=cnt;i>=1;i--)
    {
        for(int j=0;j<26;j++) ne[j][i]=ne[j][i+1];
        if(dd[i])
        {
            for(auto gg:g[i])
            {
            int u=gg.F , v=gg.S;
          //  cout <<i<<' '<< u << ' '<<v<<endl;
            ne[u][i]=ne[v][i];
            }
        }
    }
 for(int i=1;i<=cnt;i++) e[i]=b[i];
 for(int i=1;i<=cnt;i++)
    {
        dq(e[i],i);
    }
    for(int i=1;i<=cnt;i++) cout << (char) (b[i]+97);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    cin>>n;
    if(n<=1e4) sub1();
    else sub2();
//sub2();
    return 0;
}
