///Phß║ím Nguyß╗àn Tuß║Ñn Ho├áng///
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a);i <= (b);i++)
#define repd(i,a,b) for(int i = (a);i >= (b);i--)
#define F first
#define S second
#define PB push_back
#define Task "fixstr"
using namespace std;
//template <class T> inline read(T &a){a = 0;char c;bool nega = 0;while(!isdigit(c = getchar()) && c != '-');if(c == '-') nega = 1,c = getchar();a = c - 48;while(isdigit(c = getchar()))a = a * 10 + c - 48;if(nega) a = -a;}
//template <class T> inline writep(T a){if(a > 9) writep(a / 10);putchar(a % 10 + 48);}
//template <class T> inline write(T a){if(a < 0) putchar('-'),a = -a;writep(a);putchar(' ');}
//template <class T> inline writeln(T a){write(a);putchar('\n');}
const int N = 1000012;
string s;
int n,a[N];

struct node
{
    int type,l,r,id;
};

vector<node> g[N];
vector<int> quest;
int t[4*N],lazy[4*N],tmin[4*N],ans[N],tr[N];

void build(int l = 1,int r = n,int id = 1)
{
    if(l == r)
    {
        tmin[id]= a[l];
        return;
    }
    int mid = l + r >> 1;
    int nid = id << 1;
    build(l,mid,nid);
    build(mid+1,r,nid+1);
    tmin[id] = min(tmin[nid],tmin[nid+1]);
}

void down(int id)
{
    int nid = id << 1;
    lazy[nid] += lazy[id];
    lazy[nid+1] += lazy[id];
    tmin[nid] += lazy[id];
    tmin[nid+1] += lazy[id];
    lazy[id] = 0;
}

void update(int u,int v,int val,int l = 1,int r = n,int id = 1)
{
    if(l > v || r < u) return;
    if(l >= u &&r <= v)
    {
        lazy[id] += val;
        tmin[id] += val;
        return;
    }
    down(id);
    int mid = l + r >> 1;
    int nid = id << 1;
    update(u,v,val,l,mid,nid);
    update(u,v,val,mid+1,r,nid+1);
    tmin[id] = min(tmin[nid],tmin[nid+1]);
}

int getvt(int u,int l = 1,int r = n,int id = 1)
{
    if(u == 0) return 0;
    if(l == r)return tmin[id];
    down(id);
    int mid = l + r >> 1;
    int nid = id << 1;
    if(u <= mid) return getvt(u,l,mid,nid);
    else return getvt(u,mid+1,r,nid+1);
}

int getmin(int u,int v,int l = 1,int r = n,int id = 1)
{
    if(l > v || r < u) return INT_MAX;
    if(l >= u &&r <= v) return tmin[id];
    down(id);
    int mid = l + r >> 1;
    int nid = id << 1;
    return min(getmin(u,v,l,mid,nid),
            getmin(u,v,mid+1,r,nid+1));
}

void DFS(node u)
{
    if(u.id != 0)
    {
        if(u.type)
        {
            int cnt = 0;
            int le = getvt(u.l - 1);
            int ri = getvt(u.r) - le;
            int mi = getmin(u.l,u.r) - le;
            if(mi < 0) ri -= mi,cnt -= mi;
            ans[u.id] = cnt + ri;
        }
        else
        {
            if(s[u.l - 1] == '(') update(u.l,n,-2),s[u.l - 1] = ')';
            else update(u.l,n,2),s[u.l - 1] = '(';
        }
    }
    for(auto v : g[u.id])
    {
        DFS(v);
    }
    if(u.id != 0 && !u.type)
    {
        if(s[u.l - 1] == '(') update(u.l,n,-2),s[u.l - 1] = ')';
        else update(u.l,n,2),s[u.l - 1] = '(';
    }
}

int gr(int u)
{
    return tr[u] ? tr[u] = gr(tr[u]) : u;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    cin >> s;
    n = s.size();
    rep(i,1,n) a[i] = a[i-1] + (s[i-1] == '(' ? 1 : -1);
    build();
    int q,last = 0;
    cin >> q;
    rep(i,1,q)
    {
        char type;
        cin >> type;
        switch(type)
        {
        case 'C':
            {
                int l;
                cin >> l;
                g[last].PB({0,l,0,i});
                last = i;
                break;
            }
        case 'Q':
            {
                int l,r;
                cin >> l >> r;
                g[last].PB({1,l,r,i});
                last = i;
                quest.PB(i);
                break;
            }
        case 'U':
            {
                int l;
                cin >> l;
                int p = gr(l - 1);
                tr[i] = p;
                last = p;
                break;
            }
        }
    }
    DFS({0,0,0,0});
    for(auto v : quest) cout << ans[v] << '\n';
    return 0;
}
