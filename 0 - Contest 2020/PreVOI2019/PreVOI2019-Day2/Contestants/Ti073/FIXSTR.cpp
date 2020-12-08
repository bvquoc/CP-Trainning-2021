#include<bits/stdc++.h>
/*---------------------Define--------------------*/
#define int long long
#define next nextt
#define pii pair<int,int>
#define fi first
#define se second
#define rd random
#define ll long long
#define taskname "FIXSTR"
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
int tree[oo];
int up[oo];
string s;

/*-----------------code-----------------------*/


void input()
{
    cin>>s;
    n = s.length();
    cin>>m;

    //read
}

void lazy(int id,int l,int r,int L,int R,int a)
{
    if(L<=l && r<=R)
    {
        up[id] += a;
    }
    //if( l <= 5 && 5 <= r ) cerr<<l<<" "<<r<<" "<<up[id]<<" "<<"TT0"<<endl;
    tree[id] += up[id];

    if(l!=r)
    {
        up[id*2] += up[id];
        up[id*2 + 1] += up[id];
    }

    up[id] = 0;

    if(L<=l && r<=R)
        return ;
    if(l > R || L > r)
        return ;

    int mid = (l + r)/2;
    lazy(id*2,l,mid,L,R,a);
    lazy(id*2+1,mid+1,r,L,R,a);
    tree[id] = min(tree[id*2],tree[id*2+1]);

}

int get(int id,int l,int r,int L,int R)
{
//    if( l <= 5 && 5 <= r ) cerr<<l<<" "<<r<< " "<<up[id]<<" "<<"TT0"<<endl;
    tree[id] += up[id];

    if(l!=r)
    {
        up[id*2] += up[id];
        up[id*2 + 1] += up[id];
    }

    up[id] = 0;

    if(L<=l && r<=R)
    {

        return tree[id];
    }
    if(l > R || L > r)
        return inf;
    int mid = (l + r)/2;
    int t1 = get(id*2,l,mid,L,R);
    int t2 = get(id*2+1,mid+1,r,L,R);
    return min(t1,t2);
}

void cre()
{

}

string mems[oo];

void trau()
{
    char c;
    for(int i=1; i<=m; i++)
    {
        cin>>c;
        int l,r;
        if(c=='Q')
        {
            cin>>l>>r;
            int t = 0;
            int minn = 0;
            for(int i=l-1; i<=r-1; i++)
            {
                if(s[i] == '(')
                    t ++;
                else
                    t--;
                minn = min(t,minn);
            }
            cout<<t-2*minn<<"\n";
        }
        if(c == 'C')
        {
            cin>>l;
            if(s[l-1] == '(')
                s[l-1] = ')';
            else
                s[l-1] = '(';
        }
        if(c == 'U')
        {
            cin>>l;
            s = mems[l-1];
        }
        mems[i] = s;
    }
}

void build(int id,int l,int r)
{
    if(l == r)
    {
        tree[id] = a[l];
        return ;
    }
    int mid = (l + r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id] = min(tree[id*2],tree[id*2+1]);
}

void solve()
{
    cre();
    if(n<=1000&&m<=1000)
    {
        trau();
    }
    else
    {
        int t = 0;
        n++;
        a[1] = 0 ;
        for(int i=1; i<n; i++)
        {
            if(s[i-1] == '(')
                t ++;
            else
                t--;
            a[i+1] = t;
        }
        build(1,1,n);
        char c;
        for(int i=1; i<=m; i++)
        {

            cin>>c;
            int l,r;
            if(c=='Q')
            {
                cin>>l>>r;
                int t = get(1,1,n,l,r+1);
                int st = get(1,1,n,l,l);
                int en = get(1,1,n,r+1,r+1);
             //   cerr<<s<<" "<<st<<" "<<t<<" "<<en<<"\n";
                cout<<st - t + en - t<<"\n";
            }
            if(c == 'C')
            {
                cin>>l;
             //  cerr<<get(1,1,n,5,5)<<" "<<"TT1\n";
                if(s[l-1] == '(')
                    { s[l-1] = ')'; lazy(1,1,n,l+1,n,-2);}
                else
                    { s[l-1] = '('; lazy(1,1,n,l+1,n,2);}
               //8 cerr<<get(1,1,n,5,5)<<" "<<"TT1\n";
            }
            if(c == 'U')
            {

            }
           // mems[i] = s;
        }
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

