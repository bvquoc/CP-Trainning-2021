#include<bits/stdc++.h>
#define ll long long
#define db double
#define maxx 1000112
#define val first
#define lazy second
#define pp pair<ll,ll>
#define pb push_back
#define mp make_pair
using namespace std;

const ll oo=1e18;
int t,n,m;
int a[maxx];
pp IT[4*maxx];
ll res;

int readint(){
    char c=getchar();
    while(c<'0'||'9'<c)c=getchar();
    int res=0;
    while('0'<=c&&c<='9'){
        res=res*10+c-'0';
        c=getchar();
    }
    return res;
}

void down(int dd){
    ll temp=IT[dd].lazy;
    if(temp!=0){
        IT[dd*2].val+=temp;
        IT[dd*2+1].val+=temp;
        IT[dd*2].lazy+=temp;
        IT[dd*2+1].lazy+=temp;
    }
    IT[dd].lazy=0;
}

void build(int dd,int l,int r){
    if(l==r){
        IT[dd].val=a[l];
        IT[dd].lazy=0;
        return ;
    }
    int mid=(l+r)/2;
    build(dd*2,l,mid);
    build(dd*2+1,mid+1,r);
    IT[dd].val=min(IT[dd*2].val,IT[dd*2+1].val);
}

void update(int dd,int l,int r,int u,int v,ll k){
    if(r<u||v<l)return ;
    if(u<=l&&r<=v){
        IT[dd].val+=k;
        IT[dd].lazy+=k;
        return ;
    }
    int mid=(l+r)/2;
    down(dd);
    update(dd*2,l,mid,u,v,k);
    update(dd*2+1,mid+1,r,u,v,k);
    IT[dd].val=min(IT[dd*2].val,IT[dd*2+1].val);
}

ll get(int dd,int l,int r,int u,int v){
    if(r<u||v<l)
        return oo;
    if(u<=l&&r<=v){
        return IT[dd].val;
    }
    int mid=(l+r)/2;
    down(dd);
    ll temp1=get(dd*2,l,mid,u,v);
    ll temp2=get(dd*2+1,mid+1,r,u,v);
    return min(temp1,temp2);
}

void solve(int l,int r,ll pre){
    ll temp=get(1,1,n,l,r);
//    cout<<l<<" "<<r<<" "<<pre<<" "<<temp<<"\n";
    res+=temp-pre;
    for(int i=l;i<=r;i++){
        if(get(1,1,n,i,i)>temp){
            int st=i,en=r,j=i;
            while(st<=en){
                int mid=(st+en)/2;
                if(get(1,1,n,i,mid)>temp){
                    j=mid;
                    st=mid+1;
                }
                else{
                    en=mid-1;
                }
            }
            solve(i,j,temp);
            i=j;
        }
    }
}


void kaisa(){
    freopen("CONSTRUCT.INP","r",stdin);
    freopen("CONSTRUCT.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    t=readint();
    while(t--){
        n=readint();
        m=readint();
        for(int i=1;i<=n;i++){
            a[i]=readint();
        }
        build(1,1,n);
        while(m--){
            int type,l,r,k;
            type=readint();
            if(type==1){
                l=readint();
                r=readint();
                k=readint();
                update(1,1,n,l,r,k);
            }
            else{
                l=readint();
                r=readint();
                res=0;
                solve(l,r,0);
                cout<<res<<"\n";
            }
        }
    }
}

int main()
{
    kaisa();

    return 0;
}
