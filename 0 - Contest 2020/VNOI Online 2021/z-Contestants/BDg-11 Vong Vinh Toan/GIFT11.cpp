#include <bits/stdc++.h>

using namespace std;
const int N = 2005, p = 998244353;

int n;
int A[N], type[N];
int perm[N];

void sub2()
{
    long long GT = 1, sum = 0;
    for(int i=1; i<=n; i++)
    {
        GT = (GT*i)%p;
        sum += A[i];
    }
    if(sum%11) cout<<"0\n"; else cout<<GT<<"\n";
}

void sub1()
{
    int ans = 0;
    for(int i=1; i<=n; i++) perm[i] = i;
    do
    {
        int x = 0;
        long long sum = 0;
        for(int i=1; i<=n; i++)
        {
            if(x) sum-=A[perm[i]];
            else sum+=A[perm[i]];
            x ^= type[perm[i]];
        }
        ans += sum%11==0;
    }
    while(next_permutation(perm+1, perm+1+n));
    cout<<ans<<"\n";
}

void proc()
{
    cin>>n;
    string s;
    bool issub2 = 1;
    for(int i=1; i<=n; i++)
    {
        cin>>s;
        for(int j=0; j<s.size(); j+=2) A[i]+=s[j]-'0';
        for(int j=1; j<s.size(); j+=2) A[i]-=s[j]-'0';
        type[i] = s.size()&1;
        issub2 &= type[i] == 0;
    }
    if(n<=8) sub1();
    else if(issub2) sub2();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("GIFT11.inp", "r", stdin);
    freopen("GIFT11.out", "w", stdout);
    int t; cin>>t;
    while(t--) proc();
    return 0;
}
