#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define for1(i,a,b) for(int i=a;i<=b;i++)
#define for2(i,a,b) for(int i=a;i<b;i++)
#define fordown1(i,a,b) for(int i=a;i>=b;i--)
#define fordown2(i,a,b) for(int i=a;i>b;i--)
#define endl "\n"
#define debug1(a) cout << a << "\n";
#define debug2(a,b) cout<<a<<" "<<b<<"\n";
#define debug3(a,b,c) cout<<a<<" "<<b<<" "<<c<<"\n";
#define debugvector(a) for(int i=0;i<a.size();i++) cout<<a[i]<<" ";
#define debugmang(a,n) for(int i=1;i<=n;i++) cout<<a[i]<<" ";
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define FAST1 ios_base::sync_with_stdio(0);
#define FAST2 cin.tie(0);
#define FAST3 cout.tie(0);
const ll limit = 2e5 + 5;
const ll limix = 5e6 + 5;
const ll limit2 = 1e3 + 5;
const ll MOD = 1e9 + 7;
const ll MOD1 = 998244353;
const ll MAX=1e18;
const ll MIN=-1;
long long n,m,tong,l,tam;
long long a[1000005];
int main()
{
    FAST1;
    FAST2;
    FAST3;
    cin>>n>>m;
    for1(i,1,n)
    {
        cin>>a[i];
    }
    l=1;
    for1(i,1,n)
    {
        tong+=a[i];
        while(tong>=m)
        {
            tong-=a[l];
            l++;
        }
      //  cout<<l<<endl;
        tam=max(i-l+2,tam);
    }
    cout<<tam<<endl;

}
