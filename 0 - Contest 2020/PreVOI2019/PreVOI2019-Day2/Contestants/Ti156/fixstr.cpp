#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int maxn=1e6+10;
int n,m,t[4*maxn],x,y,a[1001][1001];
string s;
char ch;
template <typename T> inline void read(T &x)
{
    x = 0; char c;
    while (!isdigit(c = getchar()));
    do x = x * 10 + c - 48; while (isdigit(c = getchar()));
}
void up(int id,int l,int r,int i,int val)
{
    if(i>r|i<l) return;
    if(l==r)
    {
        t[id]=val;
        return;
    }
    int mid=(l+r)/2;
    up(id*2,l,mid,i,val);
    up(id*2+1,mid+1,r,i,val);
    t[id]=(t[id*2]+t[id*2+1]);
}
int get(int id,int l,int r,int u,int v)
{
    if(r<u||l>v) return 0;
    if(l>=u&&r<=v) return t[id];
    int mid=(l+r)/2;
    return (get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v));
}
int main()
{
    freopen("fixstr.inp","r",stdin);
    freopen("fixstr.out","w",stdout);
    ch=getchar();
    s+='0';
    while(ch==' '||ch=='\n') ch=getchar();
    while(ch=='('||ch==')')
    {
        n++;
        s+=ch;
        ch=getchar();
    }
    For(i,1,n)
    if(s[i]==')')
        a[0][i]=1;
    read(m);
    For(i,1,m)
    {
        ch=getchar();
        while(ch!='U'&&ch!='Q'&&ch!='C') ch=getchar();
        if(ch=='C')
        {
            read(x);
            a[0][x]=1-a[0][x];
        }
        if(ch=='Q')
        {
            read(x);read(y);
            int dem=0,res=0;
            For(j,x,y)
            {
                if(a[0][j]) dem--;
                else dem++;
                if(dem<0) dem=0,res++;
            }
            res+=dem;
            cout<<res<<'\n';
        }
        if(ch=='U')
        {
            read(x);
            x--;
            For(j,1,n)
                a[0][j]=a[x][j];

        }
        For(j,1,n) a[i][j]=a[0][j];
    }
}
