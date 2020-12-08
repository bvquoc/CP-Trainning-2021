#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fio(s) freopen(s".inp","r",stdin)
#define foo(s) freopen(s".out","w",stdout)
#define pb push_back
#define pll pair<LL,LL>
#define fi first
#define se second
#define LL long long
#define mp make_pair
#define task "construct"
using namespace std;
const LL N=1000001,OO=1e15,mod=1e9+3;
struct cmp{
    bool operator() (pll a,pll b){return a.se>b.se;}
};
int n,m,test,lab[N];
LL T[N],b[N];
void upd(int id,LL val)
{
    for(;id<N;id+=id&-id) T[id]+=val;
}
int getroot(int i)
{
    if(lab[i]<0) return i;
    int x=i; while(lab[x]>0) x=lab[x];
    lab[i]=x;
    return lab[i];
}
LL get(int id)
{
    LL rs=0;
    for(;id>0;id-=id&-id) rs+=T[id];
    return rs;
}
int main()
{
    fio(task); foo(task);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scanf("%d",&test);
    int typ,l,r,val,xx;
    while(test--)
    {
        scanf("%d%d",&n,&m);
        For(i,0,n) T[i]=0;
        For(i,1,n) scanf("%d",&xx),upd(i,xx),upd(i+1,-xx);
        while(m--)
        {
            scanf("%d",&typ);
            if(typ==1){
                scanf("%d%d%d",&l,&r,&val);
                upd(l,val); upd(r+1,-val);
            }else{
                scanf("%d%d",&l,&r);
                For(i,l,r) lab[i]=-1;
                vector<pll> v;
                For(i,l,r)
                    b[i]=get(i),v.pb(mp(i,b[i]));
                v.pb(mp(0,0));
                sort(v.begin(),v.end(),cmp());
                int nn=v.size()-1,run=0,r1,r2,u;
                LL ans=0,rs=0,dis;
                while(run<=nn-1){
                    do{
                        u=v[run].fi; ++ans;
                        if(u>l&&b[u-1]>=b[u])
                        {
                            r1=getroot(u); r2=getroot(u-1);
                            if(r1!=r2){
                                if(lab[r1]>lab[r2]) swap(r1,r2);
                                lab[r1]+=lab[r2]; lab[r2]=r1;
                                --ans;
                            }
                        }
                        if(u<r&&b[u+1]>=b[u])
                        {
                            r1=getroot(u); r2=getroot(u+1);
                            if(r1!=r2){
                                if(lab[r1]>lab[r2]) swap(r1,r2);
                                lab[r1]+=lab[r2]; lab[r2]=r1;
                                --ans;
                            }
                        }
                        ++run;
                    }while(run<=nn-1&&v[run].se==v[run-1].se);
                    dis=v[run-1].se-v[run].se;
                    rs+=ans*dis;
                }
                printf("%lld\n",rs);
            }
        }
    }
    return 0;
}
