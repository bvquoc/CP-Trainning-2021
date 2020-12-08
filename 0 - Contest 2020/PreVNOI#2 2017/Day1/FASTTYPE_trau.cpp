#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const string INP=".INP", OUT=".ANS";
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
vector <char> a, tmp;
int l, r, c;

int32_t main() {
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);
    Read(k);
    Read(m);
    { // Nhap xau S
        string s;
        cin>>s;
        a.push_back(' ');
        for (char x: s) {
            a.push_back(x);
            // cerr<<x<<" ";
        }
    }

    Read(q);
    while(q--) {
        Read(l);
        Read(r);
        Read(c);
        
        tmp=a;
        for (int j=r;j>l;j--) {
            a.insert(a.begin()+c+1,tmp[j]);
        }
        
        while (a.size()>m+1) a.pop_back();
    }
    
    for (int i=1;i<=k;i++) {
        putchar(a[i]);
    }
    return 0;
}