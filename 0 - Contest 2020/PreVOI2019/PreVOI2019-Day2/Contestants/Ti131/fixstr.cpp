#include<bits/stdc++.h>
using namespace std;
#define fi   first
#define se   second
#define pb push_back
#define pu push
#define pii pair<int,int>
#define TASKNAME "fixstr"
const int minn=1000009;
struct node
{
    int lazy,val;
} tree[minn*4];
int presum[minn];
void build (int node,int l,int r)
{
    if (l==r) {tree[node].val=presum[l];return;}
    int m=(l+r)/2;
    build (2*node,l,m);build(2*node+1,m+1,r);
    tree[node].val=min(tree[2*node].val,tree[2*node+1].val);
}

void down(int vt)
{
    int tmp=tree[vt].lazy;
    tree[2*vt].lazy+=tmp;tree[2*vt].val+=tmp;
    tree[2*vt+1].lazy+=tmp;tree[2*vt+1].val+=tmp;
    tree[vt].lazy=0;
}
void upd(int node,int l,int r,int st,int en,int gt)
{
    if (r<st || l>en) return ;
    if (st<=l && r<=en)
    {
        tree[node].lazy+=gt;tree[node].val+=gt;
        return;
    }
    int m=(l+r)/2;
    down(node);
    upd(2*node,l,m,st,en,gt);upd(2*node+1,m+1,r,st,en,gt);
    tree[node].val=min(tree[2*node].val,tree[2*node+1].val);
}
int query(int node,int l,int r,int st,int en)
{
    if (en<l || r<st) return (1000005);
    if (st<=l && r<=en) {return tree[node].val;}
    int m=(l+r)/2;
    down(node);
    int q1=query(2*node,l,m,st,en),q2=query(2*node+1,m+1,r,st,en);
    return min(q1,q2);
}
///////////////////////////////////////////////////////////////////
string s,truy[1009];
int check,m;
struct _{char loai;int x,y;} que[1000009];
map <char,int> dau;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen(TASKNAME".inp", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
    #endif
    check=1; dau['(']=1;dau[')']=-1;
    cin>>s>>m;s=' '+s;
    for (int i=1;i<=m;i++)
    {
        char kt;int a,b;cin>>kt;
        if (kt=='Q')
            {cin>>a>>b;que[i]={kt,a,b};}
        else {cin>>a;que[i]={kt,a,0};}
        if (kt=='U') check=0;
    }
    if (check==1)
    {
        int n=s.size()-1;
        for (int i=1;i<=n;i++) presum[i]=dau[s[i]],presum[i]+=presum[i-1];
        build (1,1,n);
        for (int i=1;i<=m;i++)
        {
            if (que[i].loai=='C')
                {
                    if (s[que[i].x]=='(')
                            { s[que[i].x]=')';upd(1,1,n,que[i].x,n,-2); }  else {s[que[i].x]='(';upd(1,1,n,que[i].x,n,2);}
                }
            else if (que[i].loai=='Q')
                {
                    int luu,res;
                    if (s[que[i].x]=='(') luu=query(1,1,n,que[i].x,que[i].x)-1; else luu=query(1,1,n,que[i].x,que[i].x)+1;
                    int sum=query(1,1,n,que[i].y,que[i].y)-luu,mi=query(1,1,n,que[i].x,que[i].y)-luu;
                    res=(sum-mi)+abs(mi);
                    cout<<res<<'\n';
                }
        }
    }
    else
    {
        //cout<<1<<endl;
        truy[0]=s;
        for (int i=1;i<=m;i++)
        {
            truy[i]=truy[i-1];
            if (que[i].loai=='C') {   if ( truy[i][que[i].x]=='(' ) truy[i][que[i].x]=')'; else truy[i][que[i].x]='(';    }
            else if (que[i].loai=='Q')
                {
                    int tong=0,res=0;
                    for (int j=que[i].x;j<=que[i].y;j++)
                        {
                            tong+=dau[truy[i][j]];
                            if (tong<0) {tong++;res++;}
                        }
                    res+=tong;
                    cout<<res<<'\n';
                }
            else if (que[i].loai=='U') {truy[i]=truy[que[i].x-1];      }
            //cout<<truy[i]<<endl;
        }
    }
    return 0;
}
