#include <bits/stdc++.h>
#define name "GIFT11"
#define pb push_back
using namespace std;
const int N=2100;
const int H=998244353;
vector <int> v;
int O,E,n;
int e[N],o[N],c[N],b[N],a[N],a1[N],b1[N],e1[N],o1[N];
bool kt;

void get(int i)
{
    v.clear();
    while (a[i]>0)
    {
        v.pb(a[i]%10); a[i]/=10;
    }
    reverse(v.begin(),v.end());

    o[i]=e[i]=0;
    for (int j=0; j<v.size(); j++)
    {
        if ( (j+1)%2 )
        {
            o[i]+=v[j];
        }
        else e[i]+=v[j];
    }
    c[i]=v.size();
}
void trau()
{
    for (int i=1; i<=n; i++)
    {
        b[i]=i;
    }

    int res=0,O=0,E=0;
    do
    {
        for (int i=1; i<=n; i++) {
            o1[i]=o[b[i]]; e1[i]=e[b[i]];
        }
        kt=0; O=0,E=0;
        for (int i=1; i<=n; i++) {
            if (!kt) {
                O+=o1[i];
                E+=e1[i];
            }
            else {
                O+=e1[i];
                E+=o1[i];
            }
            kt=(kt+c[b[i]])%2;
        }
        if ((O-E)%11==0) res++;
    }
    while (next_permutation(b+1,b+n+1));
    cout<<res<<'\n';
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(name".inp","r"))
    {
        freopen(name".inp","r",stdin);
        freopen(name".out","w",stdout);
    }
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n; int O=0, E=0;
        for (int i=1; i<=n; i++)
        {
            cin>>a[i];
            get(i);
            O+=o[i]; E+=e[i];
        }
        if (n<=10)
        {
            trau();
        }
        else
        {
            int res=1;
            if ((O-E)%11==0)
            {
                for (int i=1; i<=n; i++)
                {
                    res=1LL*res*i%H;
                }
                cout<<res<<'\n';
            }
        }
    }
}
