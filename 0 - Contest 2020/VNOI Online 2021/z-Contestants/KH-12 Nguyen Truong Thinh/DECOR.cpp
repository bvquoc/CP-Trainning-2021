#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int l[500009];
int main()
{
    freopen("DECOR.inp","r",stdin);
    freopen("DECOR.out","w",stdout);
    cin>>n>>m>>k;
    string s;
    cin>>s;
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
    }
    if (m==0)
    {
        int z=k;
        int z1=s.length()-1;
        for (int j=0;j<s.length();j++)
        {
            int v= (int) s[j]-'0';
            if (k==0 && v==0)
            {
                z1=j-1;
                break;
            }
            if (v==0)
            {
                k--;
            }
        }
        l[0]=z1;
       // cout<<z1<<endl;
        for (int i=1;i<s.length();i++)
        {
            int v= (int) s[i-1]-'0';
            if (v==1)
            {
                l[i]=l[i-1];
            }
            else
            {
                int o=l[i-1];
                int j=o+1;
                int ok=0;
                while (j<=s.length()-1)
                {
                    int v= (int) s[j]-'0';
                    if (v==0 && ok==1)
                    {
                        break;
                    }

                    if (v==0)
                    {
                        ok=1;
                        j++;
                    }
                    else
                    {
                        j++;
                    }
                }
                l[i]=j-1;
            }
        }
        int ma=-1;
        int kq=0;
        int kq1=0;
        for (int i=0;i<s.length();i++)
        {
            //cout<<l[i]<<endl;
            if (l[i]-i+1>ma)
            {
                kq=i+1;
                kq1=l[i]+1;
            }
            ma=max(ma,l[i]-i+1);
        }
        if (ma==0 || ma==-1)
        {
            ma=-1;
            cout<<ma<<endl;
        }
        else
        {
            cout<<kq<<' '<<kq1<<endl;
        }
    }
}
