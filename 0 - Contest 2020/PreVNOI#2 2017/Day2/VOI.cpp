#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const string INP=".INP", OUT=".OUT";
const string FILENAME="VOI";
const int N=51;

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

typedef pair<int,int> ii;

int n, m, a[N], x[N];
int id[100], res=INT_MAX;
vector <int> pen[N];
set <ii> p;
set <int> Col_in_Set[3], Set[3];

void Check() {
    set <int> Both;
    for (int i=1;i<=2;i++) {
        Col_in_Set[i].clear();
        for (int x:Set[i]) {
            Col_in_Set[i].insert(a[x]);
            Both.insert(a[x]);
        }
    }
    if (Both.size()==(Col_in_Set[1].size()+Col_in_Set[2].size())) {
        res=min(res,(int)Set[0].size());
        // for (int l=1;l<=2;l++) {
        //     for (int x:Set[l]) cerr<<x<<" ";
        //     cerr<<endl;
        // }
        // cerr<<"--------\n";
    }
}

void Try(int i) {
    for (int j=0;j<=2;j++) {
        bool ok=true;
        if (j!=0) {
            for (int x:Set[j]) {
                int u=min(x,i), v=max(x,i);
                if (p.count(ii(u,v))) {
                    ok=false;
                    break;
                }
            }
        }
        if (ok) {
            Set[j].insert(i);
            if (i==n) Check();
            else Try(i+1);
            Set[j].erase(i);
        }
    }
}

int32_t main() {
    FastIO;
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);
    id['R']=1; id['G']=2; id['B']=3;

    Read(n);
    for (int i=1;i<=n;i++) {
        char c=getchar();
        a[i]=id[c];
    }

    Read(m);
    if (m==0) {
        putchar('0');
        return 0;
    }
    
    for (int i=1;i<=m;i++) {
        int u, v;
        Read(u); Read(v);
        if (u>v) swap(u,v);
        p.insert(ii(u,v));
        pen[u].push_back(v);
        pen[v].push_back(u);
    }

    if (n<=15) Try(1);
    else res=0;

    Write(res);
    return 0;
}