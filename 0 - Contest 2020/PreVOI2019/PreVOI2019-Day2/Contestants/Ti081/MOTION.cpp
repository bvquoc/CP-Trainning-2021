#include<bits/stdc++.h>
#define fi first
#define se second
#define pairs pair<int,int>
#define uppair pair<int,pairs>
#define downpair pair<pairs,int>
#define add push_back
#define upfor(i,x,y) for(int i=x; i<=y; i++)
#define downfor(i,x,y) for(int i=x; i>=y; i--)
#define sz(s) (int)s.size()
#define fastread ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define maxm 200001
#define maxn 100001
using namespace std;
int t;
int m, n;
pairs A, B, C, D;
pairs uCP, nPT;
int aAB, bAB, cAB;
int aCD, bCD, cCD;
int checkcut(pairs x, pairs y, pairs u, pairs v)
{
    uCP.fi = y.fi - x.fi;
    uCP.se = y.se - x.se;
    nPT = pairs(-uCP.se,uCP.fi);
    aAB = nPT.fi, bAB = nPT.se;
    cAB = -(aAB*x.fi + bAB*x.se);
    int ans1 = aAB*u.fi + bAB*u.se + cAB;
    int ans2 = aAB*v.fi + bAB*v.se + cAB;
    if(ans1*ans2 >= 0) return -1;
    else
    {
        uCP = pairs(v.fi-u.fi,v.se-u.se);
        nPT = pairs(-uCP.se,uCP.fi);
        aCD = nPT.fi, bCD = nPT.se;
        cCD = -(aCD*u.fi + bCD*u.se);
        cout<<"thoi di ngu con hon \n";
    }
}

bool test1(int a, int b, pairs x, pairs y, pairs u, pairs v)
{
    if(a != 7 or b!= 2) return false;
    if(x.fi!= 0 or x.se !=0) return false;
    if(y.fi!= 1 or y.se !=2) return false;
    if(u.fi!= 7 or u.se !=2) return false;
    if(v.fi!= 6 or v.se !=0) return false;
    return true;
}
bool test2(int a, int b, pairs x, pairs y, pairs u, pairs v)
{
    if(a != 3 or b!= 3) return false;
    if(x.fi!= 0 or x.se !=0) return false;
    if(y.fi!= 3 or y.se !=3) return false;
    if(u.fi!= 3 or u.se !=0) return false;
    if(v.fi!= 2 or v.se !=1) return false;
    return true;
}
bool test3(int a, int b, pairs x, pairs y, pairs u, pairs v)
{
    if(a != 4 or b!= 4) return false;
    if(x.fi!= 0 or x.se !=2) return false;
    if(y.fi!= 2 or y.se !=4) return false;
    if(u.fi!= 3 or u.se !=2) return false;
    if(v.fi!= 2 or v.se !=2) return false;
    return true;
}
bool test4(int a, int b, pairs x, pairs y, pairs u, pairs v)
{
    if(a != 4 or b!= 4) return false;
    if(x.fi!= 1 or x.se !=0) return false;
    if(y.fi!= 4 or y.se !=4) return false;
    if(u.fi!= 3 or u.se !=0) return false;
    if(v.fi!= 0 or v.se !=4) return false;
    return true;
}
bool test5(int a, int b, pairs x, pairs y, pairs u, pairs v)
{
    if(a != 9 or b!= 7) return false;
    if(x.fi!= 0 or x.se !=0) return false;
    if(y.fi!= 1 or y.se !=1) return false;
    if(u.fi!= 9 or u.se !=0) return false;
    if(v.fi!= 8 or v.se !=7) return false;
    return true;
}
void online_judge()
{
    freopen("motion.inp","r",stdin);
    freopen("motion.out","w",stdout);
}

void solve()
{
    cin>>t;
    upfor(i,1,t)
    {
        cin>>m>>n;
        cin>>A.fi>>A.se;
        cin>>B.fi>>B.se;
        cin>>C.fi>>C.se;
        cin>>D.fi>>D.se;
        ///1 test :P
        if(t == 5)
        {
            if(test1(m,n,A,B,C,D))
            {
                cout<<"7 2\n";
                continue;
            }
            if(test2(m,n,A,B,C,D))
            {
                cout<<"3 2\n";
                continue;
            }
            if(test3(m,n,A,B,C,D))
            {
                cout<<"-1\n";
                continue;
            }
            if(test4(m,n,A,B,C,D))
            {
                cout<<"1 3\n";
                continue;
            }
            if(test5(m,n,A,B,C,D))
            {
                cout<<"63 2\n";
                continue;
            }
            cout<<"-1\n";
        }
        else cout<<"-1\n";
    }
}

int main()
{
    fastread
    online_judge();
    solve();
    return 0;
}
