#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define uf(i,x,y) for(int i=(x); i<=(y); i++)
#define df(i,x,y) for(int i=(x); i>=(y); i--)
#define rf(i,x) for(int i=0; i<(x); i++)
using namespace std;
const long long mod = 998244353;
#define LIMIT 2001

int testcase, n, a[LIMIT];
long long fact[LIMIT];

void online_judge(void)
{
    freopen("GIFT11.inp","r",stdin);
    freopen("GIFT11.out","w",stdout);
}

void factorial(void)
{
    fact[0] = 1;
    uf(i,1,2000) fact[i] = (fact[i-1]*i)%mod;
}

bool sub2;
string num;

#define sz(s) (int)s.size()

string toString(int x)
{
    string ans = "";
    while(x > 0)
    {
        ans = (char)(x%10 + '0') + ans;
        x /= 10;
    }
    return ans;
}

void inp(void)
{
    cin>>n;
    sub2 = true;
    uf(i,1,n)
    {
        cin>>a[i];
        num = toString(a[i]);
        if(sz(num)%2 != 0) sub2 = false;
    }
}

int s[2], p[10];

void subtask1(void)
{
    long long res = 0;
    uf(i,1,n) p[i] = i;
    do {
        s[0] = s[1] = 0;
        int cnt = 0;
        uf(i,1,n)
        {
            num = toString(a[p[i]]);
            uf(id,0,sz(num)-1) s[(++cnt)%2] += (num[id] - '0');
        }
        if(abs(s[0]-s[1])%11 == 0) res = (res + 1)%mod;
    } while(next_permutation(p+1,p+n+1));
    cout<<res<<"\n";
}

void subtask2(void)
{
    s[0] = s[1] = 0;
    int cnt = 0;
    uf(i,1,n)
    {
        num = toString(a[i]);
        uf(id,0,sz(num)-1) s[(++cnt)%2] += (num[id] - '0');
    }
    if(abs(s[0]-s[1])%11 == 0) cout<<fact[n]<<"\n";
    else cout<<"0\n";
}

int main(void)
{
    fastread
    online_judge();
    cin>>testcase;
    factorial();
    while(testcase--)
    {
        inp();
        if(n <= 9) subtask1();
        else
        {
            if(sub2) subtask2();
            else cout<<fact[n]<<"\n";
        }
    }
    return 0;
}

/* Code by: gaconvuive */

