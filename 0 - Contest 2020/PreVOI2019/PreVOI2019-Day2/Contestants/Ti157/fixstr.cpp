///      5 Dieu Bac Ho Day    ///
/// 1. Yeu to quoc, yeu dong bao
/// 2. Hoc tap tot, lao dong tot
/// 3. Doan ket tot, ki luat tot
/// 4. Giu gin ve sinh that tot
/// 5. Khiem ton, that tha, dung cam
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ChauNgoanBacHo "fixstr"
#define maxn 2050
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define FOR(i,j,k) for(int i=j;i<=k;++i)
#define FORD(i,j,k) for(int i=j;i>=k;--i)
#define ll long long
#define endl "\n"
//#define int long long

using namespace std;
//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
//#define rand rd
int const oo=1e9+7;
int n,m,res=0;
string s;
int kt[maxn][maxn];
int l[maxn],r[maxn],k[maxn],pos[maxn];
char type[maxn];
int a[maxn],ddl[maxn],ddr[maxn];
int itl[4*1000500],itr[4*1000500];
int lazyl[4*1000500],lazyr[4*1000500];
void downl(int id)
{
    itl[id*2]+=lazyl[id];
    itl[id*2+1]+=lazyl[id];
    lazyl[id*2]+=lazyl[id];
    lazyl[id*2+1]+=lazyl[id];
    lazyl[id]=0;
}
void downr(int id)
{
    itr[id*2]+=lazyr[id];
    itr[id*2+1]+=lazyr[id];
    lazyr[id*2]+=lazyr[id];
    lazyr[id*2+1]+=lazyr[id];
    lazyr[id]=0;
}
void upl(int id, int l, int r, int u, int v,int gt)
{
    if(l>v||r<u)
        return;
    if(u<=l&&r<=v)
    {
        itl[id]+=gt;
        lazyl[id]+=gt;
        downl(id);
        return;
    }
    int mid=(l+r)/2;
    upl(id*2,l,mid,u,v,gt);
    upl(id*2+1,mid+1,r,u,v,gt);
    itl[id]=max(itl[id*2],itl[id*2+1]);
}
void upr(int id, int l, int r, int u, int v,int gt)
{
    if(l>v||r<u)
        return;
    if(u<=l&&r<=v)
    {
        itr[id]+=gt;
        lazyr[id]+=gt;
        downr(id);
        return;
    }
    int mid=(l+r)/2;
    upr(id*2,l,mid,u,v,gt);
    upr(id*2+1,mid+1,r,u,v,gt);
    itr[id]=min(itr[id*2],itr[id*2+1]);
}
int getl(int id, int l, int r, int u, int v)
{
   if(l>v||r<u||u>v)
        return -oo;
    if(u<=l&&r<=v)
    {
        return itl[id];
    }
    downl(id);
     int mid=(l+r)/2;
    int L= getl(id*2,l,mid,u,v);
    int R= getl(id*2+1,mid+1,r,u,v);
    return max(L,R);

}
int getr(int id, int l, int r, int u, int v)
{

   if(l>v||r<u||u>v)
        return oo;
    if(u<=l&&r<=v)
    {
        return itr[id];
    }
    downr(id);
     int mid=(l+r)/2;
    int L= getr(id*2,l,mid,u,v);
    int R= getr(id*2+1,mid+1,r,u,v);
    return min(L,R);

}
main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    #ifdef OK
    freopen(ChauNgoanBacHo".inp", "r", stdin);
    freopen(ChauNgoanBacHo".out", "w", stdout);
//    #endif // OK
    cin>>s;
    cin>>m;
    n=s.size();
    s=' '+s;
    int ch=0;
    FOR(i,1,m)
    {
        cin>>type[i];
        if(type[i]=='C')
            cin>>pos[i];
        else if(type[i]=='Q')
            cin>>l[i]>>r[i];
        else
        {
            ch=1;
            cin>>k[i];
        }
    }
//    if(ch)
    {

        n=min(n,2002);

        FOR(i,1,n)
        {
            kt[0][i]=(s[i]=='(') ? 1: -1;
        }
        FOR(loop,1,m)
        {
            FOR(i,1,n)
            {
                kt[loop][i]=kt[loop-1][i];
            }
            if(type[loop]=='C')
            {
                kt[loop][pos[loop]]*=-1;
            }
            if(type[loop]=='Q')
            {
                int del=0;
                int re1=0,re2=0;
                FOR(i,l[loop],r[loop])
                {
                    del+=kt[loop][i];
                    re1=min(re1,del);
                }
                del=0;
                FORD(i,r[loop],l[loop])
                {
                    del+=kt[loop][i];
                    re2=max(re2,del);
                }
                cout<<abs(re1)+re2<<endl;
            }
            if(type[loop]=='U')
            {
                FOR(i,1,n)
                {
                    kt[loop][i]=kt[k[loop]-1][i];
                }
            }
//            FOR(i,1,n)
//            {
//                cout<<kt[loop][i]<<" ";
//            }
//            cout<<endl;
        }
    }
//    else
//    {
//        FOR(i,1,n)
//        {
//            a[i]=(s[i]=='(') ? 1: -1;
//        }
//        FOR(i,1,n)
//        {
//            ddr[i]=ddr[i-1]+a[i];
//            upr(1,1,n,i,i,ddr[i]);
//        }
//        FORD(i,n,1)
//        {
//            ddl[i]=ddl[i+1]+a[i];
//            upl(1,1,n,i,i,ddl[i]);
//        }
//        FOR(i,1,n)
//        {
//            cout<<getl(1,1,n,i,i)<<" ";
//        }
//        cout<<endl;
//        upl(1,1,n,1,1,-2);
//        upr(1,1,n,1,n,-2);
//        upl(1,1,n,1,5,2);
//        upr(1,1,n,5,n,2);
//          FOR(i,1,n)
//        {
//            cout<<getl(1,1,n,i,i)<<" ";
//        }
//        cout<<endl;
//        FOR(i,1,m)
//        {
//            if(type[i]=='C')
//            {
//                a[pos[i]]*=-1;
//                upl(1,1,n,1,pos[i],2*a[i]);
//                upr(1,1,n,pos[i],n,2*a[i]);
////                cout<<getr(1,1,n,1,6)<<endl;
//            }
//            else
//            {
//                int rel=max(0,getl(1,1,n,l[i],r[i])-getl(1,1,n,r[i]+1,n));
//                int rer=min(0,getr(1,1,n,l[i],r[i])-getr(1,1,n,1,l[i]-1));
////cout<<l[i]<<" "<<r[i]<<endl;
//
////                int rel=getl(1,1,n,l[i],r[i]);
////                int rer=getr(1,1,n,l[i],r[i]);
//                cout<<rel<<" "<<rer<<" ";
//                cout<<rel+abs(rer)<<endl;
//            }
//        }
//    }
}
