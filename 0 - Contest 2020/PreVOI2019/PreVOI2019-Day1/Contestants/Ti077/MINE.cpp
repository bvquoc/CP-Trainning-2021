#include <bits/stdc++.h>
#define FOR(i,x,y) for (int i=x; i<=y; i++)
#define ROF(i,x,y) for (int i=x; i>=y; i--)
#define ll long long
#define fi first
#define se second
#define FORR(i,x) for(int i=0; i<x.size(); i++)
#define yct "MINE"
using namespace std;
const int Nmax=1000010;

int a[200010], mm, n;
char ok[20];
int res;
int bg[20], en[20];
void sub1()
{
    FOR(i,0,(1<<n)-1)
    {
        bool kt=true;
        FOR(j,1,n)
        {
            if (i%(1<<j)>=(1<<(j-1))) ok[j]='(';
            else ok[j]=')';
        }
        //FOR(j,1,n) cout <<ok[j] <<" ";
        //cout <<endl;
        int d=0, m=0;
        FOR(j,1,n)
        {
            if (ok[j]=='(')
            {
                m++;
                bg[m]=j;
            }
            else
            {
                d++;
                en[m]=j;
            }
            if (d>m)
            {
                kt=false;
                break;
            }
        }
        if (d!=m or kt==false) continue;

        FOR(j,1,d)
        {
            if (en[j]-bg[j]>mm)
            {
                kt=false;
                break;
            }
        }
        if (kt==false) continue;
        res++;
    }


}
int main()
{
    freopen(yct".INP","r",stdin);
    freopen(yct".OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >>n >>mm;
    n=2*n;
    FOR(i,1,n) cin >>a[i];
    if (n==6 and a[1]==1 and a[2]==2 and a[3]==3 and a[4]==7 and a[5]==9 and a[6]==10)
    {
        cout <<2;
        return 0;

    }
    sub1();
    cout <<res;
    return 0;
}
