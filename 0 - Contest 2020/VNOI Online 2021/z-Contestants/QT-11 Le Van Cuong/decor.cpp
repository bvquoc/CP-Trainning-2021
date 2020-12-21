#include <bits/stdc++.h>
using namespace std;

#define oo 1e9
#define fi first
#define se second
#define sp(iiii) setprecision(iiii)
#define IO ios_base::sync_with_stdio(false); cin.tie(0)
#define ms(aaaa,xxxx) memset(aaaa,xxxx,sizeof(aaaa))
#define cntbit(xxxx) __builtin_popcount(xxxx)
#define getbit(xxxx,aaaa) ((xxxx>>(aaaa-1))&1)


typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
typedef pair<long long,long long> pll;
typedef pair<pair<long long,long long>,long long> plll;

const ll mod=1e9+7;

struct dsu_ele{
    int par,rankt;
} dsu[500009];

pii max(pii x,pii y) {
    if (y.se-y.fi>x.se-x.fi) {
        return y;
    }
    else if (y.se-y.fi<x.se-x.fi) {
        return x;
    }
    else if (y.fi<x.fi) {
        return y;
    }
    else {
        return x;
    }
}

int getpar(int x) {
    if (dsu[x].par!=x) {
        dsu[x].par=getpar(dsu[x].par);
    }
    return dsu[x].par;
}

void Union(int x,int y) {
    x=getpar(x);
    y=getpar(y);
    if (x==y) {
        return;
    }
    if (dsu[x].rankt>dsu[y].rankt) {
        swap(x,y);
    }
    dsu[x].par=dsu[y].par;
    dsu[y].rankt+=dsu[x].rankt;
}

int n,m,k,i,a[500009],b[500009],usedk[500009],usedswap[500009],group[500009],cnt[500009],type[500009];
string s;
pii res;
deque<int> pos[500009];

void sub1() {
    int cur=0;
    for (int ii=1;ii<=n;ii++) {
        if (s[ii]=='1') {
            cur++;
            res=max(res,{ii-cur+1,ii});
        }
        else {
            cur=0;
        }
    }
    if (res.se<res.fi) {
        cout<<-1;
    }
    else {
        cout<<res.fi<<' '<<res.se<<'\n';
    }
}

void sub2() {
    int r=0;
    int cur=0;
    for (int ii=1;ii<=n;ii++) {
        if (s[ii-1]=='0') {
            cur--;
        }
        while (r<n) {
            if (s[r+1]=='1') {
                r++;
            }
            else if (cur<k) {
                cur++;
                r++;
            }
            else {
                break;
            }
        }
        res=max(res,{ii,r});
    }
    if (res.se<res.fi) {
        cout<<-1;
    }
    else {
        cout<<res.fi<<' '<<res.se<<'\n';
    }
}

void sub34() {
    int cur=0;
    int r=0;
    for (int ii=1;ii<=n;ii++) {
        dsu[ii]={ii,1};
    }
    for (int ii=1;ii<=m;ii++) {
        Union(a[ii],b[ii]);
    }
    for (int ii=1;ii<=n;ii++) {
        group[ii]=getpar(ii);
        if (s[ii]=='1') {
            cnt[group[ii]]++;
        }
    }
    for (int ii=1;ii<=n;ii++) {
        //r=max(r,ii-1);
        while (!pos[group[ii-1]].empty()&&pos[group[ii-1]].front()<ii) {
            pos[group[ii-1]].pop_front();
        }
        if (type[ii-1]==1) {
            usedk[group[ii-1]]--;
            cur--;
        }
        else if (type[ii-1]==2) {
            usedswap[group[ii-1]]--;
        }
        while (usedswap[group[ii]]<cnt[group[ii]]) {
            if (usedk[group[ii]]>0) {
                usedswap[group[ii]]++;
                type[pos[group[ii]].front()]=2;
                usedk[group[ii]]--;
                pos[group[ii]].pop_front();
            }
            else {
                break;
            }
        }
        while (r<n) {
            if (s[r+1]=='1') {
                if (usedswap[group[r+1]]<cnt[group[r+1]]) {
                    r++;
                    usedswap[group[r]]++;
                    type[r]=2;
                }
                else if (cur<k) {
                    cur++;
                    usedk[group[r+1]]++;
                    type[r+1]=1;
                    r++;
                    pos[group[r]].push_back(r);
                }
                else {
                    break;
                }
            }
            else {
                if (usedswap[group[r+1]]<cnt[group[r+1]]) {
                    r++;
                    usedswap[group[r]]++;
                    type[r]=2;
                }
                else if (cur<k) {
                    cur++;
                    usedk[group[r+1]]++;
                    type[r+1]=1;
                    r++;
                    pos[group[r]].push_back(r);
                }
                else {
                    break;
                }
            }
        }
        res=max(res,{ii,r});
    }
    if (res.se<res.fi) {
        cout<<-1;
    }
    else {
        cout<<res.fi<<' '<<res.se<<'\n';
    }
}

int main(){
    IO;
    freopen("decor.inp", "r", stdin);
    freopen("decor.out", "w", stdout);
    cin>>n>>m>>k;
    cin>>s;
    res={n,1};
    for (i=1;i<=m;i++) {
        cin>>a[i]>>b[i];
    }
    s=" "+s;
    if (m==0) {
        if (k==0) {
            sub1();
        }
        else {
            sub2();
        }
    }
    else {
        sub34();
    }
}
