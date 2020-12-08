#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N=1000006;
#define int long long
struct Node {
    int optimal, open, close;
    Node() {
        optimal=0;
        open=0;
        close=0;
    }
    Node(int _optimal, int _open, int _close) {
        optimal=_optimal;
        open=_open;
        close=_close;
    }
    Node operator+ (const Node& right) {
        Node res;
        int tmp=min(open, right.close);
        res.optimal=optimal+right.optimal+tmp;
        res.open=open+right.open-tmp;
        res.close=close+right.close-tmp;
        return res;
    }
};
struct FIXSTR {
    char type; int l, r, k;
    FIXSTR(){}
    FIXSTR(char _type, int _l, int _r, int _k) {
        type=_type;
        l=_l;
        r=_r;
        k=_k;
    }
} q[N];
int n, m; string s;
struct SegmentTree {
    vector <Node> st;
    SegmentTree() { st.clear(); }
    SegmentTree(int sz) { st.resize(sz*4); }
    void Assign(int sz) { st.resize(sz*4); }
    void build(int id, int l, int r) {
        if (l==r) {
            if (s[l]=='(') st[id]=Node(0,1,0);
            else st[id]=Node(0,0,1);
            return;
        }
        int mid=(l+r)>>1, id1=id<<1, id2=id1+1;
        build(id1,l,mid);
        build(id2,mid+1,r);
        st[id]=st[id*2]+st[id*2+1];
    }
    void update(int id, int l, int r, int i) {
        if (i<l || r<i) return;
        if (l==r) {
            if (s[i]=='(') st[id]=Node(0,1,0);
            else st[id]=Node(0,0,1);
            return;
        }
        int mid=(l+r)>>1, id1=id<<1, id2=id1+1;
        update(id1,l,mid,i);
        update(id2,mid+1,r,i);
        st[id]=st[id*2]+st[id*2+1];
    }
    Node query(int id, int l, int r, int u, int v) {
        if (v<l || r<u) return Node(0,0,0);
        if (u<=l && r<=v) return st[id];
        int mid=(l+r)>>1, id1=id<<1, id2=id1+1;
        return query(id1,l,mid,u,v)+query(id2,mid+1,r,u,v);
    }
    int GetAns(int l, int r) {
        // return (r-l+1)-((query(1,1,n,l,r).optimal)<<1);
        Node ans=query(1,1,n,l,r);
        return ans.open+ans.close;
    }
    void operator =(const SegmentTree &other) { st=other.st; }
} ST;

bool save[N], id[N]; int cntU=0;
void Enter();
struct svHis{
    string s; SegmentTree st;
    svHis(){}
    svHis(string _s, SegmentTree _st) {
        s=_s;
        st=_st;
    }
};
vector <svHis> his; vector<int> svk;
vector <string> his_(1,"");
int GetAns_(string str) {
    stack <char> s;
    int cnt=0;
    for(int i=0;i<str.size();i++)
    if (str[i]=='(') s.push(str[i]);
    else {
        if(!s.empty()) s.pop();
        else cnt++;
    }
    return cnt+s.size();
}

int32_t main() {
    FastIO;
    freopen("FIXSTR.INP","r",stdin);
    freopen("FIXSTR.OUT","w",stdout);
    Enter();
    // if (n<=1000 && m<=1000) { // Brute Force
    //     int l, r, k;
    //     for (int i=1;i<=m;i++) {
    //         his_.push_back(s);
    //         l=q[i].l; r=q[i].r; k=q[i].k;
    //         if (q[i].type=='Q') cout<<GetAns_(s.substr(l,r-l+1))<<endl;
    //         else if (q[i].type=='C') {
    //             if (s[k]=='(') s[k]=')';
    //             else s[k]='(';
    //         } else s=his_[k];
    //     }
    //     return 0;
    // }
    ST.Assign(n); ST.build(1,1,n);
    if (cntU==0) {
        for (int i=1;i<=m;i++) {
            int l=q[i].l, r=q[i].r, k=q[i].k;
            if (q[i].type=='Q') cout<<ST.GetAns(l,r)<<endl;
            else if (q[i].type=='C') {
                if (s[k]=='(') s[k]=')';
                else s[k]='(';
                ST.update(1,1,n,k);
            }
        }
        return 0;
    }
    if (save[0]) {
        his.push_back(svHis(s,ST));
        svk.push_back(1);
    }
    for (int i=1;i<=m;i++) {
        int l=q[i].l, r=q[i].r, k=q[i].k;
        if (q[i].type=='Q') cout<<ST.GetAns(l,r)<<endl;
        else if (q[i].type=='C') {
            if (s[k]=='(') s[k]=')';
            else s[k]='(';
            ST.update(1,1,n,k);
        } else {
            int pos=lower_bound(svk.begin(),svk.end(),k)-svk.begin();
            s=his[pos].s;
            ST=his[pos].st;
        }
        if (save[i]) {
            his.push_back(svHis(s,ST));
            svk.push_back(i+1);
        }
    }
    return 0;
}

void Enter() {
    cin>>s; n=s.size(); s=' '+s;
    cin>>m;
    int l, r, k;
    for (int i=1;i<=m;i++) {
        l=0; r=0; k=0;
        char type; cin>>type;
        if (type=='Q') cin>>l>>r;
        else cin>>k;
        if (type=='U') {
            save[k-1]=true;
            id[k]=cntU;
            cntU++;
        }
        if (l>r) swap(l,r);
        q[i]=FIXSTR(type,l,r,k);
    }
}