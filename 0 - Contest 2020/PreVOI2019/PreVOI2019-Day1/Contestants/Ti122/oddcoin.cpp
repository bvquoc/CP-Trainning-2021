#include <bits/stdc++.h>
using namespace std;
#define llint long long
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define X first
#define Y second
#define NAME "oddcoin"
inline llint nextInt(){
    register char c=getchar();
    bool neg=0;
    llint ret=0;
    while (c<'0'||'9'<c){
        if (c=='-') neg=1;
        c=getchar();
    }
    while ('0'<=c&&c<='9'){
        ret=ret*10+c-'0';
        c=getchar();
    }
    if (neg) ret=-ret;
    return ret;
}
inline char nextChar(){
    char c=getchar();
    while (c==' '||c=='\n') c=getchar();
    return c;
}
void write(llint x){
    if (x>9) write(x/10);
    putchar(x%10+48);
}
const int oo = 2e9 ;
typedef pair<int,int> ii;
int a[]{0,1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000}, w, newx;



int solve(int vi){
    int res = 0;
    int c = 15;
    while (vi){
        int x = a[c];
        int g= vi/x;
         res += g;
         vi -= x*g;
         c--;
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(NAME".inp","r",stdin);
    freopen(NAME".out","w",stdout);
        int t = nextInt();
    while (t--)
        {

            newx = nextInt();
            w = nextInt();
            int maxres = solve(w);
            int realres = maxres;
            for (int i = 1; i<= maxres; i++)
            {
                w -= newx;
                if (w<0) break;
                realres = min(realres, i + solve(w));
            }
            write(realres);
            putchar('\n');
        }
}

