#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define uf(i,x,y) for(int i=(x); i<=(y); i++)
#define df(i,x,y) for(int i=(x); i>=(y); i--)
#define rf(i,x) for(int i=0; i<(x); i++)
using namespace std;
#define LIMIT 200010
const long long mod = 1e9 + 7;

int n, a[LIMIT], b[LIMIT];
long long res;

void online_judge(void)
{
    freopen("PERMEOW.inp","r",stdin);
    freopen("PERMEOW.out","w",stdout);
}

bool similar;

void inp(void)
{
    cin>>n;
    uf(i,1,n) cin>>a[i];
    similar = true;
    uf(i,1,n)
    {
        cin>>b[i];
        if(b[i] != a[i]) similar = false;
    }
}

void subtask1(void)
{
    int pos;
    res = 0;
    uf(x,1,n)
    {
        pos = x;
        uf(i,x,n) if(a[i] == x)
        {
            pos = i;
            break;
        }
        df(i,pos,x+1)
        {
            swap(a[i],a[i-1]);
            res = (res + 1)%mod;
        }
    }
    cout<<res;
}

int main(void)
{
    fastread
    online_judge();
    inp();
    if(n <= 2000 and similar) subtask1();
    else cout<<0;
    return 0;
}

/* Code by: gaconvuive */

