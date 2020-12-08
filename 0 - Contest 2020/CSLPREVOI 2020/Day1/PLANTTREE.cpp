#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const string INP=".INP", OUT=".OUT";
const string FILENAME="PLANTTREE";
const int N=600005;

int k, n, m;
int ci=0, mi=0, id=1;
int a[N], res;
set <int> Set;
int cnt[N];

void compress() {
    set<int> s(a+1, a+1+n);
    vector<int> b(s.begin(), s.end());
    for (int i=1;i<=n;i++) {
        int x=lower_bound(b.begin(),b.end(),a[i])-b.begin()+1;
        a[i]=x;
    }
}

struct edge { 
    int l, r, w; 
    // edge() {}
    // bool operator <(const edge &other) {
    //     return (r-l<other.r-other.l);
    // }
};
vector <edge> d;
// set <edge> S;

int32_t main() {
    FastIO;
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);
    cin>>k>>n>>m;
    for (int i=1;i<=n;i++) {
        id+=ci;
        cin>>ci>>mi;
        a[id]+=mi;
        a[id+ci]-=mi;
    }
    n=(1<<k); a[0]=0;
    for (int i=1;i<=n;i++)
        a[i]+=a[i-1];
    compress();
    for (int i=1;i<=n;i++) {
        Set.insert(a[i]);
        cnt[a[i]]++;
    }

    if (Set.size()==1) {
        cout<<1;
        return 0;
    }
    if (Set.size()==n) {
        cout<<n;
        return 0;
    }

    { // Split
        int i=1;
        while (i<=n) {
            int j=i;
            while (a[i]==a[j] && j<=n) j++;
            d.push_back({i,j-1,a[i]});
            i=j;
        }
    }

    int Max_cnt=0;
    for (int i=1;;i++) {
        if (cnt[i]==0) break;
        if (cnt[Max_cnt]<cnt[i])
            Max_cnt=i;
    }
    res=1;
    for (int i=d.size()-1;i>=0;i--) {
        if (d[i].w!=Max_cnt) continue;
        d.erase(d.begin()+i);
    }


    for (edge e:d) {
        int len=e.r-e.l+1;
        // if (len==1) {
        //     res++;
        //     continue;
        // }
        // int l=0, r=len, re=0;
        // while (l<r) {
        //     int mid=(l+r)/2;
        //     if ((1<<mid)<len) {
        //         re=max(re,mid);
        //         r=mid+1;
        //     } else l=mid-1;
        // }
        // cerr<<re;
        res+=len;
    }

    cout<<res;
    return 0;
}