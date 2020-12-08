#include <bits/stdc++.h>

using namespace std;

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
#define ull unsigned long long
#define ll long long
#define ii pair<int,int>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define TASK "FIXSTR"

const ll oo = 1e15+7 ;
const ll mod = 1e9+7 ;
const int N = 1e6+7 ;
struct data{
    int mi , lazy ;
};
int m ;
string s ;
string a[N] ;
int t[N] ;
data IT[4*N] ;
int n ;
int _calc(int l,int r)
{
    int t = 0 ;
    int res = 0 ;
    For(i,l,r)
    {
        if(s[i] == '(') t++ ;
        else
            t-- ;
        if(t < 0)
        {
            res++ ;
            t = 0 ;
        }
    }
    return res + t ;
}
void sub1()
{
    char c ;
    int u, v ;
    For(i,1,m)
    {
        cin >> c ;
        if(c == 'C')
        {
            cin >> u ;
            if(s[u] == '(') s[u] = ')';
            else
                s[u] = '(' ;
            a[i] = s ;
        }
        if(c == 'Q')
        {
            cin >> u >> v ;
            cout << _calc(u , v) << "\n" ;
            a[i] = s ;
        }
        if(c == 'U')
        {
            cin >> u ;
            s = a[u-1] ;
            a[i] = s ;
        }
    }
}
void Build(int id,int l,int r)
{
    if(l == r)
    {
        IT[id].mi = t[l] ;
        return ;
    }
    int mid = (l + r) / 2 ;
    Build(id*2,l,mid) ;
    Build(id*2+1,mid+1,r) ;
    IT[id].mi = min(IT[id].mi , IT[id*2+1].mi) ;
}
void Down(int id)
{
    if(IT[id].lazy != 0)
    {
        int t = IT[id].lazy ;

        IT[id*2].mi += t ;
        IT[id*2+1].mi += t ;

        IT[id*2].lazy += t ;
        IT[id*2+1].lazy += t ;

        IT[id].lazy = 0 ;
    }
    return ;
}
void Update(int id,int l,int r,int u,int v,int val)
{
    if(l > v || r < u) return ;
    if(u <= l && r <= v)
    {
        IT[id].mi += val ;
        IT[id].lazy += val ;
        return ;
    }
    Down(id) ;
    int mid = (l + r) / 2 ;
    Update(id*2,l,mid,u,v,val) ;
    Update(id*2+1,mid+1,r,u,v,val) ;
    IT[id].mi = min(IT[id*2].mi , IT[id*2+1].mi) ;
}
int Get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return mod ;
    if(u <= l && r <= v)
        return IT[id].mi ;
    Down(id) ;
    int mid = (l + r) / 2 ;
    return min(Get(id*2,l,mid,u,v) , Get(id*2+1,mid+1,r,u,v)) ;
}
int Solve(int l,int r)
{
    int pre ;
    int res = 0 ;
    if(l == 1) pre = 0 ;
    else
        pre = Get(1,1,n,l-1,l-1) ;
    int last ;
    int tmp = Get(1,1,n,l,r) ;
    if(tmp < pre)
    {
        res += pre - tmp ;
        last = Get(1,1,n,r,r) ;
        if(last + pre - tmp > 0) res += last + pre - tmp ;
    }
    else
    {
        last = Get(1,1,n,r,r) ;
        res += last ;
    }
    return res ;
}
void sub2()
{
    int x = 0 ;
    For(i,1,n)
    {
        if(s[i] == '(') x++ ;
        else x-- ;
        t[i] = x ;
    }
    Build(1,1,n) ;
    char c ;
    int u, v ;
    For(i,1,m)
    {
        cin >> c ;
        if(c == 'C')
        {
            cin >> u ;
            if(s[u] == '(')
            {
                s[u] = ')';
                Update(1,1,n,u,n,-2) ;
            }
            else
            {
                s[u] = '(' ;
                Update(1,1,n,u,n,+2) ;
            }
        }
        if(c == 'Q')
        {
            cin >> u >> v ;
            cout << Solve(u , v) << "\n" ;
        }
    }
}
int main()
{
    freopen(TASK".INP","r",stdin) ;
    freopen(TASK".OUT","w",stdout) ;
    ios_base::sync_with_stdio(0) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    cin >> s ;
    n = s.size() ;
    s = " " + s ;
    cin >> m ;
    if(m <= 1000) sub1() ;
    else
        sub2() ;
    return 0;
}
