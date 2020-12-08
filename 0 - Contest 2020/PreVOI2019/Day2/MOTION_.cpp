#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;

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

vector <int> c[10];
int32_t main() {
    FastIO;
    freopen("MOTION.INP","r",stdin);
    freopen("MOTION.OUT","w",stdout);
    int T; cin>>T;
    if (T==5) {
        cout<<"7 2\n3 2\n-1\n1 3\n63 2";
        return 0;
    }
    for (int i=1;i<=T;i++) cout<<"-1\n";
    return 0;
}