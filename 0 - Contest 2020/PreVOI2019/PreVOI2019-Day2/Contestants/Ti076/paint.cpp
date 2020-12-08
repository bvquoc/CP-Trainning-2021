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
char a[1000010];
int n, dem;
pii aa[1000010];
void inp ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen ("paint.inp", "r", stdin);
    freopen ("paint.out", "w", stdout);
    cin>>n;
}
void sub1 ()
{
    fr (i, 1, n)
    {
        int num;
        cin>>num;
        if (num==1)
        {
            char s;
            cin>>s;
            dem++;
            a[dem]=s;
        }
        else
        {
            char x, y;
            cin>>x>>y;
            fr (i, 1, dem)
            {
                if (a[i]==x)
                {
                    a[i]=y;
                }
            }
        }
    }
    fr (i, 1, dem)
    {
        cout<<a[i];
    }
}
char alphabet (int x)
{
    for (char i='a'; i<='z'; i++)
    {
        if (i-'a'+1==x) return i;
    }
}
bool cmd (pii a, pii b)
{
    if (a.se<b.se) return a<b;
}
void sub2 ()
{
    fr (i, 1, n)
    {
        int num;
        cin>>num;
        if (num==1)
        {
            char s;
            cin>>s;
            dem++;
            aa[dem].fi=s-'a'+1;
            aa[dem].se=dem;
        }
        sort (aa+1, aa+dem+1);
        else
        {
            char x, y;
            cin>>x>>y;
            int xx=x-'a'+1;
            int yy=y-'a'+1;
            int ed=upper_bound(aa+1, aa+dem+1, xx);
            int st=lower_bound(aa+1, aa+dem+1, xx);
            don[i]=ed-st;
        }
        sort (aa+1, aa+dem+1, cmd);
    }
    fr (i, 1, dem)
    {
        cout<<alphabet(aa[i]);
    }
}
int main ()
{
    inp ();
    sub1 ();
    return 0;
}

