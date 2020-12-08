#include<bits/stdc++.h>
/*---------------------Define--------------------*/
#define int long long
#define next nextt
#define pii pair<int,int>
#define fi first
#define se second
#define rd random
#define ll long long
#define taskname "PAINT"
#define pb push_back
#define mp make_pair
#define pb push_back
#define popb pop_back
#define popf pop_front
#define pf push_front
#define res(a,z,n) for(int i = 1 ; i<=n ; i ++) a[i] = z;
/*-------------------necesary---------------------*/
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*------------------limit-------------------------*/
const int base  = 1e9+7;
const int oo = 1e6 + 10;
const int gh = 1e3 + 3 ;
const int inf = 1e15 + 5 ;
/*-----------------globalvari-----------------------*/
int n,m,k,q;
int a[oo];
/*-----------------code-----------------------*/


void input()
{
    //read
    cin>>n;

}

void cre()
{

}

int v[28];

int par[oo];
int rankk[oo];

int fp(int x)
{
    if(par[x] == 0) return x;
    par[x] =  fp(par[x]);
    return par[x];
}

void Union(int x,int y)
{
    x = fp(x);
    y = fp(y);
    if(x == y) return ;
    if(rankk[x] == rankk[y]) rankk[x] ++ ;
    if(rankk[x] < rankk[y]) swap(x,y);
    par[y]  = x;
}

char ans[oo];

void solve()
{
    cre();
    int t;
    char c,d;
    int cur = 0;
    for(int i=1;i<=n;i++)
        {
       //     cin>>a[i];
            cin>>t;

            if(t == 1)
            {
                cin>>c;
                c-='a';
                cur ++;
                if(v[c] == 0) v[c] = cur;
                else Union(v[c],cur);
            }
            else
            {
                cin>>c>>d;
                c-='a';
                d-='a';
                if(v[c] == 0) continue;
                else
                {
                    if(v[d] == 0) v[d] = v[c];
                    else Union(v[c],v[d]);
                    if(par[v[d]] != 0 ) v[d] = par[v[d]];
                    v[c] = 0;
                }
            }
        }
    for(int i=0;i<=26;i++)
    {
        ans[v[i]] = char(i+'a');
    }
    for(int i=1;i<=cur;i++)
    {
        cout<<ans[fp(i)];
    }
    //main code here :))
}

void ouput()
{

    //write
}

int32_t main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //#ifndef ONLINE_JUDGES
    if (ifstream("test.txt"))
    {
        freopen("test.txt", "r", stdin);
        #ifdef CHECKING
            freopen(taskname".out", "w", stdout);
        #else
            //\freopen("test.out", "w", stdout);
        #endif //CHECKING
    }
    else if (ifstream(taskname".inp"))
    {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }
    //#endif // ONLINE_JUDGES
    int t=1;
   // cin>>t;

    while(t--)
    {
    input();
    solve();
    ouput();
    }
}

//ilove??<3

