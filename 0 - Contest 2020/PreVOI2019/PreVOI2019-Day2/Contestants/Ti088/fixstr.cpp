#include <bits/stdc++.h>
using namespace std;
string str[1001],s;
int n,l,r,i,j,q;
char ch;
void sub1()
{
    for(j=1;j<=q;j++)
    {
        str[j]=s;
        cin>>ch;
        if(ch=='C')
        {
            cin>>i;
            if(s[i]=='(') s[i]=')'; else s[i]='(';
        }
        else if(ch=='U')
        {
            cin>>i;
            s=str[i];
        }
        else
        {
            cin>>l>>r;
            int cnt=0,kq=0;
            for(i=l;i<=r;i++)
            {
                if(s[i]=='(') cnt++; else cnt--;
                if(cnt<0) { kq++; cnt++; }
            }
            kq+=abs(cnt);
            cout<<kq<<'\n';
        }
    }
}

/////////////////////////////////////////////////////////////////////////


struct IT { int open,close; };
IT operator + (const IT &a,const IT &b)
{
    IT kq;
    kq.open=b.open; kq.close=a.close;
    if(a.open>b.close) kq.open+=a.open-b.close;
    else kq.close+=b.close-a.open;
    return kq;
}
IT st[4000001];
void update(int id,int l,int r,int u,char ch)
{
    if(u<l || u>r) return ;
    if(l==r)
    {
        if(ch=='(') st[id]={ 1,0 }; else st[id]={ 0,1 };
        return ;
    }
    int mid=(l+r)>>1;
    update(id*2,l,mid,u,ch); update(id*2+1,mid+1,r,u,ch);
    st[id]=st[id*2]+st[id*2+1];
}
IT get(int id,int l,int r,int u,int v)
{
    if(v<l || u>r) return { 0,0 };
    if(u<=l && r<=v) return st[id];
    int mid=(l+r)>>1;
    return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
void sub2()
{
    for(i=1;i<=n;i++) update(1,1,n,i,s[i]);
    while(q--)
    {
        cin>>ch;
        if(ch=='C')
        {
            cin>>i;
            if(s[i]=='(') s[i]=')'; else s[i]='(';
            update(1,1,n,i,s[i]);
        }
        else
        {
            cin>>l>>r;
            IT x=get(1,1,n,l,r);
            cout<<x.open+x.close<<'\n';
        }
    }
}
int main()
{
    freopen("fixstr.inp","r",stdin);
    freopen("fixstr.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>s;
    n=s.length(); s=" "+s;
    cin>>q;
    if(n<=1000 && q<=1000) sub1();
    else sub2();
}
