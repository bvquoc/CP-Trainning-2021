#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N=1000001;
string luu[N];
ll res,vt,t,n,m,l,r;
string s;
char c;
ll info[4*N];

void build(ll id,ll l,ll r)
{
    if (l==r)
    {
        if (s[l]=='(') info[id] = 1; else info[id] = -1;
        return;
    }
    ll mid = (l + r) / 2;
    build(2*id,l,mid); build(2*id+1,mid+1,r);
    info[id] = info[2*id] + info[2 * id + 1];
}

void update(ll id,ll l,ll r,ll x)
{
    if (x<l || x>r) return;
    if (x==l && l==r) {if (s[x]=='(') info[id]=1; else info[id]=-1; return;}
    ll mid=( l + r ) / 2;
    update(2*id,l,mid,x);
    update(2*id+1,mid+1,r,x);
    info[id]=info[2*id] + info[2*id+1];
}

ll get(ll id,ll l,ll r,ll x,ll y)
{
    if (y<l || x>r) return 0;
    if (l==r) return info[id];
    ll mid = (l + r) / 2;

    return get(2*id,l,mid,x,y) + get(2*id+1,mid+1,r,x,y);
}

inline void sub1()
{
    //build(1,1,n);

    for (ll lenh=1;lenh<=m;++lenh)
    {
        luu[lenh]=s;
        cin >> c;
        if (c=='C')
        {
            cin >> vt;
            if (s[vt]=='(') s[vt]=')'; else s[vt]='(';

            //update(1,1,n,vt);
        } else
        if (c=='U')
        {
            cin >> vt;
            s=luu[vt];
            //build(1,1,n);
        } else
        {
            cin >> l >> r;
            res = 0; t = 0;
            for (ll i=l;i<=r;++i)
            {
              if (s[i]=='(') t++; else t--;
              if (t<0) {t++; res++;}
            }
            res +=abs(0 - t);
            cout << res <<'\n';
        }
    }
}

void sub2()
{
    build(1,1,n);

    for (ll lenh=1;lenh<=m;++lenh)
    {
        luu[lenh]=s;
        cin >> c;
        if (c=='C')
        {
            cin >> vt;
            if (s[vt]=='(') s[vt]=')'; else s[vt]='(';
            update(1,1,n,vt);
        } else
        if (c=='U')
        {
            cin >> vt;
            s=luu[vt];
            build(1,1,n);
        } else
        {
            cin >> l >> r;
            res = 0; t = 0;
            res= abs(0 - get(1,1,n,l,r));
            cout << res <<'\n';
        }
    }
}

int main()
{
    freopen("FIXSTR.inp","r",stdin); freopen("FIXSTR.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    n = s.length(); s=' '+s;
    cin >> m;

    if (n*m<=300000000 || (n<=1000 && m<=1000)) {sub1(); return 0;} else sub2();
    return 0;
}
