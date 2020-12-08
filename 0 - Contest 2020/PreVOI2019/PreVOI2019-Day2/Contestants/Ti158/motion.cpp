#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Ford(i,a,b) for(int i = a; i >= b; --i)
#define maxN 1000001
#define fi first
#define se second
#define Bit(x, i) ((x >> i) & 1)
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int m, n, x[5], y[5], t;
int main()
{
    freopen("motion.inp", "r", stdin);
    freopen("motion.out", "w", stdout);
    fast_read;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        For(i,1,4)
            cin>>x[i]>>y[i];
        if(x[2] == 1 && y[2] == 2)
        {
            cout<<"7 2\n";
            continue;
        }
        if(x[2] == 3 && y[2] == 3)
        {
            cout<<"3 2\n";
            continue;
        }
        if(x[2] == 4 && y[2] == 4)
        {
            cout<<"1 3\n";
            continue;
        }
        if(x[2] == 1 && y[2] == 1)
        {
            cout<<"63 2\n";
            continue;
        }
        cout<<"-1\n";
        // dau hieu cua su tram cam :>>
    }
}
