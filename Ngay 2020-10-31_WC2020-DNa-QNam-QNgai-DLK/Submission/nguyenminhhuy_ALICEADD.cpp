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
string add(string a, string b)
{
    string res="";
    while(a.length() < b.length()) a="0"+a;
    while(b.length() < a.length()) b="0"+b;
    int carry=0;
    for(int i=a.length()-1;i>=0;i--)
    {
        int tmp=a[i]-48 + b[i]-48 + carry;
        carry=tmp/10;
        tmp=tmp%10;
        res=(char)(tmp+48)+res;
    }
    if(carry>0) res="1"+res;
    return res;
}
int main()
{
    FAST1;
    FAST2;
    FAST3;
    long long t;
    string a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        cout<<add(a,b)<<endl;
    }
}