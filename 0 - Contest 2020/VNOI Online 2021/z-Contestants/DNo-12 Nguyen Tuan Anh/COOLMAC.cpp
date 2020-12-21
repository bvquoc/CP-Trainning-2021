#include <bits/stdc++.h>
#define int long long
using namespace std;
const string filename="COOLMAC";
struct pack {int u,v;};
vector<pack> a;
vector<int> b;
int m,n,res;
bool ok=true;

void init() {
    sort(a.begin(),a.end(),[](const pack &A, const pack &B) {return A.u<B.u || (A.u==B.u && A.v>B.v);});
    int i=1;
    if(a[a.size()-1].v!=1e5) ok=false;
    while(i<a.size()) {
        if(a[i].u>a[i-1].v) {
            ok=false;
            break;
        }
        if(a[i].v<a[i-1].v) {
            a.erase(a.begin()+i);
        }
        else ++i;
    }
    i=1;
    while(i<a.size()) {
        int k=i;
        while(k>0 && a[i].u<=a[k-1].v)   --k;
        ++k;
        for(int j=i-1;j>=k;--j) a.erase(a.begin()+j);
        i=k;
        ++i;
    }
}

int32_t main() {
    freopen((filename+".INP").c_str(),"r",stdin);
    freopen((filename+".OUT").c_str(),"w",stdout);
    scanf("%lld", &m);
    for(int i=1;i<=m;++i) {
        pack x;
        scanf("%lld%lld", &x.u, &x.v);
        a.push_back(x);
    }
    init();
    if(!ok) {
        printf("-1");
        return 0;
    }
    scanf("%lld", &n);
    for(int i=1;i<=n;++i) {
        int deg;
        scanf("%lld", &deg);
        int l=0,r=a.size()-1,k=-1;
        while(l<=r) {
            int mid=(l+r)/2;
            if(a[mid].u<=deg) {
                k=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        if(k==-1) {
            cout<<-1;
            return 0;
        }
        b.push_back(k);
    }
    sort(b.begin(),b.end());
    res=a.size()-b[0];
    printf("%lld", res);
    return 0;
}
