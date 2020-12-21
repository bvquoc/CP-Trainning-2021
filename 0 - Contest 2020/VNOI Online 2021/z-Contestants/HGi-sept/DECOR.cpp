#include <bits/stdc++.h>

using namespace std;
int i,j,n,m,k,a[1000],b[1000];
string s;
int main()
{
    cin>>n>>m>>k;
    cin>>s;
    int dem=0;
    for(i=0;i<=s.length();i++)
        if(s[i]==1) dem++;
    for(i=1;i<=m;i++)
    {
        cin>>a[i]>>b[i];
    }
    if(k+dem>=n) cout<<1<<" "<<n;
    if(k+dem<n)
    {
        int dem=0,slon=0,dau=0,cuoi=0,bd=n-1,gt=k;
        if(m==0)
        {
            for(i=n-1;i>=0;i--)
            {
                if(s[i]=='1') dem++;
                if(s[i]=='0' && gt<k && gt>0)
                {
                    gt--;
                    dem++;
                }
                if(s[i]=='0' && gt==k && s[i-1]=='1')
                {
                    gt--;
                    dem++;
                }
                if(slon<dem)
                {
                    slon==dem;
                    dau=i;
                    cuoi=bd;
                }
                if(s[i]=='0' && gt<=0)
                {
                    gt=k;
                    dem=0;
                    bd=i;
                }
            }
            cout<<dau+1<<" "<<cuoi+1;
        }
    }
    return 0;
}
