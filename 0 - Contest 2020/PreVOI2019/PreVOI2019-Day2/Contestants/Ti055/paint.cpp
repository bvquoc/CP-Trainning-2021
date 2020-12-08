#include <bits/stdc++.h>
#define x first
#define y second
#define fu(_i,_a,_b) for (int _i=_a; _i<=_b; _i++)
#define fd(_i,_a,_b) for (int _i=_a; _i>=_b; _i--)
#define task "paint"
#define pb push_back
#define ALL(vecS) vecS.begin(),vecS.end()

using namespace std;

typedef long long ll;
typedef pair <int,int> ii;
typedef pair <ll,int> li;

const int N=1e6+5;

int n,k,slt;
int plt[28],par[N];
char ans[N],Char[N];
bool ok;
vector <int> se[N];
//vector <int> lt[N];


struct query
{
    int typ; char u,v;
} Q[N];

int anc(int uu)
{
    if (par[uu]==uu) return uu;
    return par[uu]=anc(par[uu]);
}

void join(int uu, int vv)
{
    int paru=anc(uu),parv=anc(vv);
    if (paru==parv) return;
    par[paru]=par[parv];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n;

    fu(i,1,n)
    {
        cin >> Q[i].typ >> Q[i].u;
        if (Q[i].typ==2) cin >> Q[i].v;
    }
    slt=26;
    fu(i,1,26) {plt[i]=i,par[i]=i; Char[i]=(char)(i+'a'-1);}
    fu(i,1,n)
    {
        if (Q[i].typ==1)
        {
            se[plt[(Q[i].u-'a'+1)]].pb(++k);
        }
        else
        {
            if (Q[i].u==Q[i].v) continue;
            join(plt[(Q[i].u-'a'+1)],plt[(Q[i].v-'a'+1)]);
            plt[(Q[i].u-'a'+1)]=++slt; par[slt]=slt;
            Char[slt]=Q[i].u;
        }
    }
    /*fu(i,1,26)
    {
        for (int &w: se[i]) ans[w]=(char)(i+'a'-1);
    }
    fu(i,1,k) cout << ans[i];*/
    /*fu(i,1,slt)
    {   cout << "par " << par[i] << " chari "<< Char[i]<< '\n';
        for (int &w: se[i]) cout << w << " ";
        cout << '\n';
    }*/
    fu(i,1,slt)
        if ((int)se[i].size()!=0) {int parr=anc(i); for (int &w : se[i]) ans[w]=Char[parr];}
    fu(i,1,k) cout << ans[i];
    return 0;
}
