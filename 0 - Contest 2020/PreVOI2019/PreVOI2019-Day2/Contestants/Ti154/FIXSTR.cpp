#include<bits/stdc++.h>

using namespace std;

string a;
int t,m,lazy[4000006],n,sta[1000006];
char s[1000006];
struct qwe
{
    int tr,tong;
}f[4000006],base;

void sub1()
{
    string xau[1005];
    cin>>m;
    for(int id=1;id<=m;id++)
    {
        char ty;
        int x,y,k;
        cin>>ty;
        xau[id]=a;
        if(ty=='C')
        {
            cin>>x;
            if(a[x-1]=='(') a[x-1]=')';
            else a[x-1]='(';
        }
        else if(ty=='U')
        {
            cin>>k;
            a=xau[k];
        }
        else if(ty=='Q')
        {
            cin>>x>>y;
            int res=0,ans=1e8;
            for(int i=x-1;i<y;i++)
            {
                if(a[i]=='(')
                {
                    res++;
                    ans=min(ans,res);
                }
                else
                {
                    res--;
                    ans=min(ans,res);
                }
            }
            if(ans>=0)
            {
                cout<<res<<'\n';
            }
            else
            {
                cout<<-ans+abs(res-ans)<<'\n';
            }
        }
    }

}

void build(int id,int l,int r)
{
    if(l==r)
    {
        f[id].tr=sta[l];
        f[id].tong=sta[l];
    }
    else
    {
        int m=(l+r)/2;
        build(id*2,l,m);
        build(id*2+1,m+1,r);
        f[id].tr=min(f[2*id].tr,f[2*id+1].tr);
        f[id].tong=f[2*id+1].tong;
    }
}

void update(int id,int l,int r,int x,int gt)
{
    if(r<x) return ;
    else if(x<=l)
    {
        lazy[id]+=gt;
    }
    else
    {
        int m=(l+r)/2;
        update(id*2,l,m,x,gt);
        update(id*2+1,m+1,r,x,gt);
    }
}

void down(int id,int l,int r,int gt)
{
    if(l==r)
    {
        gt+=lazy[id];
        lazy[id]=0;
        f[id].tr+=gt;
        f[id].tong+=gt;
        //cout<<l<<" "<<r<<" "<<f[id].tong<<'\n';
    }
    else
    {
        gt+=lazy[id];

        lazy[id]=0;
        int m=(l+r)/2;
        down(id*2,l,m,gt);
        down(id*2+1,m+1,r,gt);
        f[id].tr=min(f[2*id].tr,f[2*id+1].tr);
        f[id].tong=f[2*id+1].tong;
        //cout<<l<<" "<<r<<" "<<f[id].tr<<'\n';
    }
}

int su(int id,int l,int r,int x)
{
    if(x<l) return 0;
    else if(x>=r)
    {
        //down(id,l,r);
        return f[id].tong;
    }
    else
    {
        int m=(l+r)/2;
        //down(id,l,r);
        int res=su(id*2+1,m+1,r,x);
        return res;
    }
}

qwe get(int id,int l,int r,int x,int y)
{
    if(x>r||y<l) return base;
    else if(l>=x&&r<=y)
    {
        //down(id,l,r);
        return f[id];
    }
    else
    {
        int m=(l+r)/2;
        //down(id,l,r);
        qwe le=get(id*2,l,m,x,y);
        qwe ri=get(id*2+1,m+1,r,x,y);
        qwe kq;
        kq.tr=min(le.tr,ri.tr);
        kq.tong=ri.tong;
        return kq;
    }
}

void sub2()
{
    base.tr=1e8;
    for(int i=1;i<=n;i++)
    {
        s[i]=a[i-1];
        if(s[i]=='(') sta[i]=sta[i-1]+1;
        else sta[i]=sta[i-1]-1;
    }
    build(1,1,n);
    cin>>m;
    while(m--)
    {
        char ty;
        int x,y,k;
        cin>>ty;
        if(ty=='C')
        {
            cin>>x;
            if(s[x]=='(')
            {
                s[x]=')';
                update(1,1,n,x,-2);
            }
            else
            {
                s[x-1]='(';
                update(1,1,n,x,2);
            }
        }
        else if(ty=='Q')
        {
            cin>>x>>y;
            down(1,1,n,0);
            int q=su(1,1,n,x-1);
            qwe kq=get(1,1,n,x,y);
            int res=kq.tong-q;
            int ans=kq.tr-q;
            //cout<<q<<" "<<res<<" "<<ans<<" ";
            if(ans>=0)
            {
                cout<<res<<'\n';
            }
            else
            {
                cout<<-ans+abs(res-ans)<<'\n';
            }
        }
    }
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("FIXSTR.inp","r",stdin);
    freopen("FIXSTR.out","w",stdout);
    cin>>a;
    n=a.length();
    if(a.length()<=1000) sub1();
    else sub2();
}
