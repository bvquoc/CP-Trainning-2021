#include <bits/stdc++.h>
#define int long long
#define N 1000006
using namespace std;
int n,m;
string s;
string a[1005];
stack  < int > st;
struct node
{
    int m,d,x;
}t[4*N],mau;
void build(int k ,int l,int r)
{
    if(l==r)
    {
        if(s[l]==')')t[k].d=1;
        if(s[l]=='(')t[k].m=1;
        return;
    }
    int mid=(l+r)/2;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    t[k].x=t[k*2].x+t[k*2+1].x+min(t[k*2].m,t[k*2+1].d);
    t[k].m=t[k*2].m-min(t[k*2].m,t[k*2+1].d)+t[k*2+1].m;
    t[k].d=t[k*2+1].d-min(t[k*2+1].d,t[k*2].m)+t[k*2].d;
}
void update(int k,int l,int r,int i)
{
    if(l>i || i>r)return;
    if(i==l && l==r)
    {
        if(s[i]=='(')
        {
            s[i]=')';
            //cout<<s<<" ";
            t[k].d=1;
            t[k].m=0;
        }
        else
        {
            s[i]='(';
            //cout<<s<<" ";
            t[k].m=1;
            t[k].d=0;
        }
        return;
    }
    int mid=(l+r)/2;
    update(k*2,l,mid,i);
    update(k*2+1,mid+1,r,i);
    t[k].x=t[k*2].x+t[k*2+1].x+min(t[k*2].m,t[k*2+1].d);
    t[k].m=t[k*2].m-min(t[k*2].m,t[k*2+1].d)+t[k*2+1].m;
    t[k].d=t[k*2+1].d-min(t[k*2+1].d,t[k*2].m)+t[k*2].d;
}
node get(int k,int l,int r,int i,int j)
{
    if(i>r || l>j)return mau;
    if(i<=l && r<=j)return t[k];
    int mid=(l+r)/2;
    node le=get(k*2,l,mid,i,j);
    node ri=get(k*2+1,mid+1,r,i,j);
    node ans;
    ans.x=le.x+ri.x+min(le.m,ri.d);
    ans.m=le.m-min(le.m,ri.d)+ri.m;
    ans.d=ri.d-min(ri.d,le.m)+le.d;
    return ans;
}
void sub1()
{
    for(int t=1;t<=m;t++)
    {
        a[t]=s;
        char x;
        cin>>x;
        if(x=='C')
        {
            int pos;
            cin>>pos;
            if(s[pos]=='(')s[pos]=')';
            else s[pos]='(';
        }
        if(x=='U')
        {
            int pos;
            cin>>pos;
            s=a[pos];
        }
        if(x=='Q')
        {
            int l,r,dem=0;
            cin>>l>>r;
            for(int i=l;i<=r;i++)
            {
                if(s[i]=='(')st.push(i);
                else
                {
                    if(st.empty())
                    {
                        dem++;
                        continue;
                    }
                    st.pop();
                }
            }
            while(!st.empty())
            {
                dem++;
                st.pop();
            }
            cout<<dem<<'\n';
        }
    }
}
void sub2()
{
    build(1,1,n);
    while(m--)
    {
        char x;
        cin>>x;
        if(x=='C')
        {
            int pos;
            cin>>pos;
            update(1,1,n,pos);
        }
        if(x=='Q')
        {
            int l,r,dem=0;
            cin>>l>>r;
            cout<<(r-l+1)-get(1,1,n,l,r).x*2<<'\n';
        }
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("FIXSTR.INP","r",stdin);
    freopen("FIXSTR.OUT","w",stdout);
    cin>>s;
    n=s.size();
    s=' '+s;
    cin>>m;
    mau.x=0;
    mau.m=0;
    mau.d=0;
    if(n<=1000 && m<=1000)sub1();
    else sub2();
}
