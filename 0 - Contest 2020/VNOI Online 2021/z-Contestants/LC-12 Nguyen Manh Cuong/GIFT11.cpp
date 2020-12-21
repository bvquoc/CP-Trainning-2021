#include <bits/stdc++.h>
#define Killian "GIFT11"
#define endl "\n"
#define pii pair <int,int>
#define long long long
#define bit(mask,u) (((mask)>>(u))&1)
#define bitcount(mask) __builtin_popcount((mask))
using namespace std;
mt19937_64 random_num(chrono::high_resolution_clock::now().time_since_epoch().count());
const long MOD=998244353;
const int base=26;
const int arsz=100005;

int T,n;
long gt[2005];
int a[2005];
vector <int> p;
bool b[2005];
int s[2005][2];

void Sub1()
{
    int ans=0;
    p.clear();
    for (int i=1; i<=n; i++)
        p.push_back(i);
    do
    {
        int sumodd=0,sumeven=0,t=0;
        for (int i: p)
        {
            if (t==0)
                sumodd+=s[i][1],sumeven+=s[i][0];
            else
                sumodd+=s[i][0],sumeven+=s[i][1];
            t=(t+b[i])%2;
        }
        if (abs(sumeven-sumodd)%11==0)
            ans++;
    }
    while (next_permutation(p.begin(),p.end()));
    cout<<ans<<endl;
}
void Sub2()
{
    int sumeven=0,sumodd=0;
    for (int i=1; i<=n; i++)
        sumeven+=s[i][0],sumodd+=s[i][1];
    if (abs(sumeven-sumodd)%11==0)
        cout<<gt[n]<<endl;
    else
        cout<<0<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Killian".inp","r",stdin);
    freopen(Killian".out","w",stdout);
    gt[0]=1;
    for (int i=1; i<=2000; i++)
        gt[i]=gt[i-1]*i%MOD;
    cin>>T;
    while (T--)
    {
        bool check2=1,check3=1;
        cin>>n;
        for (int i=1; i<=n; i++)
            s[i][1]=s[i][0]=0;
        for (int i=1; i<=n; i++)
        {
            cin>>a[i];
            int x=a[i],cnt=0;
            while (x)
            {
                cnt++;
                s[i][cnt%2]+=x%10;
                x/=10;
            }
            b[i]=cnt%2;
            if (cnt%2==0)
                swap(s[i][0],s[i][1]);
            if (cnt%2)
                check2=0;
            if (cnt%2==0)
                check3=0;
        }
        if (n<=9)
            Sub1();
        else if (check2)
            Sub2();
//        else if (check3)
//            Sub3();
    }
}
