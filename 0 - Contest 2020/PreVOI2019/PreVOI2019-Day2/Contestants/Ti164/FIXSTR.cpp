#include <bits/stdc++.h>

using namespace std;
int cmd;
string s;
struct queries
{
    char ch;
    int pos1;
    int pos2;
};
pair<int,int> St[4000004];
void update(int id,int l,int r,int i,pair<int,int> val)
{
    if(i<l||i>r) return;
    if(l==r)
    {
        St[id]=val;
        return;
    }
    int mid=(l+r)/2;
    update(2*id,l,mid,i,val);
    update(2*id+1,mid+1,r,i,val);
    if(St[2*id].second>St[2*id+1].first)
    St[id]=make_pair(St[2*id].first,St[2*id+1].second+St[2*id].second-St[2*id+1].first);
    else
        St[id]=make_pair(St[2*id].first+St[2*id+1].first-St[2*id].second,St[2*id+1].second);
}
pair<int,int> get(int id,int l,int r,int u,int v)
{
    if(u>r||v<l) return make_pair(0,0);
    if(u<=l&&v>=r)
    {
        return St[id];
    }
    int mid=(l+r)/2;
    pair<int,int> get1=get(2*id,l,mid,u,v);
    pair<int,int> get2=get(2*id+1,mid+1,r,u,v);
    if(get1.second>get2.first)
        return make_pair(get1.first,get1.second-get2.first+get2.second);
    else
        return make_pair(get1.first+get2.first-get1.second,get2.second);
}
int ts(int l,int r)
{
    int am=0,dg=0;
    for(int i=l;i<=r;i++)
    {
        if(s[i]==')'&&dg==0) am++;
        else
        {
            if(s[i]=='('&&dg==0)
            {
                dg++;
                continue;
            }
            if(s[i]==')'&&dg>0)
            {
                dg--;
                continue;
            }
            if(s[i]=='('&&dg>0)
            {
                dg++;
            }
        }
    }
    return dg+am;
}
queries q[1000001];
int cntu=0;
bool kk[1000001];
int n;
map<int,string> m;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("FIXSTR.inp","r",stdin);
    freopen("FIXSTR.out","w",stdout);
    cin>>s;
    n=s.size();
    s=' '+s;
    cin>>cmd;
    for(int i=1;i<=cmd;i++)
    {
        char x;
        cin>>x;
        if(x=='C')
        {
            cin>>q[i].pos1;
        }
        if(x=='Q')
        {
            cin>>q[i].pos1>>q[i].pos2;
        }
        if(x=='U')
        {
            cin>>q[i].pos1;
            kk[q[i].pos1]=true;
            cntu++;
        }
        q[i].ch=x;
    }
    //kk.push_back(-1);
    //reverse(kk.begin(),kk.end());
    if(cntu==0)
    {
        for(int i=1;i<=n;i++)
        if(s[i]==')')update(1,1,n,i,make_pair(1,0));
        else update(1,1,n,i,make_pair(0,1));
        for(int i=1;i<=cmd;i++)
        {
            if(q[i].ch=='C')
            {
                if(get(1,1,n,q[i].pos1,q[i].pos1).first==1)
                update(1,1,n,q[i].pos1,make_pair(0,1));
                else update(1,1,n,q[i].pos1,make_pair(1,0));
            }
            else
            {
                int pos1,pos2;
                pos1=q[i].pos1;
                pos2=q[i].pos2;
                pair<int,int> tg=get(1,1,n,pos1,pos2);
                cout<<tg.first+tg.second<<'\n';
            }
        }
        return 0;
    }
    //  if(s.size()<=1000&&cmd<=1000)
    {
        for(int i=1;i<=cmd;i++)
        {
            //cout<<s<<'\n';
            if(kk[i])
            {
                m[i]=s;
               // cout<<i<<' '<<m[i]<<'\n';
            }
            if(q[i].ch=='U')
            {
                //cout<<q[i].pos1<<'\n';
                s=m[q[i].pos1];
                //cout<<q[i].pos1<<' '<<s<<'\n';
                continue;
            }
            if(q[i].ch=='C')
            {
                if(s[q[i].pos1]=='(') (s[q[i].pos1])=')';
                else s[q[i].pos1]='(';
                continue;
            }
            if(q[i].ch=='Q')
            {
               cout<<ts(q[i].pos1,q[i].pos2)<<'\n';
            }
        }
        return 0;
    }
}
