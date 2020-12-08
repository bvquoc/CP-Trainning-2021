#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define y1 zzz
#define fi first
#define se second
#define PII pair<int,int>
#define PII2 pair<int,PII >
#define PII3 pair<PII,int >
#define PII4 pair<PII,PII >
#define pb push_back;
string s,cur[1010];
int n;
void sub1()
{
    s='.'+s;
    for(int i=1;i<=n;i++)
    {
        char ope;
        int id,l,r;
        cin>>ope;
        cur[i]=s;
        if(ope=='C')
        {
            cin>>id;
            if(s[id]=')')s[id]='(';
            else s[id]=')';
        }
        else if(ope=='Q')
        {
            cin>>l>>r;
            int cur=0,res=0;
            for(int j=l;j<=r;j++)
            {
                if(s[j]==')')cur--;
                else cur++;
                if(cur<0)
                {
                    cur++;
                    res++;
                }
            }
            cout<<res+cur<<'\n';
        }
        else
        {
            cin>>id;
            s=cur[id];
        }
    }
}
int t[8000010],a[8000010],numNode;
int d[8000010],h;
void push(int node,int l,int r)
{
    d[node<<1|1]+=d[node];
    d[node<<1]+=d[node];
    t[node]+=d[node];
    d[node]=0;
}
void build(int l,int r,int node)
{
    if(l==r)
    {
        t[node]=a[l];
        return ;
    }
    int mid=(l+r)/2;
    build(l,mid,node<<1);
    build(mid+1,r,node<<1|1);
    t[node]=min(t[node<<1],t[node<<1|1]);
}
void upd(int l,int r,int ql,int qr,int node,int val)
{
    if(d[node]!=0)push(node,l,r);
    if(ql>r||qr<l||r<l)return;
    if(ql<=l&&r<=qr)
    {
        d[node]+=val;
        push(node,l,r);
        return;
    }
    int mid=(l+r)/2;
    upd(l,mid,ql,qr,node<<1,val);
    upd(mid+1,r,ql,qr,node<<1|1,val);
    t[node]=min(t[node<<1],t[node<<1|1]);
}
int query(int l,int r,int ql,int qr,int node)
{
    //if(ql==0&&qr==5)cerr<<node<<" "<<t[node]<<" "<<l<<" "<<r<<'\n';
    if(d[node]!=0)push(node,l,r);
    if(ql>r||qr<l||r<l)return LONG_MAX;
    if(ql<=l&&r<=qr)return t[node];
    int mid=(l+r)/2;
    return min(query(l,mid,ql,qr,node<<1),
               query(mid+1,r,ql,qr,node<<1|1));
}
void sub2()
{
    int cur=0;
    numNode=s.size()-1;
    for(int i=0;i<s.size();i++)
    {
        cur+=(s[i]=='(');
        cur-=(s[i]==')');
        a[i]=cur;
        cerr<<a[i]<<" ";
    }cerr<<'\n';
    build(0,numNode,1);
    for(int j=0;j<s.size();j++)cerr<<query(0,numNode,j,j,1)<<" ";cerr<<'\n';
    for(int i=1;i<=n;i++)
    {
        char ope;
        int id,l,r;
        cin>>ope;
        if(ope=='C')
        {
            cin>>id;
            id--;
            if(s[id]=='(')
            {
                s[id]=')';
                upd(0,numNode,id,numNode,1,-2);
            }
            else
            {
                s[id]='(';
                upd(0,numNode,id,numNode,1,2);
            }
        }
        else if(ope=='Q')
        {
            cin>>l>>r;
            l--;r--;
            int base=query(0,numNode,l,r,1);
            int first;
            if(l-1<0)first=0;
            else first=query(0,numNode,l-1,l-1,1);
            int last=query(0,numNode,r,r,1);
            //cout<<first<<" "<<base<<" "<<last<<'\n';
            base-=first;
            last-=first;
            //cerr<<base<<" "<<last<<'\n';
            if(base<0)cout<<abs(base*2)+last<<'\n';
            else cout<<last<<'\n';
        }
        //for(int j=0;j<s.size();j++)cerr<<query(0,numNode,j,j,1)<<" ";cerr<<'\n';
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    freopen("FIXSTR.inp", "r", stdin);
    freopen("FIXSTR.out", "w", stdout);
    //int test;cin>>test;while(test--)
    cin>>s;
    cin>>n;
    if(s.size()<=1000)sub1();
    else sub2();
    return 0;
}
/*
((()))
10
C 1
Q 2 5
C 5
Q 1 6
U 3
C 4
Q 3 6
U 5
C 1
Q 1 5

((()))
8
C 1
Q 2 5
C 5
Q 1 6
C 4
Q 3 6
C 1
Q 1 5
*/
