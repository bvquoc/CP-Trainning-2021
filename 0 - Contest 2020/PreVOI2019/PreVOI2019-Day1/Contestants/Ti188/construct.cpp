#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

int T,n,m,kqmax,kqmin,keyL,keyR,a[maxn],b[maxn];
int64_t tong;
//int ITmax[4*maxn],ITmin[4*maxn],dt[4*maxn];
//int ITmax1[4*maxn],ITmin1[4*maxn],dt1[4*maxn];

/*void update(int k,int l,int r,int u,int v,int val)
{
    if (l>v || r<u) return;
    if (l>=u && r<=v) {dt[k]+=val; return;}
    int m=(l+r)/2;
    dt[2*k]+=dt[k]; dt[2*k+1]+=dt[k]; dt[k]=0;
    update(2*k,l,m,u,v,val);
    update(2*k+1,m+1,r,u,v,val);
    ITmax[k]=max(ITmax[2*k]+dt[2*k],ITmax[2*k+1]+dt[2*k+1]);
    ITmin[k]=min(ITmin[2*k]+dt[2*k],ITmin[2*k+1]+dt[2*k+1]);
}

void findmax(int k,int l,int r,int x,int y)
{
    if (y<l || x>r) return;
    if (l>=x && r<=y) kqmax=max(kqmax,ITmax[k]), kqmin=min(kqmin,ITmin[k]);
    else
    {
        int mid=(l+r)/2;
        findmax(2*k,l,mid,x,y);
        findmax(2*k+1,mid+1,r,x,y);
    }
}

void update1(int k,int l,int r,int u,int v,int val)
{
    if (l>v || r<u) return;
    if (l>=u && r<=v) {dt1[k]+=val; return;}
    int m=(l+r)/2;
    dt1[2*k]+=dt1[k]; dt1[2*k+1]+=dt1[k]; dt1[k]=0;
    update1(2*k,l,m,u,v,val);
    update1(2*k+1,m+1,r,u,v,val);
    ITmax1[k]=max(ITmax1[2*k]+dt1[2*k],ITmax1[2*k+1]+dt1[2*k+1]);
    ITmin1[k]=min(ITmin1[2*k]+dt1[2*k],ITmin1[2*k+1]+dt1[2*k+1]);
}

void findmax1(int k,int l,int r,int x,int y)
{
    if (y<l || x>r) return;
    if (l>=x && r<=y) kqmax=max(kqmax,ITmax1[k]), kqmin=min(kqmin,ITmin1[k]);
    else
    {
        int mid=(l+r)/2;
        findmax1(2*k,l,mid,x,y);
        findmax1(2*k+1,mid+1,r,x,y);
    }
}*/

void xuly1()
{
    int L,R,k; scanf("%d%d%d",&L,&R,&k);
    //update(1,1,n,L,R,k);
    for (int i=L; i<=R; i++) a[i]+=k;
}

void chatdoan(int l,int r)
{
    kqmax=-1e9; kqmin=1e9;
    //findmax1(1,1,n,l,r);
    for (int i=l; i<=r; i++) kqmax=max(kqmax,b[i]), kqmin=min(kqmin,b[i]);
    tong+=kqmin; //cerr<<kqmin<<" "<<kqmax<<"    "<<tong<<"\n";
    //update1(1,1,n,l,r,-kqmin);
    for (int i=l; i<=r; i++) b[i]-=kqmin;//, cerr<<b[i]<<" "; cerr<<"\n";
   // int i=1;
   // while (i<=n)
   // {
    int i=keyL;
    while (b[i]==0 && i<=keyR) i++;
    if (i==n+1) return;
    int vt1=i;
    while (b[i]!=0 && i<=keyR) i++;
    int vt2=i-1; //cerr<<"vi tri "<<vt1<<" => "<<vt2<<"\n";
    //if (vt2-vt1==0) tong+=b[vt1], b[vt1]=0; else
    if (vt1<=vt2) chatdoan(vt1,vt2); else return;
   // }

}

void xuly2()
{
    int L,R; scanf("%d%d",&L,&R); keyL=L; keyR=R;
    for (int i=1; i<=n; i++) b[i]=a[i];
    tong=0; chatdoan(L,R); cout<<tong<<"\n"; //cerr<<"\n\n\n";
}

int main()
{
    freopen("construct.inp","r",stdin);
    freopen("construct.out","w",stdout);
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1; i<=n; i++) scanf("%d",&a[i]);//, update1(1,1,n,i,i,a[i]);
        //kqmax=-1e9; kqmin=1e9; findmax(1,1,n,1,n); cerr<<kqmin<<" "<<kqmax;
        for (int i=1; i<=m; i++)
        {
            int key; scanf("%d",&key);
            if (key==1) xuly1(); else xuly2();
        }
    }
}
