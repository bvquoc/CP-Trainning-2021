#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int dem =0 ;
int a[2005], b[2005];

int main()
{
    freopen("permeow.inp","r",stdin);
    freopen("permeow.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];
    for(int i=1; i<=n; i++)
        for(int j = 1; j<=n; j++) if( a[j] > a[j + 1] ) dem++, swap (a[j], a[j+1]);
    cout<<dem;
    return 0;
    /*
5
5 4 3 2 1
5 4 3 2 1
*/
}
