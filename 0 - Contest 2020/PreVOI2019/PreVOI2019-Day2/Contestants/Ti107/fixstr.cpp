#include <bits/stdc++.h>
#define maxn 1000005
#define NTLiinhh "fixstr"
#define fto(i,a,b) for (int i=a;i<=b;i++)
#define fdto(i,a,b) for (int i=a;i>=b;i--)
#define endl '\n'
using namespace std;

string s;
int n, m;

void input()
{
    ios_base::sync_with_stdio(0);
    cout.tie(NULL);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen (NTLiinhh".inp","r",stdin);
    freopen (NTLiinhh".out","w",stdout);
#endif // ONLINE_JUDGE
    cin >> s;
    n=s.length(); s=' '+s;
    cin >> m;
}
/// 1 : ngoac mo
/// -1 : ngoac dong
string luu[maxn];
void solve1()
{
    fto (dt, 1, m) {
        char c; int i, j, k;
        cin >> c;
        luu[dt]=s;
        if (c=='C') {
            cin >> i;
            if (s[i]=='(') s[i]=')'; else s[i]='(';
        }
        else if (c=='Q') {
            cin >> i >> j;
            int dem=0, res=0;
            fto (t, i, j) {
                if (s[t]=='(') ++dem; else --dem;
                if (dem<0) res-=dem, dem=0;
            }
            res+=dem;
            cout << res << endl;
        }
        else if (c=='U') {
            cin >> k;
            s=luu[k];
        }
    }
}


int main()
{
    input();
    solve1();
}
