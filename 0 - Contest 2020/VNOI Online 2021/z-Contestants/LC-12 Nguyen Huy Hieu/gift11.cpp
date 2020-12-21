						///*******ZoHuyHieuZo*******///
#include<bits/stdc++.h>
#define F first
#define S second
#define int long long
#define pii pair<int,int>
#define Zo "gift11"
#define MOD 1000000007
#define maxn 1000111
#define pb push_back
#define mp make_pair
#define mem(i,m) memset(i,m,sizeof(i))
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1) // kiem tra bit i
#define SET_ON(x, i) ((x) | MASK(i)) // bat bit thu i cua x
#define SET_OFF(x, i) ((x) & ~MASK(i)) // tat bit thu i cua x

using namespace std;
int arr[20];
string a[maxn];
bool check(string s)
{
    int ans1=0,ans2=0;
    for(int i=0;i<s.size();i++)
    {
        if(i%2==0)
            ans1+=s[i]-'0';
        else ans2+=s[i]-'0';
    }
    if(abs(ans1-ans2)%11==0)
        return true;
    else return false;
}
void nhap()
{
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        arr[i]=i;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(arr+1,arr+1+n);
    do
    {
        string g;
        for(int i=1;i<=n;i++)
        {
            g=g+a[arr[i]];
        }
        ans+=check(g);
    } while(next_permutation(arr+1,arr+1+n));
    cout<<ans<<'\n';
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Zo".inp","r",stdin);
    freopen(Zo".out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
        nhap();
}
