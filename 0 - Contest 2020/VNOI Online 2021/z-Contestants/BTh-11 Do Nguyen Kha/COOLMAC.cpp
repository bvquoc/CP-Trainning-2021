#include <iostream>
#include <bits/stdc++.h>
using namespace std;
pair <int,int> a[100005];
bool b[100005],ok;
stack<pair<int,int> > q;
int n,m,l,r,tmp=INT_MAX,res=0,tam;
int main()
{
    freopen("COOLMAC.inp","r",stdin);freopen("COOLMAC.out","w",stdout);
    cin >>m;
    for (int i=1; i<=m; i++)
    {
        cin >>a[i].first>>a[i].second;
        if (a[i].first==100000 || a[i].second ==100000)
                ok=true;

    }
    if (ok==false)
    {
        cout <<"-1";
        return 0;
    }
    cin >>n;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin >>x;
        tmp=min(x,tmp);
    }
    int vt;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=m; j++)
        {
            if (i==j)
                continue;
            if (a[j].first >= a[i].first && a[j].second <= a[i].second && b[i]==false)
            {
                b[j]=true; a[j].first=-1; a[j].second=-1;
            }
        }
    sort(a+1,a+1+m);
    for (int i=1; i<=m; i++)
        if (a[i].first !=-1 && a[i].second !=-1)
        {
            l=a[i].first;
            r=a[i].second;
            break;
        }
    if (l>tmp)
        {
            cout <<"-1";
            return 0;
        }
    for (int i=1; i<=m; i++)
    {
        if (a[i].first <=tmp)
        {
            if (r<=a[i].second)
            {
                l=a[i].first;
                r=a[i].second;
                vt=i;
            }
        }
    }
    res=1;
    int tam=0;
    while (r<100000)
    {
         ok=0;
        for (int i=vt+1; i<=m; i++)
        {
            if (a[i].first <=r)
            {
                if (tam<=a[i].second)
                {
                    tam=a[i].second;
                    vt=i;
                    ok=true;
                }
            }
        }
        r=tam;
        if (ok==0)
        {
            cout <<"-1";
            return 0;
        }
        else res++;
    }
    cout <<res;
    return 0;
}
