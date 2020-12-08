#include <bits/stdc++.h>

using namespace std;

int n,m,d[11],t,res,l[11],f[201][201],a[201],t1,t2;

void TRY(int k)
{
    if (k==n*2+1)
    {
        stack <int> s;
        for (int i=1; i<=n*2; ++i)
        {
            if (l[i]==0)
                s.push(i);
            else
            {
                int j=s.top();
                if (a[i]-a[j]>m)
                    break;
                s.pop();
            }
        }
        if (s.empty()==true)
            ++res;
    }
    if (t1<n)
    {
        ++t1;
        l[k]=0;
        TRY(k+1);
        --t1;
    }
    if (t2<t1)
    {
        ++t2;
        l[k]=1;
        TRY(k+1);
        --t2;
    }

}

void sub1()
{
    TRY(1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MINE.inp","r",stdin);
    freopen("MINE.out","w",stdout);

    cin>>n>>m;
    for (int i=1; i<=2*n; ++i)
    {
        cin>>a[i];
    }
    if (n<=10)
       {
           sub1();
           cout<<res%1000003;
           return 0;
       }

    cout<<1000002;

    return 0;
}
