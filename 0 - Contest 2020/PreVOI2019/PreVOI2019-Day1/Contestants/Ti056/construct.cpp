#include<bits/stdc++.h>

const int N=1e6+5;
using namespace std;
int n,m;
long long a[N],tmp[N];

void Init(int pos)
{
    long long val=tmp[pos];
    for(int i=pos-1;i>=1;i--)
    {
        if(tmp[i]==0) break;
        tmp[i]-=val;
    }
    for(int i=pos+1;i<=n;i++)
    {
        if(tmp[i]==0) break;
        tmp[i]-=val;
    }
    tmp[pos]=0;
}

void Sol()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    while(m--)
    {
        int type,l,r,k;
        cin>>type;
        if(type==1)
        {
            cin>>l>>r>>k;
            for(int i=l;i<=r;i++) a[i]=a[i]+1ll*k;
        }
        else
        {
            cin>>l>>r;
            int cnt=0;
            for(int i=l;i<=r;i++)
            {
                cnt++;
                tmp[cnt]=a[i];
            }
            long long res=0;
            while(true)
            {
                int pos=-1;
                long long best=1e18;
                for(int i=1;i<=cnt;i++)
                {
                    if(best>tmp[i]&&tmp[i]!=0)
                    {
                        pos=i;
                        best=tmp[i];
                    }
                }
                if(pos==-1) break;
                res=res+tmp[pos];
                Init(pos);
            }
            cout<<res<<'\n';
        }
    }
}

int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("CONSTRUCT.INP","r",stdin);
    freopen("CONSTRUCT.OUT","w",stdout);
    int T;
    cin>>T;
    while(T--) Sol();
}
