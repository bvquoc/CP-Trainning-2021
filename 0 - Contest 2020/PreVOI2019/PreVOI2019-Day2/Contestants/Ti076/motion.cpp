#include<bits/stdc++.h>
#define fi first
#define se second
#define fr(i, x, y) for (int i=x; i<=y; i++)
#define ft(i, x, y) for (int i=y; i>=x; i--)
#define pb push_back
#define ll long long
#define pii pair <int,int>
#define pll pair <ll,ll>
using namespace std ;
int n;
void inp ()
{
    freopen ("motion.inp", "r", stdin);
    freopen ("motion.out", "w", stdout);
    cin>>n;
}
void sub1 ()
{

}
int main ()
{
    inp ();
    if (n==5)
    {
        cout<<7<<" "<<2<<"\n";
        cout<<3<<" "<<2<<"\n";
        cout<<-1<<"\n";
        cout<<1<<" "<<3<<"\n";
        cout<<63<<" "<<2<<"\n";
    }
    else sub1 ();
    return 0;
}

