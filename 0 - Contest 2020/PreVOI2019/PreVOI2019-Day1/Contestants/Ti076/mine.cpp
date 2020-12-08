#include<bits/stdc++.h>
#define fi first
#define se second
#define fr(i, x, y) for (int i=x; i<=y; i++)
#define ft(i, x, y) for (int i=y; i>=x; i--)
#define pb push_back
#define ll long long
#define pii pair <int,int>
#define pll pair <ll,ll>
using namespace std ;
void inp ()
{
    freopen ("mine.inp", "r", stdin);
    freopen ("mine.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    fr (i, 1, 2*n);
    {
        scanf ("%d", &a[i]);
    }
}
void sub1 ()
{
    fr (i, 1, 2*n)
    {
        int l=i+1;
        int r=2*n;
        while (l<r)
        {
            int mid=(l+r+1)/2;
            if (a[mid]-a[i]>m) r=mid-1;
            else l=mid;
        }
        fr (j, i+1, r)
        {
            mine[i].push_back(j);
        }
    }
}
int main ()
{
    inp ();
    sub1 ();
    cout<<"1 2 3"
    return 0;
}

