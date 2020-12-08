#include <bits/stdc++.h>
#define maxn 200005
#define MOD 1000003

using namespace std;

int n,m,x[21],a[2*maxn],S[maxn],kq=0;

void inkq()
{
    int sl[2]; sl[0]=0; sl[1]=0;
    for (int i=1; i<=2*n; i++) sl[x[i]]++;
    if (sl[0]!=sl[1]) return;
    int nguoi=n;
    int i=1, dem=0;
    while (i<=2*n)
    {
        if (x[i]==0) S[++dem]=a[i];
        if (x[i]==1 && dem==0) return;
        if (x[i]==1 && dem>0)
        {
            if (a[i]-S[dem]>m) return;
            nguoi--; dem--;
        }
        i++;
    }
    if (nguoi==0) kq=(kq+1)%MOD;
}

void Try(int i)
{
    for (int j=0; j<=1; j++)
    {
        x[i]=j;
        if (i>=2*n) inkq(); else Try(i+1);
    }
}

int main()
{
    freopen("mine.inp","r",stdin);
    freopen("mine.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1; i<=2*n; i++) scanf("%d",&a[i]);
    Try(1); cout<<kq; return 0;
}
