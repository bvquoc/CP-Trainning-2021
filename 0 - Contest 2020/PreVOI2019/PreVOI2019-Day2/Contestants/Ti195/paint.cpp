#include <bits/stdc++.h>
#define name "paint"
#define INPUT freopen(name".inp", "r",stdin)
#define OUTPUT freopen(name".out", "w", stdout);
using namespace std;

int n;
string s;
int cntcolor['z'-'a'];
int f['z'-'a'][1000000];
void xl()
{
    char c, d;
    cin >> c >> d;
    if(c==d) return;
    int x1=c-'a', x2=d-'a';
    for(int i=1; i<=cntcolor[x1]; i++)    f[x2][++cntcolor[x2]]=f[x1][i];
    cntcolor[x1]=0;
}
int main()
{
    INPUT; OUTPUT;
    cin >> n;
    for(int i=0; i<n; i++) {
        int k; cin >> k;
        if(k-1) xl();
        else {
            char c; cin >> c;
            int tmp=int(c-'a');
            f[tmp][++cntcolor[tmp]]=s.size();
            s+=' ';
        }
    }
    for(int i=0; i<='z'-'a'; i++)
        for(int j=1; j<=cntcolor[i]; j++)   s[ f[i][j] ]=char(i+'a');
    cout << s;
}
