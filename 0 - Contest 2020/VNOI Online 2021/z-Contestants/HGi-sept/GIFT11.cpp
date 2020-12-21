#include <bits/stdc++.h>

using namespace std;
int i,j,n,t,tong1,tong2,gt,kt,a[100]={1};
string s[10000],x;
int main()
{
    freopen("GIFT11.INP","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>n;
        kt=0;
        for(i=1;i<=n;i++)
        {
            cin>>s[i];
            if(s[i].size()%2!=0) kt=1;
        }
        if(kt==0)
        {
            tong1=0;
            tong2=0;
            gt=0;
            for(i=1;i<=n;i++)
            {
                x=s[i];
                for(j=0;j<=x.size();j++)
                {
                    if(gt==0)
                    {
                        gt=1;
                        tong1=tong1+x[j];
                    }else
                    {
                        gt=0;
                        tong2=tong2+x[j];
                    }
                }
            }
            if((tong1-tong2)%11==0)
            {
                tong1=1;
                for(i=1;i<=n;i++)
                {
                    tong1=tong1*i;
                    if(tong1>=998244353) tong1=tong1%998244353;
                }
                cout<<tong1<<endl;
            } else cout<<-1<<endl;
        } else
        {
            int dem=0;
            for(i=1;i<=n;i++)
                a[i]=i;
            do
            {
                tong1=0;
                tong2=0;
                gt=0;
                for(i=0;i<=n-1;i++)
                {
                    x=s[a[i]];
                    for(j=0;j<=x.size()-1;j++)
                    {
                        if(gt==0)
                        {
                            tong1=(tong1+x[j])-48;
                            gt=1;
                        }else
                        {
                            tong2=(tong2+x[j])-48;
                            gt=0;
                        }
                    }
                }
                if((tong1-tong2)%11==0) dem++;
            }while(next_permutation(a+1,a+n+1));
            cout<<dem<<endl;
        }
    }
    return 0;
}
