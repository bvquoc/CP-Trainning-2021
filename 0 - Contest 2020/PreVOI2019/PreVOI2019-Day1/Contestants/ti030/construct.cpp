#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
long long st[400005],L[400005],R[400005],a[100005],n,b[100005],mn,ans;
vector<ll> vt;
void build(ll id,ll l,ll r)
{
    L[id]=l;
    R[id]=r;
    if(l==r)
    {
        st[id]=a[l];
        return;
    }
    long long mid=(l+r)>>1;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=min(st[(id<<1)],st[(id<<1)|1]);
}
void update(ll id,ll l,ll r,ll val)
{
    if(l>R[id] || r<L[id]) return;
    if(L[id]==R[id])
    {
            st[id]+=val;
            return;
    }
    long long m=(l+r)>>1;
    update(id<<1,l,r,val);
    update((id<<1)|1,l,r,val);
    st[id]=min(st[(id<<1)],st[(id<<1)|1]);
}
void update1(ll id,ll l,ll r,ll val)
{
    if(l>R[id] || r<L[id]) return;
    if(L[id]==R[id])
    {
        st[id]-=val;
        if (st[id]==0)
        st[id]=1e9;
        //vt.push_back(L[id]);
        return;
    }
    long long m=(l+r)>>1;
    update(id<<1,l,r,val);
    update((id<<1)|1,l,r,val);
    st[id]=min(st[(id<<1)],st[(id<<1)|1]);
}
long long  get(ll id,ll l,ll r)
{
    if(L[id]>r ||R[id]<l)
        return 1e9;
    if(L[id]<=l && R[id]>=r)
    {
        return st[id];
    }
    long long m=(l+r)>>1;
    return min(get((id<<1),l,m),get((id<<1)|1,m+1,r));
}

int main()
{
    freopen("construct.inp","r",stdin);
    freopen("construct.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long T,m;
    cin>>T;
    for (int k=1;k<=T;k++)
    {
        cin>>n>>m;
        for (int i=1;i<=n;i++)
            cin>>a[i];
        build(1,1,n);
        cout<<st[1]<<endl;
        while(m--)
        {
            long long type,le,ri,v;
            cin>>type>>le>>ri;
            if(type==1)
            {
                cin>>v;
                for (int i=le;i<=ri;i++)
                    a[i]+=v;
                //update(1,le,ri,v);
            }
            //cout<<st[1]<<'\n';
            if(type==2)
            {
                ans=0;
                build(1,le,ri);
                for (int i=le;i<=ri;i++)
                    b[i]=a[i];
                while(1)
                {
                    bool ok=true;
                    for(int i=le;i<=ri;i++)
                    {
                        if(b[i]!=0)
                        {
                            ok=false;
                            long long j;
                            for (j=i+1;j<=n;j++)
                            {
                                if(a[j]==0)
                                  break;
                            }
                            j--;
                            if(j>=i)
                            {
                                mn=get(1,i,j-1);
                                ans+=mn;
                                update1(1,i,j,mn);
                                for (int x=i;x<=j;x++)
                                    b[x]-=mn;
                            }
                        }
                    }
                    if(ok) break;
                }
                cout<<ans<<'\n';
            }
        }
        /*mn=st[1];
        update(id,mn);
        vt.push_back(n+1);
        for (int i=0;i<vt.size();i++);
*/
    }
    return 0;
}
