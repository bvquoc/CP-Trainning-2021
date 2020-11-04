#include<bits/stdc++.h>
using namespace std;
int q,n;
long long m;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>q;
    while (q--)
    {
        int res=0;
        cin>>n;
        m=n*(n+1)*(n+2);
        long long p=m;
        m*=m;
        for (long long i=1;i*i<=m;i++)
        {
            if (m%i==0)
            {
                long long j=i;
                if (j*j==m  && j<p && p%j!=0)
                    res++;
                else
                {
                    if (j<p && p%j!=0)
                    res++;
                    long long x=m/j;
                    if (x<p && p%j!=0 )
                        res++;
                }
            }
        }
        cout<<res<<'\n';
    }
}
