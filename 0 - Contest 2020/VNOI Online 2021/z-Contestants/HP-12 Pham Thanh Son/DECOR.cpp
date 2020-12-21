#include<bits/stdc++.h>
using namespace std;
#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){ return rng()%(r-l+1) +l;}
#define fi first
#define se second
#define pii pair<int,int>
#define ii pair<int,pii>
#define getbit(i,x) ((x>>i)&1ll)
#define tatbit(i,x) (x&~(1ll<<i))
#define batbit(i,x) (x^(1ll<<i))

const int maxn=2010;
int n,m,k;
int a[maxn],sum[maxn];
string s;
int id[maxn],sl[maxn],copy_sl[maxn];
pii E[maxn];
pii Range;
bool check12(int val){
    forinc(i,1,n-val+1){
        int nex=i+val-1;
        if(sum[nex]-sum[i-1]+k>=val){
            Range={i,nex};
            return 1;
        }
    }
    return 0;
}

void SUB12(){
    int L=0,R=n,kq=0;
    while(L<=R){
        int mid=(L+R)/2;
        if(check12(mid)) kq=mid,L=mid+1;
        else R=mid-1;
    }
    ///cout<<(kq==0?-1:kq);
    if(kq==0) cout<<-1;
    else cout<<Range.fi<<" "<<Range.se;
}

int root(int u){
    return id[u]<0?u:id[u]=root(id[u]);
}

void join(int u,int v){
    if((u=root(u))==(v=root(v))) return;
    if(id[u]>id[v]) swap(u,v);
    id[u]+=id[v];
    id[v]=u;
}

bool check3(int val){
    forinc(i,1,n){
        int nex=i+val-1;
        forinc(i,1,n) copy_sl[i]=sl[i];

        forinc(j,i,nex) if(a[j]) copy_sl[root(j)]--;
        int tmp=sum[nex]-sum[i-1];

        forinc(j,i,nex) if(!a[j]){
            int RR=root(j);
            if(copy_sl[RR]>0){
                tmp++;
                copy_sl[RR]--;
            }
        }
        if(tmp+k>=val){
            Range={i,nex};
            return 1;
        }
    }
    return 0;
}

void SUB3(){
    memset(id,-1,sizeof id);
    forinc(i,1,m){
        if(root(E[i].fi)!=root(E[i].se)) join(E[i].fi,E[i].se);
    }
    forinc(i,1,n) if(a[i]) sl[root(i)]++;

    int L=0,R=n,kq=0;
    while(L<=R){
        int mid=(L+R)/2;
        if(check3(mid)) kq=mid,L=mid+1;
        else R=mid-1;
    }
    ///cout<<(kq==0?-1:kq);
    if(kq==0) cout<<-1;
    else cout<<Range.fi<<" "<<Range.se;
}

int MEM[maxn],cnt[2][maxn];
int tplt,fre[maxn];

bool check(int val){
    int tmp=0;
    forinc(j,0,n) fre[j]=0;
    forinc(j,0,n) cnt[0][j]=cnt[1][j]=0;
    forinc(i,1,n-val+1){
        int nex=i+val-1;
        if(i==1){
            forinc(j,1,nex){
                if(a[j]==0) cnt[0][MEM[j]]++;
                else cnt[1][MEM[j]]++;
            }
            forinc(j,1,n) if(!fre[MEM[j]]){
                tmp+=max(0ll,min(cnt[0][MEM[j]],sl[MEM[j]]-cnt[1][MEM[j]]));
                fre[MEM[j]]=1;
            }
            ///cout<<tmp<<" "<<k<<"\n";
            if(tmp+k+sum[nex]-sum[i-1]>=val){
                Range={i,nex};
                return 1;
            }
        }else{
            ///tmp-=(sum[nex-1]-sum[i-2]);

            tmp-=min(cnt[0][MEM[i-1]],sl[MEM[i-1]]-cnt[1][MEM[i-1]]);
            if(a[i-1]==0) cnt[0][MEM[i-1]]--;
            else cnt[1][MEM[i-1]]--;

            tmp+=min(cnt[0][MEM[i-1]],sl[MEM[i-1]]-cnt[1][MEM[i-1]]);

            tmp-=min(cnt[0][MEM[nex]],sl[MEM[nex]]-cnt[1][MEM[nex]]);

            if(a[nex]==0) cnt[0][MEM[nex]]++;
            else cnt[1][MEM[nex]]++;
            tmp+=min(cnt[0][MEM[nex]],sl[MEM[nex]]-cnt[1][MEM[nex]]);
            if(tmp+k+sum[nex]-sum[i-1]>=val){
                Range={i,nex};
                return 1;
            }
        }
     //   cout<<tmp<<" "<<"++"<<"\n";
    }
    return 0;
}


void brute_force(){
    memset(id,-1,sizeof id);
    forinc(i,1,m){
        if(root(E[i].fi)!=root(E[i].se)) join(E[i].fi,E[i].se);
    }
    forinc(i,1,n) if(a[i]) sl[root(i)]++;
    forinc(i,1,n) MEM[i]=root(i);

    ///forinc(i,1,n) cout<<sl[i]<<" ";



    int L=0,R=n,kq=0;
    while(L<=R){
        int mid=(L+R)/2;
        if(check(mid)) kq=mid,L=mid+1;
        else R=mid-1;
    }
    ///cout<<(kq==0?-1:kq);
    if(kq==0) cout<<-1;
    else cout<<Range.fi<<" "<<Range.se;
}

main(){
    freopen("DECOR.inp","r",stdin);
    freopen("DECOR.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    cin>>s;
    forinc(i,0,n-1) a[i+1]=(s[i]-'0');
    forinc(i,1,n) sum[i]=sum[i-1]+a[i];

    forinc(i,1,m) cin>>E[i].fi>>E[i].se;

    if(m==0){
        SUB12();
    }else if(n<=2000){ ///// change it!
        SUB3();
    }
    else{
        brute_force();
    }

}
