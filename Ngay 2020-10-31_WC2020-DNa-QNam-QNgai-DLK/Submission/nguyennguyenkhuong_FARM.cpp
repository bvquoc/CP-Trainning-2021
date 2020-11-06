#include <bits/stdc++.h>
using namespace std;
const int N=1e4+12;
int temp[N][N];
int n,k,p,q;
int a[N];
int f(int nx, int qx)
{
    if (nx<1||qx==0) return 0;
    if (temp[nx][qx]!=-1) return temp[nx][qx];
    int cr=min(p,qx);
    return temp[nx][qx]=max(f(nx-1,qx),f(nx-k,qx-cr)+a[nx]*cr);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k>>q>>p;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    memset(temp,-1,sizeof(temp));
    cout<<f(n,q);
}
