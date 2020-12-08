#include<bits/stdc++.h>
using namespace std;
string before[1010];
int l[4*1000010],h[4*1000010],sum[4*1000010],leaf[4*1000010],sum2[4*1000010],sum3[4*1000010];
void build(int x,int low,int high)
{
    l[x]=low;h[x]=high;
    sum[x]=0;
    sum2[x]=0;
    sum3[x]=0;
    if(low==high)leaf[low]=x;
    else
    {
        int mid=(low+high)/2;
        build(2*x,low,mid);
        build(2*x+1,mid+1,high);
    }
}
void update(int x,int k)
{
    int up=leaf[x];
    sum[up]=k;sum2[up]=1-k;
    if(sum2[up]>sum[up])
    {
        sum3[up]++;
        sum2[up]=sum[up];
    }
    for(up/=2;up>0;up/=2)
    {
        sum3[up]=sum3[2*up];
        sum[up]=sum[2*up]+sum[2*up+1];
        sum2[up]=sum2[2*up]+sum2[2*up+1];
    }
}
int qi,qj;
int request(int x)
{
    if(h[x]<qi||l[x]>qj)return 0;
    if(qi<=l[x]&&h[x]<=qj)return sum3[x];
    return request(2*x)+request(2*x+1);
}
int query(int i,int j)
{
    qi=i;qj=j;
    return request(1);
}
int request2(int x)
{
    if(h[x]<qi||l[x]>qj)return 0;
    if(qi<=l[x]&&h[x]<=qj)return sum[x];
    return request(2*x)+request(2*x+1);
}
int query2(int i,int j)
{
    qi=i;qj=j;
    return request2(1);
}
int request3(int x)
{
    if(h[x]<qi||l[x]>qj)return 0;
    if(qi<=l[x]&&h[x]<=qj)return sum2[x];
    return request(2*x)+request(2*x+1);
}
int query3(int i,int j)
{
    qi=i;qj=j;
    return request3(1);
}
main()
{
    freopen("FIXSTR.inp","r",stdin);
    freopen("FIXSTR.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int m;
    cin>>m;
    int n=s.size();
    if(n<=1000&&m<=1000)
    {
        for(int i=1;i<=m;i++)
        {
            before[i]=s;
            char type;
            cin>>type;
            if(type=='C')
            {
                int id;
                cin>>id;
                if(s[id-1]=='(')s[id-1]=')';
                else s[id-1]='(';
            }
            else if(type=='Q')
            {
                int l,r;
                cin>>l>>r;
                int cnt1=0,cnt2=0,res=0;
                for(int i1=l-1;i1<r;i1++)
                {
                    if(s[i1]=='(')
                    {
                        cnt1++;
                    }
                    else cnt2++;
                    if(cnt2>cnt1)
                    {
                        res+=cnt2-cnt1;
                        cnt2=cnt1;
                    }
                }
                cout<<res+cnt1-cnt2<<'\n';
            }
            else
            {
                int id;
                cin>>id;
                s=before[id];
            }
        }
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')update(i+1,1);
            else update(i+1,0);
        }
        for(int i=1;i<=m;i++)
        {
            char type;
            cin>>type;
            if(type=='C')
            {
                int id;
                cin>>id;
                if(s[id-1]=='(')
                {
                    update(id,0);
                }
                else
                {
                    update(id,1);
                }
            }
            else if(type=='Q')
            {
                int l,r;
                cin>>l>>r;
                cout<<query(l,r)+query2(l,r)-query3(l,r)<<'\n';
            }
        }
    }
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
*/
