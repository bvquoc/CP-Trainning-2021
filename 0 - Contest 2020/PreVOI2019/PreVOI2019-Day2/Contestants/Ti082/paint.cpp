#include <bits/stdc++.h>
#define forinc(i,a,b) for(int i = a; i <= b; ++i)
#define fordec(i,a,b) for(int i = a; i >= b; --i)
#define ll long long
#define f first
#define s second
#define pii pair<int,int>
#define nmax 1000005
#define pb push_back
#define task "paint"
#define endl '\n'
#define reset(x) memset(x,0,sizeof(x))
#define MOD 1000000007
#define mp make_pair
using namespace std;
vector <int> a[nmax];
int n, cnt=0, tr[nmax];
int dd[nmax];
void sub1()
{
    char kq[nmax];
    vector<int> point[30];
    //for(int i=1;i<=n;i++) kq[i]='*';
    for(int i=1; i<=n; i++)
    {
        int type;
        char x, y;
        cin>>type;
        if(type==1)
        {
            cin>>x;
            cnt++;
            point[x-'a'].pb(cnt);
        }
        else
        {
            cin>>x>>y;
            for(int j=0; j<point[x-'a'].size(); j++)
                point[y-'a'].pb(point[x-'a'][j]);
            point[x-'a'].clear();
        }
    }
    for(int i=0; i<=25; i++)
        for(int j=0; j<point[i].size(); j++)
            kq[point[i][j]]=(char)(i+'a');
    for(int i=1; i<=cnt; i++)
        cout<<kq[i];
}
/*void dfs(int u, int x){
  dd[u]=x;
  for(auto v:a[u]) if(dd[v]=-1) dfs(v,x);
}
void sub2()
{
    int dem[30];
    bool check[nmax];
    for(int i=1; i<=n; i++)
    {
        int type;
        char x, y;
        cin>>type;
        if(type==1)
        {
            cin>>x;
            cnt++;
            if(cnt!=1||dem[x-'a']!=0)
            {
                a[cnt].pb(tr[x-'a']);
                a[tr[x-'a']].pb(cnt);
            }
            dem[x-'a']++;
            dd[tr[x-'a']]=-1;
            dd[cnt]=x-'a';
            tr[x-'a']=cnt;
            check[tr[x-'a']]=true;
        }
        else
        {
            cin>>x>>y;
            if(dem[y-'a']!=0)
            {
                a[tr[y-'a']].pb(tr[x-'a']);
                a[tr[x-'a']].pb(tr[y-'a']);
                check[tr[y-'a']]=true;
                check[tr[x-'a']]=false;
                dd[tr[x-'a']]=-1;
            }
            else{ dd[tr[x-'a']]=y-'a'; check[tr[x-'a']]=true;}
            dem[y-'a']+=dem[x-'a'];
            dem[x-'a']=0;
        }
    }
    for(int i=1;i<=cnt;i++) if(check[i]==true) dfs(i, dd[i]);
    for(int i=1;i<=cnt;i++) cout<<dd[i];
}*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    //if(n<=10000)
    sub1();
    //sub2();
    return 0;
}
