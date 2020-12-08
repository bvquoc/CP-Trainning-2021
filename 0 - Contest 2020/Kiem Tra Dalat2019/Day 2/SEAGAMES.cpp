#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const string INP=".INP", OUT=".OUT";
const string FILENAME="SEAGAMES";
const int N=203;

template <typename T>
inline void Read(T& x) {
    bool Neg=false;
    char c;
    for (c=getchar();c<'0' || c>'9';c=getchar()) if (c=='-') Neg=!Neg;
    x=c-'0';
    for (c=getchar();c>='0' && c<='9';c=getchar()) x=x*10+c-'0';
    if (Neg) x=-x;
}
template <typename T>
inline void Write(T x) {
    if (x<0) { putchar('-'); x=-x; }
    T p=1;
    for (T temp=x/10;temp>0;temp/=10) p*=10;
    for (;p>0;x%=p,p/=10) putchar(x/p+'0');
}

int n, m, c[N], a[N][N];
int res=INT_MAX;
int x[N];
set <int> Set;

void check() {
    set <int> cur_set;
    int cur_max=0;
    for (int i=1;i<=m;i++) {
        cur_set.insert(x[i]);
        cur_max=max(cur_max,a[c[i]][x[i]]);
    }
    if (cur_set!=Set || res<=cur_max) return;
    res=cur_max;
    for (int i=1;i<=m;i++) {
        cout<<x[i]<<" ";
    }
    cout<<endl;
}

void Try(int i) {
    for (int j=1;j<=n;j++) {
        x[i]=j;
        if (i==m) check();
        else Try(i+1);
    }
}
int32_t main() {
    FastIO;
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);
    Read(n); Read(m);
    for (int i=1;i<=m;i++) {
        Read(c[i]);
        Set.insert(c[i]);
    }
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    Try(1);
    return 0;
}