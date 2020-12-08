#include<bits/stdc++.h>
#define up(i,d,c) for(int i=d;i<=c;i++)
#define pb push_back
#define ii pair<int ,int >
#define x first
#define y second

using namespace std;
int t;
int n,m;
int a[100005]={};
int b[100005]={};
/*int xuli(int l,int r)
{
    int res=0;
    if(l==r)
    {
        res+=b[l];
        return res;
    }
    int vt=*min_element(b+l,b+r+1);
    if(vt!=0)
    {
        res+=vt;
        up(i,l,r)
        {
            b[i]-=vt;
        }
    }

    int i=l;
    while(i<=r)
    {
        while(b[i]==0&&i<=r)
            i++;
            int j=i;

        if(i<=r)
        {

            while(b[j]!=0&&j<=r)
                j++;
            res+=xuli(i,j-1);
        }
        i=j;

    }
    return res;
}*/
int xuli(int l,int r)
{
    int res=b[l];
    up(i,l+1,r)
    {
       if(b[i]>b[i-1]) res+=b[i]-b[i-1];
    }
    return res;
}
int main()
{
	#define NAME "CONSTRUCT"
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen(NAME".inp","r",stdin);
	freopen(NAME".out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        up(i,1,n)
        {
            cin>>a[i];

        }
        while(m--)
        {
            int type;
            cin>>type;
            if(type==1)
            {
                int l,r,k;
                cin>>l>>r>>k;
                up(i,l,r)
                {
                    a[i]+=k;
                }

            }
            else
            {
                int l;int r;
                cin>>l>>r;
                up(i,l,r)
                {
                    b[i]=a[i];
                }

                cout<<xuli(l,r)<<'\n';
            }
        }
    }
}
