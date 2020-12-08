#include <bits/stdc++.h>
using namespace std;
#define llint long long
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define X first
#define Y second
#define NAME "construct"
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
const int oo = 1e9 , maxn = 1e6+5, fmaxn = 4 *maxn;
typedef pair<int,int> ii;
int n, m,muctieu[maxn], f[maxn], a[maxn];
bool b[maxn];

void solve(int left, int right){
    int res = 0;
    bool stop =0;
    for (int i= 1; i<left; i++) {f[i]=0;b[i]=0;}
    for (int i= left; i<= right;i++) {f[i] = a[i];b[i]=0;}
    for (int i = right+1; i<= n; i++) {f[i] = 0;b[i]=0;}

     while (stop==0){
            stop =1;
            for (int i = 1; i<= n;i++)
            {
                if (f[i]<muctieu[i]) {
                        res ++;
                        res -= b[i-1];
                        b[i]=1;
                        f[i]++;
                }
                else b[i]=0;
                if (f[i]<muctieu[i]) stop =0;
            }
            for (int i=1;i<=n;i++) b[i]=0;
     }
    write(res);
    putchar('\n');
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(NAME".inp","r",stdin);
    freopen(NAME".out","w",stdout);
    int ntest = nextInt();
    while (ntest--){
        n = nextInt();
        m = nextInt();
        for (int i =1 ;i<=n ;i++) {muctieu[i] = nextInt();a[i]=0;}
        while (m--){
            int kind = nextInt();
            if (kind == 1){
                int left = nextInt();
                int right = nextInt();
                int k = nextInt();
                for (int i = left; i <= right;i++) {a[i]+=k;a[i]= min(a[i],muctieu[i]);}
            }
            else {
                int left = nextInt();
                int right = nextInt();
                solve(left, right);

            }
        }
}
}
