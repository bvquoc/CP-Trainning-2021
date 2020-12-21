#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[2005];
int n,t;
long long res=0;
vector <int> s;
void pt(int k)
{
    while (k>9)
    {
        s.push_back(k%10);
        k=k/10;
    }
    s.push_back(k);
}
int main()
{
    freopen("GIFT11.inp","r",stdin);
    freopen("GIFT11.out","w",stdout);
    cin >>t;
    while (t--)
    {
        cin >>n;
        for (int i=1; i<=n; i++)
            cin >>a[i];
        long long  gt=1;
        res=0;
        if (n<=8)
        {
            for (int i=1; i<=n; i++)
                gt*=i;
            for (int k=1; k<=gt; k++)
            {
                s.clear();
                int dem=1,chan=0,le=0;
                for (int i=n; i>=1; i--)
                {
                    pt(a[i]);
                }
               for (int i=s.size()-1; i>=0; i--)
                {
                    if (dem%2==0)
                        chan+=s[i];
                    else
                        le+=s[i];
                    dem++;
                }
                if (chan==le)
                    res++;
                next_permutation(a+1,a+1+n);
            }
            cout <<res%998244353<<"\n";
        }
        else
        {
            for (int i=n; i>=1; i--)
                pt(a[i]);
            int dem=1,chan=0,le=0;
            for (int i=s.size()-1; i>=0; i--)
            {
                if (dem%2==0)
                    chan+=s[i];
                else
                    le+=s[i];
                dem++;
            }
            if (chan==le)
            {
                for (int i=1; i<=n; i++)
                    gt=(gt%998244353*i%998244353)%998244353;
            }
            cout <<gt<<"\n";
        }
    }
    return 0;
}
