#include<bits/stdc++.h>
#define fr(i,x,y) for(int i = x; i <= y; i++)
using namespace std;
int n,m = 0;
char ans[1000100];
void inp()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("PAINT.inp","r",stdin);
    freopen("PAINT.out","w",stdout);
    cin>>n;
}
void sub1()
{
    fr(t,1,n)
    {
        int tv;
        char c1,c2;
        cin>>tv;
        if (tv == 1)
        {
            cin>>c1;
            ans[++m] = c1;
        }
        else
            {
                cin>>c1>>c2;
                fr(i,1,m)
                    if (ans[i] == c1) ans[i] = c2;
            }
    }
    fr(i,1,m)
        cout<<ans[i];
}
int main()
{
    inp();
    sub1();
    return 0;
}
