#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define taskname "FIXSTR"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int maxn = 1e6 + 100;
const int logn = log2(maxn) + 1;
const int mod = 1e6 + 3;
string s;
int n , m;
struct TNode{
    int lef , rig;
    TNode(){};
    TNode(int lef , int rig):lef(lef) , rig(rig){};
    TNode operator + (const TNode other){
        if(lef == -1)return other;
        if(other.lef == -1)return (*this);
        return TNode(lef + max(other.lef - rig , 0) , other.rig + max(rig - other.lef,0));
    }
};

struct node
{
    TNode val;
    node * l , * r;
    node(){};
    node(TNode val, node * l , node * r): val(val) , l(l) , r(r) {};
}*null,*root[maxn],*cur;

node * build(int l , int r)
{
    if(l == r){
        return new node(TNode(s[l - 1] == ')' , s[l - 1] == '(') , null,null);
    }
    int mid = l + r >> 1;
    node * res = new node();
    res->l = build(l,mid);
    res->r = build(mid+1,r);
    res->val = res->l->val + res->r->val;
    return res;
}

node* update(node * x , int l , int r , int pos)
{
    node* it = new node(x->val,x->l,x->r);
    if(l == r){
        swap(it->val.lef,it->val.rig);
        return it;
    }
    int mid = l + r >> 1;
    if(mid >= pos){
        it->l = update(it->l,l,mid,pos);
    }else{
        it->r = update(it->r,mid+1,r,pos);
    }
    it->val = it->l->val + it->r->val;
    return it;
}

TNode query(node * x , int l , int r , int L , int R)
{
    if(L > r || l > R)return TNode(-1,-1);
    if(L <= l && r <= R)return x->val;
    int mid = l + r >> 1;
    return query(x->l,l,mid,L,R) + query(x->r,mid+1,r,L,R);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP","r")){
		freopen(taskname".INP", "r",stdin);
		freopen(taskname".OUT", "w",stdout);
    }
    cin >> s;n = s.size();
    null = new node(TNode(-1,-1),0,0);
    null->l = null->r = null;
    root[0] = build(1,n);
    cin >> m;
    for(int i = 1 ; i <= m ; ++i){
        char type;cin >> type;
        if(type == 'C'){
            int x;cin >> x;
            root[i] = update(root[i - 1] , 1 , n , x);
        }else if(type == 'Q'){
            int l , r;cin >> l >> r;
            root[i] = root[i - 1];
            auto res = query(root[i] , 1 , n , l , r);
            cout << res.lef + res.rig << '\n';
        }else{
            int x;cin >> x;
            root[i] = root[x - 1];
        }
    }
}

