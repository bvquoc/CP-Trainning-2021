#include <bits/stdc++.h>

using namespace std;
long long maxc,x=INT_MAX,y,n,m,vt1,vt2,z,v,j,b[500009],l,r,bien=0,k,i,a[500009],dem=1;
string s;
int main()
{
    freopen("DECOR.INP","r",stdin);
    freopen("DECOR.OUT","w",stdout);
    cin>>n>>m>>k;
    cin>>s;
    for (i=0;i<s.length();i++)
    {
        a[i+1]=(int)(s[i]-48);
        if (a[i+1]==1)
            bien=1;
    }
    if (k==0 && m==0)
    {
        for (i=1;i<=n;i++)
        {
            if (a[i]==1 && a[i+1]==1)
                dem++;
            else {
                if (maxc<dem && a[i]!=0)
                {
                    maxc=dem;
                    r=i;
                    l=i-dem+1;
                }
                dem=1;
            }
        }
        if (bien==0)
            cout<<-1;
        else
            cout<<l<<" "<<r;
        return 0;
    }
    dem=0;maxc=0;vt1=1;
    if (m==0)
    {
        for (i=1;i<=n;i++)
        {
            j=i;
            z=0;
            v=k;
            while (j<=n)
            {
                if (a[j]==0)
                {
                    z++;
                    b[z]=j;
                    a[j]=1;
                    v--;
                }
                j++;
                if (j>n || v==0)
                    break;
            }
            for (j=i;j<=n;j++)
                if (a[j]!=0)
                {
                    dem++;
                    vt2=j;
                }
                else
                    break;
            for (j=i-1;j>=1;j--)
                if (a[j]!=0)
                {
                    dem++;
                    vt1=j;
                }
                else
                    break;
            if (maxc<=dem && vt1<x)
            {
                maxc=dem;
                x=vt1;
                y=vt2;
            }
            dem=0;
            for (j=1;j<=z;j++)
                a[b[j]]=0;
        }
    }
    if (maxc!=0)
        cout<<x<<" "<<y<<endl;
    else cout<<-1;
    return 0;
}
