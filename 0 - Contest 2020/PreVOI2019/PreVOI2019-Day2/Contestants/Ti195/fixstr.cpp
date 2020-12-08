#include <bits/stdc++.h>
#define fo(i, a, b) for(int i=a; i<=b; i++)
#define name "fixstr"
#define INPUT freopen(name".inp", "r",stdin)
#define OUTPUT freopen(name".out", "w", stdout);
using namespace std;

string s;
int m;
void xl(int l, int r){
    int kq=0, sl=0;
    fo(i, l, r) if( s[i]=='(') sl++;
    else {
        if(sl) sl--;  else kq++;
    }
    cout << kq+sl << '\n';
}
void sub1()
{
    string w[100001];
    fo(i, 1, m) {
        char c; cin >> c;
        int u, v;
        if(c=='U') { cin >> u;  s=w[u-1]; }
        if(c=='C') { cin >> u;  s[u-1]='('+')'-s[u-1]; }
        if(c=='Q')
            { cin >> u >> v; xl(u-1, v-1); }
        w[i]=s;
    }
}
int main()
{
    INPUT; OUTPUT;
    cin >> s >> m;
    sub1();
}
