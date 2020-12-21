#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
#define MASK(i) (1LL << (i))
#define BIT(x,i) (((x)>>(i)) & 1)
#define SET_ON(x,i) ((x) | MASK(i))
#define SET_OFF(x,i) ((x) & ~(MASK(i)))
using namespace std;
const int MAXN=200001;
int n;
int a[MAXN],b[MAXN],res=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("PERMEOW.INP" , "r" , stdin);
    freopen("PERMEOW.OUT" , "w" , stdout);
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=1;i<=n;i++)   cin>>b[i];
    int i=1;
    int ans=0;
    while(true)
    {
        if(i>=n) i=1;
        if(a[i]>a[i+1])
        {
            ans++;
            swap(a[i],a[i+1]);
        }
        bool ok=true;
        for(int i=1;i<n;i++)
        {
            if(a[i]>a[i+1])
            {
                ok=false;
                break;
            }
        }
        if(ok==true)    break;
        i++;
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
