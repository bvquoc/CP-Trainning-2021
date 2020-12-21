#include<bits/stdc++.h>
using namespace std;
#define nhat "coolmac"
#define ll long long
#define db double
#define pb push_back
const int mm=1e5+5,oo=1e9+7;
int m,n=1e5+1;
struct ii
{
    int l,r;
    bool operator <(ii st)
    {
        return r<st.r;
    }
};ii st[mm];
int f[mm],b[mm];
void upd(int vt,int val)
{
    while(vt<=n) f[vt]=min(f[vt],val),vt+=(vt&-vt);
}
int get(int u,int v)
{
    if(!u) return 0;
    int res=oo;
    while(v>=u)
        if(v-(v&-v)>=u) res=min(res,f[v]),v-=(v&-v);
        else res=min(res,b[v]),v--;
    return res;
}
int main()
{
    freopen(nhat".inp","r",stdin);
    freopen(nhat".out","w",stdout);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
        scanf("%d %d",&st[i].l,&st[i].r),st[i].l++,st[i].r++;
    sort(st+1,st+m+1);
    for(int i=1;i<=n;i++) f[i]=oo,b[i]=oo;
    int t,mi=oo,x; scanf("%d",&t);
    while(t--) scanf("%d",&x),x++,mi=min(mi,x);
    for(int i=1;i<mi;i++) b[i]=0,f[i]=0,upd(i,0);
    for(int i=1;i<=m;i++)
        if(st[i].r>=mi)
        {
            int tam=get(st[i].l-1,st[i].r);
            if(tam-oo) b[st[i].r]=min(b[st[i].r],tam+1),upd(st[i].r,b[st[i].r]);
        }
    if(b[n]-oo) printf("%d",b[n]);
    else printf("-1");
}
