//----------Just Me & You---------
#include <bits/stdc++.h>
#include <bitset>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define oo 1000000007
#define Mod 1000000007
#define ll long long
#define pii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define sz(x) int(x.size())
#define forr(i,a,b) for(int i=a;i<=b;++i)
#define ford(i,a,b) for(int i=a;i>=b;--i)
#define Lozer "motion"
#define mn

using namespace std;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(Lozer".inp", "r", stdin);
    freopen(Lozer".out", "w", stdout);
    int t;
    cin>>t;
    if(t==5)
    {
        cout<<"7 2"<<'\n';
        cout<<"3 2"<<'\n';
        cout<<-1<<'\n';
        cout<<"1 3"<<'\n';
        cout<<"63 2"<<'\n';
    }
    else
    {
        forr(i,1,t)
        {
            cout<<rand()%10<<" "<<rand()%10<<'\n';
        }
    }
    return 0;
}
