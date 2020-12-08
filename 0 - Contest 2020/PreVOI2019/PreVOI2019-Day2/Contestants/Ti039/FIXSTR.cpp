#include <bits/stdc++.h>
using namespace std;
#define tag "FIXSTR"
#define maxn 1000007
#define oo 1000000007LL
#define mid ((l+r)>>1)
#define meset(a,x) memset(a,x,sizeof(a))
#define loop(x) for(int LoOpEr=1;LoOpEr<=x;LoOpEr++)
#define debug(x) cerr<<#x<<" = "<<x<<"\n"
#define runtime(stime) ((clock() - stime) / CLOCKS_PER_SEC * 1000)
#define checkfile(FiLeNaMe) { if(fopen(FiLeNaMe".inp","r")) freopen(FiLeNaMe".inp","r",stdin),freopen(FiLeNaMe".out","w",stdout); }
//// my data:
struct pstIT{
    int sum,mi;
    int laz;

    pstIT *left,*right;

    pstIT(): sum(0), mi(oo), left(this), right(this) {};

    void push(int l,int r){
        auto &L = left;
        auto &R = right;

        if(L) L->sum+=(mid-l+1)*laz,L->mi+=laz,L->laz+=laz;
        if(R) R->sum+=(r-mid)*laz,R->mi+=laz,R->laz+=laz;
        laz=0;
    }

    pstIT* unite(pstIT *L,pstIT *R){
        pstIT *rep;
        rep->left=L;
        rep->right=R;
        rep->sum = L->sum + R->sum;
        rep->mi = min(L->mi,R->mi);
        rep->laz=0;
        return rep;
    }

    pstIT(const int &sum,const int &mi,const int &lz,pstIT *l,pstIT *r): sum(sum), mi(mi), laz(lz), left(l), right(r) {};
    pstIT(const int &val): pstIT(val,val,0,0,0) {};

    pstIT* insert(const int &l,const int &r,const int &u,const int &v,const int &val)
    {
        if(v<l || u>r) return this;

        if(u<=l && r<=v){
            return new pstIT(sum+(r-l+1)*val,mi+val,laz+val,left,right);
        }

        push(l,r);

        return unite(left->insert(l,mid,u,v,val),right->insert(mid+1,r,u,v,val));
    }

    int getsum(int l,int r,int u,int v){
        if(v<l || u>r) return 0;

        if(u<=l && r<=v) return sum;
        push(l,r);

        return left->getsum(l,mid,u,v) + right->getsum(mid+1,r,u,v);
    }

    int getmin(int l,int r,int u,int v){
        if(v<l || u>r) return oo;

        if(u<=l && r<=v) return mi;

        push(l,r);

        return min(left->getmin(l,mid,u,v),right->getmin(mid+1,r,u,v));
    }
};
///>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int n,m;
string s;
string version[1007];

void brute(){
    version[0]=s;

    char ques;
    for(int i=1,l,r,k,ans;i<=m;i++){
        cin>>ques;

        version[i]=version[i-1];
        auto &str = version[i];

        if(ques=='C'){
            cin>>k;
            str[k] = str[k] == ')' ? '(' : ')';
        }else if(ques=='U'){
            cin>>k;
            str=version[k-1];
        }else if(ques=='Q'){
            cin>>l>>r;

            ans=0;
            k=0;
            for(int j=l,sum=0;j<=r;j++){
                if(str[j]=='(') ++sum;
                else --sum;

                k=min(k,sum);

                if(j==r){
                    ans+=-k,sum+=-k;
                    ans+=sum;
                    cout<<ans<<"\n";
                }
            }
        }
    }
}

int a[maxn];
pstIT *step[maxn];
pstIT *null;

pstIT* build(int l,int r){
    if(l==r){
        int x = a[l];
        return new pstIT(x);
    }

    pstIT *rep = new pstIT(0);
    rep->left = build(l,mid);
    rep->right = build(mid+1,r);
    rep->sum = rep->left->sum + rep->right->sum;
    rep->mi = min(rep->left->mi,rep->right->mi);

    return rep;
}

void dm(){

    for(int i=1;i<=n;i++) a[i] = a[i-1] + (s[i]=='(' ? 1 : -1);
    step[0]=build(1,n);

    char ques;
    for(int i=1,l,r,k,ans,x;i<=m;i++){
        cin>>ques;

        step[i] = step[i-1];

        if(ques=='C'){
            cin>>k;

            x = step[i]->getsum(1,n,k,k) - step[i]->getsum(1,n,k-1,k-1);

            step[i] = step[i]->insert(1,n,k,n,x<0 ? +2 : -2);

        }else if(ques=='U'){

            cin>>k;
            step[i]=step[k-1];

        }else if(ques=='Q'){
            cin>>l>>r;

            ans=0;
            int bef = step[i]->getsum(1,n,l-1,l-1);
            int suri = step[i]->getsum(1,n,r,r) - bef;

            k=min(0,step[i]->getmin(1,n,l,r)-bef);

            ans+=-k;
            suri+=-k;
            ans+=suri;

            cout<<ans<<"\n";
        }
    }
}

void enter(){
    cin>>s;
    n=s.size();
    s='$'+s;
    cin>>m;

    if(n<=1e4 && m<=1e4) brute(); else dm();
}

int main()
{
    checkfile(tag);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    enter();

    return 0;
}
