#include <bits/stdc++.h>
#define name "PERMEOW"
using namespace std;
const int N=2e5+10;
const int H=1e9+7;
bool cksub1=1;
int a[N],b[N],res,n;

void trau()
{
    bool stop;
    long long sum=0,res;
    do
    {
        res=0; stop=1;
        for (int i=1; i<=n; i++)
        {
            if (a[i]!=b[i]) stop=0;
            for (int j=i-1; j>0; j--)
            {
               if (a[j]>a[i]) res++;
            }
        }
        sum+=res;
        if (stop) break;
    }
    while ( next_permutation(a+1,a+n+1) );
    cout<<sum<<'\n';
}



bool cksb2=1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(name".inp","r"))
    {
        freopen(name".inp","r",stdin);
        freopen(name".out","w",stdout);
    }
    cin>>n;
    for (int i=1; i<=n;i++)
    {
        cin>>a[i];
        if (a[i]==i) cksb2=0;
    }
    for (int i=1; i<=n; i++)
    {
        cin>>b[i];
        if (b[i]==i) cksb2=0;
    }
    trau();
}
