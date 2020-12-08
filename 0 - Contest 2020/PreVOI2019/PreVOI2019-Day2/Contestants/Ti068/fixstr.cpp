                                        ///*******ZoHuyHieuZo*******///
#include<bits/stdc++.h>
#define F first
#define S second
#define int long long
#define pii pair<int,int>
#define Zo "fixstr"
#define MOD 1000000007
#define maxn 1000111
#define pb push_back
#define mp make_pair
#define mem(i,m) memset(i,m,sizeof(i))

using namespace std;
struct II
{
    int x,y,z;
};
int st[maxn*4][3];
string s;
int n;
string Q[maxn];
void make_st(int node,int l,int r)
{
    if(l==r)
    {
        st[node][0]=0;
        st[node][1]=0;
        st[node][2]=0;
        if(s[l]=='(')
            st[node][1]=1;
        else st[node][2]=1;
        return ;
    }
    int mid=(l+r)/2;
    make_st(node*2,l,mid);
    make_st(node*2+1,mid+1,r);
    int g=min(st[node*2][1],st[node*2+1][2]);
    st[node][0]=st[node*2][0]+st[node*2+1][0]+g;
    st[node][1]=st[node*2][1]+st[node*2+1][1]-g;
    st[node][2]=st[node*2][2]+st[node*2+1][2]-g;
}
void update(int node,int l,int r,int pos)
{
    if(l>pos||r<pos) return ;
    if(l==r)
    {
        st[node][0]=0;
        st[node][1]=0;
        st[node][2]=0;
        if(s[l]=='(')
            st[node][1]=1;
        else
            st[node][2]=1;
        return ;
    }
    int mid=(l+r)/2;
    update(node*2,l,mid,pos);
    update(node*2+1,mid+1,r,pos);
    int g=min(st[node*2][1],st[node*2+1][2]);
    st[node][0]=st[node*2][0]+st[node*2+1][0]+g;
    st[node][1]=st[node*2][1]+st[node*2+1][1]-g;
    st[node][2]=st[node*2][2]+st[node*2+1][2]-g;
}
II get(int node,int l,int r,int u,int v)
{
  if(l>v||r<u)
    return {0,0,0};
    if(u<=l&&r<=v)
    {
        return {st[node][0],st[node][1],st[node][2]};
    }
    int mid=(l+r)/2;
    II g=get(node*2,l,mid,u,v);
    II h=get(node*2+1,mid+1,r,u,v);
    int k=min(g.y,h.z);
    int a1=k+g.x+h.y;
    int a2=g.y+h.y-k;
    int a3=g.z+h.z-k;
    return {a1,a2,a3};
}
void nhap()
{
    cin>>s;
    s=' '+s;
    int m=s.size()-1;
    cin>>n;
    make_st(1,1,m);
    Q[0]=s;
    for(int i=1;i<=n;i++)
    {
        char type;
        cin>>type;
        if(type=='C')
        {
            int x;
            cin>>x;
            if(s[x]=='(')
                s[x]=')';
            else
                s[x]='(';
            update(1,1,m,x);
        }
        else if(type=='Q')
        {
            int l,r;
            cin>>l>>r;
            II p=get(1,1,m,l,r);
            cout<<p.y+p.z<<'\n';
        }
        else
        {
            int k;
            cin>>k;
            s=Q[k-1];
            make_st(1,1,m);
        }
        Q[i]=s;
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Zo".inp","r",stdin);
    freopen(Zo".out","w",stdout);
    nhap();
}
