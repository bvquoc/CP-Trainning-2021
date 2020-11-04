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
long long kt (long long x) {
    if (x == 1 || x < 0) return 0;
    if (x ==  2 || x == 3) return 1;
    if (x % 2 == 0 || x % 3 == 0) return 0;
    for (long long i = 5; i <= sqrt(x); i=i+6)
        if (x % i == 0 || x % ( i + 2) == 0) return 0;
    return 1;
    }
long long a[1005],c[1005],tong,tam;
vector<long long>b;
void tinhso(long long n)
{
    //memset(a,0,sizeof(a));
   int i=0;
    while(b[i]<=sqrt(n)&&i<b.size())
    {
        while(n%b[i]==0)
        {
            n/=b[i];
            a[b[i]]+=2;
            c[b[i]]++;
        }
            i++;
    }
    if(n>1000)
    {
        tong*=3;
        tam*=2;
    }
    else if(n>1)
    {
        a[n]+=2;
        c[n]++;
    }
}
long long dapso(long long e,long long d,long long f)
{
    tinhso(e);
    tinhso(d);
    tinhso(f);
    for1(i,0,b.size())
    {
        tong*=(a[i]+1);
        tam*=(c[i]+1);
    }
    return tong/2-tam+1;
}
int main()
{
    FAST1;
    FAST2;
    FAST3;
    long long t,n;
    for1(i,1,1000)
    {
        if(kt(i)==true) b.push_back(i);
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        tong=1;
        tam=1;
        cout<<dapso(n,n+1,n+2);
    }

}
