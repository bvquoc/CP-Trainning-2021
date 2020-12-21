#include <bits/stdc++.h>
#define f1(i,n) for (int i = 1; i <= n; i++)
#define f0(i,n) for (int i = 0; i < n; i++)
#define X first
#define Y second
#define N 2005
using namespace std;
typedef pair<int,int> ii;

using namespace std;

int main()
{
    ifstream fi("GIFT11.INP"); ofstream fo("GIFT11.OUT");
    int t;
    fi >> t;
    while (t--)
    {
        int n; pair<ii,int> len[N];
        string s;
        fi >> n;
        f1(j,n)
        {
            fi >> s;
            len[j].Y = s.length();
            for (int i = 0; i < s.length(); i++)
                if (i % 2 == 0)
                len[j].X.X = len[j].X.X + (int) s[i] - 47;
                else len[j].X.Y = len[j].X.Y + (int) s[i] - 47;
        }
        int a[n+1],cnt=0;
        f1(i,n) a[i]=i;
        if (n <= 15)
        {

        do {
            int le = 0, chan = 0;
            le +=len[a[1]].X.X, chan += len[a[1]].X.Y;
            for (int i = 2; i <= n; i++)
            {
                if (len[a[i-1]].Y % 2 == 0) {le+=len[a[i]].X.X; chan+=len[a[i]].X.Y;}
                else {le+=len[a[i]].X.Y; chan+=len[a[i]].X.X;}
            }
            if ((le - chan) % 11 == 0) cnt++;
        } while(next_permutation(a + 1, a + 1 + n));
        int le = 0, chan = 0;
        le +=len[a[1]].X.X, chan += len[a[1]].X.Y;
        for (int i = 2; i <= n; i++)
            {
                if (len[a[i-1]].Y % 2 == 0) {le+=len[a[i]].X.X; chan+=len[a[i]].X.Y;}
                else {le+=len[a[i]].X.Y; chan+=len[a[i]].X.X;}
            }
            if ((le - chan) % 11 == 0) cnt++;
            fo << cnt % 998244353 << endl;
        }
        if (n > 15)
        {
            if (len[1].Y % 2 == 0)
            {
                int le = 0,chan = 0,cnt=1;
                f1(i,n) le += len[i].X.X, chan+=len[i].X.Y;
                if (abs(le-chan) % 11 == 0){
                   f1(i,n) cnt*= i;
                   fo<< cnt % 998244353<<endl;
                }
                else fo << 0<< endl;
            }
        }
    }
    return 0;
}
