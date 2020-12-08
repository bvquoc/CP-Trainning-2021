#include <bits/stdc++.h>
#define FOR(i,x,y) for (int i=x; i<=y; i++)
#define ROF(i,x,y) for (int i=x; i>=y; i--)
#define ll long long
#define fi first
#define se second
#define FORR(i,x) for(int i=0; i<x.size(); i++)
#define yct "ODDCOIN"
using namespace std;

int q,x,t;
int f[20][1000010];
int a[20];
int main()
{
    freopen(yct".INP","r",stdin);
    freopen(yct".OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    a[1]=1; a[2]=3; a[3]=5;
    FOR(i,1,4)
    {
        a[i*3+3]=a[(i-1)*3+3]*10;
        a[i*3+1]=a[(i-1)*3+1]*10;
        a[i*3+2]=a[(i-1)*3+2]*10;
    }
    cin >>q;
    while(q--)
    {
        cin >>x >>t;
        a[16]=x;
        FOR(i,0,16)
            FOR(j,1,t)
            {
                f[i][j]=1e9;
            }
        f[0][0]=0;
        FOR(i,1,16)
        {
            FOR(j,1,t)
            {
                f[i][j]=f[i-1][j];
                if (j-a[i]>=0) f[i][j]=min(f[i][j],f[i][j-a[i]]+1);
            }

        }
        cout <<f[16][t] <<endl;
    }

    return 0;
}
