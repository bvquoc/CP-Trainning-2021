/// !! Killian !! ///

#include <bits/stdc++.h>
#define Killian "FIXSTR"
#define MOD 1000000007
#define endl "\n"
#define pii pair <int,int>
using namespace std;
string s;
int n,m;
int d[1000005];
string prevstr[1000005];
struct Tree
{
    int lazy;
    int val;
} st[4000005],st2[4000005];
void down(int node)
{
    int t = st[node].lazy;
    st[node*2].lazy += t;
    st[node*2].val += t;
    st[node*2+1].lazy += t;
    st[node*2+1].val += t;
    st[node].lazy = 0;
}
void Preprocess()
{
    for (int i = 1; i<=4*1000000; i++)
        st[i].val=INT_MAX;
}
void make_st(int node, int l, int r)
{
    if (l == r)
    {
        st[node].val=d[l];
        return;
    }
    make_st(node*2,l,(l+r)/2);
    make_st(node*2+1,(l+r)/2+1,r);
    st[node].val=min(st[2*node+1].val,st[2*node].val);
}
void update(int node, int l, int r, int u, int v, int value)
{
    if (v < l || r < u)
        return ;
    if (u <= l && r <= v)
    {
        st[node].val += value;
        st[node].lazy += value;
        return ;
    }
    down(node);
    update(node*2,l,(l+r)/2,u,v,value);
    update(node*2+1,(l+r)/2+1,r,u,v,value);
    st[node].val = min(st[node*2].val, st[node*2+1].val);
}
int get(int node, int l, int r, int u, int v)
{
    if (v < l || r < u)
        return INT_MAX;
    if (u <= l && r <= v)
        return st[node].val;
    down(node);
    int a=get(node*2, l,(l + r)/2, u, v);
    int b=get(node*2+1,(l + r)/2+1, r, u, v);
    return min(a,b);
}
void down2(int node)
{
    int t = st[node].lazy;
    st[node*2].lazy += t;
    st[node*2].val += t;
    st[node*2+1].lazy += t;
    st[node*2+1].val += t;
    st[node].lazy = 0;
}
void make_st2(int node, int l, int r)
{
    if (l == r)
    {
        st2[node].val=d[l];
        return;
    }
    make_st2(node*2,l,(l+r)/2);
    make_st2(node*2+1,(l+r)/2+1,r);
    st2[node].val=st2[2*node+1].val+st2[2*node].val;
}
void update2(int node, int l, int r, int u, int v, int value)
{
    if (v < l || r < u)
        return ;
    if (u <= l && r <= v)
    {
        st2[node].val += value;
        st2[node].lazy += value;
        return ;
    }
    down2(node);
    update2(node*2,l,(l+r)/2,u,v,value);
    update2(node*2+1,(l+r)/2+1,r,u,v,value);
    st2[node].val = st2[node*2].val+st2[node*2+1].val;
}
int get2(int node, int l, int r, int u, int v)
{
    if (v < l || r < u)
        return 0;
    if (u <= l && r <= v)
        return st2[node].val;
    down2(node);
    int a=get2(node*2, l,(l + r)/2, u, v);
    int b=get2(node*2+1,(l + r)/2+1, r, u, v);
    return a+b;
}
int cost (int l,int r)
{
    deque <char> dq;
    for (int i=l; i<=r; i++)
    {
        if (s[i]==')')
        {
            if (dq.size()>0)
                if (dq.front()=='(')
                {
                    dq.pop_front();
                    continue;
                }
            dq.push_back(s[i]);
        }
        else
            dq.push_front(s[i]);
    }
    return dq.size();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Killian".inp","r",stdin);
    freopen(Killian".out","w",stdout);
    cin>>s;
    n=s.size();
    s=' '+s;
    for (int i=1; i<=n; i++)
    {
        if (s[i]=='(')
            d[i]=d[i-1]+1;
        else
            d[i]=d[i-1]-1;
    }
    Preprocess();
    make_st(1,1,n);
    make_st2(1,1,n);
    cin>>m;
    prevstr[0]=s;
    for (int i=1; i<=m; i++)
    {
        char type;
        cin>>type;
        if (type=='C')
        {
            int x;
            cin>>x;
            prevstr[i]=s;
            if (s[x]=='(')
            {
                s[x]=')';
                update2(1,1,n,x,n,-2);
                update(1,1,n,x,n,-2);
            }
            else
            {
                s[x]='(';
                update2(1,1,n,x,n,2);
                update(1,1,n,x,n,2);
            }
            continue;
        }
        if (type=='Q')
        {
            int u,v;
            cin>>u>>v;
            prevstr[i]=s;
            if ((get2(1,1,n,1,v)-get2(1,1,n,1,u-1))==0 && get(1,1,n,u,v)>=d[u-1])
                cout<<0<<endl;
            else
                cout<<cost(u,v)<<endl;
            continue;
        }
        if (type=='U')
        {
            int x;
            cin>>x;
            prevstr[i]=s;
            s=prevstr[x];
            make_st(1,1,n);
            make_st2(1,1,n);
        }
    }
}
