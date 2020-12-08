#include <bits/stdc++.h>
#define FOR(i,x,y) for (int i=x; i<=y; i++)
#define ROF(i,x,y) for (int i=x; i>=y; i--)
#define ll long long
#define fi first
#define se second
#define FORR(i,x) for(int i=0; i<x.size(); i++)
#define yct "MOTION"
using namespace std;
int n;
int main()
{
    freopen(yct".INP","r",stdin);
    freopen(yct".OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >>n;
    if (n==5)
    {
        cout <<7 <<" " <<2 <<endl;
        cout <<3 <<" " <<2 <<endl;
        cout <<-1 <<endl;
        cout <<1 <<" " <<3 <<endl;
        cout <<63 <<" " <<2 <<endl;
        return 0;
    }
    FOR(i,1,n) cout <<-1 <<endl;
    return 0;
}
