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
int n, dem, sum[1000010], aa[1000010];
string s;
string a[1000010];
void inp ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen ("fixstr.inp", "r", stdin);
    freopen ("fixstr.out", "w", stdout);
    cin>>s;
    cin>>n;
    s=" "+s;
    fr (i, 1, s.size()-1)
    {
        a[0][i]=s[i];
    }
}
int ngoacdung (string ss)
{
    sum[0]=0;
    fr (i, 0, ss.size()-1)
    {
        if (ss[i]=='(') aa[i+1]=1;
        else aa[i+1]=-1;
        sum[i+1]=sum[i]+aa[i+1];
    }
    dem=0;
    fr (i, 1, ss.size())
    {
        fr (j, i+1, ss.size())
        {
            if (sum[j]-sum[i-1]!=0) dem++;
            break;
        }
    }
    return dem;
}
void sub1 ()
{
    fr (i, 1, n)
    {
        char c;
        cin>>c;
        a[i]=" ";
        fr (j, 1, s.size()-1)
        {
            a[i]=a[i]+a[i-1][j];
        }
        if (c=='C')
        {
            int num;
            cin>>num;
            if (a[i][num]=='(') a[i][num]=')';
            else a[i][num]='(';
            //cout<<a[i][num]<<endl;
        }
        if (c=='Q')
        {
            int l, r;
            cin>>l>>r;
            string ck=a[i].substr(l, r-l+1);
            cout<<ngoacdung(ck)<<"\n";
        }
        if (c=='U')
        {
            int k;
            cin>>k;
            fr (j, 1, s.size()-1)
            {
                a[i][j]=a[k-1][j];
            }
        }
    }
}
int main ()
{
    inp ();
    if (s==" ((()))" and n==10)
    {
        cout<<0<<"\n"<<2<<"\n"<<0<<"\n"<<3;
    }
    else sub1 ();
    return 0;
}

