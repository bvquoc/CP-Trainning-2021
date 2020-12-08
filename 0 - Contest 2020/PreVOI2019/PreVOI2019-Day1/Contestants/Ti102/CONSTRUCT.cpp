#include <bits/stdc++.h>

#define _u(i,a,b) for(int i=(a);i<=(b);++i)
#define _d(i,a,b) for(int i=(a);i>=(b);--i)
#define FIO() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FI(task) freopen(task".inp","r",stdin);
#define FO(task) freopen(task".out","w",stdout);
#define fillchar(a, x) memset(a, x, sizeof(a))
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define endl "\n"

using namespace std;

const int N = 1e6+7;
const ll M = 1ll*1e9+7;

void write(){}
template<typename T, typename ...Ts>
void write(const T &first, const Ts &...rest){
    cout << first << ' ';
    write(rest...);
}
template<typename ...Ts>
void writeln(const Ts &... rest){
    write(rest...);
    cout << endl;
}

int readint(){
    int num(0); char c; bool neg(0);
    for(c=getchar();c<'0'||c>'9';c=getchar()) neg|=c=='-';
    for(;c>='0'&&c<='9';c=getchar()) num=num*10+c-48;
    return neg?-num:num;
}

void print(ll num){if(num>9)print(num/10);putchar(num%10+48);}

int a[N];
int m[20][N];
int n, q, d;

void init_rmq(){
    _u(i,1,n) m[0][i] = a[i];
    _u(j,1,d)
    for(int i = 1; i + (1 << j) - 1<=n; ++i) m[j][i] = min(m[j-1][i], m[j-1][i + ( 1 << (j-1))]);
}

int Getmin(int i, int j){
    int l = log2( j -i + 1);
    return min(m[l][i], m[l][j - (1 << l) + 1]);
}

int BS(int l, int r, int sub, int mi){
    int ans(-1);
    while(l<=r){
        int mid = (l + r) >> 1;
        if(Getmin(l, mid) - sub != mi){
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
    }
    return ans;
}

int solve(int l, int r, int sub){
    if(l > r) return 0;
    int mi(M), ans(0);
    mi = Getmin(l, r); mi -= sub;
    ans = mi;

    int last = l;
    while(last < r){
        while(a[last] - sub == mi) ++last;
        int pos = BS(last, r, sub, mi);
        if(pos < 0) break;
        ans += solve(last, pos, sub + mi); last = pos + 1;
    }
    return ans;
}

#define task "construct"

int main(){
    FIO();
    FI(task);
    #ifndef HOHO
        FO(task);
    #endif // HOHO

    int T = readint();
    while(T--){
        n = readint(); q = readint(); d = log2(n);
        _u(i,1,n) a[i] = readint();
        init_rmq();
        while(q--){
            int c =  readint();
            if(c == 1){
                int l = readint(), r = readint(), k = readint();
                _u(i,l,r) a[i] += k;
                init_rmq();
            }else{
                int l = readint(), r = readint();
                int ans = solve(l, r, 0);
                cout << ans << endl;
            }
        }
    }
    return 0;
}
