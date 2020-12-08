#include<bits/stdc++.h>
#define up(i,d,c) for(int i=d;i<=c;i++)
#define pb push
using namespace std;
int n;
char a[1000005];
queue<int> cx[50];
int main()
{
	#define NAME "PAINT"
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen(NAME".inp","r",stdin);
	freopen(NAME".out","w",stdout);
    cin>>n;
    int it=0;
    up(i,1,n)
    {
        a[i]='1';
    }
    up(i,1,n)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            char c;
            cin>>c;
            a[++it]=c;
            cx[c-96].pb(it);
        }
        else
        {
            char x,y;
            cin>>x>>y;
            int l=x-96;
            int r=y-96;
            while(!cx[l].empty())
            {
                int tg=cx[l].front();
                cx[l].pop();
                a[tg]=y;
                cx[r].pb(tg);
            }

        }

    }
    up(i,1,it)
    {
    cout<<a[i];
    }

}
