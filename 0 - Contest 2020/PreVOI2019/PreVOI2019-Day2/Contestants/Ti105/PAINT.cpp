#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1000005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x>>i)&1)
#define debug4(i,j,k,l) cerr << i << ' ' << j << ' ' << k << ' ' << l << '\n';
#define debug3(i,j,k) cerr << i << ' ' << j << ' ' << k << '\n';
#define debug2(i,j) cerr << i << ' ' << j<< '\n';
#define debug1(i) cerr << i << '\n';
using namespace std;

int n,a[maxn],bit[maxn],cnt = 0;
int p[maxn],color[maxn],vtcl[maxn];

//void update(int vt,int v)
//{
//    for(int i = vt;i <= n;i += (i&(-i)))
//        bit[i] += v;
//}
//
//int get(int vt)
//{
//    int tmp = 0;
//    for(int i = vt; i > 0; i -= (i&(-i)))
//        tmp += bit[i];
//    return tmp;
//}
//
//int Findvt()
//{
//    int l = 1,r = n;
//    while(r - l > 1)
//    {
//        if(get(mid) == mid) l = mid;
//        else r = mid;
//    }
//    if(get(l) == mid) return l;
//    return r;
//}

void make_set(int i)
{
    p[i] = i;
    color[i] = 0;
}

int Find(int i)
{
    while(i != p[i]) i = p[i];
    return i;
}

bool Union(int u,int v)
{
    int x = Find(u);
    int y = Find(v);
    if(x == y) return false;
    p[u] = v;
    return true;
}

void Print()
{
    //cout << cnt << " :_\n";
    For(i,1,cnt)
    {
        //cerr << i << endl;
        cout << char(color[Find(i)] + 'a');
    }
    cout << '\n';
}

int main()
{
    fast_read;
    freopen("PAINT.inp","r",stdin);
    freopen("PAINT.out","w",stdout);
    cin >> n;
    For(i,1,n) make_set(i);
    For(i,1,n)
    {
        //cerr << i << endl;
        int type;
        char p1,p2;
        cin >> type;
        if(type == 1)
        {
            cin >> p1;
            color[++cnt] = p1 - 'a';
            if(vtcl[p1-'a'] != 0) Union(cnt,vtcl[p1-'a']);
            vtcl[p1-'a'] = cnt;
//            cout << type << ' ';
//            Print();
        }
        else
        {
            cin >> p1 >> p2;
            if(p1 == p2 || vtcl[p1-'a'] == 0) continue;
            int t = Find(vtcl[p1-'a']);
            if(vtcl[p2-'a'] != 0) Union(t,vtcl[p2-'a']);
            color[t] = p2 - 'a';
            vtcl[p1-'a'] = 0;
            vtcl[p2-'a'] = t;
            //cout << type << ' ';
            //Print();
        }
    }
    Print();
}
