#include <bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define pii pair<int,int>
using namespace std;
const int N=1e6+1,N1=1e3+1;
string S,s[10*N1];
int n,m;
int mo[4*N],dong[4*N],pre[N];
void trau()
{
    forinc(test,1,m)
    {
        s[test]=S;
        char type; cin>>type;
        if(type=='C')
        {
            int i; cin>>i;
            if(S[i]==')') S[i]='(';
            else S[i]=')';
        }
        if(type=='Q')
        {
            int l,r,sum=0,res=0;
            cin>>l>>r;
            forinc(i,l,r)
            {
                if(S[i]=='(')
                {
                    if(sum>=0) ++sum;
                    else
                    {
                        res-=sum;
                        sum=1;
                    }
                }
                else --sum;
            }
            res+=abs(sum);
            cout<<res<<'\n';
        }
        if(type=='U')
        {
            int k; cin>>k;
            S=s[k];
        }
    }
    exit(0);
}
void build(int s,int l,int r)
{
    if(l==r)
    {
        if(S[l]=='(')
        {
            mo[s]=1;
            dong[s]=0;
        }
        else
        {
            mo[s]=0;
            dong[s]=1;
        }
        return;
    }
    int mid=(l+r)/2;
    build(2*s,l,mid);
    build(2*s+1,mid+1,r);
    if(mo[2*s]>=dong[2*s+1])
    {
        mo[s]=mo[2*s]-dong[2*s+1]+mo[2*s+1];
        dong[s]=dong[2*s];
    }
    else
    {
        mo[s]=mo[2*s+1];
        dong[s]=dong[2*s]+dong[2*s+1]-mo[2*s];
    }
}
void upd(int s,int l,int r,int i)
{
    if(l>i||r<i) return;
    if(l==r)
    {
        if(S[i]=='(')
        {
            mo[s]=1;
            dong[s]=0;
        }
        else
        {
            mo[s]=0;
            dong[s]=1;
        }
        return;
    }
    int mid=(l+r)/2;
    upd(2*s,l,mid,i);
    upd(2*s+1,mid+1,r,i);
    if(mo[2*s]>=dong[2*s+1])
    {
        mo[s]=mo[2*s]-dong[2*s+1]+mo[2*s+1];
        dong[s]=dong[2*s];
    }
    else
    {
        mo[s]=mo[2*s+1];
        dong[s]=dong[2*s]+dong[2*s+1]-mo[2*s];
    }
}
pii get(int s,int l,int r,int u,int v)
{
    if(l>v||r<u) return {0,0};
    if(l>=u&&r<=v) return {mo[s],dong[s]};
    int mid=(l+r)/2,x,y;
    pii lf=get(2*s,l,mid,u,v);
    pii rt=get(2*s+1,mid+1,r,u,v);
    if(lf.first>=rt.second)
    {
        x=lf.first-rt.second+rt.first;
        y=lf.second;
    }
    else
    {
        x=rt.second;
        y=lf.second+rt.second-lf.first;
    }
    return {x,y};
}
int main()
{
    freopen("fixstr.inp","r",stdin);
    freopen("fixstr.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>S>>m;
    n=S.size();
    S=' '+S;
    if(n<N1&&m<N1) trau();
    build(1,1,n);
    int cur=0;
    s[0]=S;
    forinc(test,1,m)
    {
        pre[test]=cur;
        char type; cin>>type;
        if(type=='C')
        {
            int i; cin>>i;
            S[i]=(S[i]=='(')?')':'(';
            upd(1,1,n,i);
            s[++cur]=S;
        }
        if(type=='Q')
        {
            int i,j;
            cin>>i>>j;
            pii x=get(1,1,n,i,j);
            cout<<x.first+x.second<<'\n';
        }
        if(type=='U')
        {
            int k; cin>>k;
            S=s[pre[k]];
            s[++cur]=S;
            build(1,1,n);
        }
    }
}
