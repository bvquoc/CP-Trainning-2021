#include<bits/stdc++.h>
#define N 200010
using namespace std;
int n,a[N],b[N],ans=0,mod=1e9+7;
void bubblesort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                ans=(ans+1)%mod;
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("permeow.inp","r",stdin);
    freopen("permeow.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    bubblesort(a,n);
    cout<<ans;
}
