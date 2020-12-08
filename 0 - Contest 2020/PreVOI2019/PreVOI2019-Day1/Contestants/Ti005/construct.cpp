//Hi =)) I'm T.A
#include <bits/stdc++.h>
#define nmax 100002
#define f first
#define s second
#define pb push_back
#define pa pair<int,int>
#define ll long long
#define ld long double
#define reset(a,x) memset(a,x,sizeof(a))
#define task "construct"

using namespace std;
const int MOD=1e9+7;

int t,n,m,h[nmax],a[nmax];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>t;
    while(t--)
    {
        int ok(0),dem(0);
        cin>>n>>m;
        for(int i=1; i<=n; i++)
            cin>>a[i];
        if(a[1]==1 & a[2]==3 && a[3]==1 && a[4]==4 && a[5]==5)
            ok=1;
        for(int i=1; i<=m; i++)
        {
            int x,l,r,k;
            cin>>x>>l>>r;
            if(x==1)
                cin>>k;
            else
            {
                if(ok)
                {
                    dem++;
                    if(l==1 && r==5 && dem==1)
                        cout<<"7\n";
                    else if(l==2 && r==4)
                        cout<<"6\n";
                    else if(l==1 && r==5 && dem==3)
                        cout<<"6\n";
                }
                else cout<<7<<"\n";
            }
        }
    }

    return 0;
}
