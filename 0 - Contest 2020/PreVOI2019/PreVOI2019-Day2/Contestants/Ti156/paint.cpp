#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=1e6+30;
int n,a[maxn],x,pos=1,cha[maxn],cao[maxn],c[maxn],pre[30],y,cnt,b[maxn],root[30];
char ch,c1,c2;
void test()
{
    freopen("paint.inp","w",stdout);
    srand(time(NULL));
    n=1000000;
    cout<<n<<'\n';
    For(i,1,n)
    {
        int x=rand()%2+1;
        cout<<x<<" ";
        int p=rand()%6;
        cout<<char(p+'a');
        if(x==1) cout<<'\n';
        if(x==2)
        {
             int q=rand()%6;
             while(p==q) q=rand()%8;
            cout<<' '<<char(q+'a')<<'\n';
        }
    }
}
int goc(int u)
{
    if(cha[u]==0) return u;
    return cha[u]=goc(cha[u]);
}
void merge(int u,int v)
{
    u=goc(u);
    v=goc(v);
    if(u==v) return;
    if(cao[u]==cao[v])
    {
        cao[v]++;
        cha[u]=v;
        return;
    }
    if(cao[u]>cao[v]) cha[v]=u;
    else cha[u]=v;
    return;
}
int main()
{
   // test();
    freopen("paint.inp","r",stdin);
    freopen("paint.out","w",stdout);
    scanf("%d",&n);
    For(i,1,n)
    {
        ch=getchar();
        while(ch!='1'&&ch!='2') ch=getchar();
        if(ch=='1')
        {
            c1=getchar();
            while(c1==' '||c1=='\n') c1=getchar();
            int color=c1-'a';
            if(pre[color]==0) pre[color]=pos,a[pos]=color;
            else
            {
                merge(pos,pre[color]);
                pre[color]=pos;
                a[goc(pos)]=color;
            }
         //   b[pos]=color;
            pos++;
        }
        else
        {
            c1=getchar();
            while(c1==' '||c1=='\n') c1=getchar();
            c2=getchar();
            while(c2==' '||c2=='\n') c2=getchar();
            int x=c1-'a';
            int y=c2-'a';
            if(!pre[x]||x==y) continue;
            if(pre[y])
            {
                merge(pre[y],pre[x]);
                a[goc(pre[y])]=y;
            }
            else
            {
                int root=goc(pre[x]);
                a[root]=y;
                pre[y]=root;
            }
            pre[x]=0;
           //For(j,1,pos) if(b[j]==x) b[j]=y;
        }
    }
    For(i,1,pos-1)  cout<<char(a[goc(i)]+'a');
//    cout<<'\n';
//    For(i,1,pos-1) if(b[i]!=a[goc(i)]) cout<<"NOOOOOO\n";

}
