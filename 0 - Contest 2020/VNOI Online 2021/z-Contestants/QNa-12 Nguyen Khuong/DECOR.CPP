#include <bits/stdc++.h>
using namespace std;
int n,m,k;
string st;
int a[500012];
int main()
{
    freopen("DECOR.INP","r",stdin);
    freopen("DECOR.OUT","w",stdout);
    cin>>n>>m>>k;
    cin>>st;
    if (m==0&&k==0)
    {
        int ans=-1, ansl, ansr, l=0, r=0;
        st=st+'0';
        for(int i=0; i<=n; i++)
        {
            if (st[i]-'0'==1)
            {
                r++;
            }
            else
            {
                if (ans<r-l+1)
                {
                    ans=r-l+1;
                    ansl=l;
                    ansr=r;
                }
                l=r=i;
            }
        }
        cout<<ansl+2<<" "<<ansr+1;
        return 0;
    }
    if (m==0)
    {
        for(int i=1; i<=n; i++)
        {
            int x=(int)(st[i]-'0');
            x^=1;
            a[i]=a[i-1]+x;
        }
        int l=0, r=n-1, ans=-1, ansl, ansr;
        for(int i=0; i<n; i++)
        {
            int j;
            for(j=n-1; j>=i&&a[j]-a[i-1]>k; j--);
            if (j-i+1>ans)
            {
                ans=j-i+i;
                ansl=i;
                ansr=j;
            }
        }
        cout<<ansl+1<<" "<<ansr+1;
    }
}
