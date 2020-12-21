#include<bits/stdc++.h>
#define INF 100005
using namespace std;
int m,n,L,R;
struct node
{
    int l;
    int r;
};
bool cmp_l(node &a,node &b)
{
    if(a.l==b.l)
    {
        return  a.r<b.r;
    }
    return a.r<b.r;
}
node B[100005];
int A[100005];
void sub1()
{
    sort(B+1,B+m+1,cmp_l);
    for(int i=1;i<=m;i++)
    {
        if(B[i].l<L)
        {
            B[i].l=L;
        }
    }
    int preL=A[1];int preR=A[1];
    int L_res=100005;int R_res=0;
    int res=1;
    if(B[1].l>L)
    {
        cout<<-1;
        exit(0);
    }
    for(int i=1;i<=m;i++)
    {
        if(B[i].r<L) continue;
        if(B[i].r<preR) continue;
        if(B[i].l<=preL && B[i].r>=preR)
        {
            preL=B[i].l;
            preR=B[i].r;
            L_res=min(preL,L_res);
            R_res=max(R_res,preR);
        }
        else if((B[i].l>=preL && B[i].l<=preR)&& B[i].r>=preR)
        {
           res++;
           preL=B[i].l;
           preR=B[i].r;
           R_res=max(R_res,preR);
        }
    }
    if(L_res<=L && R_res>=100000)
    {
        cout<<res;
        exit(0);
    }
    else
    {
        cout<<-1;
    }
}
int main()
{
    freopen("COOLMAC.inp","r",stdin);
    freopen("COOLMAC.out","w",stdout);
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>B[i].l>>B[i].r;
    }
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>A[i];
    }
    sort(A+1,A+n+1);
    L=A[1];R=100000;
    sub1();
    return 0;
}
