#include <bits/stdc++.h>
using namespace std;
#define llint long long
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define X first
#define Y second
#define NAME "mine"
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
const int oo = 1e9 , mod = 1e6 +3, maxn = 6005;
typedef pair<int,int> ii;
int n, m, a[maxn], f[maxn][maxn], l[maxn];
llint  g[maxn][maxn], save[maxn];
void enter(){
    n = nextInt();
    n = (n << 1);
    m = nextInt();
    for (int i = 1; i <= n; i++)
    a[i] = nextInt();

}

void init(){
    f[0][0]=1;
    f[1][1]=1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
    {

        if (j!=0) f[i][j] = f[i-1][j-1];else f[i][j] = 0;
        f[i][j] +=f[i-1][j+1];
        if (f[i][j]>= mod) f[i][j] -= mod;
    }
        save[i]= f[i][0];
        f[i][0]=0;
    }
    int chay = 1;
    for (int i = 1; i <= n; i++)
    {
        while (a[chay] + m <a[i]) chay++;
        l[i] =i- chay+1;
    }
   // for (int i= 1; i <= n; i++) cout <<  l[i]<<" ";cout << endl;
}

void solve(){
   // cout << f[6][0];
    g[0][0]=1;
    for (int i = 2; i <= n; i+=2)
    for (int j = 2; j <= min(i,l[i]); j+=2)
    {
        g[i][j] = (g[i][j]+ g[i-j][0] *save[j]) % mod;
        g[i][0] = (g[i][0] + g[i][j]) % mod;
    }

    cout << g[n][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(NAME".inp","r",stdin);
    freopen(NAME".out","w",stdout);
    enter();
    init();
    solve();
}

