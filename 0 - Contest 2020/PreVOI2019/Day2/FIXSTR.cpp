#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N=1000006;
#define int long long
#define oo LLONG_MAX
struct query {
    char type; int l, r, k;
    query(){}
    query(char _type, int _l, int _r, int _k) {
        type=_type;
        l=_l;
        r=_r;
        k=_k;
    }
} q[N];
struct Node { int lazy,val; };
int n, m; vector <int> a(1,0);

struct SegmentTree {
    vector <Node> stmax, stsum;
    void assign(int sz) {
        stmax.resize(4*sz+1);
        stsum.resize(4*sz+1);
    }
    void update(int id, int l, int r, int u, int v, int val) {
        if (v < l || r < u) {
            return ;
        }
        if (u <= l && r <= v) {
            // Khi cài đặt, ta LUÔN ĐẢM BẢO giá trị của nút được cập nhật ĐỒNG THỜI với
            // giá trị lazy propagation. Như vậy sẽ tránh sai sót.
            nodes[id].val += val;
            nodes[id].lazy += val;
            return ;
        }
        int mid = (l + r) / 2;

        down(id); // đẩy giá trị lazy propagation xuống các con

        update(id*2, l, mid, u, v, val);
        update(id*2+1, mid+1, r, u, v, val);

        nodes[id].val = max(nodes[id*2].val, nodes[id*2+1].val);
    }
    void downmax(int id) {
        int t=stmax[id].lazy, id1=id<<1, id2=id1+1;
        stmax[id1].lazy+=t;
        stmax[id1].val+=t;
        stmax[id2].lazy+=t;
        stmax[id2].val+=t;
        stmax[id].lazy=0;
    }
    void downsum(int id) {
        int t=stsum[id].lazy, id1=id<<1, id2=id1+1;
        stsum[id1].lazy+=t;
        stsum[id1].val+=t;
        stsum[id2].lazy+=t;
        stsum[id2].val+=t;
        stsum[id].lazy=0;
    }
    void updatesum(int id, int l, int r, int u, int v, int val) {
        if (v<l || r<u) return;
        if (u<=l && r<=v) {
            stmax[id].val+=val;
            stmax[id].lazy+=val;
            return;
        }
        int mid=(l+r)>>1, id1=id<<1, id2=id1+1;
        downmax(id); downsum(id);
        update(id1,l, mid,u,v,val); update(id2,mid+1,r,u,v,val);
        stmax[id].val=max(stmax[id1].val,stmax[id2].val);
        stsum[id].val=stsum[id1].val+stsum[id2].val;
    }
    int getmax(int id, int l, int r, int u, int v) {
        if (v<l || r<u) return -oo;
        if (u<=l && r<=v) return stmax[id].val;
        int mid=(l+r)>>1, id1=id<<1, id2=id1+1;
        downmax(id);
        return max(getmax(id1,l,mid,u,v),getmax(id2,mid+1,r,u,v));
    }
    int getsum(int id, int l, int r, int u, int v) {
        if (v<l || r<u) return 0;
        if (u<=l && r<=v) return stsum[id].val;
        int mid=(l+r)>>1, id1=id<<1, id2=id1+1;
        downsum(id);
        return getsum(id1,l,mid,u,v)+getsum(id2,mid+1,r,u,v);
    }
    void operator =(const SegmentTree &other) {
        stmax=other.stmax;
        stsum=other.stsum;
    }
} tree;

bool save[N], id[N]; int cntU=0;

struct THis{
    vector <int> a; SegmentTree st;
    THis(){}
    THis(vector <int> _a, SegmentTree _st) {
        a=_a;
        st=_st;
    }
};
vector <THis> his; vector<int> svk;

void Enter();
int32_t main() {
    FastIO;
    freopen("FIXSTR.INP","r",stdin);
    freopen("FIXSTR.OUT","w",stdout);
    string s; cin>>s; n=s.size();
    for (int i=0;i<n;i++) 
        if (s[i]=='(') a.push_back(1); 
        else a.push_back(-1);
    cin>>m;
    for (int i=1;i<=m;i++) {
        char type; cin>>type;
        if (type=='Q') {
            cin>>q[i].l>>q[i].r;
            if (q[i].l>q[i].r) swap(q[i].l,q[i].r);
        } else cin>>q[i].k;
        if (type=='U') {
            int k=q[i].k;
            save[k-1]=true;
            id[k]=cntU;
            cntU++;
        }
    }
    { //Build Segment Tree
        tree.assign(n);
        tree.build(1,1,n);
    }
    for (int i=1;i<=n;i++) {
        cerr<<a[i]<<" "<<tree.getsum(1,1,n,1,i)<<" "<<tree.getmax(1,1,n,1,i);
        cerr<<endl;
    }
    if (save[0]) {
        his.push_back(THis(a,tree));
        svk.push_back(1);
    }
    int l, r, k;
    for (int i=1;i<=m;i++) {
        l=q[i].l, r=q[i].r, k=q[i].k;
        if (q[i].type=='Q') {

        } else if (q[i].type=='C') {
            a[k]*=-1;
            // ST.update(1,1,n,k);
        } else {
            // int pos=lower_bound(svk.begin(),svk.end(),k)-svk.begin();
            // a=his[pos].a;
            // tree=his[pos].st;
        }
        if (save[i]) {
            his.push_back(THis(a,tree));
            svk.push_back(i+1);
        }
    }
    return 0;
}