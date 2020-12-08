#include <bits/stdc++.h>
#define maxn 1000009

using namespace std;
int x[maxn],n,xd[100],ans[maxn];
int y[maxn],z[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("paint.inp", "r", stdin);
    freopen("paint.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; ++i){
        char c;
        cin >> x[i] >> c;
        y[i]=c-'a';
        if(x[i]==2)cin >> c,z[i]=c-'a';
    }
    for(int i=0; i<=26; ++i) xd[i]=i;
    for(int i=n; i>=1; --i){
        if(x[i]==1)ans[i]=xd[y[i]];
        else xd[y[i]]=xd[z[i]];
    }
    for(int i=1; i<=n; ++i)
    if(x[i]==1)putchar(ans[i]+'a');
    return 0;
}
