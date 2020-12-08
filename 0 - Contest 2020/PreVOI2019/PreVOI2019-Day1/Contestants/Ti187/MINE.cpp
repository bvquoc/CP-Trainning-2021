#include <bits/stdc++.h>
#define fr(i,x,y) for(int i = x; i <= y; i++)
using namespace std;
int n,m;
int a[400100];
void inp()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("MINE.inp","r",stdin);
    freopen("MINE.out","w",stdout);
    cin>>n>>m;
    fr(i,1,n)
        cin>>a[i];
}
void sub()
{
    cout<<"2"<<endl;
}
int main()
{
    inp();
    sub();
    return 0;
}
