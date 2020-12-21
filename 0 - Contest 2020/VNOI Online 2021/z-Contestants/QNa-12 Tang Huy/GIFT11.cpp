#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
const long long MOD=998244353;
int t,q[12],sum=0,n,x[N];
string b[12][N];
long long res=0;
string a[N];
bool Bool[N];
void xuat() {
    string s="#";
    for (int i = 1; i <= n; i++)
        {
            s+=a[x[i]];
        }
    long long s1=0,s2=0;
    for (int i=1;i<s.size();i++)
    {
        if (i%2==0) s1+=(s[i]-'0');
        else s2+=(s[i]-'0');
    }
    if ((s1-s2+11)%11==0) res++;
}

void tryy(int k) {
    for (int i = 1; i <= n; i++) {
        if (!Bool[i]) {
            x[k] = i;
            Bool[i] = 1;
            if (k == n)
                xuat();
            else
                tryy(k + 1);
            Bool[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("GIFT11.inp","r",stdin);
    freopen("GIFT11.OUT","w",stdout);
    cin>>t;
    bool kt=true;
    for (int i=1;i<=t;i++)
    {
        cin>>q[i];
        for (int j=1;j<=q[i];j++)
            {
                cin>>b[i][j];
                if (b[i][j].size()%2) kt=false;
            }
    }
    if (kt){
    for (int test=1;test<=t;test++)
    {
        fill(a+1,a+n+1,"");
        n=q[test];
        fill(a+1,a+n+1,"");
        string st="#";
        for (int i=1;i<=n;i++)
            {
                a[i]=b[test][i];
            }
        for (int i=1;i<=n;i++)
            st+=a[i];
        bool ok=false;
        long long s1=0,s2=0;
        for (int i=1;i<st.size();i++)
        {
            if (i%2==0) s1+=(st[i]-'0');
            else s2+=(st[i]-'0');
        }
        if ((s1-s2+11)%11==0) ok=true;
        if (ok) {
                res=1;
            for (int i=1;i<=n;i++)
             res=(res*i)%MOD;
        cout<<res%MOD<<'\n';
        }
        else cout<<0<<'\n';
    }
    }
    else
    {
       for (int test=1;test<=t;test++)
    {
        fill(a+1,a+n+1,"");
        memset(Bool,0,sizeof Bool);
        memset(x,0,sizeof x);
        n=q[test];
        fill(a+1,a+n+1,"");
        for (int i=1;i<=n;i++)
            {
                a[i]=b[test][i];
            }
        res=0;
        tryy(1);
        cout<<res%MOD<<'\n';
    }
    }
}
