#include <bits/stdc++.h>
using namespace std;
const int maxn=(int) 1e4;
int n,a[maxn],k,d[maxn];
bool kt=false;
void datgt(int i)
{
    for (int j=0;j<=1;j++)
    {
        if (kt) continue;
        d[i]=j;
        if (i==n-1)
        {
            int tam=a[0];
            for (int m=0;m<n;m++)
            {
                if (d[m]==0)
                {
                    tam-=a[m+1];
                }
                else tam+=a[m+1];
            }
            if (tam%k==0)
            {
                cout<<1<<"\n";
                for (int m=0;m<n-1;m++)
                {
                    if (d[m]==0) cout<<"-";
                    else cout<<"+";
                }
                kt=true;
            }
        }
        else datgt(i+1);
    }
}
int main()
{
    freopen("kmult.inp","r",stdin);
    freopen("kmult.out","w",stdout);
    cin>>n>>k;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    datgt(0);
    if (kt==false) cout<<0;
    return 0;
}
