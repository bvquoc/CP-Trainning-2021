#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define y1 zzz
#define fi first
#define se second
#define PII pair<int,int>
#define PII2 pair<int,PII >
#define PII3 pair<PII,int >
#define PII4 pair<PII,PII >
#define pb push_back;
int root[30],color[1000010],p[1000010],lv[1000010],n;
int par(int u)
{
    if(p[u]!=u)p[u]=par(p[u]);
    return p[u];
}
void uni(int u,int v,int val)
{
    u=par(u);
    v=par(v);
    if(u==v)return ;
    if(lv[u]==lv[v])lv[u]++;
    if(lv[u]<lv[v])
    {
        //cerr<<"union "<<u<<" "<<v<<" "<<val<<'\n';
        p[u]=v;
        color[v]=val;
    }
    else
    {
        //cerr<<"union "<<u<<" "<<v<<" "<<val<<'\n';
        p[v]=u;
        color[u]=val;
    }
}
void solve()
{
    srand(time(0));
    cin>>n;
    for(int i=1;i<=n;i++)p[i]=i;
    int cur=0;
    for(int i=0;i<n;i++)
    {
        int ope;
        char c;
        cin>>ope>>c;
        //ope=rand()%2+1;
        //c=rand()%26+'a';
        if(ope==1)
        {
            ++cur;
            int val=c-'a';
            if(root[val]==0)
            {
                root[val]=cur;
                color[cur]=val;
            }
            else uni(root[val],cur,val);
        }
        else
        {
            char d;
            cin>>d;
            //d=rand()%26+'a';
            int val_c=c-'a';
            int val_d=d-'a';
            //cerr<<par(root[val_c])<<" "<<root[val_d]<<'\n';
            if(root[val_c]!=0&&root[val_d]==0)
            {
                color[par(root[val_c])]=val_d;
                root[val_d]=root[val_c];
                if(val_c!=val_d)root[val_c]=0;
            }
            else if(root[val_c]&&root[val_d])
            {
                uni(root[val_c],root[val_d],val_d);
                if(val_c!=val_d)root[val_c]=0;
            }
        }
    }
    for(int i=1;i<=cur;i++)
    {
        char ans=color[par(i)]+'a';
        cout<<ans;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    freopen("PAINT.inp", "r", stdin);
    freopen("PAINT.out", "w", stdout);
    //int test;cin>>test;while(test--)
    solve();
    return 0;
}
/*
10
1 c
1 b
1 a
1 c
1 d
2 a b
1 c
1 a
1 b
2 b d

100
1 y
1 n
1 p
1 t
2 z r
1 r
2 a w
1 n
1 d
1 e
2 g f
2 s c
2 n c
2 v q
1 u
2 w w
2 m u
2 j d
2 y i
2 i i
1 f
1 b
1 b
2 h v
1 v
2 z g
1 c
1 i
2 d n
2 v o
1 m
1 m
1 d
2 o b
1 g
2 n u
1 w
1 h
2 a v
2 l h
1 n
2 v t
1 r
2 o t
1 k
2 e n
1 g
1 m
1 o
1 j
2 n q
1 k
2 y c
2 w u
1 i
2 n a
1 j
1 v
2 h d
1 a
2 i v
2 v z
1 u
1 z
1 k
1 i
1 w
1 g
2 f e
2 m r
1 a
1 u
2 o r
2 a f
1 a
2 q m
1 e
2 n c
1 x
1 p
1 i
2 t m
1 s
1 j
2 z o
2 j w
1 h
1 t
1 x
1 y
2 b m
1 s
2 j b
2 a c
2 p v
2 i t
2 l r
2 s h
1 z
1 r
*/
