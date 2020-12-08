#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const string INP=".INP", OUT=".OUT";
const string FILENAME="ANCTEXT";
const int N=300005; 

int n, q;
string s;
pair <string,int> dict[N];

int32_t main() {
    FastIO;
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);
    int T; cin>>T;
    int n, q;
    cin>>s>>n;  
    for (int i=1; i<=n;i++) {
        int x; string si;
        cin>>x>>si;
        dict[i].first=dict[x].first+si;
        dict[i].second=-i;
    }
    sort(dict+1, dict+1+n);
    cin>>q;
    for (int i=1; i<=q; ++i) {
        int l, r;
        cin>>l>>r;
        l--; r--;
        int len=r-l+1;
        int pos=lower_bound(dict+1, dict+n+1, make_pair(s.substr(l, len), (int) 1e9))-dict-1;
        if (pos<=0)
            cout<<"-1\n";
        else
            cout<<-dict[pos].second<<'\n';
    }
    return 0;
}
