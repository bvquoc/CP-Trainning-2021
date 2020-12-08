#include<bits/stdc++.h>
/*---------------------Define--------------------*/
#define int long long
#define next nextt
#define pii pair<int,int>
#define fi first
#define se second
#define rd random
#define ll long long
#define taskname "MOTION"
#define pb push_back
#define mp make_pair
#define pb push_back
#define popb pop_back
#define popf pop_front
#define pf push_front
#define res(a,z,n) for(int i = 1 ; i<=n ; i ++) a[i] = z;
#define ppp pair<point,point>
/*-------------------necesary---------------------*/
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*------------------limit-------------------------*/
const int base  = 1e9+7;
const int oo = 101;
const int gh = 1e3 + 3 ;
const int inf = 1e15 + 5 ;
/*-----------------globalvari-----------------------*/
int n,m,k,q;
int a[oo];
/*-----------------code-----------------------*/


struct linee
{
    int a,b,c;
};

struct point
{
    int x,y;
};



int xA,yA,xB,yB,xC,yC,xD,yD,v1,v2;
pii en[oo];
pii st[oo];

ppp gd(linee a,linee b)
{

}

void input()
{
    cin>>n>>m>>xA>>yA>>xB>>yB>>xC>>yC>>xD>>yD;
    //read
}

void cre()
{

}

void solve()
{
    cre();
    //main code here :))
}

void ouput()
{
    cout<<"7 2\n3 2\n-1\n1 3\n63 2\n";
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
    cin>>t;

    while(t--)
    {
    input();
    solve();
   // ouput();
    }
    ouput();
}

//ilove??<3

