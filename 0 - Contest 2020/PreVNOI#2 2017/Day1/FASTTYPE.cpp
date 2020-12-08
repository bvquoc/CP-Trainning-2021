#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const string INP=".INP", OUT=".OUT";
const string FILENAME="FASTTYPE";
const int N=200005;

template <typename T>
inline void Read(T& x) {
    bool Neg=false;
    char c;
    for (c=getchar();c<'0' || c>'9';c=getchar()) if (c=='-') Neg=!Neg;
    x=c-'0';
    for (c=getchar();c>='0' && c<='9';c=getchar()) x=x*10+c-'0';
    if (Neg) x=-x;
}

int k, m, q;
string s, tmp;
int l, r, c;

int32_t main() {
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);
    Read(k); Read(m);
    cin>>s;
    Read(q);
    while(q--) {
        Read(l); Read(r); Read(c);
        r--; l--;
        // for (int j=r;j>l;j--) {
        //     s.insert(s.begin()+c,tmp[j]);
        // }
        tmp=s;
        s.insert(s.begin()+c,tmp.begin()+l+1,tmp.begin()+r);
        while (s.size()>m)
            s.pop_back();
        // cerr<<s<<endl;
    }
    
    for (int i=0;i<k;i++) {
        putchar(s[i]);
    }
    return 0;
}