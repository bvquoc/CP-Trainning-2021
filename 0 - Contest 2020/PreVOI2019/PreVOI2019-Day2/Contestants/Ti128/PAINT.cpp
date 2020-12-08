#include <bits/stdc++.h>

using namespace std;

int n,m,j=0,p[1000001],l[1000001];

int root(int a)
{
    if (p[a]!=a)
        return p[a]=root(p[a]);
    else
        return a;
}

void connect(int a, int b)
{
    p[a]=root(p[b]);
    root(p[a]);
}


char a[1000001],b[1000001];
int q[1000001],kq[1000001];

void query(int k)
{
    cin>>q[k];
    if (q[k]==1)
    {
        cin>>a[k];
    }
    else
    {
        cin>>a[k]>>b[k];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PAINT.inp","r",stdin);
    freopen("PAINT.out","w",stdout);

    cin>>n;
    int m=n;
        while (n--)
        {
            query(n);
        }
    if (n<=10000)
    {
        int z=0;
        for (int i=m-1; i>=0; --i)
        {
            if (q[i]==1)
            {
                ++z;
                l[z]=a[i];
            }
            else
            {
                for (int e=1; e<=z; ++e)
                    if (a[i]==l[e])
                    l[e]=b[i];
            }
        }
        for (int i=1; i<=z; ++i)
        cout<<char(l[i]);
        return 0;
    }

    for (int i='a'; i<='z'; ++i)
        p[i]=i;

    for (int i=0; i<m; ++i)
    {
        if (q[i]==2)
        {
            for (int z='a'; z<='z'; ++z)
            if (p[z]==a[i]) p[z]=z;
            connect(a[i],b[i]);
        }
        else
        {
            ++j;
            kq[j]=root(a[i]);
        }
    }

    ++j;
    while (j--)
    {
        cout<<char(kq[j]);
    }
    return 0;
}
