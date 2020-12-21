#include<bits/stdc++.h>
using namespace std;
int n;
int A[2005];
int B[2005];
int cnt=0;
int main()
{
    freopen("PERMEOW.inp","r",stdin);
    freopen("PERMEOW.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>A[i];
    for(int i=1;i<=n;i++) cin>>B[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(A[i]>A[j])
            {
                swap(A[i],A[j]);
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
