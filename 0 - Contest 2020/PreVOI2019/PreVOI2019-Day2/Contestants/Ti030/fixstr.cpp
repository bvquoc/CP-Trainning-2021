#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<ll ,ll> ii;
typedef pair<ll, string> is;
stack<ii> luu;
stack<is> luu2;
string s;
char type;
ll x,y,st[4000006],L[4000006],R[4000006];
void build (ll id ,ll l,ll r)
{
    L[id]=l;
    R[id]=r;
    if(l==r)
    {
        if(s[l]=='(')
        st[id]=1;
        else st[id]=-1;
        return;
    }
    long long m=(l+r)>>1;
    build(id<<1,l,m);
    build((id<<1) | 1,m+1,r);
    if(st[id<<1]>=0)
    st[id]=st[id<<1]+st[(id<<1) | 1];
    else
      st[id]=abs(st[id<<1])+st[(id<<1) | 1];
    return;
}
long long update(ll id,ll pos)
{
    if(pos<L[id] || pos> R[id])
    {
        return st[id];
    }
    if(L[id]==R[id])
    {
        st[id]=st[id]*(-1);
        return st[id];
    }
    long long le=update(id<<1,pos);
    long long ri=update((id<<1) | 1,pos);
    if(le>=0)
        st[id]=le+ri;
    else st[id]=abs(le)+ri;
    return st[id];
}
long long  get(ll id,ll l,ll r)
{
    if(L[id]>r || R[id]<l)
        return 0;
    if(L[id]>=l && R[id]<=r)
    {
        return st[id];
    }
    long long m=(l+r)>>1;
    ll le=get(id<<1,l,r),ri=get((id<<1)|1,l,r);
    if(le>=0)
    return(le+ri);
    else return (abs(le)+ri);

}
int main()
{
    freopen("fixstr.inp","r",stdin);
    freopen("fixstr.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s;
    build(1,0,s.size()-1);
    int m;
    cin>>m;
    /*if(s.size()>1000 || m>1000)
    for(int k=1;k<=m;k++)
    {
        cin>>type>>x;
        if(type=='C')
        {
            update(1,x-1);
            luu.push({k,x-1});
        }
        if(type=='Q')
        {
            cin>>y;
            long long ans=get(1,x-1,y-1);
            cout<<ans<<'\n';
        }
        if(type=='U')
        {
            while (!luu.empty() && luu.top().F <= x)
            {
                ii tmp=luu.top();
                long long vt=tmp.S;
                luu.pop();
                update(1,vt);
            }
        }
    }
    else*/
        for(int k=1;k<=m;k++)
    {
        cin>>type>>x;
        if(type=='C')
        {
            luu2.push({k,s});
            x--;
            if(s[x]==')') s[x]='(';
            else s[x]=')';
        }
        if(type=='Q')
        {
            cin>>y;
            long long ans=0,open=0,close=0;
            x--;
            y--;
            if(s[x]=='(') open++;
            else close++;
            for (int i=x+1;i<=y;i++)
            {
            if(s[i]=='(')
                open++;
            else
            {
                if (open>1)
                    open--;
                else close++;
            }
            }
            ans+=abs(close-open);
            cout<<ans<<'\n';
        }
        if(type=='U')
        {
          //      is tmp2=luu2.top();
            while (!luu2.empty() &&
                   luu2.top().F >= x)
            {
                is tmp=luu2.top();
                s=tmp.S;
                //cout<<s<<'\n';
                luu2.pop();
            }
        }
        //cout<<s<<endl;

    }
    return 0;
}
