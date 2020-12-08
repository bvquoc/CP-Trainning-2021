#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5;
string s[N];
int n,m,ST[4*N],lazy[4*N],val[N];

void build (int id,int l,int r)
{
    if (l==r)
    {
        ST[id]=val[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build (id*2+1,mid+1,r);
    ST[id]=min(ST[id*2],ST[id*2+1]);

}

void dolazy(int id,int l,int r)
{
    if (lazy[id]==0)
        return;
    ST[id]+=lazy[id];
    if (l!=r)
    {
        lazy[id*2]+=lazy[id];
        lazy[id*2+1]+=lazy[id];
    }
    lazy[id]=0;
}

void Update(int id,int l,int r,int L,int R,int val)
{
    dolazy(id,l,r);
    if (r<L||R<l) return;
    if(L<=l&&r<=R)
    {
        ST[id]+=val;
        if (l!=r)
        {
            lazy[id*2]+=val;
            lazy[id*2+1]+=val;
        }
        return;
    }
    int mid=(l+r)/2;
    Update(id*2,l,mid,L,R,val);
    Update(id*2+1,mid+1,r,L,R,val);
    ST[id]=min(ST[id*2],ST[id*2+1]);
}

int get (int id,int l,int r,int L,int R)
{
    dolazy(id,l,r);
    if (r<L||R<l)
        return 1e9;
    if (L<=l&&r<=R)
    {
        return ST[id];
    }
    int mid=(l+r)/2;
    return min(get (id*2,l,mid,L,R),get (id*2+1,mid+1,r,L,R));
}


void sub1()
{
    for(int i=1;i<=m;i++)
    {
        s[i]=s[i-1];
        char type;
        cin>>type;
        if(type=='C')
        {
            int id;
            cin>>id;
            if(s[i][id]=='(') s[i][id]=')';
            else s[i][id]='(';
        }
        else if(type=='U')
        {
            int k;
            cin>>k;
            s[i]=s[k-1];
        }
        else
        {
            int l,r;
            cin>>l>>r;
            int cnt=0;
            int res=0;
            for(int j=l;j<=r;j++)
            {
                if(s[i][j]=='(') cnt++;
                else cnt--;
                if(cnt<0)
                {
                    res++;
                    cnt=0;
                }
            }
            res+=cnt;
            cout<<res<<'\n';
        }
    }
}

void sub2()
{
    string t=s[0];
    for(int i=1;i<=n;i++)
    {
        if(t[i]=='(') val[i]=val[i-1]+1;
        else val[i]=val[i-1]-1;
    }
    build(1,1,n);
    while(m--)
    {
        char type;
        cin>>type;
        if(type=='C')
        {
            int id;
            cin>>id;
            if(t[id]=='(')
            {
                t[id]=')';
                Update(1,1,n,id,n,-2);
            }
            else
            {
                t[id]='(';
                Update(1,1,n,id,n,2);
            }
        }
        else
        {
            int l,r;
            cin>>l>>r;
            int mn=get(1,1,n,l,r);
            int res=0;
            int last=get(1,1,n,r,r);
            if(l>1)
            {
                mn-=get(1,1,n,l-1,l-1);
                last-=get(1,1,n,l-1,l-1);
            }
            if(mn<0)
            {
                res=res+(-mn);
                last+=(-mn);
            }
            cout<<res+last<<'\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("FIXSTR.INP","r",stdin);
    freopen("FIXSTR.OUT","w",stdout);
    cin>>s[0]>>m;
    n=s[0].size();
    s[0]=" "+s[0];
    if(n<=1000&&m<=1000) sub1();
    else sub2();
}
