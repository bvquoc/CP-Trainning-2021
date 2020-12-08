#include <bits/stdc++.h>
using namespace std;
inline long long read() { long long s = 0, t = 1; char c = getchar(); while( !isdigit(c) ) { if( c == '-' ) t = -1; c = getchar(); } while( isdigit(c) ) s = s * 10 + c - 48, c = getchar(); return s * t; }
inline void Write(long long x){ if (x>9) Write(x/10); putchar(x%10+48); }
long long st[4001],q,i,n,m,a[1001],lz[4001],stt[1001],top,L[1001],R[1001];
struct pt { long long k,vt; };
pt b[1001];
bool cmp(pt a,pt b) { return a.k<b.k; }
void build(int id,int l,int r)
{
    lz[id]=0;
    if(l==r) { st[id]=b[l].k; return ; }
    int mid=(l+r)>>1;
    build(id*2,l,mid); build(id*2+1,mid+1,r);
    st[id]=st[id*2]+st[id*2+1];
}
void down(int id)
{
    st[id*2]+=lz[id]; lz[id*2]+=lz[id];
    st[id*2+1]+=lz[id]; lz[id*2+1]+=lz[id];
    lz[id]=0;
}
void update(int id,int l,int r,int u,int v,int k)
{
    if(v<l || u>r) return ;
    if(u<=l && r<=v) { st[id]-=k; lz[id]-=k; return ; }
    down(id);
    int mid=(l+r)>>1;
    update(id*2,l,mid,u,v,k); update(id*2+1,mid+1,r,u,v,k);
    st[id]=st[id*2]+st[id*2+1];
}
long long get(int id,int l,int r,int u)
{
    if(u<l || u>r) return 0;
    if(l==r) return st[id];
    down(id);
    int mid=(l+r)>>1;
    return get(id*2,l,mid,u)+get(id*2+1,mid+1,r,u);
}
int main()
{
    freopen("construct.inp","r",stdin);
    freopen("construct.out","w",stdout);
    cin>>q;
    while(q--)
    {
        cin>>n>>m;
        for(i=1;i<=n;i++) a[i]=read();
        while(m--)
        {
            int ch=read();
            if(ch==1)
            {
                int l=read(),r=read(),k=read();
                for(i=l;i<=r;i++) a[i]+=k;
            }
            else
            {
                long long l=read(),r=read(),sl=0;
                for(i=l;i<=r;i++) b[++sl]={ a[i],i };
                build(1,1,sl);
                top=0; stt[top]=0;
                for(i=1;i<=sl;i++)
                {
                    while(top>0 && b[stt[top]].k>=b[i].k) top--;
                    L[i]=stt[top]+1;
                    stt[++top]=i;
                }
                top=0; stt[top]=sl+1;
                for(i=sl;i>=1;i--)
                {
                    while(top>0 && b[stt[top]].k>=b[i].k) top--;
                    R[i]=stt[top]-1;
                    stt[++top]=i;
                }
                sort(b+1,b+sl+1,cmp);
                long long kq=0;
                for(i=1;i<=sl;i++)
                {
                    int u=b[i].vt;
                    long long k=get(1,1,sl,u);
                    kq+=k;
                    update(1,1,sl,L[u],R[u],k);
                }
                Write(kq); printf("\n");
            }
        }
    }
}
