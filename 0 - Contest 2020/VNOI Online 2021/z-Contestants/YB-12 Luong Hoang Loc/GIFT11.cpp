#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int mod=998244353;
int t,n,ans=0;
pair <int,string> a[100007];
bool visit[200];
string s[100007];
void inra()
{
    string res="";
    int chan=0,le=0;
    for (int i=1;i<=n;i++)
        a[i].se=s[i];
    sort (a+1,a+n+1);
    for (int i=1;i<=n;i++)
        res+=a[i].se;
//    cout << res << '\n';
    for (int i=0;i<res.size();i+=2)
    {
        le=le+(res[i]-'0');
        chan=chan+(res[i+1]-'0');
    }
//    cout << chan << " " << le << '\n';
    if (abs(chan-le)%11==0)
        ans++;
}
void quaylui(int i)
{
    for (int j=1;j<=n;j++)
    if (visit[j]==0)
    {
        visit[j]=1;
        a[i].fi=j;
        if (i==n)
            inra();
        else
            quaylui(i+1);
        visit[j]=0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("GIFT11.INP","r",stdin);
    freopen("GIFT11.OUT","w",stdout);
    cin >> t;
    while (t--)
    {
        int chan=0,le=0;
        bool check=0;
        cin >> n;
        for (int i=1;i<=n;i++)
        {
            cin >> s[i];
            if (s[i].size()%2!=0)
                check=1;
        }
        if (check==0)
        {
            string res="";
            for (int i=1;i<=n;i++)
                res=res+s[i];
            for (int i=0;i<res.size();i+=2)
            {
                le=le+(res[i]-'0');
                chan=chan+(res[i+1]-'0');
            }
            if (abs(chan-le)%11==0)
            {
                for (int i=2;i<=n;i++)
                    ans=ans*(i%mod)%mod;
            }
            else
            {
                cout << 0 << '\n';
                continue;
            }
            cout << ans << '\n';
        }
        else
        {
            quaylui(1);
            cout << ans << '\n';
        }
    }
    return 0;
}
